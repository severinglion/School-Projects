import java.util.ArrayList;
import java.util.Iterator;

class Example {
    private ArrayList<Integer> vector;
    private int functionValue;
    private Scheme scheme;

    public Example( Scheme scheme, ArrayList<String> order ) {
        functionValue = 0;
        vector = new ArrayList<>();
        this.scheme = scheme;
    }

    public void addAttributeValue( String attribute, String value ){
        int index = scheme.getValueIndex(attribute, value);
        if( index < 0 ) UTIL.HandleError( "Invalid attribute value pair (" + attribute + ", " + value + ")"  );
        vector.add(index);
    }

    public void setFunctionValue ( String value ) {
        int index = scheme.getValueIndex( scheme.getFunction().getName(), value );
        if( index < 0 ) UTIL.HandleError( "Invalid function value pair (Func, " + value + ")" );
        functionValue = index;
    }

    public int getSize() {
        return vector.size() - 1;
    }

    public int getFunctionValue() {
        return functionValue;
    }

    public int getExampleCountWithValue( int v ) {
        int size = 0; 
        Iterator<Integer> it = vector.iterator();
        while( it.hasNext() ) {
            int val = it.next();
            if( val == v ) size++;
        }
        return size;
    }

    public Example subg( int b ) {
        if( b < 0 ) return null;
        Example sub = new Example(scheme, null);
        Iterator<Integer> it = vector.iterator();
        while( it.hasNext() ) {
            Integer val = it.next();
            int attribute = vector.indexOf( val );
            if(attribute != b) {
                sub.addAttributeValue( "" + attribute, val.toString() );
            }
        }
        return sub;
    }

    public boolean hasAttributeValue( int attribute, int value ) {
        if(attribute > vector.size())   UTIL.HandleError("Invalid attribute " + attribute + " in example " + vector.toString());
        return value == vector.get(attribute);
    }
}