import java.util.ArrayList;

class Node extends Element {
    public Node parent;
    public int label;
    public int incomingLink;
    public ArrayList<Node> children;
    boolean isEndNode;

    public Node( int label) {
        this.parent = null;
        this.label = label;
        this.incomingLink = -1;
        children = new ArrayList<>();
        isEndNode = false;
    }

    public Node ( int label, boolean end ) {
        this.parent = null;
        this.label = label;
        this.incomingLink = -1;
        children = new ArrayList<>();
        isEndNode = end;
    }

    public void accept( Visitor visitor, int depth) {
        visitor.visit(this, depth);
    }

    public void addChild( Node child ) {
        children.add(child);
    }

    public void setParent( Node parent ) {
        this.parent = parent;
    }

}