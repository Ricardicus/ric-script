#include "eval.h"

/* Namespace (all global) */
hashtable_t *funcDecs = NULL;
hashtable_t *varDecs = NULL;

jmp_buf jmpbuf;

int evaluate_condition(ifCondition_t *cond,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args,
  hashtable_t *argVals)
{
  /* Will set ax either 1 or 0 (or interrupt the program on error) */
  stackval_t svLeft;
  stackval_t svRight;

  /* Arbitrary double resoultion, not sure what to set this to */
  double epsilon = 0.00001;

  evaluate_expression(cond->left, PROVIDE_CONTEXT(), args, argVals);
  POP_VAL(&svLeft, sp, sc);

  evaluate_expression(cond->right, PROVIDE_CONTEXT(), args, argVals);
  POP_VAL(&svRight, sp, sc);

  switch (cond->type) 
  {
  case CONDITION_EQ:
  {
    if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {

      if ( svLeft.i == svRight.i ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
      *f0 = (double) svLeft.i;

      if ( fabs(*f0 - svRight.d) < epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
      *f0 = svRight.d;
      *f1 = svLeft.d;

      if ( fabs(*f0 - *f1) < epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f0 = (double) svRight.i;

      if ( fabs(*f0 - svLeft.d) < epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == TEXT && svRight.type == TEXT ) {
      *ax = strcmp(svLeft.t, svRight.t) == 0;
    }
    break;
  }
  case CONDITION_NEQ:
  {
    if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {

      if ( svLeft.i != svRight.i ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
      *f0 = (double) svLeft.i;

      if ( fabs(*f0 - svRight.d) > epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
      *f0 = svRight.d;
      *f1 = svLeft.d;

      if ( fabs(*f0 - *f1) > epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f0 = (double) svRight.i;

      if ( fabs(*f0 - svLeft.d) > epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    }
    break;
  }
  case CONDITION_LEQ:
  {
    if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {

      if ( svLeft.i <= svRight.i ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
      *f0 = (double) svLeft.i;

      if ( *f0 - svRight.d < -epsilon || fabs(*f0 - svRight.d) < epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
      *f0 = svLeft.d;
      *f1 = svRight.d;

      if ( *f0 - *f1 < -epsilon || fabs(*f0 - *f1) < epsilon) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f1 = (double) svRight.i;

      if ( svLeft.d - *f1 < -epsilon || fabs(svLeft.d - *f1) < epsilon) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    }
    break;
  }
  case CONDITION_GEQ:
  {
    if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {

      if ( svLeft.i >= svRight.i ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
      *f0 = (double) svLeft.i;

      if ( *f0 - svRight.d > epsilon || fabs(*f0 - svRight.d) < epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
      *f0 = svLeft.d;
      *f1 = svRight.d;

      if ( *f0 - *f1 > epsilon || fabs(*f0 - *f1) < epsilon) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f1 = (double) svRight.i;

      if ( svLeft.d - *f1 > epsilon || fabs(svLeft.d - *f1) < epsilon) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    }
    break;
  }
  case CONDITION_GE:
  {
    if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {

      if ( svLeft.i > svRight.i ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
      *f0 = (double) svLeft.i;

      if ( *f0 - svRight.d > epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
      *f0 = svLeft.d;
      *f1 = svRight.d;

      if ( *f0 - *f1 > epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f1 = (double) svRight.i;

      if ( svLeft.d - *f1 > epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    }
    break;
  }
  case CONDITION_LE:
  {
    if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {

      if ( svLeft.i < svRight.i ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
      *f0 = (double) svLeft.i;

      if ( *f0 - svRight.d < -epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }

    } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
      *f0 = svLeft.d;
      *f1 = svRight.d;

      if ( *f0 - *f1 < -epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f1 = (double) svRight.i;

      if ( svLeft.d - *f1 < -epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    }
    break;
  }
  default:
  break;
  }

  return 0;
}

void evaluate_expression(
  expr_t *expr,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args,
  hashtable_t *argVals)
{
  if ( expr == NULL )
    return;

  switch (expr->type) 
  {
    case EXPR_TYPE_ID:
    {
      heapval_t *hv;
      int stop = 0;

      /* Check if this ID is among the arguments */
      argsList_t *walk = args;

      while ( walk != NULL && !stop ) {
        expr_t *exp = walk->arg;
        if ( exp->type == EXPR_TYPE_ID ) {
          expr_t *expArg;

          /* Check among the variables if we have it defined there */
          expArg = hashtable_get(argVals, expr->id.id);

          if ( expArg != NULL ) {
            /* This was an argument! */
            switch ( expArg->type ) {
            case EXPR_TYPE_IVAL:
              PUSH_INT(expArg->ival, sp, sc);
              break;
            case EXPR_TYPE_FVAL:
              PUSH_DOUBLE(expArg->fval, sp, sc);
              break;
            case EXPR_TYPE_TEXT:
            {
              size_t len = strlen(expArg->text);
              stackval_t sv;
              heapval_t *hvp;
              char *newText = ast_emalloc(len+1);
              snprintf(newText, len+1, "%s", expArg->text);

              sv.type = TEXT;
              sv.t = newText;

              ALLOC_HEAP(&sv, hp, &hvp);

              PUSH_STRING(sv.t, sp, sc);
              break;
            }
            default:
              fprintf(stderr, "error: Invalid usage of identifier '%s'\n", expr->id.id);
              exit(1);
              break;
            }

            stop = 1;
          }
        } else {
          fprintf(stderr, "error: unknown, this is crazy. The interpreter is borken or something.\n");
          exit(1);
        }

        walk = walk->next;
      }

      if ( stop ) {
        break;
      }

      if ( walk == NULL ) {
        /* Check among the variables if we have it defined there */
        hv = hashtable_get(varDecs, expr->id.id);

        if ( hv != NULL ) {

          switch ( hv->sv.type ) {
          case DOUBLETYPE:
            PUSH_DOUBLE(hv->sv.d, sp, sc);
            break;
          case INT32TYPE:
            PUSH_INT(hv->sv.i, sp, sc);
            break;
          case TEXT: {
            size_t len = strlen(hv->sv.t);
            stackval_t sv;
            heapval_t *hvp;

            char *newText = ast_emalloc(len+1);
            snprintf(newText, len+1, "%s", hv->sv.t);

            sv.type = TEXT;
            sv.t = newText;

            ALLOC_HEAP(&sv, hp, &hvp);

            PUSH_STRING(sv.t, sp, sc);
            break;
          }
          default:
            break;
          }

        } else {
          fprintf(stderr, "Failed to find ID: %s\n", expr->id.id);
          exit(1);
        }
      }

      break;
    }
    case EXPR_TYPE_FVAL:
    PUSH_DOUBLE(expr->fval, sp, sc);
    break;
    case EXPR_TYPE_IVAL:
    PUSH_INT(expr->ival, sp, sc);
    break;
    case EXPR_TYPE_UVAL:
    PUSH_INT(expr->uval, sp, sc);
    break;
    case EXPR_TYPE_TEXT: {
      size_t len = strlen(expr->text);
      stackval_t sv;
      heapval_t *hvp;
      heapval_t hv;
      char *newText = ast_emalloc(len+1);
      snprintf(newText, len+1, "%s", expr->text);

      sv.type = TEXT;
      sv.t = newText;

      ALLOC_HEAP(&sv, hp, &hvp);

      hv = *hvp;

      PUSH_STRING(hv.sv.t, sp, sc);
      break;
    }
    break;
    case EXPR_TYPE_OPADD:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svRight, sp, sc);

      switch (svLeft.type) {
        case INT32TYPE: {
          *r0 = svLeft.i;
          break;
        }
        case DOUBLETYPE: {
          *f0 = svLeft.d;
          break;
        }
        case TEXT: {
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svLeft.type);
          exit(1);
          break;
      }

      switch (svRight.type) {
        case INT32TYPE: {
          *r1 = svRight.i;
          break;
        }
        case DOUBLETYPE: {
          *f1 = svRight.d;
          break;
        }
        case TEXT: {
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {
        PUSH_INT(*r0+*r1, sp, sc);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 + *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 + *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 + *r1, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == TEXT ) {
        size_t len = strlen(svLeft.t) + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        heapval_t hv;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s%s", svLeft.t, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp);

        hv = *hvp;
        PUSH_STRING(hv.sv.t, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == TEXT ) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        heapval_t hv;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%.4f%s", svLeft.d, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp);

        hv = *hvp;
        PUSH_STRING(hv.sv.t, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == DOUBLETYPE ) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        heapval_t hv;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s%.4f", svLeft.t, svRight.d);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp);

        hv = *hvp;
        PUSH_STRING(hv.sv.t, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == INT32TYPE ) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        heapval_t hv;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s%d", svLeft.t, svRight.i);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp);

        hv = *hvp;
        PUSH_STRING(hv.sv.t, sp, sc);
      } else if ( svLeft.type == INT32TYPE && svRight.type == TEXT ) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        heapval_t hv;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%d%s", svLeft.i, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp);

        hv = *hvp;
        PUSH_STRING(hv.sv.t, sp, sc);
      }

      break;
    }
    break;
    case EXPR_TYPE_OPSUB:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svRight, sp, sc);

      switch (svLeft.type) {
        case INT32TYPE: {
          *r0 = svLeft.i;
          break;
        }
        case DOUBLETYPE: {
          *f0 = svLeft.i;
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Cannot substract strings..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svLeft.type);
          exit(1);
          break;
      }

      switch (svRight.type) {
        case INT32TYPE: {
          *r1 = svRight.i;
          break;
        }
        case DOUBLETYPE: {
          *f1 = svRight.i;
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Cannot substract strings..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {
        PUSH_INT(*r0-*r1, sp, sc);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 - *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 - *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 - *r1, sp, sc);
      }

      break;
    }
    case EXPR_TYPE_OPMUL:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svRight, sp, sc);

      switch (svLeft.type) {
        case INT32TYPE: {
          *r0 = svLeft.i;
          break;
        }
        case DOUBLETYPE: {
          *f0 = svLeft.i;
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Cannot multiply strings..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svLeft.type);
          exit(1);
          break;
      }

      switch (svRight.type) {
        case INT32TYPE: {
          *r1 = svRight.i;
          break;
        }
        case DOUBLETYPE: {
          *f1 = svRight.i;
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Cannot multiply strings..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {
        PUSH_INT(*r0 * *r1, sp, sc);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 * *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 * *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 * *r1, sp, sc);
      }

      break;
    }
    case EXPR_TYPE_OPMOD:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svRight, sp, sc);

      switch (svLeft.type) {
        case INT32TYPE: {
          *r0 = svLeft.i;
          break;
        }
        case DOUBLETYPE: {
          fprintf(stderr, "error: Invalid expression, cannot calculate modulus on floating point.\n");
          exit(1);
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Invalid expression, cannot calculate modulus on string.\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svLeft.type);
          exit(1);
          break;
      }

      switch (svRight.type) {
        case INT32TYPE: {
          *r1 = svRight.i;
          break;
        }
        case DOUBLETYPE: {
          fprintf(stderr, "error: Invalid expression, cannot calculate modulus on floating point.\n");
          exit(1);
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Invalid expression, cannot calculate modulus on string.\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {
        PUSH_INT(*r0 % *r1, sp, sc);
      }

      break;
    }
    break;
    case EXPR_TYPE_OPDIV:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&svRight, sp, sc);

      switch (svLeft.type) {
        case INT32TYPE: {
          *r0 = svLeft.i;
          break;
        }
        case DOUBLETYPE: {
          *f0 = svLeft.i;
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Not implemented string additions yet..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svLeft.type);
          exit(1);
          break;
      }

      switch (svRight.type) {
        case INT32TYPE: {
          *r1 = svRight.i;
          break;
        }
        case DOUBLETYPE: {
          *f1 = svRight.i;
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Not implemented string additions yet..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unknown stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if ( svLeft.type == INT32TYPE && svRight.type == INT32TYPE ) {
        PUSH_INT(*r0 / *r1, sp, sc);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 / *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 / *f1, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 / *r1, sp, sc);
      }

      break;
    }
    break;
    case EXPR_TYPE_COND:
    {
      evaluate_condition(expr->cond, PROVIDE_CONTEXT(), args, argVals);
      /* Push ax to stack */
      PUSH_INT(*ax, sp, sc);
      break;
    }
    case EXPR_TYPE_EMPTY:
    default:
    break;
  }
}

void interpret_statements_(
  void *stmt,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t *args,
  hashtable_t *argVals
)
{
  entity_eval_t *eval = (entity_eval_t*)stmt;
  void *next = NULL;

  if ( stmt == NULL )
    return;

  switch ( eval->entity ) {
    case LANG_ENTITY_DECL:
    case LANG_ENTITY_FUNCDECL:
    case LANG_ENTITY_FUNCCALL:
    case LANG_ENTITY_CONDITIONAL:
    case LANG_ENTITY_SYSTEM:
      next = ((statement_t*)stmt)->next;
    break;
    case LANG_ENTITY_EMPTY_MATH:
    case LANG_ENTITY_EMPTY_STR:
    { 
      stackval_t sv;
      expr_t *e = ((statement_t*)stmt)->content;
      evaluate_expression(e, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&sv, sp, sc);
      switch ( sv.type) {
      case INT32TYPE:
      printf("%" PRIi32 "\n", sv.i);
      break;
      case DOUBLETYPE:
      printf("%lf\n", sv.d);
      break;
      case TEXT:
      printf("%s\n", sv.t);
      break;
      default:
      printf("%s.error: unknown type of value on the stack (%d)\n", 
        __func__, sv.type);
      break;
      }

      next = ((statement_t*)stmt)->next;
      break;
    }
    case LANG_ENTITY_BODY: {
      next = ((body_t*)stmt)->content;
    }
    break;
    case LANG_ENTITY_FIN: {
      /* Jump to VM shutdown */
      longjmp(jmpbuf, 1);
    }
    break;
    default:
    break;
  }

  switch ( eval->entity ) {
    case LANG_ENTITY_DECL:
    {
      stackval_t sv;
      heapval_t *hvp;
      declaration_t* decl = ((statement_t*)stmt)->content;

      /* Evaluating the expression among global variables */
      evaluate_expression(decl->val, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&sv, sp, sc);

      /* Placing value on the heap */
      if ( sv.type == TEXT ) {
        /* Special case */
        char *c = sv.t;
        size_t len = strlen(c)+1;
        char *newText = ast_emalloc(len);
        snprintf(newText,len,"%s",c);
        sv.t = newText;
      }
      ALLOC_HEAP(&sv, hp, &hvp); 

      /* Placing variable declaration in global variable namespace */
      hashtable_put(varDecs, decl->id.id, hvp);
    }
    break;
    case LANG_ENTITY_SYSTEM:
    {
      statement_t *sys_stmt = ((statement_t*)stmt)->content;

      stackval_t sv;
      expr_t *e = sys_stmt->content;
      evaluate_expression(e, PROVIDE_CONTEXT(), args, argVals);
      POP_VAL(&sv, sp, sc);
      switch ( sv.type ) {
      case TEXT:
        /* Making the system call */
        system(sv.t);
        break;
      default:
        printf("%s.error: unknown type of system call on the stack (%d)\n", 
          __func__, sv.type);
        break;
      }
    }
    break;
    case LANG_ENTITY_FUNCDECL:
    {
      functionDef_t *funcDef = ((statement_t*)stmt)->content;

      /* Placing funciton declaration in global function namespace */
      hashtable_put(funcDecs, funcDef->id.id, funcDef);
    }
    break;
    case LANG_ENTITY_CONTINUE:
    {
      /* Set PC to continue 'st' */
      next = *st;
    }
    break;
    case LANG_ENTITY_BREAK:
    {
      /* Set PC to break 'end' */
      interpret_statements_(*ed, PROVIDE_CONTEXT(), args, argVals);
    }
    break;
    case LANG_ENTITY_FUNCCALL:
    {
      functionDef_t *funcDef;
      functionCall_t *funcCall = ((statement_t*)stmt)->content;
      argsList_t *argsWalk = funcCall->args;
      argsList_t *params;
      hashtable_t *newArgumentTable = new_argstable();
      stackval_t sv;

      /* Looking up the function and calling it if it exists */
      funcDef = hashtable_get(funcDecs, funcCall->id.id);

      /* Check lookup status */
      if ( funcDef == NULL ) {
        fprintf(stderr, "Error: Function call undefined: '%s'.\r\n", funcCall->id.id);
        exit(1);
      }

      /* Check that # parameters == # arguments */
      params = funcDef->params;

      if ( params == NULL && argsWalk != NULL ) {
        fprintf(stderr, "Error: function '%s' expected 0 arguments, got: %u\n",
          funcCall->id.id, argsWalk->length );
        exit(1);
      }

      if ( params != NULL && argsWalk == NULL ) {
        fprintf(stderr, "Error: function '%s' expected %u arguments, got: 0\n",
          funcCall->id.id, params->length );
        exit(1);
      }

      if ( params != NULL && argsWalk != NULL )  {
        /* Verifying function definition parameters and function call arguments */
        if ( params->length != argsWalk->length ) {
          /* print error message */
          fprintf(stderr, "Error: function '%s' expected %u arguments, got: %u\n",
            funcCall->id.id, params->length, argsWalk->length );
          exit(1);
        }

        /* Populate arguments */
        while ( argsWalk != NULL && params != NULL ) {
          stackval_t sv;
          expr_t *newArg = NULL;

          if ( params->arg->type != EXPR_TYPE_ID ) {
            /* This is not supposed to happen */
            printf("Error: parameter in function definition '%s' was invalid\n",
              funcCall->id.id);
          }

          /* Evaluate expression */
          evaluate_expression(argsWalk->arg, PROVIDE_CONTEXT(), args, argVals);
          
          /* Fetch the evaluated expression to the arguments table */
          POP_VAL(&sv, sp, sc);

          switch (sv.type) {
            case INT32TYPE: {
              newArg = newExpr_Ival(sv.i);
              break;
            }
            case DOUBLETYPE: {
              newArg = newExpr_Float(sv.d);
              break;
            }
            case TEXT: {
              newArg = newExpr_Text(sv.t);
              break;
            }
            default:
              fprintf(stderr, "error: Unknown stackval_t type: %d\n", sv.type);
              exit(1);
              break;
          }

          /* Adding expression to argument table */
          hashtable_put(newArgumentTable, params->arg->id.id, newArg);

          params = params->next;
          argsWalk = argsWalk->next;
        }

      }

      PUSH_POINTER((*(uintptr_t*)st), sp, sc);
      (*(uintptr_t*)st) = (uintptr_t) stmt;
      PUSH_POINTER((*(uintptr_t*)ed), sp, sc);
      (*(uintptr_t*)ed) = (uintptr_t) next;

      /* Call the function */
      interpret_statements_(funcDef->body, PROVIDE_CONTEXT(), funcDef->params, newArgumentTable);

      POP_VAL(&sv, sp, sc);
      (*(uintptr_t*)ed) = sv.p;
      POP_VAL(&sv, sp, sc);
      (*(uintptr_t*)st) = sv.p;

      /* Push some value on the stack: When implementing return, this should be fixed */
      PUSH_POINTER((*(uintptr_t*)st), sp, sc);

      /* Free the argument value table */
      flush_arguments(newArgumentTable);
    }
    break;
    case LANG_ENTITY_CONDITIONAL:
    {
      ifStmt_t *ifstmt = ((statement_t*)stmt)->content;
      ifStmt_t *ifstmtWalk;
      stackval_t sv;

      if ( (*(uintptr_t*)st) != (uintptr_t) stmt ) {
        PUSH_POINTER((*(uintptr_t*)st), sp, sc);
        (*(uintptr_t*)st) = (uintptr_t) stmt;
      }
      if ( (*(uintptr_t*)ed) != (uintptr_t) next ) {
        PUSH_POINTER((*(uintptr_t*)ed), sp, sc);
        (*(uintptr_t*)ed) = (uintptr_t) next;
      }

      /* Read ax for conditional */
      evaluate_condition(ifstmt->cond, PROVIDE_CONTEXT(), args, argVals);
      if ( *ax ) {
        interpret_statements_(ifstmt->body,
          PROVIDE_CONTEXT(), args, argVals);
      } else {
        // Walk through the elifs.
        int stop = 0;
        ifstmtWalk = ifstmt->elif;

        while ( ifstmtWalk != NULL ) {
          evaluate_condition(ifstmtWalk->cond, PROVIDE_CONTEXT(), args, argVals);
          if ( *ax ) {
            interpret_statements_(ifstmtWalk->body,
              PROVIDE_CONTEXT(), args, argVals);
            stop = 1;
            break;
          }
          ifstmtWalk = ifstmtWalk->elif;
        }

        if ( ! stop ) {
          // Print the else if it is not NULL
          if ( ifstmt->endif != NULL ) {
            ifstmtWalk = ifstmt->endif;
            interpret_statements_(ifstmtWalk->body, PROVIDE_CONTEXT(), args, argVals);
          }
        }

      }

      POP_VAL(&sv, sp, sc);
      (*(uintptr_t*)ed) = sv.p;
      POP_VAL(&sv, sp, sc);
      (*(uintptr_t*)st) = sv.p;

    }
    break;
    default:
    break;
  }

  interpret_statements_(next, PROVIDE_CONTEXT(), args, argVals);
}

void setup_namespaces() {
  funcDecs = hashtable_new(100, 0.8);
  assert(funcDecs != NULL);
  varDecs = hashtable_new(200, 0.8);
  assert(varDecs != NULL);
}

void close_namespaces() {
  hashtable_free(funcDecs);
  hashtable_free(varDecs);
}

hashtable_t *new_argstable()
{
  hashtable_t *argTable = hashtable_new(20, 0.8);
  assert(argTable != NULL);
  argTable->data_also = 1;
  return argTable;
}

void print_expr(expr_t *expr)
{
  if ( expr == NULL )
    return;

  switch (expr->type) 
  {
    case EXPR_TYPE_ID:
    printf("ID('%s')", expr->id.id);
    break;
    case EXPR_TYPE_FVAL:
    printf("%lf", expr->fval);
    break;
    case EXPR_TYPE_IVAL:
    printf("%d", expr->ival);
    break;
    case EXPR_TYPE_UVAL:
    printf("%u", expr->uval);
    break;
    case EXPR_TYPE_TEXT:
    printf("'%s'", expr->text);
    break;
    case EXPR_TYPE_OPADD:
    printf("ADD(");
    print_expr((expr_t*)expr->add.left);
    printf(",");
    print_expr((expr_t*)expr->add.right);
    printf(")");
    break;
    case EXPR_TYPE_OPSUB:
    printf("SUB(");
    print_expr((expr_t*)expr->add.left);
    printf(",");
    print_expr((expr_t*)expr->add.right);
    printf(")");
    break;
    case EXPR_TYPE_OPMUL:
    printf("MUL(");
    print_expr((expr_t*)expr->add.left);
    printf(",");
    print_expr((expr_t*)expr->add.right);
    printf(")");
    break;
    case EXPR_TYPE_OPMOD:
    printf("MOD(");
    print_expr((expr_t*)expr->add.left);
    printf(",");
    print_expr((expr_t*)expr->add.right);
    printf(")");
    break;
    case EXPR_TYPE_OPDIV:
    printf("DIV(");
    print_expr((expr_t*)expr->add.left);
    printf(",");
    print_expr((expr_t*)expr->add.right);
    printf(")");
    break;
    case EXPR_TYPE_COND:
    printf("Conditional(");
    print_condition((ifCondition_t*)expr->cond);
    printf(")");
    break;
    case EXPR_TYPE_EMPTY:
    default:
    break;
  }

}

void print_condition(ifCondition_t *cond)
{
  if ( cond == NULL )
    return;

  printf("[");
  print_expr(cond->left);
  printf("]");

  switch ( cond->type ) {
  case CONDITION_EQ:
    printf(" == ");
    break;
  case CONDITION_NEQ:
    printf(" != ");
    break;
  case CONDITION_LEQ:
    printf(" <= ");
    break;
  case CONDITION_GEQ:
    printf(" >= ");
    break;
  case CONDITION_GE:
    printf(" > ");
    break;
  case CONDITION_LE:
    printf(" < ");
    break;

  default:
    break;
  }

  printf("[");
  print_expr(cond->right);
  printf("]");
}

void print_indents(int indent) {
  int i = 0;
  while ( i < indent ){
    printf("    ");
    ++i;
  }
}

void flush_arguments(hashtable_t *table)
{
  if ( table != NULL ) {
    hashtable_free(table);
  }
}

int print_args(argsList_t *args)
{
  if ( args == NULL )
    return 0;

  if ( print_args(args->next) ) {
    printf(",");
  }
  print_expr(args->arg);
  return 1;
}

void print_statements_(void *stmt, int indent)
{
  entity_eval_t *eval = (entity_eval_t*)stmt;
  void *next = NULL;

  if ( stmt == NULL )
    return;

  switch ( eval->entity ) {
    case LANG_ENTITY_DECL:
    case LANG_ENTITY_FUNCDECL:
    case LANG_ENTITY_FUNCCALL:
    case LANG_ENTITY_CONDITIONAL:
    case LANG_ENTITY_CONTINUE:
    case LANG_ENTITY_BREAK:
    case LANG_ENTITY_EMPTY_MATH:
    case LANG_ENTITY_EMPTY_STR:
    case LANG_ENTITY_SYSTEM:
      printf("[0x%lx] ", (uintptr_t)stmt);
      print_indents(indent);
      next = ((statement_t*)stmt)->next;
    break;
    case LANG_ENTITY_BODY:
      next = ((body_t*)stmt)->content;
      indent++;
    break;
    default:
    break;
  }

  switch ( eval->entity ) {
    case LANG_ENTITY_EMPTY_MATH:
    case LANG_ENTITY_EMPTY_STR:
    {
      printf("Expr(");
      print_expr(((statement_t*)stmt)->content);
      printf(");\n");
    }
    break;
    case LANG_ENTITY_DECL:
    {
      declaration_t* decl = ((statement_t*)stmt)->content;
      printf("Declaration: ID('%s'), Expr(", decl->id.id);
      print_expr(decl->val);
      printf(")\n");
    }
    break;
    case LANG_ENTITY_SYSTEM:
    {
      statement_t *sys_stmt = ((statement_t*)stmt)->content;

      printf("System(");
      print_expr(((statement_t*)sys_stmt)->content);
      printf(");\n");
    }
    break;
    case LANG_ENTITY_CONTINUE:
    {
      printf("=== CONTINUE ===\n");
    }
    break;
    case LANG_ENTITY_BREAK:
    {
      printf("=== BREAK ===\n");
    }
    break;
    case LANG_ENTITY_FUNCDECL:
    {
      functionDef_t *funcDef = ((statement_t*)stmt)->content;
      printf("Function Declaration: ID('%s') args(", funcDef->id.id);
      argsList_t *params = funcDef->params;
      print_args(params);
      printf(")\n");
      print_statements_(funcDef->body,indent+1);
    }
    break;
    case LANG_ENTITY_FUNCCALL:
    {
      functionCall_t *funcCall = ((statement_t*)stmt)->content;
      printf("Function Call: ID('%s') args(", funcCall->id.id);
      argsList_t *args = funcCall->args;
      print_args(args);
      printf(")\n");
    }
    break;
    case LANG_ENTITY_CONDITIONAL:
    {
      ifStmt_t *ifstmt = ((statement_t*)stmt)->content;
      ifStmt_t *ifstmtWalk;
      ifCondition_t *cond = ifstmt->cond;

      printf("if-statement - condition: ");
      print_condition(cond);
      printf("\n");
      print_statements_(ifstmt->body, indent);

      // Walk through the elifs.
      ifstmtWalk = ifstmt->elif;

      while ( ifstmtWalk != NULL ) {
        print_indents(indent);
        printf("else-if-statement - condition: ");
        print_condition(ifstmtWalk->cond);
        printf("\n");
        print_statements_(ifstmtWalk->body, indent+1);
        ifstmtWalk = ifstmtWalk->elif;
      }

      // Print the else if it is not NULL
      if ( ifstmt->endif != NULL ){
        ifstmtWalk = ifstmt->endif;
        print_indents(indent);
        printf("else-statment:\n");
        print_statements_(ifstmtWalk->body, indent);
      }

    }
    break;
    default:
    break;
  }

  print_statements_(next, indent);

}

void print_statements(statement_t *stmt)
{
  printf("\n\nPROGRAM:\n\n");
  print_statements_(stmt, 0);
  printf("\n\n");
}

void interpret_statements(statement_t *stmt)
{
  // "CPU" registers definitions
  DEF_NEW_CONTEXT();

  // Setup stack
  SETUP_STACK(&sp, &sb, RIC_STACKSIZE);

  // Setup heap
  SETUP_HEAP(&hp, &hb, RIC_HEAPSIZE);

  // Setup namespaces
  setup_namespaces();

  /* Set starting point and end point */
  st = stmt;
  ed = NULL;

  if ( setjmp(jmpbuf) == 0) {
    /* Start descending and evaluating the AST */
    interpret_statements_(stmt, PROVIDE_CONTEXT_INIT(), NULL, NULL);
  } else {
    // Close namespaces
    close_namespaces();

    // free heap
    FREE_HEAP(hp, hb);

    // Free stack
    FREE_STACK(sp, sb);

    // Free memory associated with the AST
    free_ast(stmt);
  }
}


