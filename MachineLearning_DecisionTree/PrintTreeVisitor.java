import java.util.Iterator;

class PrintTreeVisitor implements Visitor {
    final static int SPACE = 4;
    private Scheme scheme;

    public PrintTreeVisitor( Scheme s) {
        scheme = s;
    }
    void indent(int depth) {
        int limit = depth * SPACE;
        for(int i = 0; i < limit; i++){
            System.out.print(" ");
        }
    }

    @Override
    public void visit(Node attrib, int depth) {
        if(attrib.incomingLink >= 0 && attrib.parent != null) {
            indent(depth);
            String link = scheme.getAttibuteValueLabel(attrib.parent.label, attrib.incomingLink);
            System.out.println("incoming link: " + link);
        }
        
        indent(depth);
        String label = "";
        if(attrib.isEndNode) {
            label = scheme.getFunctionValueLabel(attrib.label);
        } else {
            label = scheme.getAttributeLabel(attrib.label);
        }
        System.out.println("node: " + label);


        Iterator<Node> child = attrib.children.iterator();
        while( child.hasNext() ) {
            Node node = child.next();
            node.accept(this, depth + 1);
        }

    }

    @Override
    public void visit(DTLearn root, int depth) {
        System.out.println("Decision Tree");
        root.accept(this, depth);
    }

}