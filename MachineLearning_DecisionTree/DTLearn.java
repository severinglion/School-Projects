import java.util.ArrayList;

class DTLearn extends Element {
    private Scheme scheme;
    private Sample data;
    private Node root;

    DTLearn( String[] filenames ) {
        init( filenames );
        root = null;
    }

    @Override
    public void accept( Visitor visitor, int depth ) {
        visitor.visit(root, depth);
    }

    public Scheme getScheme() {
        return scheme;
    }

    public void generateTree() {
        //genenerate set of attributes
        ArrayList<Integer> attributes = new ArrayList<>();
        int lim = scheme.getAttributeSize();
        for( int i = 0; i < lim; i++ ) {
            attributes.add(i);
        }
        //generate tree
        root = learnDecisionTree(data, attributes, -1);
    }

    private Node learnDecisionTree( Sample data, ArrayList<Integer> attribute, int majorityValue) {
        if( data.isEmpty() )    return new Node(majorityValue, true);
        if( data.hasSameFuncVal() )     return new Node(data.getFirstFunctionValue(), true);
        if( attribute.isEmpty() )   return new Node(data.getMajorityFuncVal(), true);
        int b = data.getAttribute(attribute, data);
        Node tr = new Node(b);
        int m = data.getMajorityFuncVal();
        int sizeB = scheme.getAttributeSize(b);
        for( int v = 0; v < sizeB; v++ ){
            Sample subg = data.split(b, v);
            ArrayList<Integer> attrib = new ArrayList<>();
            for (Integer integer : attribute) {
                if(integer != b)    attrib.add(integer);
            }
            Node subtr = learnDecisionTree(subg, attrib, m);
            subtr.setParent(tr);
            subtr.incomingLink = v;
            tr.addChild(subtr);
        }
        return tr;
    }

    public static void main( String[] args ) {
        DTLearn decisionTree = new DTLearn( args );
        PrintTreeVisitor printer = new PrintTreeVisitor( decisionTree.getScheme() );

        decisionTree.generateTree();
        printer.visit(decisionTree, 0);

        return;
    }

    private void init( String [] args ) {
        if (args.length != 2)   UTIL.HandleError( "Usage: java DTLearn <scheme_file> <data_file>" );

        scheme = UTIL.LoadSchemeFile( args[0] );
        if( scheme == null )    UTIL.HandleError( "Scheme file could not be loaded" );

        data = UTIL.LoadDataFile( args[1], scheme );
        if( data == null )    UTIL.HandleError( "Sample data could not be loaded" );
    }
}