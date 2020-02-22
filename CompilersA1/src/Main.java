/**@file Main.java
 * Contains the main function for the scanner application
 */
import java.io.InputStreamReader;
import java.io.StringReader;

class Main{
  static Stack tagStack;
  
  public static void main(String[] args){
    //TestStack();
    RunApp();
  }

  public static void TestStack(){
    Stack tagStack = new Stack();
    for(int i = 0; i < 10; i++){
      Token tmp = new Token(Token.ERROR, "err", 3, 3);
      tagStack.push(tmp);
      tmp.relavant = true;
    }
    System.out.println("Is the stack relavant? " + tagStack.isStackRelavant());
    Token tok = null;
    int i = 1;
    while ((tok = tagStack.pop()) != null){
      System.out.println(i + " " + tok + " relavant? " + tok.relavant);
      i++;
    }
  }

  public static void RunApp(){

    tagStack = new Stack();
    try {
      Scanner scanner = new Scanner(new Lexer(new InputStreamReader(System.in)));
      Token tok = null;
      Boolean relevantData = false;
      while( (tok=scanner.getNextToken()) != null ){
        if(tok.m_type == Token.OPEN_TAG){
          tagStack.push(tok);
          Scanner tagScanner = new Scanner(new LexerTag(new StringReader(tok.m_value)));
          int tagCount = 0;
          String tmp = "";
          String tagName = "";
          try{
            while((tmp = tagScanner.getNextString()) != null){ // parse opening tag
              if(tagCount == 0)
                tagName = tmp;
              tagCount++;
            }
            if(Token.isRelavantTag(tagName)){  // if it's a relavant tag, then update token and print      
              tok.relavant = true;
              System.out.println("OPEN_" + tagName.toUpperCase());
            } else {
              tok.relavant = false;
            }
            
          } catch (Exception e){
              System.out.println("Unexpected exception:");
              e.printStackTrace();
          }

        }
        else if(tok.m_type == Token.CLOSE_TAG){
          Token t = tagStack.pop();
          if(t == null){
            System.err.println("Error, tag mismatch. Missing closing tag " + tok.m_value);
          }
          else {
            Scanner openTagScanner = new Scanner(new LexerTag(new StringReader(t.m_value)));
            Scanner closeTagScanner = new Scanner(new LexerTag(new StringReader(tok.m_value)));

            try{
              String tmp = "";
              String openTagName = "";
              String closeTagName = "";
              int tokenCount = 0;
              while ((tmp = openTagScanner.getNextString()) != null){
                if (tokenCount == 0)
                  openTagName = tmp.toLowerCase();
                tokenCount++;
              }
              tokenCount = 0;

              while ((tmp = closeTagScanner.getNextString()) != null){
                if (tokenCount == 0)
                  closeTagName = tmp.toLowerCase();
                tokenCount++;
              }

              if(!openTagName.equals(closeTagName) || openTagName.isEmpty()){
                System.err.println("Error, tag mismatch. Missing closing tag. Line: " + tok.m_line + ", Col: " + tok.m_column);
                System.err.println("Expected: " + openTagName.toUpperCase() + " Recieved: " + closeTagName.toUpperCase());
              } else {
                if(Token.isRelavantTag(closeTagName))
                  System.out.println("CLOSE_" + closeTagName.toUpperCase());
              }

            } catch (Exception e) {
              System.err.println("Unexpected exception:");
              e.printStackTrace();
            }

          }
        }
        //System.out.println("Checking if current token is relavant: " + tok);
        if(tagStack.isStackRelavant()){
          if(tok.m_type != Token.OPEN_TAG && tok.m_type != Token.CLOSE_TAG)
            System.out.println(tok);
        }
      }
    } catch (Exception e) {
      System.err.println("Unexpected exception:");
      e.printStackTrace();
    }
    if(!tagStack.isEmpty()){
      Token t = null;
      System.err.println("Error! The following tags have not been closed: ");
      while((t = tagStack.pop()) != null){
        System.err.println(t);
      }
    }

  }
}