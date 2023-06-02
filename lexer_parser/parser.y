%{
void yyerror (char *s);
int yylex();

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int id = 2;
typedef struct node_t {
	char *name;
	int id;
	struct node_t *left;
	struct node_t *right;
} node;

node *root_node = NULL;
node* make_node(char *name, int id);
%}
%union {
	struct {
		char *name;
		int id;
		char *type;
		void* nd;
	} c_token;
}

%start program
%token <c_token> COL O_R C_R O_S C_S MOD STRING_CONST SEMI MAIN ARROW INT REAL STRING BOOL TRUE FALSE INT_NUM REAL_NUM AND OR ADD SUB DIV MUL LE GE EQ NE GT LT PRINT FOR IF ELSE FUNC ID
%type <c_token> program statements statement expression block

%%

program		: FUNC MAIN O_R C_R ARROW INT block  					{
												root_node = (void*)make_node("root", -1);
												//compile(root_node);
											}
		;

statements      : statement								{
												$$.id = $1.id;
												node * nd = (void*) make_node("statements", $1.id);
												nd -> right = $1.nd;
												$$.nd = nd;
											}
		| statement statements							{
												$$.id = $1.id;
                                                                                                node * nd = (void*) make_node("statements", $1.id);
                                                                                                nd -> right = $1.nd;
                                                                                                $$.nd = nd;
											}
		;

block           : O_S statements C_S               				{
											node* nd1 = (node*) $2.nd;
											printf("%d PUSH_CONTEXT %d", id++, nd1->id);
											$$.nd = (void*)make_node("block", id - 1);
										}
		;

expression	: STRING_CONST							{ printf("%d CONST_STR %s\n", id++, $1.name); $$.id = id - 1; $$.type = "str";  }
		| INT_NUM							{ printf("%d CONST_INT %s\n", id++, $1.name); $$.id = id - 1; $$.type = "int";}
		| REAL_NUM							{ printf("%d CONST_FLOAT %s\n", id++, $1.name); $$.id = id - 1; $$.type = "real";}
		| expression ADD expression					{
											if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) {
                                                                                		printf("%d SUM_INT %d %d\n", id++, $1.id, $3.id);
                                                                                		$$.name = "SUM_INT";
                                                                                		$$.id = id - 1;
                                                                                		$$.type = "int";
                                                                                	} else if (strcmp($1.type, "real") == 0 && strcmp($3.type, "real") == 0) {
												printf("%d SUM_FLOAT %d %d\n", id++, $1.id, $3.id);
                                                                                                $$.name = "SUM_FLOAT";
                                                                                                $$.id = id - 1;
                                                                                                $$.type = "real";
											} else if (strcmp($1.type, "str") == 0 && strcmp($3.type, "str") == 0) {
                                                                                        	printf("%d SUM_STR %d %d\n", id++, $1.id, $3.id);
                                                                                        	$$.name = "SUM_STR";
                                                                                        	$$.id = id - 1;
                                                                                        	$$.type = "str";
                                                                                        } else {
                                                                                        	printf("There is no operator + suppoting types: %s and %s", $1.type, $3.type);
                                                                                        	exit(500);
                                                                                        }
										}
		| expression SUB expression					{
											if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) {
                                                                                		printf("%d SUM_INT %d %d\n", id++, $1.id, $3.id);
                                                                                		$$.name = "SUM_INT";
                                                                                		$$.id = id - 1;
                                                                                		$$.type = "int";
                                                                                	} else if (strcmp($1.type, "real") == 0 && strcmp($3.type, "real") == 0) {
												printf("%d SUM_FLOAT %d %d\n", id++, $1.id, $3.id);
                                                                                                $$.name = "SUM_FLOAT";
                                                                                                $$.id = id - 1;
                                                                                                $$.type = "real";
											} else if (strcmp($1.type, "str") == 0 && strcmp($3.type, "str") == 0) {
                                                                                        	printf("%d SUM_STR %d %d\n", id++, $1.id, $3.id);
                                                                                        	$$.name = "SUM_STR";
                                                                                        	$$.id = id - 1;
                                                                                        	$$.type = "str";
                                                                                        } else {
                                                                                        	printf("There is no operator + suppoting types: %s and %s", $1.type, $3.type);
                                                                                        	exit(500);
                                                                                        }
										}
		| expression DIV expression					{
											if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) {
                                                                                		printf("%d DIV_INT %d %d\n", id++, $1.id, $3.id);
                                                                                		$$.name = "DIV_INT";
                                                                                		$$.id = id - 1;
                                                                                		$$.type = "int";
                                                                                	} else if (strcmp($1.type, "real") == 0 && strcmp($3.type, "real") == 0) {
												printf("%d DIV_FLOAT %d %d\n", id++, $1.id, $3.id);
                                                                                                $$.name = "DIV_FLOAT";
                                                                                                $$.id = id - 1;
                                                                                                $$.type = "real";
											} else {
                                                                                        	printf("There is no operator + suppoting types: %s and %s", $1.type, $3.type);
                                                                                        	exit(500);
                                                                                        }
										}
		| expression MUL expression					{
											if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) {
                                                                                		printf("%d SUM_INT %d %d\n", id++, $1.id, $3.id);
                                                                                		$$.name = "SUM_INT";
                                                                                		$$.id = id - 1;
                                                                                		$$.type = "int";
                                                                                	} else if (strcmp($1.type, "real") == 0 && strcmp($3.type, "real") == 0) {
												printf("%d MUL_FLOAT %d %d\n", id++, $1.id, $3.id);
                                                                                                $$.name = "MUL_FLOAT";
                                                                                                $$.id = id - 1;
                                                                                                $$.type = "real";
											} else {
                                                                                        	printf("There is no operator + suppoting types: %s and %s", $1.type, $3.type);
                                                                                        	exit(0xA01);
                                                                                        }
										}
		| expression MOD expression					{
											if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) {
                                                                                		printf("%d MOD %d %d\n", id++, $1.id, $3.id);
                                                                                		$$.name = "MOD";
                                                                                		$$.id = id - 1;
                                                                                		$$.type = "int";
                                                                                	} else {
                                                                                		printf("Broken statement format \n MOD type missmatch");
                                                                                        	printf("There is no operator + suppoting types: %s and %s", $1.type, $3.type);
                                                                                        	exit(500);
                                                                                        }
										}
		;


statement	: PRINT O_R expression C_R SEMI					{
											if(strcmp($3.type, "str") == 0){
												printf("1 PRINT %d 0\n", $3.id);
												$$.id = id-1;
											} else {
												printf("There is no operator + suppoting types: %s and %s", $1.type, $3.type);
                                                                                                exit(500);
											}
										}
		| ID COL STRING SEMI 						{ printf("%d NEW_STR %s %d", id++, $1.name); }
		| block
		;


%%

int main (void) {
	return yyparse ( );
}

void yyerror (char *s) {
	fprintf (stderr, "Eu printez %s\n", s);
}

node* make_node(char *name, int id) {
	node *ans = (node *)malloc(sizeof(node));
	ans -> name = strdup(name);
	ans -> id = id;
	return ans;
}

