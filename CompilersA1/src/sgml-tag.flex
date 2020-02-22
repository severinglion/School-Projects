/*
  File Name: sgml-tag.flex
  JFlex specification for sgml tags
*/
   
import java.util.ArrayList;

%%
   
%class LexerTag
%type String
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
letter = [a-zA-Z]
digit = [0-9]
word = ({letter}*{digit}*{letter}+{digit}*{letter}*)+
punctuation = [<>\/]+
literal = (\".*\")|('(~['\"])*')
optArg = {word}{WhiteSpace}*={WhiteSpace}{literal}

%%

{WhiteSpace}       { /*System.out.println("Whitespace(" + yytext() + ")"); */ }
{punctuation}      { /*System.out.println("Punctuation(" + yytext() + ")"); */ }
{word}             { return yytext(); }
{optArg}           { /*System.out.println("Optional Argument"); */}
.                  { /*System.out.println("Error(" + yytext() + ")"); */}