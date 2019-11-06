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

/* Root statement */
statement_t *root;

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
%type<data> declaration;
%type<data> statements;
%type<data> statement;
%type<data> program;

%%

program: statements {
    printf("program\n");
    root = (statement_t*)$$;
};

statements: statement {
        printf("statement\n");
        $$ = $1;
    }
    | statements statement {
        statement_t *stmt = (statement_t*)$1;
        stmt->next = (statement_t*)$2;

        $$ = $1;

        printf("statements statement\n");
    } 
    ;

statement:
    declaration {
        $$ = newStatement(STMT_TYPE_DECL, $1);
        printf("declaration\n");
    }
    ;

declaration: 
    ID '=' DIGIT {
        expr_t *d = newExpr_Ival($3);
        $$ = newDeclaration($1,d);
    }
    | ID '=' DOUBLE {
        expr_t *d = newExpr_Float($3);
        $$ = newDeclaration($1,d);
    }
    | ID '=' stringContents {
        $$ = newDeclaration($1,$3);
    }
    /*| KEYWORD_STR WHITESPACE ID WHITESPACE '=' */
    ;

stringContents:
    stringContents '+' stringContent {
        expr_t *e1 = (expr_t*)$1;
        expr_t *e2 = (expr_t*)$3;

        $$ = newExpr_OPAdd(e1,e2);
    }
    | stringContents '+' '<' ID '>' {
        expr_t *e1 = (expr_t*)$1;
        expr_t *e2 = newExpr_ID($4);

        $$ = newExpr_OPAdd(e1,e2);
    }
    | stringContent {
        $$ = $1;
    }
    ;

stringContent:
    '\'' stringEditions '\'' {
        $$ = $2;
    }
    | '"' stringEditions '"' {
        $$ = $2;
    }
    ;

stringEditions:
    stringEditions stringEdition {
        char *textBuffer;

        expr_t *e1 = (expr_t*)$1;
        expr_t *e2 = (expr_t*)$2;

        textBuffer = ast_emalloc(e1->textLen+e2->textLen+1);

        snprintf(textBuffer, sizeof(textBuffer),
            "%s%s",
            e1->text,
            e2->text
        );

        textBuffer[e1->textLen + e2->textLen] = 0;

        free(e1->text);
        free(e2->text);
        free(e1);
        free(e2);

        $$ = newExpr_Text(textBuffer);
    }
    | stringEdition {
        $$ = $1;
    }
    | {}/* Empty */
    ;

stringEdition:
    ID {
        $$ = newExpr_Text(yyval.id);
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
    }
    ;

%%


int main() {
    yyparse();
}

