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

void yyerror(const char *s);

#define SOURCE_LOCATION(loc) ((source_location_t){sourceFile(ParsedFile), \
  (loc).first_line, (loc).first_column, (loc).last_line, (loc).last_column})

static statement_t *sourceStatement(int type, void *content, source_location_t location) {
    statement_t *stmt = newStatement(type, content);
    stmt->location = location;
    stmt->file = location.file;
    stmt->line = location.first_line;
    return stmt;
}

int yylex(void);

/* Root statement */
statement_t *root = NULL;

%}

/* Fail parser generation if a future edit introduces a conflict. */
%expect 0
%locations

%union { int val_int; double val_double; char id[256]; void *data; }

%token<val_int> DIGIT
%token<val_double> DOUBLE
%token<id> ID
%token RETURN
%token FOREACH
%token COMMENT
%token MEMBER ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token NEWLINE
%token<id> QUOTED_CHAR
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
%type<data> indexer primaryExpression
%type<data> class
%type<data> classFunctionCall
%type<data> functionCall
%type<data> namespacedFunctionCall
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

/* Prefer extending an expression over starting an adjacent statement. */
%nonassoc STATEMENT_END
%right'=' 
%left '+' '-'
%left '*' '/' '%'
%nonassoc ATOM
%nonassoc ID '(' '[' '.' ':' '!' MEMBER
%nonassoc NEWLINE

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
    _ statement statements {
        statement_t *stmt = (statement_t*)$2;
        stmt->next = (statement_t*)$3;
        $$ = $2;
    }
    | _ { $$ = NULL; }
    ;

statement:
    declaration {
        $$ = sourceStatement(LANG_ENTITY_DECL, $1, SOURCE_LOCATION(@$));
    } 
    | function {
        $$ = sourceStatement(LANG_ENTITY_FUNCDECL, $1, SOURCE_LOCATION(@$));
    }
    | forEachStatementFull {
        $$ = sourceStatement(LANG_ENTITY_FOREACH, $1, SOURCE_LOCATION(@$));
    }
    | expressions %prec STATEMENT_END {
        $$ = sourceStatement(LANG_ENTITY_EXPR, $1, SOURCE_LOCATION(@$));
    }
    | ifStatement {
        $$ = sourceStatement(LANG_ENTITY_CONDITIONAL, $1, SOURCE_LOCATION(@$));
    }
    | loopStatement {
        $$ = sourceStatement(LANG_ENTITY_CONDITIONAL, $1, SOURCE_LOCATION(@$));
    }
    | continueStatement {
        $$ = sourceStatement(LANG_ENTITY_CONTINUE, $1, SOURCE_LOCATION(@$));
    }
    | breakStatement {
        $$ = sourceStatement(LANG_ENTITY_BREAK, $1, SOURCE_LOCATION(@$));
    }
    | returnStatement {
        $$ = sourceStatement(LANG_ENTITY_RETURN, $1, SOURCE_LOCATION(@$));
    }
    | systemStatement {
        $$ = sourceStatement(LANG_ENTITY_SYSTEM, $1, SOURCE_LOCATION(@$));
    }
    | class {
        $$ = sourceStatement(LANG_ENTITY_CLASSDECL, $1, SOURCE_LOCATION(@$));
    };

_: _ NEWLINE {} | {};

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
    '(' _ expressions FOREACH ID _ ')' body {
    $$ = newForEach($3, $5, $8);
};

returnStatement: RETURN expressions %prec STATEMENT_END {
    $$ = $2;
};

continueStatement: '@' %prec STATEMENT_END {
    $$ = NULL;
};

breakStatement: '!' '@' {
    $$ = NULL;
};

expressions: 
    expression %prec ATOM {
      $$ = $1;
    }
    | expressions '+' _ expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$4;

      $$ = newExpr_OPAdd(e1,e2);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '*' _ expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$4;

      $$ = newExpr_OPMul(e1,e2);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '-' _ expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$4;

      $$ = newExpr_OPSub(e1,e2);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '%' _ expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$4;

      $$ = newExpr_OPMod(e1,e2);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '/' _ expressions {
      expr_t *e1 = (expr_t*)$1;
      expr_t *e2 = (expr_t*)$4;

      $$ = newExpr_OPDiv(e1,e2);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

expression:
    primaryExpression %prec ATOM { $$ = $1; }
    | classFunctionCall { $$ = $1; }
    ;

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
    logical_a '|' '|' _ logical_b {
      $$ = newExpr_Logical($1, NULL, $5);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | logical_b {
      $$ = $1;
    };

logical_b:
    logical_b '&' '&' _ logical_expression {
      $$ = newExpr_Logical($5, $1, NULL);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
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
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expression {
        $$ = $1;
    };

condition:
    expressions '=' '=' expressions {
        $$ = newConditional(CONDITION_EQ, $1, $4);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '!' '=' expressions {
        $$ = newConditional(CONDITION_NEQ, $1, $4);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '<' '=' expressions {
        $$ = newConditional(CONDITION_LEQ, $1, $4);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '>' '=' expressions {
        $$ = newConditional(CONDITION_GEQ, $1, $4);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '<' expressions %prec STATEMENT_END {
        $$ = newConditional(CONDITION_LE, $1, $3);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expressions '>' expressions %prec STATEMENT_END {
        $$ = newConditional(CONDITION_GE, $1, $3);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | '(' _ condition ')' {
        $$ = $3;
    };

class: ';' ';' ID ';' ';' body {
    /* Only declarations allowed */
    body_t *bod = $6;
    statement_t *walk = bod->content;
    while ( walk != NULL ) {
        if (
            walk->entity != LANG_ENTITY_DECL &&
            walk->entity != LANG_ENTITY_FUNCDECL &&
            walk->entity != LANG_ENTITY_BODY &&
            walk->entity != LANG_ENTITY_BODY_END
        ) {
            reportSourceError(&walk->location,
                "SyntaxError: class '%s' may contain only variable and function declarations\n", $3);
            exit(1);
        }

        if ( walk->entity == LANG_ENTITY_FUNCDECL ) {
            functionDef_t *funcDef = walk->content;

            /* Sanity check, constructor may not use arguments */
            if ( strcmp(funcDef->id.id, $3) == 0 ) {
                if ( funcDef->params != NULL ) {
                    reportSourceError(&walk->location,
                        "SyntaxError: constructor '%s' must not have parameters\n", $3);
                    exit(1);
                }
            }
        }
        walk = walk->next;
    }
    $$ = newClass($3, bod);
}

function:
    '@' ID '(' parameters_list ')' body {
        $$ = newFunc($2,$4,$6);
    } |
    '@' ID '(' ')' body {
        $$ = newFunc($2,NULL,$5);
    };

classFunctionCall:
    expression MEMBER ID '(' arguments_list ')' {
        $$ = newClassFunCall($1, $3, $5);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expression MEMBER ID '(' ')' {
        $$ = newClassFunCall($1, $3, NULL);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expression MEMBER ID %prec ATOM {
        $$ = newClassAccesser($1, $3);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };


functionCall:
    ID '(' arguments_list ')' {
        expr_t *id = newExpr_ID($1);
        $$ = newFunCall(id,$3);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | ID '(' ')' {
        expr_t *id = newExpr_ID($1);
        $$ = newFunCall(id,NULL);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | namespacedFunctionCall {
        $$ = $1;
    }
    | indexedVector '(' arguments_list ')' {
        expr_t *id = (expr_t*)$1;
        $$ = newFunCall(id,$3);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | indexedVector '(' ')' {
        expr_t *id = (expr_t*)$1;
        $$ = newFunCall(id,NULL);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

namespacedFunctionCall: 
    ID '.' ID '(' ')' {
        expr_t *id = newExpr_ID($3);
        expr_t *expr = newExpr_ID($1);
        argsList_t *args = newArgument(expr, NULL);
        $$ = newFunCall(id, args);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | ID '.' ID '(' arguments_list ')' {
        expr_t *id = newExpr_ID($3);
        expr_t *expr = newExpr_ID($1);
        argsList_t *args = newArgument(expr, NULL);
        argsList_t *walk = $5;
        walk->length += 1;
        while ( walk->next != NULL ) {
          walk = walk->next;
        }
        walk->next = args;
        $$ = newFunCall(id, $5);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

declaration: 
    ID '=' expressions %prec STATEMENT_END {
        expr_t *idexpr = newExpr_ID($1);

        $$ = newDeclaration(idexpr,$3);
    }
    | ID ADD_ASSIGN expressions %prec STATEMENT_END {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPAdd(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | ID SUB_ASSIGN expressions %prec STATEMENT_END {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPSub(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | ID MUL_ASSIGN expressions %prec STATEMENT_END {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPMul(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | ID DIV_ASSIGN expressions %prec STATEMENT_END {
        expr_t *idexpr = newExpr_ID($1);
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPDiv(idexpr, valexpr);

        $$ = newDeclaration(idexpr,opadd);
    }
    | indexedVector ADD_ASSIGN expressions %prec STATEMENT_END {
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPAdd($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | indexedVector SUB_ASSIGN expressions %prec STATEMENT_END {
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPSub($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | indexedVector MUL_ASSIGN expressions %prec STATEMENT_END {
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPMul($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | indexedVector DIV_ASSIGN expressions %prec STATEMENT_END {
        expr_t *valexpr = $3;
        expr_t *opadd = newExpr_OPDiv($1, valexpr);

        $$ = newDeclaration($1,opadd);
    }
    | ID '=' condition {
        expr_t *idexpr = newExpr_ID($1);

        $$ = newDeclaration(idexpr,$3);
    }
    | indexedVector '=' expressions %prec STATEMENT_END {
        $$ = newDeclaration($1,$3);
    }
    | indexedVector '=' condition {
        $$ = newDeclaration($1,$3);
    };

dictionary:
    '{' _ dictionary_keys_vals '}' {
      $$ = newExpr_Dictionary($3);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

dictionary_keys_vals:
    dictionary_keys_vals ',' _ dictionary_key_val _ {
      keyValList_t *left = (keyValList_t*)$1;
      keyValList_t *right = (keyValList_t*)$4;

      right->next = left;
      $$ = right;
    }
    | dictionary_key_val _ {
      $$ = $1;
    }
    | {
        $$ = NULL;
    }

dictionary_key_val:
    stringContent ':' expression {
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
    '[' _ arguments_list _ ']' {
      argsList_t *args = (argsList_t*) $3;
      $$ = newExpr_Vector(args);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    |
    '[' _ forEachStatement _ ']' {
      statement_t* stmt = sourceStatement(LANG_ENTITY_FOREACH, $3, SOURCE_LOCATION(@3));
      $$ = newExpr_VectorFromForEach(stmt);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | '[' _ ']' {
      $$ = newExpr_Vector(NULL);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

arguments_list:
    arguments_list _ ',' _ expressions {
        expr_t *expr = $5;
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
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | mathContentDigit {
        $$ = $1;
    }
    | '-' mathContentDigit {
        expr_t *neg = newExpr_Ival(-1);
        $$ = newExpr_OPMul(neg, $2);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

indexedVector:
    expression '[' expressions ']' {
        expr_t *id = $1;
        expr_t *index = $3;

        $$ = newExpr_VectorIndex(id, index);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | expression '[' indexer ']' {
        expr_t *id = $1;
        expr_t *index = $3;

        $$ = newExpr_VectorIndex(id, index);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

/* A colon at the top level of an index denotes a slice. Parenthesize
 * member access in an index, e.g. values[(object::field)], to distinguish
 * it from a slice such as values[start::step]. */
primaryExpression:
    indexedVector %prec ATOM {
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
    | stringContent {
      $$ = $1;
    }
    | ID %prec STATEMENT_END {
      $$ = newExpr_ID($1);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | '-' ID {
      expr_t *id = newExpr_ID($2);
      expr_t *neg = newExpr_Ival(-1);
      $$ = newExpr_OPMul(neg, id);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | '(' _ expressions ')' {
      $$ = $3;
    };

indexer:
  primaryExpression ':' primaryExpression {
    $$ = newExpr_Indexer($1, $3, NULL);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  | ':' primaryExpression {
    $$ = newExpr_Indexer(NULL, $2, NULL);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  | primaryExpression ':' {
    $$ = newExpr_Indexer($1, NULL, NULL);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  | ':' {
    $$ = newExpr_Indexer(NULL, NULL, NULL);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  | primaryExpression ':' primaryExpression ':' primaryExpression {
    $$ = newExpr_Indexer($1, $3, $5);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  | ':' primaryExpression ':' primaryExpression {
    $$ = newExpr_Indexer(NULL, $2, $4);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  | primaryExpression MEMBER primaryExpression {
    $$ = newExpr_Indexer($1, NULL, $3);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  | MEMBER primaryExpression {
    $$ = newExpr_Indexer(NULL, NULL, $2);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }
  |  MEMBER {
    $$ = newExpr_Indexer(NULL, NULL, NULL);
    ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
  }

mathContentDigit:
    DIGIT {
      if ( strlen(yyval.id) >= 10 ) {
        $$ = newExpr_BigIntFromStr(yyval.id);
      } else {
        if ( yyval.id[0] == '0' && strlen(yyval.id) > 1 ) {
          $$ = newExpr_Text(yyval.id);
        } else {
          $$ = newExpr_Ival(atoi(yyval.id));
        }
      }
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    };

mathContentDouble:
    DOUBLE {
        $$ = newExpr_Float(yyval.val_double);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
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
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | '\'' '\'' {
        /* Empty text */
        $$ = newExpr_Text("");
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
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
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | stringEdition {
        $$ = $1;
    };

stringEdition:
    ID {
        $$ = newExpr_Text(yyval.id);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | mathContentDouble {
        char buffer[256];
        expr_t *e = (expr_t*)$1;
        snprintf(buffer, sizeof(buffer), "%lf", e->fval);
        $$ = newExpr_Text(buffer);
        free($1);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
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
        } else if ( d->type == EXPR_TYPE_TEXT ) {
          snprintf(buffer, sizeof(buffer), "%s", d->text);
        }
        $$ = newExpr_Text(buffer);
        free($1);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | RETURN {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "->");
        $$ = newExpr_Text(buffer);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | FOREACH {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%s", "...");
        $$ = newExpr_Text(buffer);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
    }
    | otherChar {
        $$ = newExpr_Text($1);
      ((expr_t*)$$)->location = SOURCE_LOCATION(@$);
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
    | QUOTED_CHAR {
        strcpy($$, $1);
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
    }
    | '_' {
        $$[0] = yyval.id[0];
        $$[1] = 0;
    };

%%

void yyerror(const char *s) {
    source_location_t location = SOURCE_LOCATION(yylloc);
    reportSourceError(&location, "SyntaxError: %s\n", s);
}

#include <stdlib.h>
#include <string.h>
#include "hooks.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yyparse(void);
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void initParser(void) {
    setParser(yyparse);
    setRoot(&root);
}

void runInteractive(int argc, char *argv[], interactiveInterpreterFunc func, int stacksize, int heapsize, const char *prompt) {
    char lineBuffer[256];

    memset(lineBuffer, 0, sizeof(lineBuffer));

    PRINT_INTERACTIVE_BANNER();

    while ( readCommand(lineBuffer, sizeof(lineBuffer), prompt) != NULL ) {
        YY_BUFFER_STATE buffer;

        /* Check if the user wants to quit */
        if ( strstr(lineBuffer, "quit") != NULL ) {
            func(argc, argv, NULL, 1, stacksize, heapsize);
            return;
        }

        /* Parse from read line */
        ParsedFile = "<stdin>";
        resetLexerLocation();
        root = NULL;
        buffer = yy_scan_string(lineBuffer);
        int parsed = yyparse();
        yy_delete_buffer(buffer);

        if ( parsed == 0 && root != NULL ) {
            func(argc, argv, root, 0, stacksize, heapsize);
        }

        memset(lineBuffer, 0, sizeof(lineBuffer));
    }
}


int runCommand(int argc, char *argv[], interactiveInterpreterFunc func, char *command, int stacksize, int heapsize) {
    YY_BUFFER_STATE buffer;

    /* Parse from provided command line */
    ParsedFile = "<command>";
    resetLexerLocation();
    root = NULL;
    buffer = yy_scan_string(command);
    int parsed = yyparse();
    yy_delete_buffer(buffer);

    if ( parsed == 0 && root != NULL ) {
        func(argc, argv, root, 0, stacksize, heapsize);
    }
    return parsed != 0;
}
