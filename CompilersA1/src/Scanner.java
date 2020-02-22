/** @file Scanner.java
 * Scanner to get tokens from a given Lexar object
 */
class Scanner {
    private Lexer scanner = null;
    private LexerTag tagScanner = null;

    public Scanner( Lexer lexer ) {
      scanner = lexer; 
    }

    public Scanner(LexerTag lexer){
      tagScanner = lexer;
    }
  
    //Retrieves Token objs from stream
    public Token getNextToken() throws java.io.IOException {
      return scanner.yylex();
    }

    //Retrieves string tokens from an input string
    public String getNextString() throws java.io.IOException {
      return tagScanner.yylex();
    }
  
}