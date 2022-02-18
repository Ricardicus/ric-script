%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"
#include "hooks.h"

extern int yylinenor;
extern char *ParsedFile;

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
        "%s:%d: %s\n",
        ParsedFile,
        yylinenor,
        s);
}

int yylex(void);

/* Root statement */
statement_t *root = NULL;

%}

%union { int val_int; double val_double; char id[256]; void *data; }

%token<val_int> DIGIT
%token<val_double> DOUBLE
%token<id> ID
%token RETURN
%token FOREACH
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
%type<data> mathContentDigit
%type<data> mathContentDouble
%type<data> indexedVector
%type<data> stringContent
%type<data> stringEditions
%type<data> stringEdition
%type<data> declaration
%type<data> dictionary
%type<data> dictionary_keys_vals
%type<data> dictionary_key_val
%type<data> statements
%type<data> statement
%type<data> program
%type<data> expressions
%type<data> expression
%type<data> arguments_list
%type<data> parameters_list
%type<data> body
%type<data> function
%type<data> indexer
%type<data> class
%type<data> classFunctionCall
%type<data> functionCall
%type<data> mathContent
%type<data> vector
%type<data> ifStatement
%type<data> loopStatement
%type<data> forEachStatement
%type<data> forEachStatementFull
%type<data> continueStatement
%type<data> returnStatement
%type<data> breakStatement
%type<data> systemStatement
%type<data> middleIfs
%type<data> middleIf
%type<data> endIf
%type<data> condition
%type<data> logical_a
%type<data> logical_b
%type<data> logical_expression

%right'=' 
%left '+' '-'
%left '*' '/' '%'

%%

program: statements {
    root = (statement_t*)$$;

    if ( root != NULL ) {
      statement_t *walk1,*walk2;

      walk1 = root;
      while ( walk1 != NULL ) {
        walk2 = walk1;
        walk1 = walk1->next;
      }

      walk2->next = newStatement(LANG_ENTITY_FIN, NULL);
    }
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
    | forEachStatementFull {
        $$ = newStatement(LANG_ENTITY_FOREACH, $1);
    }
    | expressions {
        $$ = newStatement(LANG_ENTITY_EXPR, $1);
    }
    | ifStatement {
        $$ = newStatement(LANG_ENTITY_CONDITIONAL, $1);
    }
    | loopStatement {
        $$ = newStatement(LANG_ENTITY_CONDITIONAL, $1);
    }
    | continueStatement {
        $$ = newStatement(LANG_ENTITY_CONTINUE, $1);
    }
    | breakStatement {
        $$ = newStatement(LANG_ENTITY_BREAK, $1);
    }
    | returnStatement {
        $$ = newStatement(LANG_ENTITY_RETURN, $1);
    }
    | systemStatement {
        $$ = newStatement(LANG_ENTITY_SYSTEM, $1);
    }
    | class {
        $$ = newStatement(LANG_ENTITY_CLASSDECL, $1);
    };

systemStatement: '$' ID {
    $$ = newExpr_ID($2);
} | '$' stringContent {
    $$ = $2;
};

forEachStatementFull:
  '.' forEachStatement {
    $$ = $2;
};

forEachStatement: 
    '(' expressions FOREACH ID ')' body {
    $$ = newForEach($2, $4, $6);
};

returnStatement: RETURN expressions {
    $$ = $2;
};

continueStatement: '@' {
    $$ = NULL;
};

breakStatement: '!' '@' {
    $$ = NULL;
};

expressions: 
    expression {
      $$ = $1;
    }
    | expressions '+' expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$3;

      $$ = newExpr_OPAdd(e1,e2);
    }
    | expressions '*' expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$3;

      $$ = newExpr_OPMul(e1,e2);
    }
    | expressions '-' expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$3;

      $$ = newExpr_OPSub(e1,e2);
    }
    | expressions '%' expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$3;

      $$ = newExpr_OPMod(e1,e2);
    }
    | expressions '/' expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$3;

      $$ = newExpr_OPDiv(e1,e2);
    };

expression:
    indexedVector {
      $$ = $1;
    }
    | mathContent {
      $$ = $1;
    }
    | dictionary {
      $$ = $1;
    }
    | vector {
      $$ = $1;
    }
    | functionCall {
      $$ = $1;
    }
    | classFunctionCall {
      $$ = $1;
    }
    | stringContent {
      $$ = $1;
    }
    | ID {
      $$ = newExpr_ID($1);
    }
    | '(' expressions ')' {
      $$ = $2;
    };

ifStatement:
    '?' '[' logical_a ']' body {
        $$ = newIfStatement(LANG_CONDITIONAL_IF, $3, $5);
    } | 
    '?' '[' logical_a ']' body middleIfs {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, $3, $5);

        ifs->elif = $6;
        
        $$ = ifs;
    } |
    '?' '[' logical_a ']' body middleIfs endIf {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, $3, $5);

        ifs->elif = $6;
        ifs->endif = $7;
        
        $$ = ifs;
    } |
    '?' '[' logical_a ']' body endIf {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF, $3, $5);

        ifs->endif = $6;
        
        $$ = ifs;
    };

loopStatement:
    '.' '[' logical_a ']' body {
        $$ = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, $3, $5);
    }
    | '.' '[' logical_a ']' body middleIfs {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, $3, $5);

        ifs->elif = $6;
        
        $$ = ifs;
    }
    | '.' '[' logical_a ']' body middleIfs endIf {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, $3, $5);

        ifs->elif = $6;
        ifs->endif = $7;
        
        $$ = ifs;
    }
    | '.' '[' logical_a ']' body endIf {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_IF | LANG_CONDITIONAL_CTX, $3, $5);

        ifs->endif = $6;

        $$ = ifs;
    };

middleIfs:
    middleIfs middleIf {
        ifStmt_t *ifs1 = (ifStmt_t *) $1;
        ifStmt_t *ifs2 = (ifStmt_t *) $2;

        ifs2->elif = ifs1;
        $$ = ifs2;
    }
    | middleIf {
        $$ = $1;
    };

middleIf:
    '~' '[' logical_a ']' body {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELIF, $3, $5);
       
        $$ = ifs;
    };

endIf:
    '~' body {
        ifStmt_t *ifs = newIfStatement(LANG_CONDITIONAL_ELSE, NULL, $2);
        $$ = ifs;
    };

logical_a:
    logical_a '|' '|' logical_b {
      $$ = newExpr_Logical($1, NULL, $4);
    }
    | logical_b {
      $$ = $1;
    };

logical_b:
    logical_b '&' '&' logical_expression {
      $$ = newExpr_Logical($1, $4, NULL);
    }
    | logical_expression {
      $$ = $1;
    };

logical_expression:
    condition {
        $$ = $1;
    }
    | '!' expression {
        expr_t *zero = newExpr_Ival(0);
        expr_t *cond = newConditional(CONDITION_EQ, zero, $2);
        $$ = cond;
    }
    | expression {
        $$ = $1;
    };

condition:
    expressions '=' '=' expressions {
        $$ = newConditional(CONDITION_EQ, $1, $4);
    }
    | expressions '!' '=' expressions {
        $$ = newConditional(CONDITION_NEQ, $1, $4);
    }
    | expressions '<' '=' expressions {
        $$ = newConditional(CONDITION_LEQ, $1, $4);
    }
    | expressions '>' '=' expressions {
        $$ = newConditional(CONDITION_GEQ, $1, $4);
    }
    | expressions '<' expressions {
        $$ = newConditional(CONDITION_LE, $1, $3);
    }
    | expressions '>' expressions {
        $$ = newConditional(CONDITION_GE, $1, $3);
    }
    | '(' condition ')' {
        $$ = $2;
    };

class: ';' ';' ID ';' ';' body {
    /* Only declarations allowed */
    body_t *bod = $6;
    statement_t *walk = bod->content;
    char *classId = ast_emalloc(strlen($3)+2);
    memset(classId, 0, strlen($3)+1);
    while ( walk != NULL ) {
        if (
            walk->entity != LANG_ENTITY_DECL &&
            walk->entity != LANG_ENTITY_FUNCDECL &&
            walk->entity != LANG_ENTITY_BODY &&
            walk->entity != LANG_ENTITY_BODY_END
        ) {
            fprintf(stderr, "Syntax error, class '%s':\r\n", $3);
            fprintf(stderr, "  You may only have variable and or function declaration statements here.\r\n");
            exit(1);
        }

        if ( walk->entity == LANG_ENTITY_FUNCDECL ) {
            functionDef_t *funcDef = walk->content;

            /* Sanity check, constructor may not use arguments */
            if ( strcmp(funcDef->id.id, $3) == 0 ) {
                if ( funcDef->params != NULL ) {
                    fprintf(stderr, "Syntax error, class '%s':\r\n", $3);
                    fprintf(stderr, "  You may not define a constructor with function parameters.\r\n");
                    exit(1);
                }
            }
        }
        walk = walk->next;
    }
    snprintf(classId, strlen($3)+2, "%s", $3);
    $$ = newClass(classId, bod);
}

function:
    '@' ID '(' parameters_list ')' body {
        $$ = newFunc($2,$4,$6);
    } |
    '@' ID '(' ')' body {
        $$ = newFunc($2,NULL,$5);
    };

classFunctionCall:
    expression ':' ':' ID '(' arguments_list ')' {
        $$ = newClassFunCall($1, $4, $6);
    }
    | expression ':' ':' ID '(' ')' {
        $$ = newClassFunCall($1, $4, NULL);
    };

functionCall:
    ID '(' arguments_list ')' {
        expr_t *id = newExpr_ID($1);
        $$ = newFunCall(id,$3);
    }
    | ID '(' ')' {
        expr_t *id = newExpr_ID($1);
        $$ = newFunCall(id,NULL);
    }
    | indexedVector '(' arguments_list ')' {
        expr_t *id = (expr_t*)$1;
        $$ = newFunCall(id,$3);
    }
    | indexedVector '(' ')' {
        expr_t *id = (expr_t*)$1;
        $$ = newFunCall(id,NULL);
    };

declaration: 
    ID '=' expressions {
        expr_t *idexpr = newExpr_ID($1);

        $$ = newDeclaration(idexpr,$3);
    }
    | ID '+' '=' expressions {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | ID '-' '=' expressions {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | ID '*' '=' expressions {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | ID '/' '=' expressions {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | indexedVector '+' '=' expressions {
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPAdd($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | indexedVector '-' '=' expressions {
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPSub($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | indexedVector '*' '=' expressions {
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPMul($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | indexedVector '/' '=' expressions {
        expr_t *valexpr = $4;
        expr_t *opadd = newExpr_OPDiv($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | ID '=' condition {
        expr_t *idexpr = newExpr_ID($1);

        $$ = newDeclaration(idexpr,$3);
    }
    | indexedVector '=' expressions {
        $$ = newDeclaration($1,$3);
    }
    | indexedVector '=' condition {
        $$ = newDeclaration($1,$3);
    };

dictionary:
    '{' dictionary_keys_vals '}' {
      $$ = newExpr_Dictionary($2);
    };

dictionary_keys_vals:
    dictionary_keys_vals ',' dictionary_key_val {
      keyValList_t *left = (keyValList_t*)$1;
      keyValList_t *right = (keyValList_t*)$3;

      right->next = left;
      $$ = right;
    }
    | dictionary_key_val {
      $$ = $1;
    }
    | {
        $$ = NULL;
    }

dictionary_key_val:
    stringContent ':' expressions {
      keyValList_t *keyVal = ast_emalloc(sizeof(keyValList_t));

      keyVal->key = $1;
      keyVal->val = $3;
      keyVal->next = NULL;

      $$ = keyVal;
    };

body:
    '{' statements '}' {
        $$ = newBody($2);
    };

vector:
    '[' arguments_list ']' {
      argsList_t *args = (argsList_t*) $2;
      $$ = newExpr_Vector(args);
    }
    |
    '[' forEachStatement ']' {
      statement_t* stmt = newStatement(LANG_ENTITY_FOREACH, $2);
      $$ = newExpr_VectorFromForEach(stmt);
    }
    | '[' ']' {
      $$ = newExpr_Vector(NULL);
    };

arguments_list:
    arguments_list ',' expressions {
        expr_t *expr = $3;
        $$ = newArgument(expr, $1);
    }
    | expressions {
        $$ = newArgument($1, NULL);
    };

parameters_list:
    parameters_list ',' ID {
        /* A parameter list is an argument struct list with only ID expressions */
        expr_t *expr = newExpr_ID($3);
        $$ = newArgument(expr, $1);
    }
    | ID {
        expr_t *expr = newExpr_ID($1);
        $$ = newArgument(expr, NULL);
    };

mathContent:
    mathContentDouble {
        $$ = $1;
    }
    | '-' mathContentDouble {
        expr_t *neg = newExpr_Ival(-1);
        $$ = newExpr_OPMul(neg, $2);
    }
    | mathContentDigit {
        $$ = $1;
    }
    | '-' mathContentDigit {
        expr_t *neg = newExpr_Ival(-1);
        $$ = newExpr_OPMul(neg, $2);
    };

indexedVector:
    expression '[' expressions ']' {
        expr_t *id = $1;
        expr_t *index = $3;

        $$ = newExpr_VectorIndex(id, index);
    }
    | expression '[' indexer ']' {
        expr_t *id = $1;
        expr_t *index = $3;

        $$ = newExpr_VectorIndex(id, index);
    }
    | indexedVector '[' expressions ']' {
      $$ = newExpr_VectorIndex($1, $3);
    };

indexer:
  expression ':' expression {
    $$ = newExpr_Indexer($1, $3, NULL);
  }
  | ':' expression {
    $$ = newExpr_Indexer(NULL, $2, NULL);
  }
  | expression ':' {
    $$ = newExpr_Indexer($1, NULL, NULL);
  }
  | ':' {
    $$ = newExpr_Indexer(NULL, NULL, NULL);
  }
  | expression ':' expression ':' expression {
    $$ = newExpr_Indexer($1, $3, $5);
  }
  | ':' expression ':' expression {
    $$ = newExpr_Indexer(NULL, $2, $4);
  }
  | expression ':' ':' expression {
    $$ = newExpr_Indexer($1, NULL, $4);
  }
  | ':' ':' expression {
    $$ = newExpr_Indexer(NULL, NULL, $3);
  }
  |  ':' ':' {
    $$ = newExpr_Indexer(NULL, NULL, NULL);
  }

mathContentDigit:
    DIGIT {
      if ( strlen(yyval.id) >= 10 ) {
        $$ = newExpr_BigIntFromStr(yyval.id);
      } else {
        $$ = newExpr_Ival(atoi(yyval.id));
      }
    };

mathContentDouble:
    DOUBLE {
        $$ = newExpr_Float(yyval.val_double);
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

        size_t textlen_e1 = strlen(e1->text);
        size_t textlen_e2 = strlen(e2->text);

        textBuffer = ast_emalloc(textlen_e1+textlen_e2+1);

        snprintf(textBuffer, textlen_e1+textlen_e2+1,
            "%s%s",
            e1->text,
            e2->text
        );

        textBuffer[textlen_e1+textlen_e2] = 0;

        free(e1->text);
        free(e2->text);
        free(e1);
        free(e2);

        $$ = newExpr_Text(textBuffer);

        free(textBuffer);
    }
    | stringEdition {
        $$ = $1;
    };

stringEdition:
    ID {
        $$ = newExpr_Text(yyval.id);
    }
    | mathContentDouble {
        char buffer[256];
        expr_t *e = (expr_t*)$1;
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        $$ = newExpr_Text(buffer);
        free($1);
    }
    | mathContentDigit {
        char buffer[256];
        expr_t *d = (expr_t*)$1;
        if ( d->type == EXPR_TYPE_IVAL ) {
          snprintf(buffer, sizeof(buffer), "%d", d->ival);
        } else if ( d->type == EXPR_TYPE_BIGINT ) {
          char buf[128];
          char *c = NULL;

          c = mpz_get_str(buf, 10, *d->bigInt);
          snprintf(buffer, sizeof(buffer), "%s", c);
        }
        $$ = newExpr_Text(buffer);
        free($1);
    }
    | RETURN {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        $$ = newExpr_Text(buffer);
    }
    | FOREACH {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        $$ = newExpr_Text(buffer);
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
    |
    '?' {
        $$[0] = '?';
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
    | '\\' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | ':' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | ';' {
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
    }
    | '!' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | ',' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '\'' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '\"' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '.' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '[' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | ']' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '*' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '^' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '$' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '&' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '|' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '{' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '}' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    }
    | '=' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    };

%%

#include <stdlib.h>
#include <string.h>
#include "hooks.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yyparse();
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void initParser() {
    setParser(yyparse);
    setRoot(&root);
}

void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func) {
    char lineBuffer[256];

    ParsedFile = "stdin";

    memset(lineBuffer, 0, sizeof(lineBuffer));

    PRINT_INTERACTIVE_BANNER();

    printf(">> ");
    while ( fgets(lineBuffer, sizeof(lineBuffer), stdin) != NULL ) {
        YY_BUFFER_STATE buffer;

        /* Check if the user wants to quit */
        if ( strstr(lineBuffer, "quit") != NULL ) {
            func(argc, argv, NULL, 1);
            return;
        }

        /* Parse from read line */
        buffer = yy_scan_string(lineBuffer);
        yyparse();
        yy_delete_buffer(buffer);

        if ( root != NULL ) {
            func(argc, argv, root, 0);
        }

        printf(">> ");
        memset(lineBuffer, 0, sizeof(lineBuffer));
    }
}
