#include "eval.h"
#include <stdarg.h>

jmp_buf endingJmpBuf;

#if 0
/* I define and use this function during debugging of the interpreter */
static void debugPrint(char *format, ...) {
  char buffer[100];
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, sizeof(buffer), format, args);
  va_end(args);
  printf("-- DEBUG: %s", buffer);
}
#endif

void push_stackval(stackval_t *stackval, void *sp, size_t *sc) {
  stackval_t sv = *stackval;
    /* Push value to the stack */
  switch (sv.type) {
    case INT32TYPE: {
      PUSH_INT(sv.i, sp, sc);
      break;
    }
    case DOUBLETYPE: {
      PUSH_DOUBLE(sv.d, sp, sc);
      break;
    }
    case TEXT: {
      PUSH_STRING(sv.t, sp, sc);
      break;
    }
    case POINTERTYPE: {
      PUSH_POINTER(sv.p, sp, sc);
      break;
    }
    case VECTORTYPE: {
      PUSH_VECTOR(sv.vec, sp, sc);
      break;
    }
    case FUNCPTRTYPE: {
      PUSH_FUNCPTR(sv.func, sp, sc);
      break;     
    }
    case LIBFUNCPTRTYPE: {
      PUSH_LIBFUNCPTR(sv.libfunc, sp, sc);
      break;
    }
    case DICTTYPE: {
      PUSH_DICTIONARY(sv.dict, sp, sc);
      break;
    }
    case CLASSTYPE: {
      PUSH_CLASSREF(sv.classObj, sp, sc);
      break;
    }
    case TIMETYPE: {
      PUSH_TIME(sv.time, sp, sc);
      break;
    }
    case RAWDATATYPE: {
      PUSH_RAWDATA(sv.rawdata, sp, sc);
      break;
    }
    default:
      fprintf(stderr, "error: Unknown stackval_t type: %d\n", sv.type);
      exit(1);
      break;
  }
}

void push_heapval(heapval_t *hv, void *sp, size_t *sc) {
  if ( hv != NULL ) {
    switch ( hv->sv.type ) {
    case DOUBLETYPE:
      PUSH_DOUBLE(hv->sv.d, sp, sc);
      break;
    case POINTERTYPE:
      PUSH_POINTER(hv->sv.p, sp, sc);
      break;
    case VECTORTYPE:
      PUSH_VECTOR(hv->sv.vec, sp, sc);
      break;
    case INT32TYPE:
      PUSH_INT(hv->sv.i, sp, sc);
      break;
    case LIBFUNCPTRTYPE:
      PUSH_LIBFUNCPTR(hv->sv.libfunc, sp, sc);
      break;
    case FUNCPTRTYPE:
      PUSH_FUNCPTR(hv->sv.func, sp, sc);
      break;
    case DICTTYPE:
      PUSH_DICTIONARY(hv->sv.dict, sp, sc);
      break;
    case CLASSTYPE:
      PUSH_CLASSREF(hv->sv.classObj, sp, sc);
      break;
    case TIMETYPE:
      PUSH_TIME(hv->sv.time, sp, sc);
      break;
    case RAWDATATYPE:
      PUSH_RAWDATA(hv->sv.rawdata, sp, sc);
      break;
    case TEXT: {
      PUSH_STRING(hv->sv.t, sp, sc);
      break;
    }
    default:
      break;
    }
  }
}

int evaluate_condition(ifCondition_t *cond,
  EXPRESSION_PARAMS())
{
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  int32_t *ax = PROVIDE_CONTEXT()->ax;
  double *f0 = PROVIDE_CONTEXT()->f0;
  double *f1 = PROVIDE_CONTEXT()->f1;
  /* Will set ax either 1 or 0 (or interrupt the program on error) */
  stackval_t svLeft;
  stackval_t svRight;

  /* Arbitrary double resoultion, not sure what to set this to */
  double epsilon = 0.00001;

  evaluate_expression(cond->left, EXPRESSION_ARGS());
  POP_VAL(&svLeft, sp, sc);

  evaluate_expression(cond->right, EXPRESSION_ARGS());
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
    } else if ( svLeft.type == TEXT && svRight.type == TEXT ) {
      *ax = !(strcmp(svLeft.t, svRight.t) == 0);
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

      if ( *f0 - *f1 < -epsilon || fabs(*f0 - *f1) < epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f1 = (double) svRight.i;

      if ( svLeft.d - *f1 < -epsilon || fabs(svLeft.d - *f1) < epsilon ) {
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

      if ( *f0 - *f1 > epsilon || fabs(*f0 - *f1) < epsilon ) {
        *ax = 1;
      } else {
        *ax = 0;
      }
    } else if ( svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE ) {
      *f1 = (double) svRight.i;

      if ( svLeft.d - *f1 > epsilon || fabs(svLeft.d - *f1) < epsilon ) {
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

void free_vector(vector_t *vec) {
  /*argsList_t *walk = vec->content;

  while ( walk != NULL ) {
    if ( walk->arg != NULL ) {
      free_expression(walk->arg);
    }
    walk->arg = NULL;
    walk = walk->next;
  }*/
}

expr_t*  copy_vector(
  vector_t *vec,
  EXPRESSION_PARAMS()) {
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *sp = PROVIDE_CONTEXT()->sp;
  // The idea is to create a new vector based on
  // a raw one, where all identifiers have been replaced
  // with their actual value
  expr_t *newVec = newExpr_Vector(NULL);
  argsList_t *newContent = NULL;
  argsList_t *walk = vec->content;
  statement_t *forEach = vec->forEach;

  if ( walk != NULL ) {
    argsList_t *prev = NULL;
    argsList_t *current;
    argsList_t *walknext;

    while ( walk != NULL ) {
      stackval_t sv;
      expr_t *newExp;
      evaluate_expression(walk->arg, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      switch (sv.type) {
      case INT32TYPE:
        newExp = newExpr_Ival(sv.i);
        break;
      case DOUBLETYPE:
        newExp = newExpr_Float(sv.d);
        break;
      case TEXT:
        newExp = newExpr_Text(sv.t);
        break;
      case TIMETYPE:
        newExp = newExpr_Time(sv.time);
        break;
      case POINTERTYPE:
        newExp = newExpr_Pointer(sv.p);
        break;
      case FUNCPTRTYPE:
        newExp = newExpr_FuncPtr(sv.func);
        break;
      case LIBFUNCPTRTYPE:
        newExp = newExpr_LibFuncPtr(sv.libfunc);
        break;
      case VECTORTYPE: {
        newExp = copy_vector(sv.vec, EXPRESSION_ARGS());
        break;
      }
      default:
        printf("%s.error: unknown type of value on the stack (%d)\n", 
          __func__, sv.type);
        GENERAL_REPORT_ISSUE_MSG();
        break;
      }

      newContent = newArgument(newExp, newContent);
      newVec->vec->length++;
      newVec->vec->content = newContent;

      walk = walk->next;
    }

    /* Reverse the order of the vector expressions */
    /* Reverse the args list order */
    prev = NULL;
    current = newVec->vec->content;
    while (current != NULL) {
      walknext = current->next;
      current->next = prev;
      prev = current;
      current = walknext;
    }

    newVec->vec->content = prev;

  } else if ( forEach != NULL ) {
    void *sp;
    size_t *sc = PROVIDE_CONTEXT()->sc;
    locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
    size_t stackCount = *sc;
    stackval_t sv;
    int *interactive = PROVIDE_CONTEXT()->interactive;
    int interactiveTmp = *interactive;

    /* Moving along, interpreting function */
    int localsStackSp = varLocals->sp;
    int localsStackSb = varLocals->sb;
    varLocals->sb = varLocals->sp;

    *interactive = INTERACTIVE_STACK;

    interpret_statements_(forEach, PROVIDE_CONTEXT(), NULL, NULL);
    
    varLocals->sb = localsStackSb;
    varLocals->sp = localsStackSp;

    sp = PROVIDE_CONTEXT()->sp;
    sc = PROVIDE_CONTEXT()->sc;
    *interactive = interactiveTmp;

    /* Printing result of computation */
    while ( *sc > stackCount ) {
      expr_t *newExp;
      POP_VAL(&sv, sp, sc);

      switch (sv.type) {
      case INT32TYPE:
        newExp = newExpr_Ival(sv.i);
        break;
      case DOUBLETYPE:
        newExp = newExpr_Float(sv.d);
        break;
      case TEXT:
        newExp = newExpr_Text(sv.t);
        break;
      case TIMETYPE:
        newExp = newExpr_Time(sv.time);
        break;
      case POINTERTYPE:
        newExp = newExpr_Pointer(sv.p);
        break;
      case FUNCPTRTYPE:
        newExp = newExpr_FuncPtr(sv.func);
        break;
      case LIBFUNCPTRTYPE:
        newExp = newExpr_LibFuncPtr(sv.libfunc);
        break;
      case VECTORTYPE: {
        newExp = copy_vector(sv.vec, EXPRESSION_ARGS());
        break;
      }
      default:
        printf("%s.error: unknown type of value on the stack (%d)\n", 
          __func__, sv.type);
        GENERAL_REPORT_ISSUE_MSG();
        break;
      }

      newContent = newArgument(newExp, newContent);
      newVec->vec->length++;
      newVec->vec->content = newContent;
    }
  }

  return newVec;
}


void evaluate_expression(
  expr_t *expr,
  EXPRESSION_PARAMS())
{
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  class_t *classCtx = PROVIDE_CONTEXT()->classCtx;
  locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
  int *interactive = PROVIDE_CONTEXT()->interactive;
  double *f0 = PROVIDE_CONTEXT()->f0;
  double *f1 = PROVIDE_CONTEXT()->f1;
  int32_t *r0 = PROVIDE_CONTEXT()->r0;
  int32_t *r1 = PROVIDE_CONTEXT()->r1;
  int32_t *ax = PROVIDE_CONTEXT()->ax;
  if ( expr == NULL )
    return;
  switch (expr->type) 
  {
    case EXPR_TYPE_ID:
    {
      heapval_t *hv = NULL;
      int stop = 0;

      /* Check if this ID is among the arguments */
      argsList_t *walk = args;

      while ( walk != NULL && !stop ) {
        expr_t *exp = walk->arg;
        if ( exp->type == EXPR_TYPE_ID ) {
          expr_t *expArg;

          /* Check among the arguments if we have it defined there */
          expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, expr->id.id);

          if ( expArg != NULL ) {
            /* This was an argument! */
            switch ( expArg->type ) {
            case EXPR_TYPE_IVAL:
              PUSH_INT(expArg->ival, sp, sc);
              break;
            case EXPR_TYPE_POINTER:
              PUSH_POINTER(expArg->p, sp, sc);
              break;
            case EXPR_TYPE_VECTOR:
              PUSH_VECTOR(expArg->vec, sp, sc);
              break;
            case EXPR_TYPE_CLASSPTR:
              PUSH_CLASSREF(expArg->classObj, sp, sc);
              break;
            case EXPR_TYPE_FVAL:
              PUSH_DOUBLE(expArg->fval, sp, sc);
              break;
            case EXPR_TYPE_FUNCPTR:
              PUSH_FUNCPTR(expArg->func, sp, sc);
              break;
            case EXPR_TYPE_LIBFUNCPTR:
              PUSH_LIBFUNCPTR(expArg->func, sp, sc);
              break;
            case EXPR_TYPE_TIME:
              PUSH_TIME(expArg->time, sp, sc);
              break;
            case EXPR_TYPE_RAWDATA:
              PUSH_RAWDATA(expArg->rawdata, sp, sc);
              break;
            case EXPR_TYPE_DICT:
              PUSH_DICTIONARY(expArg->dict, sp, sc);
              break;
            case EXPR_TYPE_TEXT:
            {
              PUSH_STRING(expArg->text, sp, sc);
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
          fprintf(stderr, "error: unknown, this is crazy. The interpreter is broken or something.\n\
Please report back to me.\n\
- %s\n", GENERAL_ERROR_ISSUE_URL);
          exit(1);
        }

        walk = walk->next;
      }

      if ( stop ) {
        break;
      }

      /* Check if it is among the class context members */
      if ( classCtx != NULL ) {
        functionDef_t *classFunc = NULL;
        hv = hashtable_get(classCtx->varMembers, PROVIDE_CONTEXT()->syncCtx, expr->id.id);

        if ( hv != NULL ) {
          push_heapval(hv, sp, sc);
          stop = 1;
        }

        classFunc = hashtable_get(classCtx->funcDefs, PROVIDE_CONTEXT()->syncCtx, expr->id.id);
        if ( classFunc != NULL ) {
          // Pushing the function definition
          PUSH_FUNCPTR(classFunc, sp, sc);
          stop = 1;
        }

      }

      if ( !stop && walk == NULL ) {
        class_t *classDef; // if it is a class construction reference
        functionDef_t *funcDef; // if it is a function pointer

        /* Check among the global variables if we have it defined there */
        hv = hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, expr->id.id);

        if ( hv == NULL ) {
          /* Check among the locals if we have it defined there */
          hv = locals_lookup(varLocals, expr->id.id);
        }

        if ( hv != NULL ) {
          push_heapval(hv, sp, sc);
          stop = 1;
        }

        if ( stop ) {
          break;
        }
        /* Check among the class declaration if we have this id defined there */
        classDef = hashtable_get(PROVIDE_CONTEXT()->classDecs, PROVIDE_CONTEXT()->syncCtx, expr->id.id);
        if ( classDef != NULL ) {
          PUSH_CLASSREF(classDef, sp, sc);
          stop = 1;
        }

        if ( !stop ) {
          /* Check among the function declarations if we have it defined there */
          funcDef = hashtable_get(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, expr->id.id);
          if ( funcDef != NULL ) {
            // Pushing the function definition
            PUSH_FUNCPTR(funcDef, sp, sc);
            stop = 1;
          }
        }

        if ( !stop ) {
           /* Check among the standard lib function declarations if we have it defined there */
          libFunction_t *libFunc = look_up_lib(expr->id.id);

          if ( libFunc != NULL ) {
            PUSH_LIBFUNCPTR(libFunc, sp, sc);
            stop = 1;
          } else {
            fprintf(stderr, "Failed to find ID: '%s'\n", expr->id.id);
            if ( ! *interactive ) {
              exit(1);
            }
          }
        }

      }

      break;
    }
    case EXPR_TYPE_POINTER:
    PUSH_POINTER(expr->p, sp, sc);
    break;
    case EXPR_TYPE_FVAL:
    PUSH_DOUBLE(expr->fval, sp, sc);
    break;
    case EXPR_TYPE_FUNCPTR:
    PUSH_FUNCPTR(expr->func, sp, sc);
    break;
    case EXPR_TYPE_LIBFUNCPTR:
    PUSH_LIBFUNCPTR(expr->func, sp, sc);
    break;
    case EXPR_TYPE_VECTOR:
    PUSH_VECTOR(expr->vec, sp, sc);
    break;
    case EXPR_TYPE_DICT:
    PUSH_DICTIONARY(expr->dict, sp, sc);
    break;
    case EXPR_TYPE_RAWDATA:
    PUSH_RAWDATA(expr->rawdata, sp, sc);
    break;
    case EXPR_TYPE_VECTOR_IDX:
    {
      int32_t arrayIndex = 0;
      vector_t *vec = NULL;
      dictionary_t *dict = NULL;
      argsList_t *walk;
      char *text = NULL;
      rawdata_t *rawdata = NULL;
      int typeOfVal = 0;
      expr_t *exp = NULL;
      expr_t *id = expr->vecIdx->id;
      expr_t *index = expr->vecIdx->index;

      stackval_t sv;

      if ( id->type == EXPR_TYPE_ID || id->type == EXPR_TYPE_VECTOR_IDX ) {
        evaluate_expression(id, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);

        if (
          sv.type != VECTORTYPE &&
          sv.type != DICTTYPE &&
          sv.type != TEXT &&
          sv.type != RAWDATATYPE
        ) {
          fprintf(stderr, "%s.%d index error: '%s' is a datatype the does not support indexing.\n",
            ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, id->id.id);
          if ( ! *interactive ) {
            exit(1);
          }
        }

        typeOfVal = sv.type;
        if ( sv.type == VECTORTYPE ) {
          vec = sv.vec;
        } else if ( sv.type == DICTTYPE ) {
          dict = sv.dict;
        } else if ( sv.type == TEXT ) {
          text = sv.t;
        } else if ( sv.type == RAWDATATYPE ) {
          rawdata = sv.rawdata;
        }
      } else {
        fprintf(stderr, "error: Invalid indexing\n");
        exit(1);
      }

      switch ( typeOfVal ) {
        case DICTTYPE: {
          /* Dictionary indexing */
          char *key = NULL;
          heapval_t *hpv;

          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if ( sv.type != TEXT ) {
            fprintf(stderr, "index error: Must provide an string as index for dictionaries\n");
            exit(1);
          }

          key = sv.t;

          /* find heapval */
          hpv = hashtable_get(dict->hash, PROVIDE_CONTEXT()->syncCtx, key);
          if ( hpv == NULL ) {
            fprintf(stderr, "error: key '%s' not present in dictionary\n", key);
            exit(1);
          }

          sv = hpv->sv;

          /* Push value to the stack */
          switch (sv.type) {
            case INT32TYPE: {
              PUSH_INT(sv.i, sp, sc);
              break;
            }
            case DOUBLETYPE: {
              PUSH_DOUBLE(sv.d, sp, sc);
              break;
            }
            case TEXT: {
              PUSH_STRING(sv.t, sp, sc);
              break;
            }
            case POINTERTYPE: {
              PUSH_POINTER(sv.p, sp, sc);
              break;
            }
            case VECTORTYPE: {
              PUSH_VECTOR(sv.vec, sp, sc);
              break;
            }
            case FUNCPTRTYPE: {
              PUSH_FUNCPTR(sv.func, sp, sc);
              break;     
            }
            case LIBFUNCPTRTYPE: {
              PUSH_LIBFUNCPTR(sv.libfunc, sp, sc);
              break;
            }
            case DICTTYPE: {
              PUSH_DICTIONARY(sv.dict, sp, sc);
              break;
            }
            case CLASSTYPE: {
              PUSH_CLASSREF(sv.classObj, sp, sc);
              break;
            }
            case TIMETYPE: {
              PUSH_TIME(sv.time, sp, sc);
              break;
            }
            case RAWDATATYPE: {
              PUSH_RAWDATA(sv.rawdata, sp, sc);
              break;
            }
            default:
              fprintf(stderr, "error: Unknown stackval_t type: %d\n", sv.type);
              exit(1);
              break;
          }

        }
        break;
        case VECTORTYPE: {
          /* Array indexing */
          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if ( sv.type != INT32TYPE ) {
            fprintf(stderr, "index error: Must provide an integer as index\n");
            exit(1);
          }

          arrayIndex = sv.i;

          /* check the limits */
          if ( arrayIndex >= vec->length ) {
            fprintf(stderr, "index error: index: '%" PRIi32 "' is too large, length: '%" PRIi32 "'\n",
              arrayIndex,
              vec->length);
            exit(1);
          }

          walk = vec->content;
          while ( walk != NULL && arrayIndex >= 0 ) {
            exp = walk->arg;
            walk = walk->next;
            --arrayIndex;
          }

          if ( exp == NULL ) {
            fprintf(stderr, "Unexpected index error!\n");
            fprintf(stderr, "Please include the script and file an error report to me here:\n    %s\n\
    This is not supposed to happen, I hope I can fix the intepreter!\n", GENERAL_ERROR_ISSUE_URL);
            exit(1);
          }

          /* Evaluate the expression */
          evaluate_expression(exp, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          /* Push value to the stack */
          switch (sv.type) {
            case INT32TYPE: {
              PUSH_INT(sv.i, sp, sc);
              break;
            }
            case DOUBLETYPE: {
              PUSH_DOUBLE(sv.d, sp, sc);
              break;
            }
            case TEXT: {
              PUSH_STRING(sv.t, sp, sc);
              break;
            }
            case POINTERTYPE: {
              PUSH_POINTER(sv.p, sp, sc);
              break;
            }
            case VECTORTYPE: {
              PUSH_VECTOR(sv.vec, sp, sc);
              break;
            }
            case FUNCPTRTYPE: {
              PUSH_FUNCPTR(sv.func, sp, sc);
              break;     
            }
            case LIBFUNCPTRTYPE: {
              PUSH_LIBFUNCPTR(sv.libfunc, sp, sc);
              break;
            }
            case DICTTYPE: {
              PUSH_DICTIONARY(sv.dict, sp, sc);
              break;
            }
            case CLASSTYPE: {
              PUSH_CLASSREF(sv.classObj, sp, sc);
              break;
            }
            case TIMETYPE: {
              PUSH_TIME(sv.time, sp, sc);
              break;
            }
            case RAWDATATYPE: {
              PUSH_RAWDATA(sv.rawdata, sp, sc);
              break;
            }
            default:
              fprintf(stderr, "error: Unknown stackval_t type: %d\n", sv.type);
              exit(1);
              break;
          }
        }
        break;
        case TEXT: {
          size_t len = 1;
          stackval_t sv;
          heapval_t *hvp;
          int heapUpdated;
          char *newText = NULL;

          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if ( sv.type != INT32TYPE ) {
            fprintf(stderr, "index error: Must provide an integer as index (%d)\n", sv.type);
            exit(1);
          }

          arrayIndex = sv.i;

          if ( arrayIndex > strlen(text) ) {
            fprintf(stderr, "index error: out of bounds\n");
            exit(1);
          }

          newText = ast_emalloc(len+1);
          newText[0] = text[arrayIndex];
          newText[1] = 0;
          sv.type = TEXT;
          sv.t = newText;

          ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);
          PUSH_STRING(sv.t, sp, sc);
        }
        break;
        case RAWDATATYPE: {
          stackval_t sv;

          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if ( sv.type != INT32TYPE ) {
            fprintf(stderr, "index error: Must provide an integer as index (%d)\n", sv.type);
            exit(1);
          }

          arrayIndex = sv.i;

          if ( arrayIndex > rawdata->size ) {
            fprintf(stderr, "index error: out of bounds\n");
            exit(1);
          }

          sv.type = INT32TYPE;
          sv.i = ((unsigned char*)rawdata->data)[arrayIndex];

          PUSH_INT(sv.i, sp, sc);
        }
        break;
        default:
        break;
      }

    }
    break;
    case EXPR_TYPE_IVAL:
    PUSH_INT(expr->ival, sp, sc);
    break;
    case EXPR_TYPE_UVAL:
    PUSH_INT(expr->uval, sp, sc);
    break;
    case EXPR_TYPE_TIME:
    PUSH_TIME(expr->time, sp, sc);
    break;
    case EXPR_TYPE_TEXT: {
      PUSH_STRING(expr->text, sp, sc);
      break;
    }
    break;
    case EXPR_TYPE_OPADD:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, EXPRESSION_ARGS());
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
        case RAWDATATYPE: {
          /* Interpret as text */
          svLeft.type = TEXT;
          svLeft.t = svLeft.rawdata->data;
        }
        case TEXT:
        case VECTORTYPE:
        case POINTERTYPE:
        case TIMETYPE:
          break;
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svLeft.type);
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
        case RAWDATATYPE: {
          /* Interpret as text */
          svRight.type = TEXT;
          svRight.t = svRight.rawdata->data;
        }
        case TEXT:
        case VECTORTYPE:
        case POINTERTYPE:
        case TIMETYPE:
          break;
        default:
          fprintf(stderr, "error %s.%d: Unexpected stackval_t type: %d\n",
            ((statement_t*) stmt)->file, ((statement_t*) stmt)->line, svRight.type);
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
      } else if ( svLeft.type == TIMETYPE && svRight.type == TIMETYPE ) {
        PUSH_DOUBLE(svLeft.time + svRight.time, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == TEXT ) {
        size_t len = strlen(svLeft.t) + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s%s", svLeft.t, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == DOUBLETYPE && svRight.type == TEXT ) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%.4f%s", svLeft.d, svRight.t);

        sv.type = TEXT;
        sv.t = newText;
  
        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == DOUBLETYPE ) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s%.4f", svLeft.t, svRight.d);

        sv.type = TEXT;
        sv.t = newText;
  
        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == INT32TYPE ) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s%d", svLeft.t, svRight.i);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == INT32TYPE && svRight.type == TEXT ) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%d%s", svLeft.i, svRight.t);

        sv.type = TEXT;
        sv.t = newText;
  
        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == POINTERTYPE && svRight.type == TEXT ) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "<%" PRIuPTR ">%s", svLeft.p, svRight.t);

        sv.type = TEXT;
        sv.t = newText;
  
        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == POINTERTYPE ) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s<%" PRIuPTR ">", svLeft.t, svRight.p);

        sv.type = TEXT;
        sv.t = newText;
  
        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == VECTORTYPE && svRight.type == TEXT ) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "<List:size=%" PRIi32 ">%s", svLeft.vec->length, svRight.t);

        sv.type = TEXT;
        sv.t = newText;
  
        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if ( svLeft.type == TEXT && svRight.type == VECTORTYPE ) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s<List:size=%" PRIi32 ">", svLeft.t, svRight.vec->length);

        sv.type = TEXT;
        sv.t = newText;
  
        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if ( !heapUpdated ) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      }

      break;
    }
    break;
    case EXPR_TYPE_OPSUB:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, EXPRESSION_ARGS());
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
          fprintf(stderr, "error: Cannot substract strings..\n");
          exit(1);
          break;
        }
        case TIMETYPE:
        break;
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svLeft.type);
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
          fprintf(stderr, "error: Cannot substract strings..\n");
          exit(1);
          break;
        }
        case TIMETYPE:
        break;
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
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
      } else if ( svLeft.type == TIMETYPE && svRight.type == TIMETYPE ) {
        PUSH_TIME(svLeft.time - svRight.time, sp, sc);
      }

      break;
    }
    case EXPR_TYPE_OPMUL:
    {
      stackval_t svLeft;
      stackval_t svRight;
      char *leftStr = NULL;

      evaluate_expression((expr_t*)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, EXPRESSION_ARGS());
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
          leftStr = svLeft.t;
          break;
        }
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svLeft.type);
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

          if ( leftStr != NULL ) {
            fprintf(stderr, "error: Cannot multiply string with float\n");
            exit(1);
          }
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Cannot multiply strings..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
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
      } else if ( svLeft.type == TEXT && svRight.type == INT32TYPE ) {
        heapval_t *hpv;
        stackval_t stv;
        size_t strLen = strlen(leftStr);
        int32_t mult = *r1;
        int32_t i = 0;
        int dummy;
        char *newStr = ast_emalloc(strLen*mult + 2);

        while ( i < mult ) {
          snprintf(newStr+(i*strLen), strLen+1, "%s", leftStr);
          ++i;
        }

        if ( mult == 0 )
          newStr[0] = 0;

        newStr[(mult * strLen) + 1] = 0;

        stv.type = TEXT;
        stv.t = newStr;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);

        PUSH_STRING(stv.t, sp, sc);
      }

      break;
    }
    case EXPR_TYPE_OPMOD:
    {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t*)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, EXPRESSION_ARGS());
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
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svLeft.type);
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
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
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

      evaluate_expression((expr_t*)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t*)expr->add.right, EXPRESSION_ARGS());
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
          fprintf(stderr, "error: Not implemented string additions yet..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svLeft.type);
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
          fprintf(stderr, "error: Not implemented string additions yet..\n");
          exit(1);
          break;
        }
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
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
      evaluate_condition(expr->cond, stmt, next, PROVIDE_CONTEXT(), args, argVals);
      /* Push ax to stack */
      PUSH_INT(*ax, sp, sc);
      break;
    }
    case EXPR_TYPE_FUNCCALL:
    {
      stackval_t sv;
      functionCallContainer_t func;

      func.type = FUNC_CALL_TYPE_GLOBAL;
      func.globalCall = expr->func;

      call_func(&func, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);
      push_stackval(&sv, sp, sc);
      break;
    }
    case EXPR_TYPE_CLASSFUNCCALL:
    {
      stackval_t sv;
      functionCallContainer_t func;

      func.type = FUNC_CALL_TYPE_CLASS;
      func.classCall = (classFunctionCall_t *) expr->func;

      call_func(&func, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);
      push_stackval(&sv, sp, sc);
      break;
    }
    case EXPR_TYPE_EMPTY:
    default:
    break;
  }
}

/* Check if ID is valid */
int evaluate_id_valid(
  char *id,
  EXPRESSION_PARAMS())
{
  locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
  heapval_t *hv = NULL;
  /* Check if this ID is among the arguments */
  argsList_t *walk = args;

  if ( id == NULL )
    return 0;

  while ( walk != NULL ) {
    expr_t *exp = walk->arg;
    if ( exp->type == EXPR_TYPE_ID ) {
      expr_t *expArg;

      /* Check among the arguments if we have it defined there */
      expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, id);

      if ( expArg != NULL ) {
        /* This was an argument, ID ok! */
        return 1;
      }
    }

    walk = walk->next;
  }

  if ( walk == NULL ) {
    functionDef_t *funcDef; // if it is a function pointer

    /* Check among the global variables if we have it defined there */
    hv = hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, id);

    if ( hv == NULL ) {
      /* Check among the locals if we have it defined there */
      hv = locals_lookup(varLocals, id);
    }

    if ( hv != NULL ) {
      return 1;
    }

    /* Check among the function declarations if we have it defined there */
    funcDef = hashtable_get(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, id);
    if ( funcDef != NULL ) {
      // Pushing the function definition
      return 1;
    }

    /* Check among the standard lib function declarations if we have it defined there */
    libFunction_t *libFunc = look_up_lib(id);

    if ( libFunc != NULL ) {
      return 1;
    }
  }

  /* Failed to find the id*/
  return 0;
}


void call_func(
  functionCallContainer_t *func,
  EXPRESSION_PARAMS())
{
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
  int *depth = PROVIDE_CONTEXT()->depth;
  class_t *classCtx = PROVIDE_CONTEXT()->classCtx;
  functionDef_t *funcDef = NULL;
  functionCall_t *funcCall = NULL;
  classFunctionCall_t *classCall = NULL;
  argsList_t *argsWalk = NULL;
  hashtable_t *newArgumentTable = new_argstable();
  stackval_t sv;
  stackval_t sv_ret;
  expr_t *expArg;
  int stop = 0;
  class_t *classRef = NULL;
  libFunction_t *libFunc = NULL;
  char *funcID = NULL;

  if ( func->type == FUNC_CALL_TYPE_GLOBAL ) {
    /* Calling a global function */
    funcCall = func->globalCall;
    argsWalk = funcCall->args;

    /* Evaluate id */
    evaluate_expression(funcCall->id, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    switch ( sv.type ) {
    case TEXT:
      funcID = sv.t;
      break;
    case CLASSTYPE:
      classRef = sv.classObj;
      funcID = sv.classObj->id;
      break;
    case FUNCPTRTYPE: {
      functionDef_t *func = sv.func;
      funcID = func->id.id;
      break;
    }
    case LIBFUNCPTRTYPE: {
      libFunction_t *func = sv.libfunc;
      funcID = func->libFuncName;
      break;
    }
    default:
      fprintf(stderr, "error: invalid function call (%d)\n", sv.type);
      exit(1);
      break;
    }

    /* Check if this is a class construction call */
    classRef = hashtable_get(PROVIDE_CONTEXT()->classDecs, PROVIDE_CONTEXT()->syncCtx, funcID);
    if ( classRef != NULL ) {
      functionDef_t *constructor = NULL;
      class_t *class = NULL;
      /* Create a new instance, place it on the heap */
      expr_t *classObj = newExpr_ClassPtr(classRef);
      class = classObj->classObj;
      free(classObj);  // expression container not needed
      /* Run the initializer */
      initClass(class, EXPRESSION_ARGS());
      /* Find the constructor hook and run it if so */
      constructor = hashtable_get(class->funcDefs, PROVIDE_CONTEXT()->syncCtx, funcID);
      if ( constructor != NULL ) {
        exeCtx->classCtx = class;
        /* Moving along, interpreting function */
        int localsStackSp = varLocals->sp;
        int localsStackSb = varLocals->sb;
        varLocals->sb = varLocals->sp;
        *depth = 1;  // There is only one global scope
        interpret_statements_(constructor->body, PROVIDE_CONTEXT(), NULL, NULL);
        varLocals->sb = localsStackSb;
        varLocals->sp = localsStackSp;
      }
      PUSH_CLASSREF(class, sp, sc);
      stop = 1;
      flush_arguments(newArgumentTable);
    }

    if ( !stop && classCtx != NULL ) {
      /* Check if this is a function member call */
      functionDef_t *classFunc = hashtable_get(classCtx->funcDefs, PROVIDE_CONTEXT()->syncCtx, funcID);
      /* Call the function */
      if ( classFunc ) {
        uintptr_t spBefore;
        /* Check that # parameters == # arguments */
        argsList_t *params = classFunc->params;
        int localsStackSp;
        int localsStackSb;

        /* Default return type: a zero */
        sv_ret.type = INT32TYPE;
        sv_ret.i = 0;

        spBefore = *(uintptr_t*)sp;

        if ( params == NULL && argsWalk != NULL ) {
          fprintf(stderr, "Error: function '%s' expected 0 arguments, got: %u\n",
            funcID, argsWalk->length );
          exit(1);
        }

        if ( params != NULL && argsWalk == NULL ) {
          fprintf(stderr, "Error: function '%s' expected %u arguments, got: 0\n",
            funcID, params->length );
          exit(1);
        }

        if ( params != NULL && argsWalk != NULL )  {
          /* Verifying function definition parameters and function call arguments */
          if ( params->length != argsWalk->length ) {
            /* print error message */
            fprintf(stderr, "Error: function '%s' expected %u arguments, got: %u\n",
              funcID, params->length, argsWalk->length);
            exit(1);
          }

          /* Populate arguments */
          while ( argsWalk != NULL && params != NULL ) {
            stackval_t sv;
            expr_t *newArg = NULL;

            if ( params->arg->type != EXPR_TYPE_ID ) {
              /* This is not supposed to happen */
              printf("Error: parameter in function definition '%s' was invalid\n",
                funcID);
            }

            /* Evaluate expression */
            evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());
            
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
              case POINTERTYPE: {
                newArg = newExpr_Pointer(sv.p);
                break;
              }
              case VECTORTYPE: {
                newArg = newExpr_Vector(sv.vec->content);
                break;
              }
              case FUNCPTRTYPE: {
                newArg = newExpr_FuncPtr(sv.func);
                break;
              }
              case TIMETYPE: {
                newArg = newExpr_Time(sv.time);
                break;
              }
              case LIBFUNCPTRTYPE: {
                newArg = newExpr_LibFuncPtr(sv.libfunc);
                break;
              }
              case RAWDATATYPE: {
                expr_t *e = newExpr_RawData(sv.rawdata->size);
                memcpy(e->rawdata->data, sv.rawdata->data, sv.rawdata->size);
                newArg = e;
                break;
              }
              case DICTTYPE: {
                expr_t *e = ast_emalloc(sizeof(expr_t));
                e->type = EXPR_TYPE_DICT;
                e->dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
                newArg = e;
                break;
              }
              default:
                fprintf(stderr, "error: sorry but argument datatype cannot be passed to a function, type: %d\n", sv.type);
                exit(1);
                break;
            }

            /* Adding expression to argument table */
            hashtable_put(newArgumentTable, PROVIDE_CONTEXT()->syncCtx, params->arg->id.id, newArg);

            params = params->next;
            argsWalk = argsWalk->next;
          }

        }

        /* Moving along, interpreting function */
        localsStackSp = varLocals->sp;
        localsStackSb = varLocals->sb;
        varLocals->sb = varLocals->sp;
        *depth = 1;  // There is only one global scope
        interpret_statements_(classFunc->body, PROVIDE_CONTEXT(), classFunc->params, newArgumentTable);
        varLocals->sb = localsStackSb;
        varLocals->sp = localsStackSp;
        if ( *(uintptr_t*)sp != spBefore ) {
          /* Return statement found, pop return value */
          POP_VAL(&sv_ret, sp, sc);
        }
        
        /* Push function return value to the stack */
        push_stackval(&sv_ret, sp, sc);

        /* Free the argument value table */
        flush_arguments(newArgumentTable);

        stop = 1;
      }
    }

    if ( ! stop ) {
      /* Check among the arguments if we have it defined there */
      expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, funcID);

      /* The argument might be a function! Evaluate and see ... */
      if ( expArg != NULL && classRef == NULL ) {
        /* This was an argument! */
        switch ( expArg->type ) {
        case EXPR_TYPE_FUNCPTR:
          funcDef = expArg->func;
          break;
        case EXPR_TYPE_LIBFUNCPTR:
          libFunc = expArg->func;
          break;
        default:
          fprintf(stderr, "error: Invalid usage of identifier '%s'\n", expArg->id.id);
          exit(1);
          break;
        }

      }

      if ( funcDef == NULL && libFunc == NULL && classRef == NULL ) {
        /* Looking up the function and calling it if it exists */
        funcDef = hashtable_get(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, funcID);
        /* Looking up the function among the library */
        libFunc = look_up_lib(funcID);

        /* Check lookup status */
        if ( funcDef == NULL && libFunc == NULL ) {
          heapval_t *hv;
          /* Check if this is a function pointer call (lowest priority) */
          hv = hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, funcID);

          if ( hv == NULL ) {
            // Check among the arguments 

            /* Check among the arguments if we have it defined there */
            expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, funcID);

            if ( expArg == NULL ) {
              fprintf(stderr, "Error: Function call undefined: '%s'.\r\n", funcID);
              exit(1);
            }

            /* The argument might be a function! Evaluate and see ... */
            if ( expArg != NULL ) {
              /* This was an argument! */
              switch ( expArg->type ) {
              case EXPR_TYPE_FUNCCALL:
                funcDef = expArg->func;
                break;
              case EXPR_TYPE_LIBFUNCPTR:
                libFunc = expArg->func;
                break;
              default:
                fprintf(stderr, "error: Invalid usage of identifier '%s'\n", expArg->id.id);
                exit(1);
                break;
              }

            }

          } else if ( hv->sv.type != FUNCPTRTYPE && hv->sv.type != LIBFUNCPTRTYPE ) {
            fprintf(stderr, "Error: Function call undefined: '%s'.\r\n", funcID);
            exit(1);
          } else {
            switch (hv->sv.type) {
            case FUNCPTRTYPE:
              funcDef = hv->sv.func;
              break;
            case LIBFUNCPTRTYPE:
              libFunc = hv->sv.libfunc;
              break;
              default:
              // This is just not supposed to be possible, look above.
              break;
            }
          }

        }
      }

      if ( funcDef != NULL ) {
        uintptr_t spBefore;

        /* Check that # parameters == # arguments */
        argsList_t *params = funcDef->params;

        if ( params == NULL && argsWalk != NULL ) {
          fprintf(stderr, "Error: function '%s' expected 0 arguments, got: %u\n",
            funcID, argsWalk->length );
          exit(1);
        }

        if ( params != NULL && argsWalk == NULL ) {
          fprintf(stderr, "Error: function '%s' expected %u arguments, got: 0\n",
            funcID, params->length );
          exit(1);
        }

        if ( params != NULL && argsWalk != NULL )  {
          /* Verifying function definition parameters and function call arguments */
          if ( params->length != argsWalk->length ) {
            /* print error message */
            fprintf(stderr, "Error: function '%s' expected %u arguments, got: %u\n",
              funcID, params->length, argsWalk->length);
            exit(1);
          }

          /* Populate arguments */
          while ( argsWalk != NULL && params != NULL ) {
            stackval_t sv;
            expr_t *newArg = NULL;

            if ( params->arg->type != EXPR_TYPE_ID ) {
              /* This is not supposed to happen */
              printf("Error: parameter in function definition '%s' was invalid\n",
                funcID);
            }

            /* Evaluate expression */
            evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());
            
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
              case TIMETYPE: {
                newArg = newExpr_Time(sv.time);
                break;
              }
              case POINTERTYPE: {
                newArg = newExpr_Pointer(sv.p);
                break;
              }
              case VECTORTYPE: {
                newArg = newExpr_Vector(sv.vec->content);
                break;
              }
              case FUNCPTRTYPE: {
                newArg = newExpr_FuncPtr(sv.func);
                break;
              }
              case LIBFUNCPTRTYPE: {
                newArg = newExpr_LibFuncPtr(sv.libfunc);
                break;
              }
              case DICTTYPE: {
                expr_t *e = ast_emalloc(sizeof(expr_t));
                e->type = EXPR_TYPE_DICT;
                e->dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
                newArg = e;
                break;
              }
              default:
                fprintf(stderr, "error: sorry but argument datatype cannot be passed to a function, type: %d\n", sv.type);
                exit(1);
                break;
            }

            /* Adding expression to argument table */
            hashtable_put(newArgumentTable, PROVIDE_CONTEXT()->syncCtx, params->arg->id.id, newArg);

            params = params->next;
            argsWalk = argsWalk->next;
          }

        }

        /* Default return type: a zero */
        sv_ret.type = INT32TYPE;
        sv_ret.i = 0;

        spBefore = *(uintptr_t*)sp;

        /* Call the function */
        if ( funcDef ) {
          /* Moving along, interpreting function */
          int localsStackSp = varLocals->sp;
          int localsStackSb = varLocals->sb;
          varLocals->sb = varLocals->sp;
          *depth = 1;  // There is only one global scope
          interpret_statements_(funcDef->body, PROVIDE_CONTEXT(), funcDef->params, newArgumentTable);
          varLocals->sb = localsStackSb;
          varLocals->sp = localsStackSp;
        }

        if ( *(uintptr_t*)sp != spBefore ) {
          /* Return statement found, pop return value */
          POP_VAL(&sv_ret, sp, sc);
        }

        /* Push function return value to the stack */
        push_stackval(&sv_ret, sp, sc);

        /* Free the argument value table */
        flush_arguments(newArgumentTable);
      } else {
        /* This is a library function */
        int libfunc_ret;

        if ( libFunc->nbrArgs > 0 && argsWalk == NULL ) {
          fprintf(stderr, "error: library function '%s' need %d agument%s, %d provided.\n",
            funcID, libFunc->nbrArgs, (libFunc->nbrArgs == 1 ? "" : "s"), 0);
          exit(1);
        }

        if ( argsWalk != NULL && libFunc->nbrArgs != (int)argsWalk->length ) {
          fprintf(stderr, "error: library function '%s' need %d agument%s, %d provided.\n",
            funcID, libFunc->nbrArgs, (libFunc->nbrArgs == 1 ? "" : "s"), (int)argsWalk->length);
          exit(1);
        }

        /* Populate arguments */
        while ( argsWalk != NULL ) {
          stackval_t sv;

          /* Evaluate expression */
          evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());
          
          /* Fetch the evaluated expression to the arguments table */
          POP_VAL(&sv, sp, sc);

          push_stackval(&sv, sp, sc);

          argsWalk = argsWalk->next;
        }

        libfunc_ret = libFunc->func(funcID, EXPRESSION_ARGS() );

        /* Free the argument value table */
        flush_arguments(newArgumentTable);

        if ( libfunc_ret != 0 ) {
          fprintf(stderr, "Error during execution of library function '%s', error code: %d\n",
            funcID, libfunc_ret);
          exit(libfunc_ret);
        }
      }
    }
  } else if ( func->type == FUNC_CALL_TYPE_CLASS ) {
    /* Calling a class function */
    classCall = func->classCall;
    argsWalk = classCall->args;
    class_t *classObj = NULL;
    functionDef_t *funcDef = NULL;
    stackval_t sv_ret;
    uintptr_t spBefore;
    char *funcID = NULL;

    /* Evaluate class id */
    evaluate_expression(classCall->classID, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    switch ( sv.type ) {
    case CLASSTYPE:
      classObj = sv.classObj;
      break;
    default:
      fprintf(stderr, "error: invalid class function call, ID must point to a class object.\n");
      exit(1);
      break;
    }

    if ( !classObj->initialized ) {
      fprintf(stderr, "error: invalid class function call, ID must point to an initialized class object.\n");
      exit(1);
    }

    /* Evaluate class func id */
    funcID = classCall->funcID;

    /* Find the class function */
    funcDef = hashtable_get(classObj->funcDefs, PROVIDE_CONTEXT()->syncCtx, funcID);

    if ( funcDef == NULL ) {
      fprintf(stderr, "error: cannot find function '%s' in class '%s'.\n", 
        funcID, classObj->id);
      exit(1);
    }

    /* Default return type: a zero */
    sv_ret.type = INT32TYPE;
    sv_ret.i = 0;

    spBefore = *(uintptr_t*)sp;

    /* Call the function */
    if ( funcDef ) {
      /* Check that # parameters == # arguments */
      argsList_t *params = funcDef->params;
      int localsStackSp;
      int localsStackSb;
      class_t *tmp;

      if ( params == NULL && argsWalk != NULL ) {
        fprintf(stderr, "Error: function '%s' expected 0 arguments, got: %u\n",
          funcID, argsWalk->length );
        exit(1);
      }

      if ( params != NULL && argsWalk == NULL ) {
        fprintf(stderr, "Error: function '%s' expected %u arguments, got: 0\n",
          funcID, params->length );
        exit(1);
      }

      if ( params != NULL && argsWalk != NULL )  {
        /* Verifying function definition parameters and function call arguments */
        if ( params->length != argsWalk->length ) {
          /* print error message */
          fprintf(stderr, "Error: function '%s' expected %u arguments, got: %u\n",
            funcID, params->length, argsWalk->length);
          exit(1);
        }

        /* Populate arguments */
        while ( argsWalk != NULL && params != NULL ) {
          stackval_t sv;
          expr_t *newArg = NULL;

          if ( params->arg->type != EXPR_TYPE_ID ) {
            /* This is not supposed to happen */
            printf("Error: parameter in function definition '%s' was invalid\n",
              funcID);
          }

          /* Evaluate expression */
          evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());
          
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
            case TIMETYPE: {
              newArg = newExpr_Time(sv.time);
              break;
            }
            case POINTERTYPE: {
              newArg = newExpr_Pointer(sv.p);
              break;
            }
            case VECTORTYPE: {
              newArg = newExpr_Vector(sv.vec->content);
              break;
            }
            case FUNCPTRTYPE: {
              newArg = newExpr_FuncPtr(sv.func);
              break;
            }
            case LIBFUNCPTRTYPE: {
              newArg = newExpr_LibFuncPtr(sv.libfunc);
              break;
            }
            case DICTTYPE: {
              expr_t *e = ast_emalloc(sizeof(expr_t));
              e->type = EXPR_TYPE_DICT;
              e->dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
              newArg = e;
              break;
            }
            default:
              fprintf(stderr, "error: sorry but argument datatype cannot be passed to a function, type: %d\n", sv.type);
              exit(1);
              break;
          }

          /* Adding expression to argument table */
          hashtable_put(newArgumentTable, PROVIDE_CONTEXT()->syncCtx, params->arg->id.id, newArg);

          params = params->next;
          argsWalk = argsWalk->next;
        }

      }

      /* Moving along, interpreting function */
      localsStackSp = varLocals->sp;
      localsStackSb = varLocals->sb;
      varLocals->sb = varLocals->sp;
      *depth = 1;  // There is only one global scope
      tmp = PROVIDE_CONTEXT()->classCtx;
      PROVIDE_CONTEXT()->classCtx = classObj;  // Set class context
      interpret_statements_(funcDef->body, PROVIDE_CONTEXT(), funcDef->params, newArgumentTable);
      varLocals->sb = localsStackSb;
      varLocals->sp = localsStackSp;
      PROVIDE_CONTEXT()->classCtx = tmp;
    }

    if ( *(uintptr_t*)sp != spBefore ) {
      /* Return statement found, pop return value */
      POP_VAL(&sv_ret, sp, sc);
    }
    
    /* Push function return value to the stack */
    push_stackval(&sv_ret, sp, sc);

    /* Free the argument value table */
    flush_arguments(newArgumentTable);
  }
}

void interpret_statements_(
  void *stmt,
  PROVIDE_CONTEXT_ARGS(),
  argsList_t *args,
  hashtable_t *argVals
)
{
  locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  class_t *classCtx = PROVIDE_CONTEXT()->classCtx;
  int *interactive = PROVIDE_CONTEXT()->interactive;
  int32_t *ax = PROVIDE_CONTEXT()->ax;
  entity_eval_t *eval;
  void *next = NULL;
  ctx_table_t *ctx = ast_emalloc(sizeof(ctx_table_t));

  /* Initialize the context */
  memset(ctx, 0, sizeof(ctx_table_t));

  while ( stmt != NULL ) {
    eval = (entity_eval_t*)stmt;

    switch ( eval->entity ) {
      case LANG_ENTITY_DECL:
      case LANG_ENTITY_FUNCDECL:
      case LANG_ENTITY_FUNCCALL:
      case LANG_ENTITY_CONDITIONAL:
      case LANG_ENTITY_SYSTEM:
      case LANG_ENTITY_EXPR:
      case LANG_ENTITY_CLASSDECL:
      case LANG_ENTITY_FOREACH:
        next = ((statement_t*)stmt)->next;
      break;
      case LANG_ENTITY_RETURN:
        next = NULL;
      break;
      case LANG_ENTITY_BODY: {
        next = ((body_t*)stmt)->content;
        ctx->sp[ctx->depth] = varLocals->sp;
        ctx->sb[ctx->depth] = varLocals->sb;
        ctx->depth++;
        ctx->start[ctx->depth] = ctx->start[ctx->depth-1]; 
        ctx->end[ctx->depth] = ctx->end[ctx->depth-1]; 
        ctx->ctxDepth[ctx->depth] = ctx->ctxDepth[ctx->depth-1];
        stmt = next;
        continue;
      }
      break;
      case LANG_ENTITY_BODY_END: {
        ctx->depth--;
        next = ctx->bodyEnd[ctx->depth];
        varLocals->sp = ctx->sp[ctx->depth];
        varLocals->sb = ctx->sb[ctx->depth];
        stmt = next;
        continue;
      }
      break;
      case LANG_ENTITY_FIN: {
        /* Free context */
        free(ctx);
        /* Jump to VM shutdown */
        longjmp(endingJmpBuf, 1);
      }
      break;
      default:
      break;
    }

    switch ( eval->entity ) {
      case LANG_ENTITY_DECL:
      {
        stackval_t sv;
        expr_t *id;
        heapval_t *hvp = NULL;
        declaration_t* decl = ((statement_t*)stmt)->content;
        id = decl->id;

        switch ( id->type ) {
        case EXPR_TYPE_ID: {
          int heapUpdated;
          heapval_t *globalCheck = NULL;
          heapval_t *classCheck = NULL;
          char *idStr = id->id.id;
          int stop = 0;

          /* Evaluating the expression among global variables */
          evaluate_expression(decl->val, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          /* Placing value on the heap */
          if ( sv.type == TEXT ) {
            /* Special case */
            char *c = sv.t;
            size_t len = strlen(c)+1;
            char *newText = ast_emalloc(len);
            snprintf(newText,len,"%s",c);
            sv.t = newText;
          } else if ( sv.type == VECTORTYPE ) {
            expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
            sv.vec = e->vec;
            free(e);
          } else if ( sv.type == DICTTYPE ) {
            dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
            sv.dict = dict;
          } else if ( sv.type == RAWDATATYPE ) {
            expr_t *e = newExpr_RawData(sv.rawdata->size);
            memcpy(e->rawdata->data, sv.rawdata->data, sv.rawdata->size);
            sv.rawdata = e->rawdata;
            free(e);
          }

          ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

          /* Check if the variable is to be put in the class namespace */
          if ( classCtx != NULL ) {
            classCheck = hashtable_get(classCtx->varMembers, PROVIDE_CONTEXT()->syncCtx, idStr);
            if ( classCheck != NULL ) {
              /* Placing variable declaration in class member namespace */
              hashtable_put(classCtx->varMembers, PROVIDE_CONTEXT()->syncCtx, idStr, hvp);
              stop = 1;
            }
          }

          if ( !stop ) {
            /* Check if the variable is in the global namespace */
            globalCheck = hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, idStr);

            if ( globalCheck != NULL || ctx->depth == 0 ) {
              /* Placing variable declaration in global variable namespace */
              hashtable_put(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, idStr, hvp);
            } else {
              /* Placing variable declaration in local variable namespace */
              locals_push(varLocals, idStr, hvp);
            }
          }
        }
        break;
        case EXPR_TYPE_VECTOR_IDX: {
          vector_t *vec = NULL;
          dictionary_t *dict = NULL;
          int32_t arrayIndex;
          argsList_t *walk;
          expr_t **expToSet = NULL;
          expr_t *vecid = id->vecIdx->id;
          expr_t *index = id->vecIdx->index;

          stackval_t sv;

          evaluate_expression(vecid, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          switch ( sv.type ) {
            case DICTTYPE: {
              dict = sv.dict;
              /* Assigning a dictionary */
              char *key = NULL;
              heapval_t *hvp = NULL;
              int dummy;

              evaluate_expression(index, EXPRESSION_ARGS());
              POP_VAL(&sv, sp, sc);

              if ( sv.type != TEXT ) {
                fprintf(stderr, "index error: Must provide a string as key\n");
                exit(1);
              }

              key = ast_emalloc(strlen(sv.t)+2);
              snprintf(key, strlen(sv.t)+1, "%s", sv.t);

              /* Evaluating the expression among global variables */
              evaluate_expression(decl->val, EXPRESSION_ARGS());
              POP_VAL(&sv, sp, sc);

              /* Placing value on the heap */
              if ( sv.type == TEXT ) {
                /* Special case */
                char *c = sv.t;
                size_t len = strlen(c)+1;
                char *newText = ast_emalloc(len);
                snprintf(newText,len,"%s",c);
                sv.t = newText;
              } else if ( sv.type == VECTORTYPE ) {
                expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
                sv.vec = e->vec;
                free(e);
              } else if ( sv.type == DICTTYPE ) {
                dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
                sv.dict = dict;
              }

              ALLOC_HEAP(&sv, hp, &hvp, &dummy);

              // Check if collision, if so, free key
              hashtable_put(dict->hash, PROVIDE_CONTEXT()->syncCtx, key, hvp);
            }
            break;
            case VECTORTYPE: {
              /* Assigning a vector */
              expr_t *newExp = NULL;
              vec = sv.vec;
              evaluate_expression(index, EXPRESSION_ARGS());
              POP_VAL(&sv, sp, sc);

              if ( sv.type != INT32TYPE ) {
                fprintf(stderr, "index error: Must provide an integer as index\n");
                exit(1);
              }

              arrayIndex = sv.i;

              /* check the limits */
              if ( arrayIndex >= vec->length ) {
                fprintf(stderr, "index error: index: '%" PRIi32 "' is too large, length: '%" PRIi32 "'\n",
                  arrayIndex,
                  vec->length);
                exit(1);
              }

              walk = vec->content;
              while ( walk != NULL && arrayIndex >= 0 ) {
                expToSet = &walk->arg;
                walk = walk->next;
                --arrayIndex;
              }

              if ( *expToSet == NULL ) {
                fprintf(stderr, "Unexpected index error!\n");
                GENERAL_REPORT_ISSUE_MSG();
                exit(1);
              }

              /* Placing this expression into the array */
              free_expression(*expToSet);
              free(*expToSet);

              evaluate_expression(decl->val, EXPRESSION_ARGS());
              POP_VAL(&sv, sp, sc);

              switch (sv.type) {
              case INT32TYPE:
                newExp = newExpr_Ival(sv.i);
                break;
              case DOUBLETYPE:
                newExp = newExpr_Float(sv.d);
                break;
              case TEXT:
                newExp = newExpr_Text(sv.t);
                break;
              case TIMETYPE:
                newExp = newExpr_Time(sv.time);
                break;
              case POINTERTYPE:
                newExp = newExpr_Pointer(sv.p);
                break;
              case FUNCPTRTYPE:
                newExp = newExpr_FuncPtr(sv.func);
                break;
              case LIBFUNCPTRTYPE:
                newExp = newExpr_LibFuncPtr(sv.libfunc);
                break;
              case VECTORTYPE: {
                newExp = copy_vector(sv.vec, EXPRESSION_ARGS());
                break;
              }
              default:
                printf("%s.error: unknown type of value on the stack (%d)\n", 
                  __func__, sv.type);
                GENERAL_REPORT_ISSUE_MSG();
                break;
              }

              *expToSet = newExp;
            }
            break;
            case TEXT: {
              char *text = sv.t;
              size_t origLen = strlen(text);
              size_t additionLen;
              size_t diff;
              size_t q = 0;
              char *newAddition = NULL;

              evaluate_expression(index, EXPRESSION_ARGS());
              POP_VAL(&sv, sp, sc);

              if ( sv.type != INT32TYPE ) {
                fprintf(stderr, "index error: Must provide an integer as index\n");
                exit(1);
              }

              arrayIndex = sv.i;

              if ( arrayIndex >= strlen(text) ) {
                fprintf(stderr, "index error: index out of bounds\n");
                exit(1);
              }

              /* Evaluating the expression among global variables */
              evaluate_expression(decl->val, EXPRESSION_ARGS());
              POP_VAL(&sv, sp, sc);

              if ( sv.type != TEXT ) {
                fprintf(stderr, "string index error: Can only assign text to text.\n");
                exit(1);
              }

              newAddition = sv.t;
              additionLen = strlen(newAddition);

              diff = origLen - arrayIndex;

              additionLen = ( diff < additionLen ? diff : additionLen );
              q = 0;
              while ( q < additionLen ) {
                text[arrayIndex + q] = newAddition[q];
                q++;
              }
            }
            break;
            default: {
              fprintf(stderr, "index error: '%s' is not an indexable object.\n", id->id.id);
              GENERAL_REPORT_ISSUE_MSG();
              exit(1);
              break;
            }
          }
        }
        break;
        default:
          GENERAL_REPORT_ISSUE_MSG();
          break;
        }

        if ( *interactive & INTERACTIVE_STACK ) {
          break;
        }

        // Mark and sweep the heap
        mark_and_sweep(PROVIDE_CONTEXT()->varDecs, EXPRESSION_ARGS());
      }
      break;
      case LANG_ENTITY_SYSTEM:
      {
        expr_t *sys_var = (expr_t*)((statement_t*)stmt)->content;
        stackval_t sv;

        evaluate_expression(sys_var, EXPRESSION_ARGS());
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
      case LANG_ENTITY_RETURN:
      {
        expr_t *retVal = (expr_t*)((statement_t*)stmt)->content;
        stackval_t sv;

        evaluate_expression(retVal, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);
        switch ( sv.type ) {
        case TEXT:
          /* Pushing the return value as a string */
          PUSH_STRING(sv.t, sp, sc);
          break;
        case INT32TYPE:
          /* Pushing the return value as an int */
          PUSH_INT(sv.i, sp, sc);
          break;
        case TIMETYPE:
          /* Pushing the return value as an int */
          PUSH_TIME(sv.time, sp, sc);
          break;
        case RAWDATATYPE:
          /* Pushing the return value as an int */
          PUSH_RAWDATA(sv.rawdata, sp, sc);
          break;
        case VECTORTYPE:
          /* Pushing the return value as a vector */
          PUSH_VECTOR(sv.vec, sp, sc);
          break;
        case DOUBLETYPE:
          /* Pushing the return value as a double */
          PUSH_DOUBLE(sv.d, sp, sc);
        break;
        default:
          printf("%s.error: unknown type of system call on the stack (%d)\n", 
            __func__, sv.type);
          break;
        }
        /* Returning now from this function */
        free(ctx);
        return;
      }
      break;
      case LANG_ENTITY_CLASSDECL:
      {
        class_t *newClass = ((statement_t*)stmt)->content;

        /* Placing funciton declaration in global function namespace */
        hashtable_put(PROVIDE_CONTEXT()->classDecs, PROVIDE_CONTEXT()->syncCtx, newClass->id, newClass);
      }
      break;
      case LANG_ENTITY_FUNCDECL:
      {
        functionDef_t *funcDef = ((statement_t*)stmt)->content;

        /* Placing funciton declaration in global function namespace */
        hashtable_put(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, funcDef->id.id, funcDef);
      }
      break;
      case LANG_ENTITY_FOREACH:
      {
        forEachStmt_t *festmt = ((statement_t*)stmt)->content;
        expr_t *root = festmt->root;
        expr_t *entry = festmt->entry;
        vector_t *rootVec = NULL;
        char *rootChars = NULL;
        int32_t rootInt = -1;
        dictionary_t *rootDict = NULL;
        argsList_t *walk = NULL;
        expr_t *expToSet = NULL;
        heapval_t *hvp = NULL;
        int dummy;
        int32_t arrayIndex;
        int32_t festmtIndex;
        char *entryId = NULL;
        stackval_t sv;

        evaluate_expression(root, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);
        switch ( sv.type ) {
        case VECTORTYPE:
        rootVec = sv.vec;
        break;
        case DICTTYPE:
        rootDict = sv.dict;
        break;
        case TEXT:
        rootChars = sv.t;
        break;
        case INT32TYPE:
        rootInt = sv.i;
        break;
        default:
          printf("%s.%d error: '%s' isn't an indexable array\n", 
            ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, root->id.id);
        break;
        }

        if ( entry->type != EXPR_TYPE_ID ) {
          printf("%s.%d error: '%s' isn't a correct variable\n",
            ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, entry->id.id);
        } else {
          entryId = entry->id.id;
        }

        /* Get for-each unfold variable value */
        hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);
        if ( hvp == NULL ) {
          /* Create the variable with the value to be used for indexing, start with 0 */
          sv.type = INT32TYPE;
          sv.i = 0;
          ALLOC_HEAP(&sv, hp, &hvp, &dummy);
          locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
        }

        /* Get the index value */
        hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

        if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
          /* This is really not support to happen */
          printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
            ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
          exit(1);
        }

        festmtIndex = hvp->sv.i;

        if ( festmtIndex == 0 ) {
          /* Set starting */
          ctx->start[ctx->depth] = stmt;
          ctx->end[ctx->depth] = next;
          ctx->ctxDepth[ctx->depth] = ctx->depth;
          ctx->bodyEnd[ctx->depth] = next;
        }

        arrayIndex = festmtIndex;

        if ( rootVec != NULL ) {

          /* check the limits */
          if ( festmtIndex >= rootVec->length ) {
            /* End this iteration */
            stmt = next;
            /* Set the variable to 0 */
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

            if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
              /* This is really not support to happen */
              printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            hvp->sv.i = 0;
            locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
            continue;
          }

          /* Increase the value of the unfolded variable */
          festmtIndex++;
          hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

          if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
            /* This is really not support to happen */
            printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
              ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
            exit(1);
          }

          hvp->sv.i = festmtIndex;
          locals_push(varLocals, festmt->uniqueUnfoldID, hvp);        

          walk = rootVec->content;
          while ( walk != NULL && arrayIndex >= 0 ) {
            expToSet = walk->arg;
            walk = walk->next;
            --arrayIndex;
          }

          if ( expToSet == NULL ) {
            fprintf(stderr, "%s.%d error: Unexpected index error!\n",
              ((statement_t*) stmt)->file, ((statement_t*) stmt)->line);
            GENERAL_REPORT_ISSUE_MSG();
            exit(1);
          }

          evaluate_expression(expToSet, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          /* Placing value on the heap */
          if ( sv.type == TEXT ) {
            /* Special case */
            char *c = sv.t;
            size_t len = strlen(c)+1;
            char *newText = ast_emalloc(len);
            snprintf(newText,len,"%s",c);
            sv.t = newText;
          } else if ( sv.type == VECTORTYPE ) {
            expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
            sv.vec = e->vec;
            free(e);
          } else if ( sv.type == DICTTYPE ) {
            dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
            sv.dict = dict;
          }
          ALLOC_HEAP(&sv, hp, &hvp, &dummy);

          locals_push(varLocals, entryId, hvp);
        } else if ( rootDict != NULL ) {
          /* traverse the dictionary keys */
          hashtable_t *hash = rootDict->hash;
          int hashSize = hash->size;
          struct key_val_pair *ptr;
          int i = 0;
          int keyCount = 0;

          /* Check limits */
          while ( i < hashSize ) {
            ptr = hash->table[i];
            while (ptr != NULL) {
              /* Here is a key.. */
              ptr = ptr->next;
              keyCount++;
            }
            i++;
          }

          if ( arrayIndex >= keyCount ) {
            /* We are out of here */
            stmt = next;
            /* Set the variable to 0 */
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

            if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
              /* This is really not support to happen */
              printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            hvp->sv.i = 0;
            locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
            continue;
          }

          keyCount = 0;
          i = 0;
          while ( i < hashSize ) {
            ptr = hash->table[i];
            while (ptr != NULL) {
              /* Add this key to the list */
              char *c = (char*)ptr->key;

              if ( keyCount == arrayIndex ) {
                size_t len = strlen(c)+1;
                char *newText = ast_emalloc(len);
                snprintf(newText,len,"%s",c);
                sv.type = TEXT;
                sv.t = newText;
                ALLOC_HEAP(&sv, hp, &hvp, &dummy);
                locals_push(varLocals, entryId, hvp);
                /* Increase the value of the unfolded variable */
                festmtIndex++;
                hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

                if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
                  /* This is really not support to happen */
                  printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                    ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
                  exit(1);
                }

                hvp->sv.i = festmtIndex;
                locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
              }

              ptr = ptr->next;
              keyCount++;
            }
            i++;
          }
        } else if ( rootChars != NULL ) {
          /* traverse the string chars */
          stackval_t sv;
          size_t len;
          char *newText;

          /* Check limits */
          if ( arrayIndex >= strlen(rootChars) ) {
            /* We are out of here */
            stmt = next;
            /* Set the variable to 0 */
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

            if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
              /* This is really not support to happen */
              printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            hvp->sv.i = 0;
            locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
            continue; 
          }

          len = 2;
          newText = ast_emalloc(len);
          snprintf(newText, 2, "%c", rootChars[arrayIndex]);
          sv.type = TEXT;
          sv.t = newText;
          ALLOC_HEAP(&sv, hp, &hvp, &dummy);
          locals_push(varLocals, entryId, hvp);
          /* Increase the value of the unfolded variable */
          festmtIndex++;
          hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

          if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
            /* This is really not support to happen */
            printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
              ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
            exit(1);
          }

          hvp->sv.i = festmtIndex;
          locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
        } else if ( rootInt > 0 ) {
          /* traverse the integer, start from zero */
          stackval_t sv;

          /* Check limits */
          if ( festmtIndex >= rootInt ) {
            /* We are out of here */
            stmt = next;
            /* Set the variable to 0 */
            hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

            if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
              /* This is really not support to happen */
              printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
                ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            hvp->sv.i = 0;
            locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
            continue;
          }

          sv.type = INT32TYPE;
          sv.i = festmtIndex;
          ALLOC_HEAP(&sv, hp, &hvp, &dummy);
          locals_push(varLocals, entryId, hvp);
          /* Increase the value of the unfolded variable */
          festmtIndex++;
          hvp = locals_lookup(varLocals, festmt->uniqueUnfoldID);

          if ( hvp == NULL || hvp->sv.type != INT32TYPE ) {
            /* This is really not support to happen */
            printf("%s.%d error: The unfolding of this statement failed!\nPlease file an issue here: %s\n",
              ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, GENERAL_ERROR_ISSUE_URL);
            exit(1);
          }

          hvp->sv.i = festmtIndex;
          locals_push(varLocals, festmt->uniqueUnfoldID, hvp);
        }

        next = festmt->body;
      }
      break;
      case LANG_ENTITY_CONTINUE:
      {
        /* Set PC to continue 'start' */
        ctx->depth--;
        next = ctx->start[ctx->depth];
        ctx->depth = ctx->ctxDepth[ctx->depth];
        varLocals->sp = ctx->sp[ctx->depth];
        varLocals->sb = ctx->sb[ctx->depth];
        stmt = next;
        continue;
      }
      break;
      case LANG_ENTITY_BREAK:
      {
        /* Set PC to break 'end' */
        ctx->depth = ctx->ctxDepth[ctx->depth];
        next = ctx->end[ctx->depth];
        varLocals->sp = ctx->sp[ctx->depth];
        varLocals->sb = ctx->sb[ctx->depth];
        stmt = next;
        continue;
      }
      break;
      case LANG_ENTITY_EXPR:
      {
        stackval_t sv;
        size_t stackCount = *sc;
        expr_t *e = ((statement_t*)stmt)->content;

        switch ( e->type ) {
          case EXPR_TYPE_FUNCCALL: {
            functionCallContainer_t func;

            func.type = FUNC_CALL_TYPE_GLOBAL;
            func.globalCall = e->func;

            call_func(
              &func,
              EXPRESSION_ARGS()
            );

            if ( *interactive | INTERACTIVE_STACK ) {
              break;
            }

            /* Printing result of function call, if string or vector */
            while ( *sc > stackCount ) {
              POP_VAL(&sv, sp, sc);
              switch (sv.type) {
                case TEXT:
                printf("%s\n", sv.t);
                break;
                case TIMETYPE: {
                  struct tm *timeInfo;
                  if ( sv.time < 0 ) {
                    /* Relative time to now */
                    time_t nowTime;
                    time_t result;
                    time(&nowTime);
                    result = nowTime + sv.time;
                    timeInfo = localtime( &result );
                  } else {
                    timeInfo = localtime( &sv.time );
                  }
                  printf("%s", asctime(timeInfo));
                  break;
                }
                case VECTORTYPE:
                print_vector(sv.vec, EXPRESSION_ARGS());
                printf("\n");
                break;
                case INT32TYPE:
                if ( *interactive ) {
                  printf("%" PRIi32 "\n", sv.i);
                }
                break;
                case DOUBLETYPE:
                if ( *interactive ) {
                  printf("%lf\n", sv.d);
                }
                break;
                default:
                break;
              }
            }

            break;
          }
          case EXPR_TYPE_CLASSFUNCCALL: {
            functionCallContainer_t func;

            func.type = FUNC_CALL_TYPE_CLASS;
            func.classCall = e->func;

            call_func(
              &func,
              EXPRESSION_ARGS()
            );

            if ( *interactive | INTERACTIVE_STACK ) {
              break;
            }

            /* Printing result of function call, if string or vector */
            while ( *sc > stackCount ) {
              POP_VAL(&sv, sp, sc);
              switch (sv.type) {
                case TEXT:
                printf("%s\n", sv.t);
                break;
                case TIMETYPE: {
                  struct tm *timeInfo;
                  if ( sv.time < 0 ) {
                    /* Relative time to now */
                    time_t nowTime;
                    time_t result;
                    time(&nowTime);
                    result = nowTime + sv.time;
                    timeInfo = localtime( &result );
                  } else {
                    timeInfo = localtime( &sv.time );
                  }
                  printf("%s", asctime(timeInfo));
                  break;
                }
                case VECTORTYPE:
                print_vector(sv.vec, EXPRESSION_ARGS());
                printf("\n");
                break;
                case INT32TYPE:
                if ( *interactive ) {
                  printf("%" PRIi32 "\n", sv.i);
                }
                break;
                case DOUBLETYPE:
                if ( *interactive ) {
                  printf("%lf\n", sv.d);
                }
                break;
                default:
                break;
              }
            }

            break;
          }
          default: {

            if ( *interactive ) {
              /* Compute */
              evaluate_expression(e, EXPRESSION_ARGS());

              if ( *interactive | INTERACTIVE_STACK ) {
                break;
              }

              /* Printing result of computation */
              while ( *sc > stackCount ) {
                POP_VAL(&sv, sp, sc);
                switch (sv.type) {
                  case TEXT:
                  printf("%s\n", sv.t);
                  break;
                  case TIMETYPE: {
                    struct tm *timeInfo;
                    if ( sv.time < 0 ) {
                      /* Relative time to now */
                      time_t nowTime;
                      time_t result;
                      time(&nowTime);
                      result = nowTime + sv.time;
                      timeInfo = localtime( &result );
                    } else {
                      timeInfo = localtime( &sv.time );
                    }
                    printf("%s", asctime(timeInfo));
                    break;
                  }
                  case VECTORTYPE:
                  print_vector(sv.vec, EXPRESSION_ARGS());
                  printf("\n");
                  break;
                  case INT32TYPE:
                  printf("%" PRIi32 "\n", sv.i);
                  break;
                  case DOUBLETYPE:
                  printf("%lf\n", sv.d);
                  break;
                  default:
                  break;
                }
              }
            }

          }
          break;
        }

      }
      break;
      case LANG_ENTITY_CONDITIONAL:
      {
        ifStmt_t *ifstmt = ((statement_t*)stmt)->content;
        ifStmt_t *ifstmtWalk;
        stackval_t sv;

        if ( ifstmt->ifType & LANG_CONDITIONAL_CTX ) {
          /* Handle the continue '@' and break '!@' points' */
          ctx->start[ctx->depth] = stmt;
          ctx->end[ctx->depth] = next;
          ctx->ctxDepth[ctx->depth] = ctx->depth;
        }

        ctx->bodyEnd[ctx->depth] = next;

        evaluate_expression(ifstmt->cond, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);

        switch ( sv.type ) {
          case INT32TYPE:
          *ax = (sv.i != 0);
          break;
          default:
          fprintf(stderr, "Invalid conditional expression (%d)\n", sv.type);
          exit(1);
          break;
        }

        /* Read ax for conditional */
        if ( *ax ) {
          next = ifstmt->body;
        } else {
          // Walk through the elifs.
          int stop = 0;
          ifstmtWalk = ifstmt->elif;

          while ( ifstmtWalk != NULL ) {

            evaluate_expression(ifstmtWalk->cond, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            switch ( sv.type ) {
              case INT32TYPE:
              *ax = (sv.i != 0);
              break;
              default:
              fprintf(stderr, "Invalid conditional expression.\n");
              exit(1);
              break;
            }

            if ( *ax ) {
              ifStmt_t *elif = ifstmtWalk;
              next = elif->body;
              stop = 1;
              break;
            }
            ifstmtWalk = ifstmtWalk->elif;
          }

          if ( ! stop ) {
            if ( ifstmt->endif != NULL ) {
              ifStmt_t *endif = ifstmt->endif;
              next = endif->body;
            }
          }

        }

      }
      break;
      default:
      break;
    }

    stmt = next;
  }

  free(ctx);
}

heapval_t *locals_lookup(locals_stack_t *stack, char *id) {
  int i = stack->sb;
  while ( i < stack->sp && i < MAX_NBR_LOCALS ) {
    local_t local = stack->stack[i];
    if ( strcmp(id, local.id) == 0 ) {
      /* Found it */
      return local.hpv;
    }
    ++i;
  }
  /* id not among locals */
  return NULL;
}

void locals_push(locals_stack_t *stack, char *id, heapval_t *hpv) {
  if ( stack->sp >= MAX_NBR_LOCALS ) {
    fprintf(stderr,
      "You are defining over %d locals, what are you doin? I will not cooperate with you. Sorry.\n",
      MAX_NBR_LOCALS);
    exit(1);
  }
  int i = stack->sb;
  while ( i < stack->sp && i < MAX_NBR_LOCALS ) {
    local_t local = stack->stack[i];
    if ( strcmp(id, local.id) == 0 ) {
      /* Overloading this value */
      stack->stack[i].hpv = hpv;
      return;
    }
    ++i;
  }
  /* Pushing new value */
  stack->stack[stack->sp].hpv = hpv;
  stack->stack[stack->sp].id = id;
  stack->sp++;
}

void setup_namespaces(PROVIDE_CONTEXT_ARGS()) {
  static int globalNamespaceSetup = 0;

  if ( globalNamespaceSetup == 0 ) {
    PROVIDE_CONTEXT()->funcDecs = hashtable_new(100, 0.8);
    assert(PROVIDE_CONTEXT()->funcDecs != NULL);
    PROVIDE_CONTEXT()->varDecs = hashtable_new(200, 0.8);
    assert(PROVIDE_CONTEXT()->varDecs != NULL);
    PROVIDE_CONTEXT()->classDecs = hashtable_new(200, 0.8);
    assert(PROVIDE_CONTEXT()->classDecs != NULL);

    globalNamespaceSetup = 1;
  }
}

void close_namespaces(PROVIDE_CONTEXT_ARGS()) {
  hashtable_free(PROVIDE_CONTEXT()->funcDecs);
  hashtable_free(PROVIDE_CONTEXT()->varDecs);
  hashtable_free(PROVIDE_CONTEXT()->classDecs);
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
    case EXPR_TYPE_TIME:
    printf("TIME");
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
    case EXPR_TYPE_VECTOR_IDX: {
      vectorIndex_t *vecIdx = expr->vecIdx;
      printf("ListIdx, ID: ");
      print_expr(vecIdx->id);
      printf(", index: ");
      print_expr(vecIdx->index);
    }
    break;
    case EXPR_TYPE_CLASSPTR:
    printf("Class Object <'%s'>", expr->classObj->id);
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
    case EXPR_TYPE_FUNCCALL:
    {
      functionCall_t *funcCall = expr->func;
      printf("Function call: <");
      print_expr(funcCall->id);
      printf("> args(");
      argsList_t *args = funcCall->args;
      print_args(args);
      printf(")");
    }
    break;
    case EXPR_TYPE_CLASSFUNCCALL:
    {
      classFunctionCall_t *funcCall = expr->func;
      printf("Class function call: <class: '");
      print_expr(funcCall->classID);
      printf("', func: '");
      print_expr(funcCall->classID);
      printf("''> args(");
      argsList_t *args = funcCall->args;
      print_args(args);
      printf(")");
    }
    break;
    case EXPR_TYPE_VECTOR:
    {
      vector_t *vec = (vector_t *)expr->vec;
      printf("Vector, content(");
      print_args(vec->content);
      printf(")");
    }
    break;
    case EXPR_TYPE_DICT:
    printf("<Dictionary>");
    break;
    case EXPR_TYPE_EMPTY:
    default:
    break;
  }

}

void initClass(class_t *cls, EXPRESSION_PARAMS()) {
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *sp = PROVIDE_CONTEXT()->sp;
  void *hp = PROVIDE_CONTEXT()->hp;
  statement_t *initWalk = cls->defines;

  /* Sanity check */
  if ( cls->funcDefs == NULL || cls->varMembers == NULL ) {
    return;
  }

  /* Go through the initializer list and populate the members */
  while ( initWalk != NULL ) {
    switch ( initWalk->entity ) {
    case LANG_ENTITY_FUNCDECL: {
      functionDef_t *funcDef = initWalk->content;

      /* Placing funciton declaration in global function namespace */
      hashtable_put(cls->funcDefs, PROVIDE_CONTEXT()->syncCtx, funcDef->id.id, funcDef);
    }
    break;
    case LANG_ENTITY_DECL: {
      stackval_t sv;
      expr_t *id;
      heapval_t *hvp = NULL;
      declaration_t* decl = initWalk->content;
      id = decl->id;

      switch ( id->type ) {
      case EXPR_TYPE_ID: {
        int heapUpdated;
        char *idStr = id->id.id;

        /* Evaluating the expression among global variables */
        evaluate_expression(decl->val, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);

        /* Placing value on the heap */
        if ( sv.type == TEXT ) {
          /* Special case */
          char *c = sv.t;
          size_t len = strlen(c)+1;
          char *newText = ast_emalloc(len);
          snprintf(newText,len,"%s",c);
          sv.t = newText;
        } else if ( sv.type == VECTORTYPE ) {
          expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
          sv.vec = e->vec;
          free(e);
        } else if ( sv.type == DICTTYPE ) {
          dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
          sv.dict = dict;
        }

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        /* Placing variable declaration in class variable member namespace */
        hashtable_put(cls->varMembers, PROVIDE_CONTEXT()->syncCtx, idStr, hvp);
      }
      break;
      case EXPR_TYPE_VECTOR_IDX: {
        vector_t *vec = NULL;
        dictionary_t *dict = NULL;
        int32_t arrayIndex;
        argsList_t *walk = NULL;
        expr_t **expToSet = NULL;
        expr_t *vecid = id->vecIdx->id;
        expr_t *index = id->vecIdx->index;

        stackval_t sv;

        evaluate_expression(vecid, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);

        switch ( sv.type ) {
          case DICTTYPE: {
            dict = sv.dict;
            /* Assigning a dictionary */
            char *key = NULL;
            heapval_t *hvp = NULL;
            int dummy;

            evaluate_expression(index, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            if ( sv.type != TEXT ) {
              fprintf(stderr, "index error: Must provide a string as key\n");
              exit(1);
            }

            key = ast_emalloc(strlen(sv.t)+2);
            snprintf(key, strlen(sv.t)+1, "%s", sv.t);

            /* Evaluating the expression among global variables */
            evaluate_expression(decl->val, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            /* Placing value on the heap */
            if ( sv.type == TEXT ) {
              /* Special case */
              char *c = sv.t;
              size_t len = strlen(c)+1;
              char *newText = ast_emalloc(len);
              snprintf(newText,len,"%s",c);
              sv.t = newText;
            } else if ( sv.type == VECTORTYPE ) {
              expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
              sv.vec = e->vec;
              free(e);
            } else if ( sv.type == DICTTYPE ) {
              dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
              sv.dict = dict;
            }

            ALLOC_HEAP(&sv, hp, &hvp, &dummy);

            // Check if collision, if so, free key
            hashtable_put(dict->hash, PROVIDE_CONTEXT()->syncCtx, key, hvp);
          }
          break;
          case VECTORTYPE: {
            /* Assigning a vector */
            expr_t *newExp = NULL;
            vec = sv.vec;
            evaluate_expression(index, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            if ( sv.type != INT32TYPE ) {
              fprintf(stderr, "index error: Must provide an integer as index\n");
              exit(1);
            }

            arrayIndex = sv.i;

            /* check the limits */
            if ( arrayIndex >= vec->length ) {
              fprintf(stderr, "index error: index: '%" PRIi32 "' is too large, length: '%" PRIi32 "'\n",
                arrayIndex,
                vec->length);
              exit(1);
            }

            walk = vec->content;
            while ( walk != NULL && arrayIndex >= 0 ) {
              expToSet = &walk->arg;
              walk = walk->next;
              --arrayIndex;
            }

            if ( *expToSet == NULL ) {
              fprintf(stderr, "Unexpected index error!\n");
              GENERAL_REPORT_ISSUE_MSG();
              exit(1);
            }

            /* Placing this expression into the array */
            free_expression(*expToSet);
            free(*expToSet);

            evaluate_expression(decl->val, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            switch (sv.type) {
            case INT32TYPE:
              newExp = newExpr_Ival(sv.i);
              break;
            case DOUBLETYPE:
              newExp = newExpr_Float(sv.d);
              break;
            case TEXT:
              newExp = newExpr_Text(sv.t);
              break;
            case TIMETYPE:
              newExp = newExpr_Time(sv.time);
              break;
            case POINTERTYPE:
              newExp = newExpr_Pointer(sv.p);
              break;
            case FUNCPTRTYPE:
              newExp = newExpr_FuncPtr(sv.func);
              break;
            case LIBFUNCPTRTYPE:
              newExp = newExpr_LibFuncPtr(sv.libfunc);
              break;
            case VECTORTYPE: {
              newExp = copy_vector(sv.vec, EXPRESSION_ARGS());
              break;
            }
            default:
              printf("%s.error: unknown type of value on the stack (%d)\n", 
                __func__, sv.type);
              GENERAL_REPORT_ISSUE_MSG();
              break;
            }

            *expToSet = newExp;
          }
          break;
          case TEXT: {
            char *text = sv.t;
            size_t origLen = strlen(text);
            size_t additionLen;
            size_t diff;
            size_t q = 0;
            char *newAddition = NULL;

            evaluate_expression(index, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            if ( sv.type != INT32TYPE ) {
              fprintf(stderr, "index error: Must provide an integer as index\n");
              exit(1);
            }

            arrayIndex = sv.i;

            if ( arrayIndex >= strlen(text) ) {
              fprintf(stderr, "index error: index out of bounds\n");
              exit(1);
            }

            /* Evaluating the expression among global variables */
            evaluate_expression(decl->val, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            if ( sv.type != TEXT ) {
              fprintf(stderr, "string index error: Can only assign text to text.\n");
              exit(1);
            }

            newAddition = sv.t;
            additionLen = strlen(newAddition);

            diff = origLen - arrayIndex;

            additionLen = ( diff < additionLen ? diff : additionLen );
            q = 0;
            while ( q < additionLen ) {
              text[arrayIndex + q] = newAddition[q];
              q++;
            }
          }
          break;
          default: {
            fprintf(stderr, "index error: '%s' is not an indexable object.\n", id->id.id);
            GENERAL_REPORT_ISSUE_MSG();
            exit(1);
            break;
          }
        }
      }
      break;
      default:
        GENERAL_REPORT_ISSUE_MSG();
        break;
      }
    }
    break;
    default:
    break;
    }

    initWalk = initWalk->next;
  }
  cls->initialized = 1;
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
  while ( i < indent ) {
    printf("    ");
    ++i;
  }
}

int print_dictionary(dictionary_t *dict,
  EXPRESSION_PARAMS()) {
  hashtable_t *hash = dict->hash;
  //dictionary_t *newDict = NULL;
  int size;
  int i;
  int keyCount = 0;
  int keyCountTotal = 0;
  struct key_val_pair *ptr;

  if ( dict->initialized == 0 ) {
    //stackval_t sv;
    keyValList_t *walk = dict->keyVals;
    i = 0;
    printf("{");
    while ( walk != NULL ) {
      stackval_t sv;
      void *sp = PROVIDE_CONTEXT()->sp;
      size_t *sc = PROVIDE_CONTEXT()->sc;
      /* Dictionary already initialized, evaluate expressions in the key-value list */
      expr_t *expKey = walk->key;
      expr_t *expVal = walk->val;

      if ( expKey->type != EXPR_TYPE_TEXT ) {
        walk = walk->next;
        continue;
      }

      printf("%s'%s' : ", (i == 0 ? "" : ", "), expKey->text);

      evaluate_expression(expVal, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      switch ( sv.type ) {
        case INT32TYPE: {
          printf("%" PRIi32 "", sv.i);
        }
        break;
        case DOUBLETYPE: {
          printf("%lf", sv.d);
        }
        break;
        case TEXT: {
          printf("'%s'", sv.t);
        }
        break;
        case POINTERTYPE: {
          printf("<Pointer: %" PRIxPTR ">", sv.p);
        }
        break;
        case FUNCPTRTYPE: {
          functionDef_t *funcDec = sv.func;
          printf("<FuncPointer: '%s'>", funcDec->id.id);
        }
        break;
        case LIBFUNCPTRTYPE: {
          libFunction_t *libFunc = sv.libfunc;
          printf("<LibFuncPointer: '%s'>", libFunc->libFuncName);
        }
        break;
        case VECTORTYPE: {
          print_vector(sv.vec, EXPRESSION_ARGS());
        }
        break;
        case DICTTYPE: {
          print_dictionary(sv.dict, EXPRESSION_ARGS());
        }
        break;
        default:
        break;
      }

      walk = walk->next;
      ++i;
    }
    printf("}");
    return 0;
  }

  size = hash->size;

  i = 0;
  while ( i < size ) {
    ptr = hash->table[i];
    while (ptr != NULL) {
      keyCount++;
      ptr = ptr->next;
    }
    i++;
  }

  keyCountTotal = keyCount;

  if ( keyCountTotal > 0 ) {
    printf("{");
    keyCount = 0;
    i = 0;
    while ( i < size ) {
      heapval_t *hpv;
      stackval_t sv;
      ptr = hash->table[i];

      if ( ptr == NULL ) {
        ++i;
        continue;
      }

      printf("%s'%s' : ", (keyCount > 0 ? ", " : ""), ptr->key);
      hpv = ptr->data;
      sv = hpv->sv;

      switch ( sv.type ) {
        case INT32TYPE: {
          printf("%" PRIi32 "", sv.i);
        }
        break;
        case DOUBLETYPE: {
          printf("%lf", sv.d);
        }
        break;
        case TEXT: {
          printf("'%s'", sv.t);
        }
        break;
        case POINTERTYPE: {
          printf("<Pointer: %" PRIxPTR ">", sv.p);
        }
        break;
        case FUNCPTRTYPE: {
          functionDef_t *funcDec = sv.func;
          printf("<FuncPointer: '%s'>", funcDec->id.id);
        }
        break;
        case LIBFUNCPTRTYPE: {
          libFunction_t *libFunc = sv.libfunc;
          printf("<LibFuncPointer: '%s'>", libFunc->libFuncName);
        }
        break;
        case VECTORTYPE: {
          print_vector(sv.vec, EXPRESSION_ARGS());
        }
        break;
        case DICTTYPE: {
          print_dictionary(sv.dict, EXPRESSION_ARGS());
        }
        break;
        default:
        break;
      }

      keyCount++;
      i++;
    }
    printf("}");
  } else {
    printf("{}");
  }

  return 0;
}

int print_vector(
  vector_t *vec,
  EXPRESSION_PARAMS())
{
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  argsList_t *walk = vec->content;
  expr_t *vec_e = NULL;

  if ( vec->content == NULL && vec->forEach != NULL ) {
    vec_e = copy_vector(vec, EXPRESSION_ARGS());
    if ( vec_e != NULL ) {
      walk = vec_e->vec->content;
    }
  }

  printf("[");
  while ( walk != NULL ) {
    stackval_t sv;
    evaluate_expression(walk->arg, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    switch (sv.type) {
    case INT32TYPE:
      printf("%" PRIi32 "", sv.i);
      break;
    case DOUBLETYPE:
      printf("%lf", sv.d);
      break;
    case TEXT:
      printf("'%s'", sv.t);
      break;
    case TIMETYPE: {
      struct tm *info;
      if ( sv.time < 0 ) {
        /* Relative time to now */
        time_t nowTime;
        time_t result;
        time(&nowTime);
        result = nowTime + sv.time;
        info = localtime( &result );
      } else {
        info = localtime( &sv.time );
      }
      printf("%s", asctime(info));
      break;
    }
    case POINTERTYPE:
      printf("<%" PRIuPTR ">", sv.p);
      break;
    case FUNCPTRTYPE:
      printf("<Function: '%s'>", sv.func->id.id);
      break;
    case LIBFUNCPTRTYPE:
      printf("<Function: '%s'>", sv.func->id.id);
      break;
    case VECTORTYPE:
      print_vector(sv.vec, EXPRESSION_ARGS());
      break;
    case DICTTYPE:
      print_dictionary(sv.dict, EXPRESSION_ARGS());
      break;
    default:
      printf("%s.error: unknown type of value on the stack (%d)\n", 
        __func__, sv.type);
      break;
    }

    walk = walk->next;
    if ( walk != NULL ) {
      printf(",");
    }
  }

  printf("]");

  if ( vec_e != NULL ) {
    free_expression(vec_e);
    free(vec_e);
  }

  return 0;
}

static void flush_arg(void *key, void *val)
{
  expr_t *e = (expr_t*)val;
  (void)key;
  if ( e->type == EXPR_TYPE_TEXT ) {
    free(e->text);
  } else if ( e->type == EXPR_TYPE_DICT ) {
    hashtable_free(e->dict->hash);
    free(e->dict);
  } else if ( e->type == EXPR_TYPE_RAWDATA ) {
    free(e->rawdata->data);
    free(e->rawdata);
  }
}

void flush_arguments(hashtable_t *table)
{
  for_each_pair(table, flush_arg);
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
    case LANG_ENTITY_EXPR:
    case LANG_ENTITY_CLASSDECL:
    case LANG_ENTITY_RETURN:
    case LANG_ENTITY_FOREACH:
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
    case LANG_ENTITY_EXPR:
    {
      printf("Expr(");
      print_expr(((statement_t*)stmt)->content);
      printf(");\n");
    }
    break;
    case LANG_ENTITY_FOREACH:
    {
      forEachStmt_t *festmt = (forEachStmt_t*)((statement_t*)stmt)->content;
      body_t *bd = festmt->body;
      printf("For each: Expr(");
      print_expr(festmt->entry);
      printf(") <- Expr(");
      print_expr(festmt->root);
      printf(")\n");

      print_indents(indent);
      print_statements_(bd->content, indent+1);
    }
    break;
    case LANG_ENTITY_CLASSDECL:
    {
      class_t *class = ((statement_t*)stmt)->content;
      printf("Class('%s')\n", class->id);
      printf("CLASS DEFINES START\n");
      print_statements_(class->defines, indent+1);
      printf("CLASS DEFINES END\n");
    }
    break;
    case LANG_ENTITY_DECL:
    {
      declaration_t* decl = ((statement_t*)stmt)->content;
      expr_t *declId = decl->id;

      switch (declId->type) {
      case EXPR_TYPE_ID: {
        printf("Declaration: ID('%s'), Expr(", declId->id.id);
        break;
      }
      case EXPR_TYPE_VECTOR_IDX: {
        printf("Declaration: ");
        print_expr(declId);
        printf(", Expr(");
        break;
      }
      default:
        fprintf(stderr, "Unexpected expression in declaration statment\n");
        GENERAL_REPORT_ISSUE_MSG();
        break;
      }
      print_expr(decl->val);
      printf(")\n");
    }
    break;
    case LANG_ENTITY_SYSTEM:
    {
      expr_t *sys_txt = ((statement_t*)stmt)->content;

      printf("System(");
      print_expr(sys_txt);
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
    case LANG_ENTITY_RETURN:
    {
      expr_t *retVal = (expr_t*)((statement_t*)stmt)->content;
      printf("RETURN ->");
      print_expr(retVal);
      printf("\n");
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
    case LANG_ENTITY_CONDITIONAL:
    {
      ifStmt_t *ifstmt = ((statement_t*)stmt)->content;
      ifStmt_t *ifstmtWalk;
      expr_t *cond = ifstmt->cond;

      if ( ifstmt->ifType & LANG_CONDITIONAL_CTX ) {
        printf("loop-if-statement - condition: ");
      } else {
        printf("if-statement - condition: ");
      }

      print_expr(cond);
      printf("\n");
      print_statements_(ifstmt->body, indent);

      // Walk through the elifs.
      ifstmtWalk = ifstmt->elif;

      while ( ifstmtWalk != NULL ) {
        print_indents(indent);
        printf("else-if-statement - condition: ");
        print_expr(ifstmtWalk->cond);
        printf("\n");
        print_statements_(ifstmtWalk->body, indent+1);
        ifstmtWalk = ifstmtWalk->elif;
      }

      // Print the else if it is not NULL
      if ( ifstmt->endif != NULL ) {
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
  print_statements_(stmt, 0);
}

void interpret_statements(
  int argc,
  char *argv[],
  statement_t *stmt)
{
  // "CPU" registers definitions
  DEF_NEW_CONTEXT();

  // Setup stack
  SETUP_STACK(&sp, &sb, RIC_STACKSIZE, &sc);

  // Setup heap
  SETUP_HEAP(&hp, &hb, RIC_HEAPSIZE);

  // Setup locals 
  varLocals = ast_emalloc(sizeof(locals_stack_t));
  varLocals->sp = 0;
  varLocals->sb = 0;

  // Set up ric library
  initialize_ric_lib();

  /* Set starting point and end point */
  st = stmt;
  ed = NULL;

  /* Set interactive state to NON_INTERACTIVE */
  interactive = NON_INTERACTIVE;

  /* Set class context to NULL */
  classCtx = NULL;

  /* Set thread synchronization context */
  syncCtx = createContext();

  /* Set starting depth */
  depth = 0;

  /* Assigning the execution context super structure */
  ASSIGN_CONTEXT(exeCtx);

  /* Setup namespaces */
  setup_namespaces(PROVIDE_CONTEXT_INIT());

  /* arguments to environment variables */
  arguments_to_variables(PROVIDE_CONTEXT_INIT(), argc, argv, hp);

  if ( setjmp(endingJmpBuf) == JMP_CODE_INITIAL ) {
    /* Start descending and evaluating the AST */
    interpret_statements_(stmt, PROVIDE_CONTEXT_INIT(), NULL, NULL);
  } else {
    // Free thread context
    freeContext(syncCtx);

    // Close namespaces
    close_namespaces(PROVIDE_CONTEXT_INIT());

    // free locals
    free(varLocals);

    // free heap
    free_heap(hp, hb);

    // Free stack
    FREE_STACK(sp, sb);

    // Free memory associated with the AST
    free_ast(stmt);
  }
}

void interpret_statements_interactive(
  int argc,
  char *argv[],
  statement_t *stmt,
  int teardown
)
{
  static int firstCall = 1;
  // "CPU" registers definitions
  DEF_NEW_CONTEXT_STATIC();

  if ( firstCall ) {
    // Setup stack
    SETUP_STACK(&sp, &sb, RIC_STACKSIZE, &sc);

    // Setup heap
    SETUP_HEAP(&hp, &hb, RIC_HEAPSIZE);

    // Setup locals 
    varLocals = ast_emalloc(sizeof(locals_stack_t));
    varLocals->sp = 0;
    varLocals->sb = 0;

    // Set up ric library
    initialize_ric_lib();

    /* Set starting point and end point */
    st = stmt;
    ed = NULL;

    /* Set class context to NULL */
    classCtx = NULL;

    /* Set starting depth */
    depth = 0;

    /* Set interactive state to 1 */
    interactive = INTERACTIVE_PRINT;

    /* Flag that setup has been done already */
    firstCall = 0;

    /* Set thread synchronization context */
    syncCtx = createContext();

    /* Assigning the execution context super structure */
    ASSIGN_CONTEXT(exeCtx);

    /* Setup namespaces */
    setup_namespaces(PROVIDE_CONTEXT_INIT());

    /* arguments to environment variables */
    arguments_to_variables(PROVIDE_CONTEXT_INIT(), argc, argv, hp);
  }

  if ( stmt != NULL ) {

    /* Check if load */
    if ( stmt->entity == LANG_ENTITY_EXPR ) {
      stackval_t stv;
      libFunction_t *libFunc;

      expr_t *e = (expr_t*)stmt->content;

      if ( e->type == EXPR_TYPE_FUNCCALL ) {
        functionCall_t *call = e->func;
        evaluate_expression(call->id, NULL, NULL, PROVIDE_CONTEXT_INIT(), NULL, NULL);

        POP_VAL(&stv, &sp, &sc);
        if ( stv.type == LIBFUNCPTRTYPE ) {
          libFunc = stv.libfunc;

          /* Check if this is a load call */
          if ( strcmp(libFunc->libFuncName, "load") == 0 ) {
            printf("Sorry, load in interactive mode is not implemented yet\n");
            return;
          }
        }
      }

    }


    switch ( setjmp(endingJmpBuf) ) {
    case JMP_CODE_INITIAL:
        /* Start descending and evaluating the AST */
      interpret_statements_(stmt, PROVIDE_CONTEXT_INIT(), NULL, NULL);
      break;
    case JMP_CODE_TEARDOWN:
      // free thread context
      freeContext(syncCtx);

      // Close namespaces
      close_namespaces(PROVIDE_CONTEXT_INIT());

      // free locals
      free(varLocals);

      // free heap
      free_heap(hp, hb);

      // Free stack
      FREE_STACK(sp, sb);

      // Free memory associated with the AST
      free_ast(stmt);
      break;
    default:
      break;
    }
  }

  if ( teardown != 0 ) {
    // free thread context
    freeContext(syncCtx);
    
    // Close namespaces
    close_namespaces(PROVIDE_CONTEXT_INIT());

    // free locals
    free(varLocals);

    // free heap
    free_heap(hp, hb);

    // Free stack
    FREE_STACK(sp, sb);

    // Free memory associated with the AST
    free_ast(stmt);
  }
}

static int isAnInt(char *arg) {
  char *c = arg;
  while ( *c ) {
    if ( !isdigit(*c) ) {
      return 0;
    }
    ++c;
  }
  return 1;
}

static int isAFloat(char *arg) {
  char *c = arg;
  int nbrDots = 0;
  while ( *c ) {
    if ( !isdigit(*c) ) {
      // It might be a dot
      if ( *c != '.' ) {
        return 0;
      } else {
        if ( nbrDots == 1 ) {
          return 0;
        }
        nbrDots++;
      }
    }
    ++c;
  }

  if ( nbrDots == 1 ) {
    return 1;
  }

  return 0;
}

static int typeOfArgument(char *arg)
{
  if ( strlen(arg) == 1 && arg[0] == '.' ) {
    return TEXT;
  }

  if ( isAFloat(arg) ) {
    return DOUBLETYPE;
  }

  if ( isAnInt(arg) ) {
    return INT32TYPE;
  }

  return TEXT;
}

static char *reservedArgs[] = {
  "-pi", "-p", "-i", "-h", "--help"
};

static char *argumentListName = "args";

void arguments_to_variables(PROVIDE_CONTEXT_ARGS(), int argc, char* argv[], void *hp)
{
  /*
  * Invoking the program with command arguments:
  * --args value1 value2 ... valueN
  * will populate the global variable
  * args, which is a vector with max 10 arguments.
  */

  int heapUpdated;
  stackval_t sv;
  heapval_t *hvp = NULL;
  int argWalk = 0;
  int argCount = 0;
  int nbrReserved = sizeof(reservedArgs) / sizeof(*reservedArgs);
  int maxNbrArgs = MAX_NBR_ARGUMENTS;
  expr_t *args;
  argsList_t *argContent = NULL;

  if ( argc < 2 ) {
    /* Not OK :/ */
    return;
  }

  while ( argWalk < argc && argCount < maxNbrArgs ) {
    char *arg = argv[argWalk];
    int argWalkReserved = 0;
    int ignore = 0;
    int argType;
    expr_t *newArgExp;
    argsList_t *newArgContent;

    // Some arguments are not to be passed to the environment
    while ( argWalkReserved < nbrReserved ) {
      if ( strcmp(reservedArgs[argWalkReserved], arg) == 0 ) {
        // ignore this argument
        ignore = 1;
        break;
      }
      argWalkReserved++;
    }

    if ( ignore ) {
      argWalk++;
      continue;
    }

    newArgContent = ast_emalloc(sizeof(argsList_t));

    argType = typeOfArgument(arg);
    sv.type = argType;
    switch ( argType )
    {
    case INT32TYPE:
    {
      newArgExp = newExpr_Ival(atoi(arg));
      break;
    }
    case DOUBLETYPE:
    {
      newArgExp = newExpr_Float(atof(arg));
      break;
    }
    case TEXT:
    {
      newArgExp = newExpr_Text(arg);
      break;
    }
    default:
      fprintf(stderr, "There was something strange with the provided argument..\r\n");
      GENERAL_REPORT_ISSUE_MSG();
    break;
    }

    newArgContent->arg = newArgExp;
    if ( argContent == NULL ) {
      argContent = newArgContent;
      argContent->length = 1;
      argContent->next = NULL;
    } else {
      newArgContent->next = argContent;
      newArgContent->length = argContent->length + 1;
      argContent = newArgContent;
    }

    argWalk++;
  }

  args = newExpr_Vector(argContent);

  /* Add space for argN */
  sv.type = VECTORTYPE;
  sv.vec = args->vec;
  free(args);

  ALLOC_HEAP_UNSAFE(&sv, hp, &hvp, &heapUpdated);

  /* Placing variable declaration in global variable namespace */
  hashtable_put(PROVIDE_CONTEXT()->varDecs, NULL, argumentListName, hvp);
}

dictionary_t* allocNewDictionary(dictionary_t *dict, EXPRESSION_PARAMS()) {
  void *hp = PROVIDE_CONTEXT()->hp;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  dictionary_t *newDict = ast_emalloc(sizeof(dictionary_t));
  newDict->hash = hashtable_new(
    DICTIONARY_STANDARD_SIZE, DICTIONARY_STANDARD_LOAD);
  newDict->hash->key_also = 1;

  if ( dict->initialized == 0 ) {
    keyValList_t *walk = dict->keyVals;
    while ( walk != NULL ) {
      /* Dictionary already initialized, evaluate expressions in the key-value list */
      expr_t *expKey = walk->key;
      expr_t *expVal = walk->val;
      char *newKeyStr = NULL;  // Storing the key
      heapval_t *hvp = NULL;  // Storing the value
      stackval_t sv;
      int dummy;  // todo: remove the need for this..

      evaluate_expression(expKey, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      switch (sv.type) {
        case TEXT: {
          size_t len = strlen(sv.t);
          newKeyStr = ast_emalloc(len+2);
          snprintf(newKeyStr, len+2, "%s", sv.t);
          break;
        }
        default:
        fprintf(stderr, "Error: Invalid dictionary expression, keys must be given as strings.\r\n");
        exit(1);
        break;
      }

      evaluate_expression(expVal, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);
      /* Push all values to the heap */
      switch ( sv.type ) {
      case DOUBLETYPE:
      case POINTERTYPE:
      case INT32TYPE:
      case LIBFUNCPTRTYPE:
      case FUNCPTRTYPE:
      case TIMETYPE:
        ALLOC_HEAP(&sv, hp, &hvp, &dummy);
        break;
      case VECTORTYPE: {
        expr_t *eTemp = ast_emalloc(sizeof(expr_t));
        expr_t *newVecExpr = NULL;
        stackval_t newStackVal;

        eTemp->type = EXPR_TYPE_VECTOR;
        eTemp->vec = sv.vec;

        newVecExpr = newExpr_Copy(eTemp);
        free(eTemp);

        newStackVal = sv;
        newStackVal.vec = newVecExpr->vec;

        free(newVecExpr);

        ALLOC_HEAP(&newStackVal, hp, &hvp, &dummy);
        break;
      }
      case TEXT: {
        size_t len = strlen(sv.t);
        stackval_t newStackVal;

        char *newText = ast_emalloc(len+1);
        snprintf(newText, len+1, "%s", sv.t);

        newStackVal = sv;
        newStackVal.t = newText;

        ALLOC_HEAP(&newStackVal, hp, &hvp, &dummy);
        break;
      }
      case DICTTYPE: {
        dictionary_t *newDict = allocNewDictionary(expVal->dict, EXPRESSION_ARGS());
        stackval_t newStackVal = sv;

        newStackVal.dict = newDict;

        ALLOC_HEAP(&newStackVal, hp, &hvp, &dummy);
        break;
      }
      default:
        fprintf(stderr, "Error: Unexpected dictionary expression, value provided not valid in dictionary expressions.\r\n");
        exit(1);
        break;
      }
      /* Adding heap allocated value to dictionary hash table */
      hashtable_put(newDict->hash, PROVIDE_CONTEXT()->syncCtx, newKeyStr, hvp);

      walk = walk->next;
    }
  } else {
    /* Dictionary already initialized, traverse hashtable */
    hashtable_t *hash = dict->hash;
    int size = hash->size;
    int i = 0;
    struct key_val_pair *walk;
    while ( i < size ) {
      walk = hash->table[i];
      while ( walk != NULL ) {
        // Time to evaluate the keys and the values
        char *key = walk->key;
        heapval_t *hpVal = (heapval_t*)walk->data;
        char *newKeyStr = NULL;  // Storing the key
        heapval_t *hvp = NULL;  // Storing the value
        stackval_t sv;
        int dummy;  // todo: remove the need for this..
        size_t len = strlen(key);
        newKeyStr = ast_emalloc(len+2);
        snprintf(newKeyStr, len+2, "%s", key);

        sv = hpVal->sv;
        /* Push all values to the heap */
        switch ( sv.type ) {
        case DOUBLETYPE:
        case POINTERTYPE:
        case INT32TYPE:
        case LIBFUNCPTRTYPE:
        case FUNCPTRTYPE:
        case TIMETYPE:
          ALLOC_HEAP(&sv, hp, &hvp, &dummy);
          break;
        case VECTORTYPE: {
          expr_t *eTemp = ast_emalloc(sizeof(expr_t));
          expr_t *newVecExpr = NULL;
          stackval_t newStackVal;

          eTemp->type = EXPR_TYPE_VECTOR;
          eTemp->vec = sv.vec;

          newVecExpr = newExpr_Copy(eTemp);
          free(eTemp);

          newStackVal = sv;
          newStackVal.vec = newVecExpr->vec;

          free(newVecExpr);

          ALLOC_HEAP(&newStackVal, hp, &hvp, &dummy);
          break;
        }
        case TEXT: {
          size_t len = strlen(sv.t);
          stackval_t newStackVal;

          char *newText = ast_emalloc(len+1);
          snprintf(newText, len+1, "%s", sv.t);

          newStackVal = sv;
          newStackVal.t = newText;

          ALLOC_HEAP(&newStackVal, hp, &hvp, &dummy);
          break;
        }
        case DICTTYPE: {
          dictionary_t *newDict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
          stackval_t newStackVal = sv;

          newStackVal.dict = newDict;

          ALLOC_HEAP(&newStackVal, hp, &hvp, &dummy);
          break;
        }
        default:
          fprintf(stderr, "Error: Unexpected dictionary expression, value provided not valid in dictionary expressions.\r\n");
          exit(1);
          break;
        }
        /* Adding heap allocated value to dictionary hash table */
        hashtable_put(newDict->hash, PROVIDE_CONTEXT()->syncCtx, newKeyStr, hvp);

        walk = walk->next;
      }
      i++;
    }
  }

  newDict->initialized = 1;

  return newDict;
}

