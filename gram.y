%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"
#include "hooks.h"

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
statement_t *root = NULL;

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
%type<data> stringContents
%type<data> stringContent
%type<data> stringEditions
%type<data> stringEdition
%type<data> declaration
%type<data> statements
%type<data> statement
%type<data> program
%type<data> arguments
%type<data> body
%type<data> function
%type<data> functionCall
%type<data> mathContents
%type<data> mathContent
%type<data> ifStatement
%type<data> middleIfs
%type<data> middleIf
%type<data> endIf
%type<data> condition

%right'=' 
%left '+' '-'
%left '*' '/' '%'

%%

program: statements {
    root = (statement_t*)$$;
};

statements: 
    statement statements {
        statement_t *stmt = (statement_t*)$1;
        stmt->next = (statement_t*)$2;
        $$ = $1;
    }
    | { $$ = NULL; } /* EMPTY */
    ;

statement:
    declaration {
        $$ = newStatement(LANG_ENTITY_DECL, $1);
    } 
    | function {
        $$ = newStatement(LANG_ENTITY_FUNCDECL, $1);
    }
    | functionCall {
        $$ = newStatement(LANG_ENTITY_FUNCCALL, $1);
    }
    | ifStatement {
        $$ = newStatement(LANG_ENTITY_CONDITIONAL, $1);
    };

ifStatement:
    '[' condition ']' body {
        $$ = newIfStatement(LANG_CONDITIONAL_IF, $2, $4);
    }
    | '[' condition ']' body middleIfs {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, $2, $4);

        ifs->elif = $5;
        
        $$ = ifs;
    }
    | '[' condition ']' body middleIfs endIf {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, $2, $4);

        ifs->elif = $5;
        ifs->endif = $6;
        
        $$ = ifs;
    }
    | '[' condition ']' body endIf {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, $2, $4);

        ifs->endif = $5;
        
        $$ = ifs;
    };

middleIfs:
    middleIfs middleIf {
        ifStmt_t *ifs1 = (ifStmt_t *) $1;
        ifStmt_t *ifs2 = (ifStmt_t *) $2;

        ifs1->elif = ifs2;
        $$ = ifs1;
    }
    | middleIf {
        $$ = $1;
    };

middleIf:
    '~' '[' condition ']' body {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, $3, $5);
       
        $$ = ifs;
    };

endIf:
    '~' body {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, $2);
        $$ = ifs;
    };

condition:
    mathContent '=' '=' mathContent {
        $$ = newConditional(CONDITION_EQ, $1, $4);
    }
    | mathContent '!' '=' mathContent {
        $$ = newConditional(CONDITION_NEQ, $1, $4);
    }
    | mathContent '<' '=' mathContent {
        $$ = newConditional(CONDITION_LEQ, $1, $4);
    }
    | mathContent '>' '=' mathContent {
        $$ = newConditional(CONDITION_GEQ, $1, $4);
    }
    | mathContent '<' mathContent {
        $$ = newConditional(CONDITION_LE, $1, $3);
    }
    | mathContent '>' mathContent {
        $$ = newConditional(CONDITION_GE, $1, $3);
    };

function:
    ID '(' arguments ')' body {
        $$ = newFunc($1,$3,$5);
    };

functionCall:
    ID '(' arguments ')' {
        $$ = newFunCall($1,$3);
    };

declaration: 
    ID '=' stringContents {
        $$ = newDeclaration($1,$3);
    }
    | ID '=' mathContents {
        $$ = newDeclaration($1,$3);
    };

body:
    '{' statements '}' {
        $$ = newBody($2);
    };

arguments:
    ID arguments {
        $$ = newArgument($1,$2);
    }
    | {
        $$ = NULL;
    };

mathContents:
    mathContents '+' mathContents {
        $$ = newExpr_OPAdd($1,$3);
    }
    | mathContents '-' mathContents {
        $$ = newExpr_OPSub($1,$3);
    }
    | mathContents '*' mathContents {
        $$ = newExpr_OPMul($1,$3);
    }
    | mathContents '%' mathContents {
        $$ = newExpr_OPMod($1,$3);
    }
    | mathContents '/' mathContents {
        $$ = newExpr_OPDiv($1,$3);
    }
    | mathContent {
        $$ = $1;
    };

mathContent:
    ID {
        $$ = newExpr_ID($1);
    }
    | DOUBLE {
        $$ = newExpr_Float(yyval.val_double);
    }
    | DIGIT {
        $$ = newExpr_Ival(yyval.val_int);
    }
    | '(' mathContents ')' {
        $$ = $2;
    };

stringContents:
    stringContents '+' stringContent {
        expr_t *e1 = (expr_t*)$1;
        expr_t *e2 = (expr_t*)$3;

        $$ = newExpr_OPAdd(e1,e2);
    }
    | stringContents '+' ID  {
        expr_t *e1 = (expr_t*)$1;
        expr_t *e2 = newExpr_ID($3);

        $$ = newExpr_OPAdd(e1,e2);
    }
    | stringContent {
        $$ = $1;
    };

stringContent:
    '\'' stringEditions '\'' {
        $$ = $2;
    }
    | '"' stringEditions '"' {
        $$ = $2;
    }
    | '"' '"' {
        /* Empty text */
        $$ = newExpr_Text("");
    }
    | '\'' '\'' {
        /* Empty text */
        $$ = newExpr_Text("");
    };

stringEditions:
    stringEditions stringEdition {
        char *textBuffer;

        expr_t *e1 = (expr_t*)$1;
        expr_t *e2 = (expr_t*)$2;

        textBuffer = ast_emalloc(e1->textLen+e2->textLen+1);

        snprintf(textBuffer, e1->textLen+e2->textLen+1,
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
    };

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
    |
    ' ' {
        $$[0] = ' ';
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
    | '(' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | ')' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    };

%%

#include "hooks.h"

void initParser() {
    setParser(yyparse);
    setRoot(&root);
}
