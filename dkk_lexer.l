/*	DKK lexer for CPP	*/
%{
#include <stdio.h>
%}
%option noyywrap
%option case-insensitive
DIGIT [0-9]
DIGITNOZ [1-9]
ALPHA [a-z]
ALPHANUM [a-z0-9]
HEX [0-9A-F]
HEXNOZ [1-9A-F]
BINARY [0-1]
PRINTABLE [\x20-\x7e]
PRINT_WITHOUT [\x20\x21\x23-\x5b\x5d-\x7e]
ESC_SEQ   \\[\"\\/bfnrtv]
WHITE [ \n\r]
ALTWHITE \\[ \n\r]
%%
TYPEDEF|CHAR|INT|FLOAT|CONST|UNION|CLASS|PRIVATE|PROTECTED|PUBLIC|STATIC|VOID|LIST|CONTINUE|BREAK|THIS|IF|ELSE|WHILE|FOR|RETURN|LENGTH|NEW|CIN|COUT|MAIN {printf("keyword is %s\n",yytext);}

("\/*"{PRINTABLE}*"*\/"|"\/\/"{PRINTABLE}) printf("COMMENT detected\n");

("0"|{DIGITNOZ}{DIGIT}*|"0""H"{HEXNOZ}{HEX}*|"0""B""1"{BINARY}*) {printf("ICONST detected %s\n", yytext);}

(({DIGITNOZ}{DIGIT}*)?"."("0"|"0"+{DIGITNOZ}+|{DIGITNOZ}{DIGIT}+|{DIGITNOZ}+)("E"([+-])?("0"|{DIGITNOZ}{DIGIT}*))?|{DIGITNOZ}{DIGIT}*"E"([+-]?)("0"|{DIGITNOZ}{DIGIT}*)|"0H"({HEXNOZ}{HEX}*)?"."{HEX}+|"0B"("1"{BINARY}*)?"."{BINARY}+) {printf("FCONST detected %s\n", yytext);}

("'"{PRINTABLE}"'"|"'""\\"[nftrbv]"'") {printf("CCONST detected %s\n", yytext);}

"||" {printf("OROP detected\n");}
"&&" {printf("ANDOP detected\n");}
"=="|"!=" {printf("EQUOP detected\n");}
">"|">="|"<"|"<=" {printf("RELOP detected\n");}
[+-] {printf("ADDOP detected\n");}
[*/%] {printf("MULOP detected\n");}
"!" {printf("NOTOP detected\n");}
("++"|"--") {printf("INCDEC detected\n");}
"SIZEOF" {printf("SIZEOP detected\n");}

"C"("A""D"*|"D"+)"R" {printf("LISTFUNC detected %s\n", yytext);}

(["]({PRINT_WITHOUT}*{ESC_SEQ}*{ALTWHITE}*)*["]) {printf("STRING detected %s\n", yytext);}

"(" {printf("LPAREN\n");}
")" {printf("RPAREN\n");}
";" {printf("SEMI\n");}
"." {printf("DOT\n");}
"," {printf("COMMA\n");}
"=" {printf("ASSIGN\n");}
":" {printf("COLON\n");}
"[" {printf("LBRACK\n");}
"]" {printf("RBRACK\n");}
"&" {printf("REFER\n");}
"{" {printf("LBRACE\n");}
"}" {printf("RBRACE\n");}
"::" {printf("METH\n");}
">>" {printf("INP\n");}
"<<" {printf("OUT\n");}
"EOF" {printf("EOF\n");}

"_"*{ALPHA}+({ALPHA}*"_"?{ALPHANUM}+)* {printf("ID detected %s\n", yytext);}
%%
int main(){
	yylex();
}
