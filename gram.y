%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"

extern int yylinenor;

void *e_malloc(size_t size)
{
    char *mem = (char*)calloc(size,1);
    if ( mem == NULL ) {
        fprintf(stderr, "Calloc failed, size: %zu\n", size);
        exit(1);
    }
    return (void*)mem;
}

void yyerror(const char *s)
{
    fprintf(stderr,
        "%s at line: %d\n",
        s,
        yylinenor);
}

int yylex(void);

%}

%union { int val_int; double val_double; char id[256]; void *data; }

%token<val_int> DIGIT
%token<val_double> DOUBLE
%token<id> ID
%token COMMENT
%token NEWLINE
%token KEY_FLOAT
%token KEY_INT
%token KEY_STR
%token KEY_STRUCT
%token KEY_PROCESS
%token WHITESPACE
%token OPEN
%token CLOSE
%token OTHER
%type<id> otherChar
%type<data> stringContents;
%type<data> stringContent;
%type<data> stringEditions;
%type<data> stringEdition;

%%

program: statements {
    printf("program\n");  
};

statements: statement {
        printf("statement\n");
    }
    | statements statement {
        printf("statements statement\n");
    } 
    ;

statement:
    declaration {
        printf("declaration\n");
    }
    ;

declaration: 
    KEY_INT ID '=' DIGIT {

    }
    | KEY_FLOAT ID '=' DOUBLE {

    }
    | KEY_STR ID '=' stringContents {

    }
    /*| KEYWORD_STR WHITESPACE ID WHITESPACE '=' */
    ;

stringContents:
    stringContents '+' stringContent {



    }
    | stringContents '+' '<' ID '>' {

    }
    | stringContent {

    }
    | {

    } /* Empty */
    ;

stringContent:
    '\'' stringEditions '\'' {

    }
    | '"' stringEditions '"' {

    }
    ;

stringEditions:
    stringEditions stringEdition {

    }
    | stringEdition {

    }
    ;

stringEdition:
    ID {
        $$ = newExpr_ID(yyval.id);
    }
    | DOUBLE {
        $$ = newExpr_Float(yyval.val_double);
    }
    | DIGIT {
        $$ = newExpr_Ival(yyval.val_int);
    }
    | otherChar {
        $$ = newExpr_Text($1);
    };

otherChar: 
    '+' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '<' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '>' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '-' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '/' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | ':' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
        printf("A\n");
    }
    ;

%%


int main() {
    yyparse();
}

