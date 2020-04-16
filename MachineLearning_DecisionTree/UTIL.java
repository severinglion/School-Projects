import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

class UTIL {
    static public Scheme LoadSchemeFile( String filename ) {
        if( filename.isEmpty() )  return null;

        Scheme scheme = new Scheme();
        try{
            Scanner sc = new Scanner( new File( filename ) );
            int count = sc.nextInt();
            if( count < 1 ) throw new Exception( "Invalid record count " + count );

            for ( int i = 0; i < count; i++ ) {
                Attribute attr = parseParagraph( sc );
                if( i == count - 1 )    scheme.setFunction( attr );
                else    scheme.addAttribute( attr );
            }
        } catch( Exception e ) {
            System.err.println( e.getMessage() );
            e.printStackTrace();
            System.exit( -1 );
        }
        return scheme;
    }

    /**
     * Load the example data set from a file. 
     * @param filename the name of the file
     * @param scheme the scheme that defines the dataset
     * @return  the example data set
     */
    static public Sample LoadDataFile( String filename, Scheme scheme ) {
        if( filename.isEmpty() )    return null;
        Sample data = new Sample( scheme );
        ArrayList<String> order = new ArrayList<String>();
        try {
            Scanner sc = new Scanner(new File(filename));
            for( int i = 0; i < scheme.getAttributeSize() + 1; i++ ) {
                String attr = sc.next();
                if( !scheme.hasAttribute(attr) && !scheme.getFunction().getName().equalsIgnoreCase(attr) ) HandleError( "Invalid attribute type [" + attr + "]" );
                order.add(i, attr);
            }
            int position = 0;
            Example line = null;
            while( sc.hasNext() ){
                if(position == 0)   line = new Example( scheme, order );
                String value = sc.next();
                if( !scheme.hasValue(order.get(position), value) )  UTIL.HandleError("Invalid attribute value (" + order.get(position) + ", " + value + ")");
                if( position == scheme.getAttributeSize() ) {
                    line.setFunctionValue( value );
                    data.addTrainingExample( line );
                    position = 0;
                } else {
                    line.addAttributeValue(order.get(position), value);
                    position++;
                }                
            }
        } catch( Exception e ){
            e.printStackTrace();
            UTIL.HandleError( e.getMessage() );
        }
        
        return data;
    }

    static private Attribute parseParagraph( Scanner sc ) {
        String name = sc.next();
        ArrayList<String> vals = new ArrayList<String>();
        int count = sc.nextInt();
        for( int i = 0; i < count; i++ ) {
            vals.add( sc.next() );
        }
        return new Attribute( name, vals );
    }

    static public void HandleError( String message ) {
        System.err.print( "\u001b[31mError:\u001b[0m " );
        System.err.println( message );
        System.exit( -1 );
    }
}