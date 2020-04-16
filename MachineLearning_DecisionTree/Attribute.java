import java.util.ArrayList;

class Attribute {
    private String name;
    private ArrayList<String> values;
    
    public Attribute( String name ) {
        values = new ArrayList<String>();
        this.name = name;
    }

    public Attribute ( String name, ArrayList<String> values ) {
        this.name = name;
        this.values = values;
    }

    public Attribute ( Attribute attr ) {
        this.name = attr.getName();
        this.values = attr.getValues();
    }

    public void addValue( String value ) {
        values.add(value);
    }

    public ArrayList<String> getValues(  ) {
        return new ArrayList<String>(values);
    }

    public String getName(  ) {
        return name;
    }

    public boolean isAttributeValue( String value ){
        return values.contains( value );
    }

    public int getValueIndex( String value ) {
        return values.indexOf( value );
    }

    public String getAttributeValue( int index ) {
        return values.get(index);
    }

    public int getSize() {
        return values.size();
    }

}