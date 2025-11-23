
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define T_EOF 0
    #define MAX_STRING_SIZE 509

    char st[MAX_STRING_SIZE];
    char *stp;
    char s[MAX_ID_SIZE];
    
%}

%option noyywrap
%option yylineno
%option case-insensitive

%x STR COMMENT

LETTER [A-Z]
DIGIT [0-9]
DIGIT1 [1-9]
ALPHAR [A-Z0-9]
HEX [0-9A-F]
HEX1 [1-9A-F]
BIN [01]
PRINTABLE [\x20-\x7E]
PRINTABLE_STR [\x20\x21\x23-\x5B\x5D-\x7E]
ESC_SEQ \\[\"\\/bfnrtv"]
ALTWHITE \\[\n\r]
WHITE [ \n\r]

%%
"typedef"|"char"|"int"|"float"|"const"|"union"|"class"|"private"|"protected"|"public"|"static"|"void"|"list"|"continue"|"break"|"this"|"if"|"else"|"while"|"for"|"return"|"length"|"new"|"cin"|"cout"|"main" { printf("keyword is %s\n", yytext); }

"/*"                {BEGIN(COMMENT);}
<COMMENT>"*/"       {printf("/*...*/ comment detected\n"); BEGIN(INITIAL);}
<COMMENT>\n         {yylineno++;}
<COMMENT>.          ;
<COMMENT><<EOF>>    {printf("unterminated comment\n"); return T_EOF;}

"//"{PRINTABLE}* {printf("// comment detected\n");}

("0"|({DIGIT1}{DIGIT}*)|("0H"{HEX1}{HEX}*)|("0B1"{BIN}*)) {printf("ICONST detected %s\n", yytext);}

(({DIGIT1}{DIGIT}*)?"."("0"|"0"+{DIGIT1}+|{DIGIT1}{DIGIT}+|{DIGIT1}+)("E"([+-])?("0"|{DIGIT1}{DIGIT}*))?|{DIGIT1}{DIGIT}*"E"([+-]?)("0"|{DIGIT1}{DIGIT}*)|"0H"({HEX1}{HEX}*)?"."{HEX}+|"0B"("1"{BIN}*)?"."{BIN}+) {printf("FCONST detected %s\n", yytext);}

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

\"         {BEGIN(STR); stp = st}
<STR>[^\\\"\n]* {
                    char *yytp = yytext;
                    if ()
}
<STR>"\\n"      {

                    if (stp == &st[MAX_STRING_SIZE -1]) {
                        printf("Line %d: ")
                    }
}

\"({PRINTABLE_STR}*{ESC_SEQ}*{ALTWHITE}*)*\" {printf("STRING detected %s\n", yytext);}

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

"_"*{LETTER}+({LETTER}*"_"?{ALPHAR}+)* {printf("ID detected %s\n", yytext);}

%%

int main( int argc, char **argv ) {
    yylex();
}
