/*
  File Name: tiny.flex
  JFlex specification for the TINY language
*/
   
import java.util.ArrayList;

%%
   
%class Lexer
%type Token
%line
%column
    
%eofval{
  //System.out.println("*** end of file reached");
  return null;
%eofval};

%{
  private static ArrayList<String> tagStack = new ArrayList<String>();

  // static methods such as getTagName can be defined here as well

%};

LineTerminator = \r|\n|\r\n
WhiteSpace     = {LineTerminator} | [ \t\f] 
digit = [0-9]
real = ("+" | "-")?{digit}+\.?{digit}*
number = {digit}+|{real}
letter = [a-zA-Z]
alnum = [a-zA-Z0-9]
word = ({letter}*{digit}*{letter}+{digit}*{letter}*)+
punctuation = [\?!@#$%\^&*()_+=\[\]\\\.:;,']+
literal = (\".*\")
quote = {literal}|({word}-?)+('{word}?)+|'{word}*'
openTag = <{WhiteSpace}*({alnum}+-?{alnum}*){WhiteSpace}*({WhiteSpace}*{word}{WhiteSpace}*=({word}|{quote}){WhiteSpace}*)*{WhiteSpace}*>
closeTag = <\/{WhiteSpace}*({alnum}+-?{alnum}*){WhiteSpace}*>
hyphen = (({word}|{number})+-)*({word}|{number})

%%

{WhiteSpace}       { /*System.out.println("Whitespace(" + yytext() + ")"); */ }
{openTag}          { return new Token(Token.OPEN_TAG, yytext(), yyline, yycolumn); }
{closeTag}         { return new Token(Token.CLOSE_TAG, yytext(), yyline, yycolumn); }
{word}             { return new Token(Token.WORD, yytext(), yyline, yycolumn); }
{number}           { return new Token(Token.NUM, yytext(), yyline, yycolumn); }
{quote}            { return new Token(Token.APOS, yytext(), yyline, yycolumn);}
{punctuation}      { return new Token(Token.PUNC, yytext(), yyline, yycolumn); }
{hyphen}           { return new Token(Token.HYPHEN, yytext(), yyline, yycolumn); }
.                  { return new Token(Token.ERROR, yytext(), yyline, yycolumn); }