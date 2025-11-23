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
PRINTABLE[\x20-\x7e]
%%
TYPEDEF|CHAR|INT|FLOAT|CONST|UNION|CLASS|PRIVATE|PROTECTED|PUBLIC|STATIC|VOID|LIST|CONTINUE|BREAK|THIS|IF|ELSE|WHILE|FOR|RETURN|LENGTH|NEW|CIN|COUT|MAIN {printf("keyword is %s\n",yytext);}

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

"C"("A""D"*|"D"+)"R" {printf("LISTFUNC detected %s", yytext);}


"_"*{ALPHA}+({ALPHA}*"_"?{ALPHANUM}+)* {printf("ID detected %s\n", yytext);}

%%
int main(){
	yylex();
}
