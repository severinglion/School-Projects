import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

class Sample {
    private ArrayList<Example> trainingSet;
    private Scheme scheme;

    public Sample( Scheme scheme ) {
        trainingSet = new ArrayList<Example>();
        this.scheme = scheme;
    }

    public void addTrainingExample( Example training ) {
        trainingSet.add(training);
    }

    public double getInfo( Sample g, int k ) {
        int size = g.getSize();
        int[] count = new int[k];
        
        for(int j = 0; j < k; j++) {
            count[j] = g.countExamplesFuncVal(j);
        }
        double i = 0;
        for(int j = 0; j < k; j++){
            double pr = count[j] / (double) size;
            if(pr > 0 && pr < 1) {
                i = i - pr * (Math.log(pr) / Math.log(2));
            } 
        }
        return i;
    }
    
    public double getRmd( int b, Sample g, int k ) {
        int size = g.getSize();
        int m = scheme.getAttributeSize(b);
        Sample[] subg = new Sample[m];
        double[] subCount = new double[m];
        for( int i = 0; i < m; i++ ) {
            subg[i] = g.split(b, i);
            subCount[i] = subg[i].getSize();
        }
        double remainder = 0;
        for( int i = 0; i < m; i++ ) {
            double pr = subCount[i] / (double) size;
            double info = getInfo(subg[i], k);
            remainder += pr * info;
        }        
        return remainder;
    }

    public int getAttribute( ArrayList<Integer> attrib, Sample g ) {
        System.out.println("Selecting Best Attribute From: ");
        int k = scheme.getFunction().getSize();
        double I = getInfo( g, k );
        double maxGain = -1;
        int bestA = -1;
        Iterator<Integer> it = attrib.iterator();
        while( it.hasNext() ) {
            int b = it.next();
            double remainder = getRmd(b, g, k);
            double gain = I - remainder;
            String label = scheme.getAttributeLabel( b );
            System.out.println( "    Test " + label + ": info=" + I + " rmd=" + remainder + " gain=" + gain );
            if( gain > maxGain ) {
                maxGain = gain;
                bestA = b;
            }
        }
        String label = scheme.getAttributeLabel(bestA);
        System.out.println( "\tSelect Attribute " + label );
        return bestA;
    }

    public int getMajorityFuncVal() {
        Map<Integer, Integer> counter = new HashMap<>();
        Iterator<Example> it = trainingSet.iterator();
        while( it.hasNext() ) {
            Example i = it.next();
            int funcVal = i.getFunctionValue();
            counter.putIfAbsent(funcVal, 0);
            counter.put(funcVal, counter.get(funcVal) + 1);
        }
        int majorityCount = -1;
        int majorityIndex = -1;
        for( Map.Entry<Integer, Integer> entry : counter.entrySet() ) {
            if(entry.getValue() > majorityCount) {
                majorityCount = entry.getValue();
                majorityIndex = entry.getKey();
            }
        }
        return majorityIndex;
    }

    public boolean isEmpty() {
        return trainingSet.isEmpty();
    }

    public boolean hasSameFuncVal() {
        Iterator<Example> row = trainingSet.iterator();
        int val = -1;
        while( row.hasNext() ) {
            Example e = row.next();
            if(val == -1) {
                val = e.getFunctionValue();
            } else {
                int test = e.getFunctionValue();
                if(val != test)    return false;
            }
        }
        return true;
    }

    public int getFirstFunctionValue() {
        Example row = trainingSet.get(0);
        return row.getFunctionValue();
    }

    public int countExamplesFuncVal( int val ) {
        int count = 0;
        Iterator<Example> row = trainingSet.iterator();
        while( row.hasNext() ) {
            Example e = row.next();
            if(e.getFunctionValue() == val)   count++;
        }
        return count;
    }

    public int getSize() {
        return trainingSet.size();
    }

    public Sample split( int attribute, int value ) {
        Sample out = new Sample( scheme );
        Iterator<Example> row = trainingSet.iterator();
        while( row.hasNext() ) {
            Example e = row.next();
            if( e.hasAttributeValue(attribute, value) ){
                out.addTrainingExample( e );
            }
        }
        return out;
    }
}