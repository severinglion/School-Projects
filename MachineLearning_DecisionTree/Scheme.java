import java.util.ArrayList;
import java.util.Iterator;

class Scheme {
    private ArrayList<Attribute> attributes;
    private Attribute function;

    Scheme() {
        attributes = new ArrayList<Attribute>();
        function = null;
    }

    public void addAttribute( Attribute attr ) {
        if( !attributes.contains( attr ) )   attributes.add(attr);
    }

    public void setFunction( Attribute attr ) {
        function = new Attribute( attr );
    }

    public Attribute getFunction() {
        return new Attribute( function );
    }

    /**
     * Retrieve the number of attributes within the scheme
     * @return
     */
    public int getAttributeSize() {
        return attributes.size();
    }

    /**
     * Retrieve the number of possible values an attribute can have
     * @param attribute the index of the attribute within the scheme
     * @return the number of possible values
     */
    public int getAttributeSize(int attribute) {
        if(attributes.size() < attribute)   UTIL.HandleError("Invalid attribute value " + attribute);
        Attribute s = attributes.get(attribute);
        if(s == null)   UTIL.HandleError("Attribute value " + attribute + " was not found");
        return s.getSize();
    }

    public boolean hasAttribute( String name ) {
        if(name.equalsIgnoreCase(function.getName()))   return true;
        Iterator<Attribute> it = attributes.iterator();
        while( it.hasNext() ){
            Attribute attr = it.next();            
            if(attr != null && attr.getName().equalsIgnoreCase(name))   return true;
        }
        return false;
    }

    public boolean hasValue( String attribute, String value ) {
        if( !hasAttribute( attribute ) )    return false;
        if( attribute.equalsIgnoreCase(function.getName()) ) return function.isAttributeValue( value );
        Iterator<Attribute> it = attributes.iterator();
        while( it.hasNext() ) {
            Attribute attr = it.next();
            if(attr.getName().equalsIgnoreCase( attribute ) ) {
                if(attr.isAttributeValue( value ) ) return true;
            }
        }
        return false;
    }

    public int getValueIndex( String attribute, String value ) {
        if( !hasValue( attribute, value ))  return -1;
        if( attribute.equalsIgnoreCase( function.getName() ) ) return function.getValueIndex(value);
        Iterator<Attribute> it = attributes.iterator();
        while( it.hasNext() ) {
            Attribute attr = it.next();
            if(attr.getName().equalsIgnoreCase( attribute ) ) {
                return attr.getValueIndex( value );
            }
        }
        return -1;
    }

    public String getAttributeLabel( int index ) {
        if( index > attributes.size() ) {
            UTIL.HandleError( "Invalid attribute index " + index );
        }
        Attribute attr = attributes.get( index );
        return attr.getName();
    }

    public String getAttibuteValueLabel( int attributeIndex, int valueIndex ) {
        if( attributeIndex > attributes.size() )    UTIL.HandleError( "Invalid attribute " + attributeIndex );
        Attribute attr = attributes.get(attributeIndex);
        if(attr == null)    UTIL.HandleError( "Invalid attribute " + attributeIndex );
        if( valueIndex > attr.getSize() )   UTIL.HandleError( "Invalid attribute value " + valueIndex );
        String value = attr.getValues().get(valueIndex);
        if( value == null )    UTIL.HandleError( "Invalid attribute value " + valueIndex );
        return value;
    }

    public String getFunctionValueLabel( int index ) {
        if( index > function.getSize() ) {
            UTIL.HandleError( "Invalid function value " + index );
        }
        return function.getValues().get(index);
    }

}