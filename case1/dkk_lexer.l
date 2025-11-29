
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "dkk.tab.h"
    #define T_EOF 0
    #define MAX_STRING_SIZE 509

//    YYSTYPE yylval;
    int iconvert();
    float fconvert();
    char st[MAX_STRING_SIZE];
    char *stp;    
%}

%option noyywrap
%option yylineno
%option case-insensitive

%x STR COMMENT

LETTER      [A-Z]
DIGIT       [0-9]
DIGIT1      [1-9]
ALPHAR      [A-Z0-9]
HEX         [0-9A-F]
HEX1        [1-9A-F]
BIN         [01]
PRINTABLE   [\x20-\x7E]
ID          "_"*{LETTER}+({LETTER}*"_"?{ALPHAR}+)*
ICONST      ("0"|({DIGIT1}{DIGIT}*)|("0H"{HEX1}{HEX}*)|("0B1"{BIN}*))
FCONST      (({DIGIT1}{DIGIT}*)?"."("0"|"0"+{DIGIT1}+|{DIGIT1}{DIGIT}+|{DIGIT1}+)("E"([+-])?("0"|{DIGIT1}{DIGIT}*))?|{DIGIT1}{DIGIT}*"E"([+-]?)("0"|{DIGIT1}{DIGIT}*)|"0H"({HEX1}{HEX}*)?"."{HEX}+|"0B"("1"{BIN}*)?"."{BIN}+)
CCONST      ("'"{PRINTABLE}"'"|"'""\\"[nftrbv]"'")
LCOMMENT    \/\/.*
LISTFUNC    "C"("A""D"*|"D"+)"R"
WHITE       [ \t\r\f\v]
WS          {WHITE}+
NEWLINE     \n

%%

{WS}          ;
{NEWLINE}     {yylineno++;}

TYPEDEF     { return TYPEDEF;}
CHAR        { return CHAR;}
INT         { return INT;}
FLOAT       { return FLOAT;}
CONST       { return CONST;}
UNION       { return UNION;}
CLASS       { return CLASS;}
PRIVATE     { return PRIVATE;}
PROTECTED   { return PROTECTED;}
PUBLIC      { return PUBLIC;}
STATIC      { return STATIC;}
VOID        { return VOID;}
LIST        { return LIST;}
CONTINUE    { return CONTINUE;}
BREAK       { return BREAK;}
THIS        { return THIS;}
IF          { return IF;}
ELSE        { return ELSE;} 
WHILE       { return WHILE;}
FOR         { return FOR;}
RETURN      { return RETURN;}
LENGTH      { return LENGTH;}
NEW         { return NEW;}
CIN         { return CIN;}
COUT        { return COUT;}
MAIN        { return MAIN;}

"/*"                {BEGIN(COMMENT);}
<COMMENT>"*/"       {printf("/*...*/ comment detected\n"); BEGIN(INITIAL);}
<COMMENT>\n         {yylineno++;}
<COMMENT>.          ;
<COMMENT><<EOF>>    {printf("unterminated comment\n"); return EOF;}

{LCOMMENT}  {printf("// comment detected\n");}

{ICONST}    {printf("ICONST detected %s\n", yytext); yylval.ival = iconvert(yytext); return ICONST;}

{FCONST}    {printf("FCONST detected %s\n", yytext); yylval.fval = fconvert(yytext); return FCONST;}

{CCONST}    {printf("CCONST detected %s\n", yytext); yylval.cval = yytext[0]; return CCONST;}

"||"     {printf("OROP detected\n"); return OROP;}
"&&"     {printf("ANDOP detected\n"); return ANDOP;}
"=="     {printf("EQUOP detected\n"); yylval.oper = 0; return EQUOP;}
"!="     {printf("EQUOP detected\n"); yylval.oper = 1; return EQUOP;}
">"      {printf("RELOP detected\n"); yylval.oper = 0; return RELOP;}
">="     {printf("RELOP detected\n"); yylval.oper = 1; return RELOP;}
"<"      {printf("RELOP detected\n"); yylval.oper = 2; return RELOP;}
"<="     {printf("RELOP detected\n"); yylval.oper = 3; return RELOP;}
"++"     {printf("INCDEC detected\n"); yylval.oper = 0; return INCDEC;}
"--"     {printf("INCDEC detected\n"); yylval.oper = 1; return INCDEC;}
\+       {printf("ADDOP detected\n"); yylval.oper = 0; return ADDOP;}
\-       {printf("ADDOP detected\n"); yylval.oper = 1; return ADDOP;}
\*       {printf("MULOP detected\n"); yylval.oper = 0; return MULOP;}
\/       {printf("MULOP detected\n"); yylval.oper = 1; return MULOP;}
\%       {printf("MULOP detected\n"); yylval.oper = 2; return MULOP;}
\!       {printf("NOTOP detected\n"); return NOTOP;}
"SIZEOF" {printf("SIZEOP detected\n"); return SIZEOP;}

{LISTFUNC} {printf("LISTFUNC detected %s\n", yytext); yylval.str = strdup(yytext);}

\"              {BEGIN(STR); stp = st;}
<STR>[^\\\"\n]* {
            char *yytp = yytext;
            if (stp + yyleng > &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            while (*yytp) *stp++ = *yytp++;
}
<STR>"\\n"      {
            if (stp == &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            yylineno++;
            *stp++ = '\n';
}
<STR>"\\r"      {
            if (stp == &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            yylineno++;
            *stp++ = '\r';
}
<STR>"\\t"      {
            if (stp == &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            *stp++ = '\t';
}
<STR>"\\f"      {
            if (stp == &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            *stp++ = '\f';
}
<STR>"\\b"      {
            if (stp == &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            *stp++ = '\b';
}
<STR>"\\v"      {
            if (stp == &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            *stp++ = '\v';
}
<STR>"\\".      {
            if (stp == &st[MAX_STRING_SIZE - 1]) {
                printf("String overflow.\n");
                return T_EOF;
            }
            *stp++ = yytext[1];
}
<STR>"\\\n"     ;
<STR>\"         {
            *stp = '\0';
            BEGIN(INITIAL);
            yylval.str = strdup(st);
            printf("STRING detected %s.\n", st);
            return STRING;
}
<STR>"\n" |
<STR><<EOF>>    {
            printf("Reacher EOF.\n");
            return T_EOF;
}

"(" {printf("LPAREN\n"); return LPAREN;}
")" {printf("RPAREN\n"); return RPAREN;}
";" {printf("SEMI\n"); return SEMI;}
"." {printf("DOT\n"); return DOT;}
"," {printf("COMMA\n"); return COMMA;}
"=" {printf("ASSIGN\n"); return ASSIGN;}
":" {printf("COLON\n"); return COLON;}
"[" {printf("LBRACK\n"); return LBRACK;}
"]" {printf("RBRACK\n"); return RBRACK;}
"&" {printf("REFER\n"); return REFER;}
"{" {printf("LBRACE\n"); return LBRACE;}
"}" {printf("RBRACE\n"); return RBRACE;}
"::" {printf("METH\n"); return METH;}
">>" {printf("INP\n"); return INP;}
"<<" {printf("OUT\n"); return OUT;}
"EOF" {printf("EOF\n"); return EOF;}

{ID} {printf("ID detected %s\n", yytext); yylval.str = strdup(yytext);/*symbol table*/ return ID;}

%%
int iconvert(){
if (yyleng >= 3) {
        if (yytext[1] == 'H') { //hexadecimal case
        	return strtol(yytext+2, NULL, 16);
	}
        else if (yytext[1] == 'B') { //binary case
        	return strtol(yytext+2, NULL, 2);
	}
        else {
            return atoi(yytext);
         }
    }
    else {
        return atoi(yytext);
    }
}
float fconvert(){
if (yyleng >= 3) {
        if (yytext[1] == 'H') { //hexadecimal case
        	return strtol(yytext+2, NULL, 16);
        }
        else if (yytext[1] == 'B') { //binary case
        	return strtol(yytext+2, NULL, 2);
        }
        else {
            return atof(yytext);
         }
    }
    else {
        return atof(yytext);
    }
}
