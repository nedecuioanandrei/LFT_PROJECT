%{
#include "y.tab.h"
void yyerror (char *s);
int yylex();
%}

alpha [a-zA-Z]
digit [0-9]

%%

"int"                                   { yylval.c_token.name = strdup(yytext); return INT; }
"real"                                  { yylval.c_token.name = strdup(yytext); return REAL; }
"string"                                { yylval.c_token.name = strdup(yytext); return STRING; }
"bool"                                  { yylval.c_token.name = strdup(yytext); return BOOL; }

"true"                                  { yylval.c_token.name = strdup(yytext); return TRUE; }
"false"                                 { yylval.c_token.name = strdup(yytext); return FALSE; }
[-]?{digit}+                            { yylval.c_token.name = strdup(yytext); return INT_NUM; }
[-]?{digit}+\.{digit}{1,6}              { yylval.c_token.name = strdup(yytext); return REAL_NUM; }

"&&"                                    { yylval.c_token.name = strdup(yytext); return AND; }
"||"                                    { yylval.c_token.name = strdup(yytext); return OR; }
"+"                                     { yylval.c_token.name = strdup(yytext); return ADD; }
"-"                                     { yylval.c_token.name = strdup(yytext); return SUB; }
"/"                                     { yylval.c_token.name = strdup(yytext); return DIV; }
"*"                                     { yylval.c_token.name = strdup(yytext); return MUL; }
"%"                                     { yylval.c_token.name = strdup(yytext); return MOD; }

"<="                                    { yylval.c_token.name = strdup(yytext); return LE; }
">="                                    { yylval.c_token.name = strdup(yytext); return GE; }
"=="                                    { yylval.c_token.name = strdup(yytext); return EQ; }
"!="                                    { yylval.c_token.name = strdup(yytext); return NE; }
">"                                     { yylval.c_token.name = strdup(yytext); return GT; }
"<"                                     { yylval.c_token.name = strdup(yytext); return LT; }
"->"                                    { yylval.c_token.name = strdup(yytext); return ARROW; }

"("                                     { yylval.c_token.name = strdup(yytext); return O_R; }
")"                                     { yylval.c_token.name = strdup(yytext); return C_R; }
"{"                                     { yylval.c_token.name = strdup(yytext); return O_S; }
"}"                                     { yylval.c_token.name = strdup(yytext); return C_S; }
"main"                                  { yylval.c_token.name = strdup(yytext); return MAIN; }
";"                                     { yylval.c_token.name = strdup(yytext); return SEMI; }
":"                                     { yylval.c_token.name = strdup(yytext); return COL; }
["][^"]*["]                             { yylval.c_token.name = strdup(yytext); return STRING_CONST; }

"print"             			        { yylval.c_token.name = strdup(yytext); return PRINT; }
"for"                                   { yylval.c_token.name = strdup(yytext); return FOR; }
"if"                                    { yylval.c_token.name = strdup(yytext); return IF; }
"else"                                  { yylval.c_token.name = strdup(yytext); return ELSE; }
"func"                                  { yylval.c_token.name = strdup(yytext); return FUNC; }
{alpha}({alpha}|{digit})*               { yylval.c_token.name = strdup(yytext); return ID; }


\/\/.*                                  {;}
\/\*(.*\n)*.*\*\/                       {;}
[ \t]*                                  {;}
.                                       {ECHO; yyerror ("unexpected character");}

%%

int yywrap (void) {
    return 1;
}
