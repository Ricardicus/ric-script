#include "eval.h"

/* Namespace (all global) */
hashtable_t *funcDecs = NULL;
hashtable_t *varDecs = NULL;
hashtable_t *parameters = NULL;

int evaluate_condition(ifCondition_t *cond,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t* args)
{
  /* Will set ax either 1 or 0 (or interrupt the program on error) */
  stackval_t svLeft;
  stackval_t svRight;

  /* Arbitrary double resoultion, not sure what to set this to */
  double epsilon = 0.00001;

  evaluate_expression(cond->left, PROVIDE_CONTEXT(), args);
  POP_VAL(&svLeft, sp);

  evaluate_expression(cond->right, PROVIDE_CONTEXT(), args);
  POP_VAL(&svRight, sp);

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
  argsList_t* args)
{
  if ( expr == NULL )
    return;

  switch (expr->type) 
  {
    case EXPR_TYPE_ID:
    {
      heapval_t *hv;

      /* Check among the variables if we have it defined there */
      hv = hashtable_get(varDecs, expr->id.id);

      if ( hv != NULL ) {

        switch ( hv->sv.type ) {
        case DOUBLETYPE:
          PUSH_DOUBLE(hv->sv.d, sp);
          break;
        case INT32TYPE:
          PUSH_INT(hv->sv.i, sp);
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

          PUSH_STRING(sv.t, sp);
          break;
        }
        default:
          break;
        }

      } else {
        fprintf(stderr, "Failed to find ID: %s\n", expr->id.id);
      }

      break;
    }
    case EXPR_TYPE_FVAL:
    PUSH_DOUBLE(expr->fval, sp);
    break;
    case EXPR_TYPE_IVAL:
    PUSH_INT(expr->ival, sp);
    break;
    case EXPR_TYPE_UVAL:
    PUSH_INT(expr->uval, sp);
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

      PUSH_STRING(hv.sv.t, sp);
      break;
    }
    break;
    case EXPR_TYPE_OPADD:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args);
      POP_VAL(&svLeft, sp);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args);
      POP_VAL(&svRight, sp);

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
        PUSH_INT(*r0+*r1,sp);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 + *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 + *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 + *r1,sp);
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
        PUSH_STRING(hv.sv.t, sp);
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
        PUSH_STRING(hv.sv.t, sp);
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
        PUSH_STRING(hv.sv.t, sp);
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
        PUSH_STRING(hv.sv.t, sp);
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
        PUSH_STRING(hv.sv.t, sp);
      }

      break;
    }
    break;
    case EXPR_TYPE_OPSUB:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args);
      POP_VAL(&svLeft, sp);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args);
      POP_VAL(&svRight, sp);

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
        PUSH_INT(*r0-*r1,sp);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 - *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 - *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 - *r1,sp);
      }

      break;
    }
    case EXPR_TYPE_OPMUL:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args);
      POP_VAL(&svLeft, sp);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args);
      POP_VAL(&svRight, sp);

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
        PUSH_INT(*r0 * *r1,sp);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 * *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 * *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 * *r1,sp);
      }

      break;
    }
    case EXPR_TYPE_OPMOD:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args);
      POP_VAL(&svLeft, sp);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args);
      POP_VAL(&svRight, sp);

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
        PUSH_INT(*r0 % *r1,sp);
      }

      break;
    }
    break;
    case EXPR_TYPE_OPDIV:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, PROVIDE_CONTEXT(), args);
      POP_VAL(&svLeft, sp);

      evaluate_expression((expr_t*)expr->add.right, PROVIDE_CONTEXT(), args);
      POP_VAL(&svRight, sp);

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
        PUSH_INT(*r0 / *r1,sp);
      } else if ( svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*r0 / *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE ) {
        PUSH_DOUBLE(*f0 / *f1,sp);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
        PUSH_DOUBLE(*f0 / *r1,sp);
      }

      break;
    }
    break;
    case EXPR_TYPE_COND:
    {
      evaluate_condition(expr->cond, PROVIDE_CONTEXT(), args);
      /* Push ax to stack */
      PUSH_INT(*ax,sp);
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
  argsList_t *args
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
      next = ((statement_t*)stmt)->next;
    break;
    case LANG_ENTITY_EMPTY_MATH:
    case LANG_ENTITY_EMPTY_STR:
    { 
      stackval_t sv;
      expr_t *e = ((statement_t*)stmt)->content;
      evaluate_expression(e, PROVIDE_CONTEXT(), args);
      POP_VAL(&sv, sp);
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
    case LANG_ENTITY_BODY:
      next = ((body_t*)stmt)->content;
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
      evaluate_expression(decl->val, PROVIDE_CONTEXT(), args);
      POP_VAL(&sv, sp);

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
    case LANG_ENTITY_FUNCDECL:
    {
      functionDef_t *funcDef = ((statement_t*)stmt)->content;

      /* Placing funciton declaration in global function namespace */
      hashtable_put(funcDecs, funcDef->id.id, funcDef->body);
    }
    break;
    case LANG_ENTITY_FUNCCALL:
    {
      statement_t *body;
      functionCall_t *funcCall = ((statement_t*)stmt)->content;

      /* Looking up the function and calling it if it exists */
      body = hashtable_get(funcDecs, funcCall->id.id);

      /* Check lookup status */
      if ( body == NULL ) {
        fprintf(stderr, "Error: Function call undefined: '%s'.\r\n", funcCall->id.id);
        exit(1);
      }

      /* Call the function */
      interpret_statements_(body, PROVIDE_CONTEXT(), funcCall->args);
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
      interpret_statements_(ifstmt->body, PROVIDE_CONTEXT(), args);

      // Walk through the elifs.
      ifstmtWalk = ifstmt->elif;

      while ( ifstmtWalk != NULL ) {
        printf("else-if-statement - condition: ");
        print_condition(ifstmtWalk->cond);
        printf("\n");
        interpret_statements_(ifstmtWalk->body, PROVIDE_CONTEXT(), args);
        ifstmtWalk = ifstmtWalk->elif;
      }

      // Print the else if it is not NULL
      if ( ifstmt->endif != NULL ) {
        ifstmtWalk = ifstmt->endif;
        printf("else-statment:\n");
        interpret_statements_(ifstmtWalk->body, PROVIDE_CONTEXT(), args);
      }

    }
    break;
    default:
    break;
  }

  interpret_statements_(next, PROVIDE_CONTEXT(), args);
}

void interpret_statements(statement_t *stmt)
{
  // "CPU" registers definitions
  DEF_NEW_CONTEXT();

  // Setup stack
  SETUP_STACK(&sp, &sb, DEFAULT_STACKSIZE);

  // Setup heap
  SETUP_HEAP(&hp, &hb, DEFAULT_HEAPSIZE);

  // Setup namespaces
  setup_namespaces();

  interpret_statements_(stmt, PROVIDE_CONTEXT_INIT(), NULL);

  // Close namespaces
  close_namespaces();

  // free heap
  FREE_HEAP(hp, hb);

  // Free stack
  FREE_STACK(sp, sb);

  // Free memory associated with the AST
  free_ast(stmt);
}

void setup_namespaces() {
  funcDecs = hashtable_new(100, 0.8);
  assert(funcDecs != NULL);
  varDecs = hashtable_new(200, 0.8);
  assert(varDecs != NULL);
  parameters = hashtable_new(20, 0.8);
  assert(parameters != NULL);
}

void close_namespaces() {
  hashtable_free(funcDecs);
  hashtable_free(varDecs);
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

void flush_parameters()
{
  if ( parameters != NULL ) {
    hashtable_free(parameters);
    parameters = hashtable_new(20, 0.8);
    assert(parameters != NULL);
  }
}