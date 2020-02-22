
class Token{

  //token identifiers
  public final static int ERROR = 0;
  public final static int NUM = 1;
  public final static int WORD = 2;
  public final static int OPEN_TAG = 3;
  public final static int CLOSE_TAG = 4;
  public final static int PUNC = 5;
  public final static int HYPHEN = 6;
  public final static int APOS = 7;

  public int m_type;
  public String m_value;
  public int m_line;
  public int m_column;
  public Boolean relavant;
  
  Token (int type, String value, int line, int column) {
    m_type = type;
    m_value = value;
    m_line = line;
    m_column = column;
    relavant = false;
  }

  //Checks if a given string is one of the relavant tags 
  static Boolean isRelavantTag(String tagName){
    switch (tagName.toLowerCase()){
      case "doc":
        return true;
      case "docno":
        return true;
      case "text":
        return true;
      case "date":
        return true;
      case "headline":
        return true;
      case "length":
        return true;
      default:
        return false;
    }
  }
  
  public String toString() {
      switch (m_type) {
      case APOS:
        return "APOSTOPHIZED(" + m_value + ")";
      case HYPHEN:
        return "HYPHENATED(" + m_value + ")";
      case PUNC:
        return "PUNC(" + m_value + ")";
      case CLOSE_TAG:
        return "CLOSE_TAG(" + m_value + ")";
      case OPEN_TAG:
        return "OPEN_TAG(" + m_value + ")";
      case WORD:
        return "WORD(" + m_value + ")";
      case NUM:
        return "NUM(" + m_value + ")";
      case ERROR:
        return "ERROR(" + m_value + ")";
      default:
        return "UNKNOWN(" + m_value + ")";
    }
  }
}