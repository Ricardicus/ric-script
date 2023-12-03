#include "eval.h"
#include <stdarg.h>

#if 0
/* I define and use this function during debugging of the interpreter */
#define debugPrint(format, ...)                                           \
  do {                                                                    \
    printf("Debug %s.%d: " format "\n", __FILE__, __LINE__, __VA_ARGS__); \
  } while (0)
#endif

#define ERROR(format, ...)                                                         \
  do {                                                                             \
    fprintf(stderr, "error %s.%d: " format "\n", __FILE__, __LINE__, __VA_ARGS__); \
  } while (0)

void push_stackval(stackval_t *stackval, PROVIDE_CONTEXT_ARGS()) {
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
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
    case BIGINT: {
      PUSH_BIGINT(sv.bigInt, sp, sc);
      break;
    }
    default:
      fprintf(stderr, "error: Unknown stackval_t type: %d\n", sv.type);
      exit(1);
      break;
  }
}

void push_heapval(heapval_t *hv, PROVIDE_CONTEXT_ARGS()) {
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  if (hv != NULL) {
    switch (hv->sv.type) {
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
      case BIGINT:
        PUSH_BIGINT(hv->sv.bigInt, sp, sc);
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

int evaluate_indexer(indexer_t *indexer, int max, int *idxStart_, int *idxEnd_, int *offset_,
                     EXPRESSION_PARAMS()) {
  stackval_t sv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  int *interactive = PROVIDE_CONTEXT()->interactive;
  expr_t *left = indexer->left;
  expr_t *right = indexer->right;
  expr_t *offsetExp = indexer->offset;
  int idxStart = 0;
  int idxEnd = max;
  int offset = 1;

  if (left == NULL) {
    idxStart = 0;
  } else {
    /* Evaluate the left expression */
    evaluate_expression(left, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    if (sv.type != INT32TYPE) {
      fprintf(stderr, "error: expression for indexing must be an integer, was: %d\n", sv.type);
      if (!*interactive) {
        exit(1);
      }
      return -1;
    }

    idxStart = (int)sv.i;
  }

  if (right == NULL) {
    idxEnd = max;
  } else {
    /* Evaluate the left expression */
    evaluate_expression(right, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    if (sv.type != INT32TYPE) {
      fprintf(stderr, "error: expression for indexing must be an integer, was: %d\n", sv.type);
      if (!*interactive) {
        exit(1);
      }
      return -1;
    }

    idxEnd = (int)sv.i;
  }

  if (offsetExp != NULL) {
    /* Evaluate the left expression */
    evaluate_expression(offsetExp, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    if (sv.type != INT32TYPE) {
      fprintf(stderr, "error: expression for indexing must be an integer, was: %d\n", sv.type);
      if (!*interactive) {
        exit(1);
      }
      return -1;
    }

    offset = (int)sv.i;
  }

  if (idxStart < 0) {
    idxStart = idxStart + max;
  }

  if (idxEnd < 0) {
    idxEnd = idxEnd + max;
  }

  if (idxStart < 0 || idxStart > max || (idxEnd > 0 && idxStart > idxEnd)) {
    fprintf(stderr, "error: invalid value for indexing, %d:%d for list with interval [0, %d]\n",
            idxStart, idxEnd, max);
    if (!*interactive) {
      exit(1);
    }
    return -1;
  }

  if (idxEnd > max || (idxEnd > 0 && idxEnd < idxStart)) {
    fprintf(stderr, "error: invalid value for indexing, %d:%d for list with interval [0, %d]\n",
            idxStart, idxEnd, max);
    if (!*interactive) {
      exit(1);
    }
    return -1;
  }

  if (idxEnd < 0) {
    int diff = max + idxEnd;
    if (diff > idxStart) {
      idxEnd = diff;
    } else {
      fprintf(stderr, "error: invalid value for indexing, %d:%d for list with interval [0, %d]\n",
              idxStart, idxEnd, max);
      if (!*interactive) {
        exit(1);
      }
      return -1;
    }
  }

  *idxStart_ = idxStart;
  *idxEnd_ = idxEnd;
  *offset_ = offset;
  return 0;
}

int push_expression(expr_t *expArg, EXPRESSION_PARAMS()) {
  int ret = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  if (expArg != NULL) {
    /* This was an argument! */
    switch (expArg->type) {
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
      case EXPR_TYPE_BIGINT:
        PUSH_BIGINT(expArg->bigInt, sp, sc);
        break;
      case EXPR_TYPE_TEXT: {
        PUSH_STRING(expArg->text, sp, sc);
        break;
      }
      default:
        ret = -1;
        break;
    }
  } else {
    ret = -1;
  }
  return ret;
}

expr_t *stackval_to_expression(stackval_t *sv, EXPRESSION_PARAMS()) {
  expr_t *newExp = NULL;

  switch (sv->type) {
    case INT32TYPE:
      newExp = newExpr_Ival(sv->i);
      break;
    case DOUBLETYPE:
      newExp = newExpr_Float(sv->d);
      break;
    case TEXT:
      newExp = newExpr_Text(sv->t);
      break;
    case TIMETYPE:
      newExp = newExpr_Time(sv->time);
      break;
    case POINTERTYPE:
      newExp = newExpr_Pointer(sv->p);
      break;
    case FUNCPTRTYPE:
      newExp = newExpr_FuncPtr(sv->func);
      break;
    case LIBFUNCPTRTYPE:
      newExp = newExpr_LibFuncPtr(sv->libfunc);
      break;
    case BIGINT:
      newExp = newExpr_BigInt(sv->bigInt);
      break;
    case RAWDATATYPE: {
      newExp = newExpr_RawData(sv->rawdata->size);
      memcpy(newExp->rawdata->data, sv->rawdata->data, sv->rawdata->size);
      break;
    }
    case VECTORTYPE: {
      newExp = copy_vector(sv->vec, EXPRESSION_ARGS());
      break;
    }
    case DICTTYPE: {
      newExp = ast_emalloc(sizeof(expr_t));
      newExp->type = EXPR_TYPE_DICT;
      newExp->dict = allocNewDictionary(sv->dict, EXPRESSION_ARGS());
      break;
    }
    case CLASSTYPE: {
      newExp = newExpr_ClassPtrCopy(sv->classObj);
      break;
    }
    default:
      fprintf(stderr, "%s.error: unknown type of value on the stack (%d)\n", __func__, sv->type);
      GENERAL_REPORT_ISSUE_MSG();
      exit(1);
      break;
  }

  return newExp;
}

int evaluate_condition(ifCondition_t *cond, EXPRESSION_PARAMS()) {
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

  switch (cond->type) {
    case CONDITION_EQ: {
      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {

        if (svLeft.i == svRight.i) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        *f0 = (double)svLeft.i;

        if (fabs(*f0 - svRight.d) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        *f0 = svRight.d;
        *f1 = svLeft.d;

        if (fabs(*f0 - *f1) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        *f0 = (double)svRight.i;

        if (fabs(*f0 - svLeft.d) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == TEXT && svRight.type == TEXT) {
        *ax = strcmp(svLeft.t, svRight.t) == 0;
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        int cmp = mpz_cmp(*svLeft.bigInt, *svRight.bigInt);
        if (cmp == 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        int cmp = mpz_cmp_si(*svLeft.bigInt, (long)svRight.i);
        if (cmp == 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        int cmp = mpz_cmp_si(*svRight.bigInt, (long)svLeft.i);
        if (cmp == 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      }
      break;
    }
    case CONDITION_NEQ: {
      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {

        if (svLeft.i != svRight.i) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        *f0 = (double)svLeft.i;

        if (fabs(*f0 - svRight.d) > epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        *f0 = svRight.d;
        *f1 = svLeft.d;

        if (fabs(*f0 - *f1) > epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        *f0 = (double)svRight.i;

        if (fabs(*f0 - svLeft.d) > epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == TEXT && svRight.type == TEXT) {
        *ax = !(strcmp(svLeft.t, svRight.t) == 0);
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        int cmp = mpz_cmp(*svLeft.bigInt, *svRight.bigInt);
        if (cmp != 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        int cmp = mpz_cmp_si(*svLeft.bigInt, (long)svRight.i);
        if (cmp != 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        int cmp = mpz_cmp_si(*svRight.bigInt, (long)svLeft.i);
        if (cmp != 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      }
      break;
    }
    case CONDITION_LEQ: {
      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {

        if (svLeft.i <= svRight.i) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        *f0 = (double)svLeft.i;

        if (*f0 - svRight.d < -epsilon || fabs(*f0 - svRight.d) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        *f0 = svLeft.d;
        *f1 = svRight.d;

        if (*f0 - *f1 < -epsilon || fabs(*f0 - *f1) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        *f1 = (double)svRight.i;

        if (svLeft.d - *f1 < -epsilon || fabs(svLeft.d - *f1) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        int cmp = mpz_cmp(*svLeft.bigInt, *svRight.bigInt);
        if (cmp <= 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        int cmp = mpz_cmp_si(*svLeft.bigInt, (long)svRight.i);
        if (cmp <= 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        int cmp = mpz_cmp_si(*svRight.bigInt, (long)svLeft.i);
        if (cmp >= 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      }
      break;
    }
    case CONDITION_GEQ: {
      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {

        if (svLeft.i >= svRight.i) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        *f0 = (double)svLeft.i;

        if (*f0 - svRight.d > epsilon || fabs(*f0 - svRight.d) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        *f0 = svLeft.d;
        *f1 = svRight.d;

        if (*f0 - *f1 > epsilon || fabs(*f0 - *f1) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        *f1 = (double)svRight.i;

        if (svLeft.d - *f1 > epsilon || fabs(svLeft.d - *f1) < epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        int cmp = mpz_cmp(*svLeft.bigInt, *svRight.bigInt);
        if (cmp >= 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        int cmp = mpz_cmp_si(*svLeft.bigInt, (long)svRight.i);
        if (cmp >= 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        int cmp = mpz_cmp_si(*svRight.bigInt, (long)svLeft.i);
        if (cmp <= 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      }
      break;
    }
    case CONDITION_GE: {
      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {

        if (svLeft.i > svRight.i) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        *f0 = (double)svLeft.i;

        if (*f0 - svRight.d > epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        *f0 = svLeft.d;
        *f1 = svRight.d;

        if (*f0 - *f1 > epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        *f1 = (double)svRight.i;

        if (svLeft.d - *f1 > epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        int cmp = mpz_cmp(*svLeft.bigInt, *svRight.bigInt);
        if (cmp > 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        int cmp = mpz_cmp_si(*svLeft.bigInt, (long)svRight.i);
        if (cmp > 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        int cmp = mpz_cmp_si(*svRight.bigInt, (long)svLeft.i);
        if (cmp < 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      }
      break;
    }
    case CONDITION_LE: {
      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {

        if (svLeft.i < svRight.i) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        *f0 = (double)svLeft.i;

        if (*f0 - svRight.d < -epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }

      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        *f0 = svLeft.d;
        *f1 = svRight.d;

        if (*f0 - *f1 < -epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        *f1 = (double)svRight.i;

        if (svLeft.d - *f1 < -epsilon) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        int cmp = mpz_cmp(*svLeft.bigInt, *svRight.bigInt);
        if (cmp < 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        int cmp = mpz_cmp_si(*svLeft.bigInt, (long)svRight.i);
        if (cmp < 0) {
          *ax = 1;
        } else {
          *ax = 0;
        }
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        int cmp = mpz_cmp_si(*svRight.bigInt, (long)svLeft.i);
        if (cmp > 0) {
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

expr_t *copy_vector(vector_t *vec, EXPRESSION_PARAMS()) {
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *sp = PROVIDE_CONTEXT()->sp;
  // The idea is to create a new vector based on
  // a raw one, where all identifiers have been replaced
  // with their actual value
  expr_t *newVec = newExpr_Vector(NULL);
  argsList_t *newContent = NULL;
  argsList_t *walk = vec->content;
  statement_t *forEach = vec->forEach;

  if (walk != NULL) {
    argsList_t *prev = NULL;
    argsList_t *current;
    argsList_t *walknext;

    while (walk != NULL) {
      stackval_t sv;
      expr_t *newExp;
      evaluate_expression(walk->arg, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      newExp = stackval_to_expression(&sv, EXPRESSION_ARGS());

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

  } else if (forEach != NULL) {
    void *sp;
    size_t *sc = PROVIDE_CONTEXT()->sc;
    locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
    stackval_t sv;
    size_t stackCount = *sc;
    int *interactive = PROVIDE_CONTEXT()->interactive;
    int interactiveTmp = *interactive;

    /* Moving along, interpreting function */
    int localsStackSp = varLocals->sp;
    int localsStackSb = varLocals->sb;

    *interactive = INTERACTIVE_STACK;

    interpret_statements_(forEach, PROVIDE_CONTEXT(), args, argVals);

    varLocals->sb = localsStackSb;
    varLocals->sp = localsStackSp;

    sp = PROVIDE_CONTEXT()->sp;
    sc = PROVIDE_CONTEXT()->sc;
    *interactive = interactiveTmp;

    if (*sc > stackCount) {
      /* Get the stack dump vector */
      POP_VAL(&sv, sp, sc);
      if (sv.type != VECTORTYPE) {
        fprintf(stderr, "%s.%d Unfold foreach expression\n", ((statement_t *)stmt)->file,
                ((statement_t *)stmt)->line);
        exit(1);
      }

      free(newVec->vec);
      newVec->vec = sv.vec;
    }
  }

  return newVec;
}

void evaluate_expression(expr_t *expr, EXPRESSION_PARAMS()) {
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
  if (expr == NULL) return;
  switch (expr->type) {
    case EXPR_TYPE_ID: {
      heapval_t *hv = NULL;
      int stop = 0;
      argsList_t *walk = NULL;

      /* Check if it is among the class context members */
      if (classCtx != NULL) {
        functionDef_t *classFunc = NULL;
        libFunction_t *classFuncABI = NULL;
        hv = hashtable_get(classCtx->varMembers, PROVIDE_CONTEXT()->syncCtx, expr->id.id);

        if (hv != NULL) {
          push_heapval(hv, PROVIDE_CONTEXT());
          stop = 1;
        }

        classFunc =
            hashtable_get(classCtx->funcDefsScript, PROVIDE_CONTEXT()->syncCtx, expr->id.id);
        if (classFunc != NULL) {
          // Pushing the function definition
          PUSH_FUNCPTR(classFunc, sp, sc);
          stop = 1;
        }

        if (!stop) {
          classFuncABI =
              hashtable_get(classCtx->funcDefsABI, PROVIDE_CONTEXT()->syncCtx, expr->id.id);
          if (classFuncABI != NULL) {
            // Pushing the ABI function
            PUSH_LIBFUNCPTR(classFuncABI, sp, sc);
            stop = 1;
          }
        }
      }

      if (!stop) {
        class_t *classDef;      // if it is a class construction reference
        functionDef_t *funcDef; // if it is a function pointer

        /* Check among the locals if we have it defined there */
        hv = locals_lookup(varLocals, expr->id.id);

        if (hv == NULL) {
          /* Check if this ID is among the arguments */
          walk = args;

          while (walk != NULL && !stop) {
            expr_t *exp = walk->arg;
            if (exp->type == EXPR_TYPE_ID) {
              expr_t *expArg;

              /* Check among the arguments if we have it defined there */
              expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, expr->id.id);

              if (push_expression(expArg, EXPRESSION_ARGS()) == 0) {
                stop = 1;
              }
            } else {
              fprintf(stderr,
                      "error: unknown, this is crazy. The interpreter is broken or something.\n\
    Please report back to me.\n\
    - %s\n",
                      GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            walk = walk->next;
          }
        } else {
          push_heapval(hv, PROVIDE_CONTEXT());
          stop = 1;
        }

        if (stop) {
          break;
        }
        /* Check among the global variables if we have it defined there */
        hv = hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, expr->id.id);

        if (hv != NULL) {
          push_heapval(hv, PROVIDE_CONTEXT());
          stop = 1;
        }

        if (stop) {
          break;
        }
        /* Check among the class declaration if we have this id defined there */
        classDef =
            hashtable_get(PROVIDE_CONTEXT()->classDecs, PROVIDE_CONTEXT()->syncCtx, expr->id.id);
        if (classDef != NULL) {
          PUSH_CLASSREF(classDef, sp, sc);
          stop = 1;
        }

        if (!stop) {
          /* Check among the function declarations if we have it defined there */
          funcDef =
              hashtable_get(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, expr->id.id);
          if (funcDef != NULL) {
            // Pushing the function definition
            PUSH_FUNCPTR(funcDef, sp, sc);
            stop = 1;
          }
        }

        if (!stop) {
          /* Check among the standard lib function declarations if we have it defined there */
          libFunction_t *libFunc = look_up_lib(expr->id.id);

          if (libFunc != NULL) {
            PUSH_LIBFUNCPTR(libFunc, sp, sc);
            stop = 1;
          }
        }
      }

      if (!stop) {
        fprintf(stderr, "%s.%d Failed to find ID: '%s'\n", ((statement_t *)stmt)->file,
                ((statement_t *)stmt)->line, expr->id.id);
        if (!*interactive) {
          exit(1);
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
    case EXPR_TYPE_INDEXER:
      PUSH_INDEXER(expr->indexer, sp, sc);
      break;
    case EXPR_TYPE_FUNCPTR:
      PUSH_FUNCPTR(expr->func, sp, sc);
      break;
    case EXPR_TYPE_LIBFUNCPTR:
      PUSH_LIBFUNCPTR(expr->func, sp, sc);
      break;
    case EXPR_TYPE_BIGINT: {
      PUSH_BIGINT(expr->bigInt, sp, sc);
      break;
    }
    case EXPR_TYPE_VECTOR:
      PUSH_VECTOR(expr->vec, sp, sc);
      break;
    case EXPR_TYPE_LOGICAL: {
      int32_t result = 0;
      int32_t walk;
      stackval_t sv;
      logical_t *logic = expr->logical;

      if (logic->orsLen > 0) {
        walk = 0;
        while (walk < logic->orsLen && result == 0) {
          evaluate_expression(logic->ors[walk], EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);
          switch (sv.type) {
            case INT32TYPE: {
              if (sv.i != 0) {
                result = 1;
              }
              break;
            }
            case BIGINT: {
              result = (mpz_cmp_si(*sv.bigInt, 0) != 0);
              break;
            }
            case DOUBLETYPE: {
              if (fabs(sv.d) > 0.00000001) {
                result = 1;
              }
              break;
            }
            default: {
              fprintf(stderr,
                      "%s.%d error: Invalid conditional, expected numerical; got type '%d'\n",
                      ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, sv.type);
            }
          }
          walk++;
        }
      }
      if (result == 0 && logic->andsLen > 0) {
        walk = 0;
        result = 1; // True, until proven otherwise..
        while (walk < logic->andsLen) {
          int32_t tmpResult = 0;
          evaluate_expression(logic->ands[walk], EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);
          switch (sv.type) {
            case INT32TYPE: {
              if (sv.i != 0) {
                tmpResult = 1;
              }
              break;
            }
            case BIGINT: {
              result = (mpz_cmp_si(*sv.bigInt, 0) != 0);
              break;
            }
            case DOUBLETYPE: {
              if (fabs(sv.d) > 0.00000001) {
                tmpResult = 1;
              }
              break;
            }
            default: {
              fprintf(stderr, "%s.%d index error: datatype the does not support conditioning.\n",
                      ((statement_t *)stmt)->file, ((statement_t *)stmt)->line);
              if (!*interactive) {
                exit(1);
              }
            }
          }
          walk++;
          if (tmpResult == 0) {
            result = 0;
            break;
          }
        }
      }

      PUSH_INT(result, sp, sc);
      break;
    }
    case EXPR_TYPE_DICT:
      PUSH_DICTIONARY(expr->dict, sp, sc);
      break;
    case EXPR_TYPE_RAWDATA:
      PUSH_RAWDATA(expr->rawdata, sp, sc);
      break;
    case EXPR_TYPE_VECTOR_IDX: {
      int32_t arrayIndex = 0;
      vector_t *vec = NULL;
      dictionary_t *dict = NULL;
      argsList_t *walk;
      char *text = NULL;
      rawdata_t *rawdata = NULL;
      int typeOfVal = 0;
      expr_t *exp = NULL;
      expr_t *id = expr->vecIdx->expr;
      expr_t *index = expr->vecIdx->index;

      stackval_t sv;

      if (id->type == EXPR_TYPE_ID || id->type == EXPR_TYPE_VECTOR_IDX
          || id->type == EXPR_TYPE_FUNCCALL) {
        evaluate_expression(id, EXPRESSION_ARGS());
        POP_VAL(&sv, sp, sc);

        if (sv.type != VECTORTYPE && sv.type != DICTTYPE && sv.type != TEXT
            && sv.type != RAWDATATYPE) {
          fprintf(stderr, "%s.%d index error: '%s' is a datatype the does not support indexing.\n",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, id->id.id);
          if (!*interactive) {
            exit(1);
          }
        }

        typeOfVal = sv.type;
        if (sv.type == VECTORTYPE) {
          vec = sv.vec;
        } else if (sv.type == DICTTYPE) {
          dict = sv.dict;
        } else if (sv.type == TEXT) {
          text = sv.t;
        } else if (sv.type == RAWDATATYPE) {
          rawdata = sv.rawdata;
        }
      } else {
        fprintf(stderr, "error: Invalid indexing %d\n", id->type);
        exit(1);
      }

      switch (typeOfVal) {
        case DICTTYPE: {
          /* Dictionary indexing */
          char *key = NULL;
          heapval_t *hpv;

          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if (sv.type != TEXT) {
            fprintf(stderr, "index error: Must provide an string as index for dictionaries\n");
            exit(1);
          }

          key = sv.t;

          /* find heapval */
          hpv = hashtable_get(dict->hash, PROVIDE_CONTEXT()->syncCtx, key);
          if (hpv == NULL) {
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
            case BIGINT: {
              PUSH_BIGINT(sv.bigInt, sp, sc);
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
        } break;
        case VECTORTYPE: {
          /* Array indexing */
          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if (sv.type != INT32TYPE && sv.type != INDEXER) {
            fprintf(stderr, "index error: Must provide a correct indexer value as index\n");
            exit(1);
          }

          if (sv.type == INT32TYPE) {
            arrayIndex = sv.i;

            /* check the limits */
            if (arrayIndex >= vec->length) {
              fprintf(stderr,
                      "index error: index: '%" PRIi32 "' is too large, length: '%" PRIi32 "'\n",
                      arrayIndex, vec->length);
              exit(1);
            } else if (arrayIndex < 0) {
              arrayIndex = vec->length - ((vec->length - arrayIndex) % vec->length);
            }

            walk = vec->content;
            while (walk != NULL && arrayIndex >= 0) {
              exp = walk->arg;
              walk = walk->next;
              --arrayIndex;
            }

            if (exp == NULL) {
              fprintf(stderr, "Unexpected index error!\n");
              fprintf(stderr,
                      "Please include the script and file an error report to me here:\n    %s\n\
      This is not supposed to happen, I hope I can fix the intepreter!\n",
                      GENERAL_ERROR_ISSUE_URL);
              exit(1);
            }

            /* Evaluate the expression */
            evaluate_expression(exp, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);
            push_stackval(&sv, PROVIDE_CONTEXT());
          } else if (sv.type == INDEXER) {
            indexer_t *indexer = sv.indexer;
            int idxStart = 0;
            int idxEnd = vec->length;
            int idxWalk = 0;
            int offset = 1;
            expr_t *newVec = NULL;
            argsList_t *vecContent = NULL;
            argsList_t *walk = NULL;
            heapval_t *hpv;
            int dummy;

            (void)evaluate_indexer(indexer, vec->length, &idxStart, &idxEnd, &offset,
                                   EXPRESSION_ARGS());

            /* Create a new list */
            walk = vec->content;
            idxWalk = 0;
            while (walk != NULL) {
              int offsetCount;
              if (idxWalk >= idxStart && idxWalk < idxEnd) {
                /* Add this expression to the vector */
                argsList_t *a;
                expr_t *e = walk->arg;
                e = newExpr_Copy(e);
                a = newArgument(e, vecContent);
                vecContent = a;
              }
              offsetCount = 0;
              while (walk && offsetCount < abs(offset)) {
                walk = walk->next;
                idxWalk++;
                offsetCount++;
              }
            }

            newVec = newExpr_Vector(vecContent);

            if (offset < 0) {
              argsList_t *prevArg;
              argsList_t *nextArg;
              argsList_t *currentArg;
              /* Reverse the args list order */
              walk = newVec->vec->content;
              prevArg = NULL;
              currentArg = walk;
              while (currentArg != NULL) {
                nextArg = currentArg->next;
                currentArg->next = prevArg;
                prevArg = currentArg;
                currentArg = nextArg;
              }
              newVec->vec->content = prevArg;
            }

            /* Add space for argN */
            sv.type = VECTORTYPE;
            sv.vec = newVec->vec;

            ALLOC_HEAP(&sv, hp, &hpv, &dummy);

            PUSH_VECTOR(newVec->vec, sp, sc);
            free(newVec);
          }
        } break;
        case TEXT: {
          size_t len = 1;
          stackval_t sv;
          heapval_t *hvp;
          int heapUpdated;
          char *newText = NULL;
          size_t origLen = strlen(text);

          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if (sv.type != INT32TYPE && sv.type != INDEXER) {
            fprintf(stderr,
                    "index error: Must provide a valid expression as indexer, value type: (%d)\n",
                    sv.type);
            exit(1);
          }

          if (sv.type == INT32TYPE) {
            arrayIndex = sv.i;

            if (arrayIndex < 0) {
              arrayIndex = origLen - ((origLen - arrayIndex) % origLen);
            } else if (arrayIndex >= origLen) {
              fprintf(stderr, "index error: out of bounds (index: %d, size: %zu)\n", arrayIndex,
                      origLen);
              if (!*interactive) {
                exit(1);
              }
            }

            newText = ast_emalloc(len + 1);
            newText[0] = text[arrayIndex];
            newText[1] = 0;
            sv.type = TEXT;
            sv.t = newText;

            ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);
            PUSH_STRING(sv.t, sp, sc);
          } else if (sv.type == INDEXER) {
            indexer_t *indexer = sv.indexer;
            int idxStart = 0;
            int idxEnd = (int)strlen(text);
            int idxWalk = 0;
            int textLen = (int)strlen(text);
            int offset = 1;
            char *newText = NULL;
            expr_t *newTextExp = NULL;
            heapval_t *hpv;
            int dummy;

            (void)evaluate_indexer(indexer, textLen, &idxStart, &idxEnd, &offset,
                                   EXPRESSION_ARGS());

            /* Create a new string */
            newText = (char *)ast_ecalloc(idxEnd - idxStart + 2);
            idxWalk = offset >= 0 ? 0 : textLen - 1;
            if (offset == 0) {
              offset = 1; // corner case, will correct this.
            }
            int idxWritten = 0;
            while (idxWalk < textLen && idxWalk >= 0) {
              if (idxWalk >= idxStart && idxWalk < idxEnd) {
                /* Add this expression to the vector */
                newText[idxWritten] = text[idxWalk];
                idxWritten++;
              }
              idxWalk += offset;
            }

            newTextExp = newExpr_Text(newText);
            free(newText);

            /* Add space for argN */
            sv.type = TEXT;
            sv.t = newTextExp->text;
            free(newTextExp);

            ALLOC_HEAP(&sv, hp, &hpv, &dummy);
            PUSH_STRING(sv.t, sp, sc);
          }
        } break;
        case RAWDATATYPE: {
          stackval_t sv;

          evaluate_expression(index, EXPRESSION_ARGS());
          POP_VAL(&sv, sp, sc);

          if (sv.type != INT32TYPE && sv.type != INDEXER) {
            fprintf(stderr,
                    "index error: Must provide a valid expression as indexer, value type: (%d)\n",
                    sv.type);
            exit(1);
          }

          if (sv.type == INT32TYPE) {
            arrayIndex = sv.i;

            if (arrayIndex > rawdata->size) {
              fprintf(stderr, "index error: out of bounds\n");
              exit(1);
            }

            sv.type = INT32TYPE;
            sv.i = ((unsigned char *)rawdata->data)[arrayIndex];

            PUSH_INT(sv.i, sp, sc);
          } else if (sv.type == INDEXER) {
            indexer_t *indexer = sv.indexer;
            int idxStart = 0;
            int idxEnd = (int)rawdata->size;
            int idxWalk = 0;
            int dataLen = (int)rawdata->size;
            int offset = 1;
            char *newData = NULL;
            expr_t *newDataExp = NULL;
            heapval_t *hvp;
            int dummy;

            (void)evaluate_indexer(indexer, dataLen, &idxStart, &idxEnd, &offset,
                                   EXPRESSION_ARGS());

            /* Create a new data allocation */
            newData = (char *)ast_ecalloc(idxEnd - idxStart + 2);
            idxWalk = offset >= 0 ? 0 : dataLen - 1;
            if (offset == 0) {
              offset = 1; // corner case, will correct this.
            }
            int idxWritten = 0;
            while (idxWalk < dataLen && idxWalk >= 0) {
              if (idxWalk >= idxStart && idxWalk < idxEnd) {
                /* Add this expression to the vector */
                newData[idxWritten] = ((char *)rawdata->data)[idxWalk];
                idxWritten++;
              }
              idxWalk += offset;
            }

            newDataExp = newExpr_RawData(idxWritten);
            free(newDataExp->rawdata->data);
            newDataExp->rawdata->data = newData;

            sv.type = RAWDATATYPE;
            sv.rawdata = newDataExp->rawdata;
            free(newDataExp);

            ALLOC_HEAP(&sv, hp, &hvp, &dummy);

            PUSH_RAWDATA(sv.rawdata, sp, sc);
          }
        } break;
        default:
          break;
      }
    } break;
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
    } break;
    case EXPR_TYPE_OPADD: {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t *)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t *)expr->add.right, EXPRESSION_ARGS());
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
        case BIGINT:
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
        case BIGINT:
          break;
        default:
          fprintf(stderr, "error %s.%d: Unexpected stackval_t type: %d\n",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, svRight.type);
          exit(1);
          break;
      }

      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {
        PUSH_INT(*r0 + *r1, sp, sc);
      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*r0 + *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*f0 + *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        PUSH_DOUBLE(*f0 + *r1, sp, sc);
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        expr_t *e = newExpr_BigIntFromInt(0);
        stackval_t sv;

        sv.type = BIGINT;
        sv.bigInt = e->bigInt;

        mpz_add(*sv.bigInt, *svLeft.bigInt, *svRight.bigInt);
        PUSH_BIGINT(sv.bigInt, sp, sc);
        free(e);
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        expr_t *e = newExpr_BigIntFromInt(svLeft.i);
        stackval_t sv;

        sv.type = BIGINT;
        sv.bigInt = e->bigInt;

        mpz_add(*sv.bigInt, *sv.bigInt, *svRight.bigInt);

        PUSH_BIGINT(sv.bigInt, sp, sc);
        free(e);
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        expr_t *e = newExpr_BigIntFromInt(svRight.i);
        stackval_t sv;

        sv.type = BIGINT;
        sv.bigInt = e->bigInt;
        mpz_add(*sv.bigInt, *sv.bigInt, *svLeft.bigInt);

        PUSH_BIGINT(sv.bigInt, sp, sc);
        free(e);
      } else if (svLeft.type == TIMETYPE && svRight.type == TIMETYPE) {
        PUSH_DOUBLE(svLeft.time + svRight.time, sp, sc);
      } else if (svLeft.type == TEXT && svRight.type == TEXT) {
        size_t len = strlen(svLeft.t) + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        snprintf(newText, len + 1, "%s%s", svLeft.t, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == TEXT) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        snprintf(newText, len + 1, "%.4f%s", svLeft.d, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == TEXT && svRight.type == DOUBLETYPE) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        snprintf(newText, len + 1, "%s%.4f", svLeft.t, svRight.d);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == TEXT && svRight.type == INT32TYPE) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        snprintf(newText, len + 1, "%s%d", svLeft.t, svRight.i);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == INT32TYPE && svRight.type == TEXT) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        snprintf(newText, len + 1, "%d%s", svLeft.i, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == POINTERTYPE && svRight.type == TEXT) {
        size_t len = 50 + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        snprintf(newText, len + 1, "<%" PRIuPTR ">%s", svLeft.p, svRight.t);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == BIGINT && svRight.type == TEXT) {
        size_t len = RIC_BIG_INT_MAX_SIZE + strlen(svRight.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        char *bigIntBuf = ast_emalloc(RIC_BIG_INT_MAX_SIZE);
        char *bigIntStr = NULL;

        bigIntStr = mpz_get_str(bigIntBuf, 10, *svLeft.bigInt);

        snprintf(newText, len + 1, "%s%s", bigIntStr, svRight.t);

        free(bigIntBuf);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == TEXT && svRight.type == BIGINT) {
        size_t len = RIC_BIG_INT_MAX_SIZE + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        char *bigIntBuf = ast_emalloc(RIC_BIG_INT_MAX_SIZE);
        char *bigIntStr = NULL;

        bigIntStr = mpz_get_str(bigIntBuf, 10, *svRight.bigInt);

        snprintf(newText, len + 1, "%s%s", svLeft.t, bigIntStr);

        free(bigIntBuf);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == TEXT && svRight.type == POINTERTYPE) {
        size_t len = 50 + strlen(svLeft.t);
        stackval_t sv;
        heapval_t *hvp;
        int heapUpdated;
        char *newText = ast_emalloc(len + 1);
        snprintf(newText, len + 1, "%s<%" PRIuPTR ">", svLeft.t, svRight.p);

        sv.type = TEXT;
        sv.t = newText;

        ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

        if (!heapUpdated) {
          free(newText);
          sv = hvp->sv;
        }

        PUSH_STRING(sv.t, sp, sc);
      } else if (svLeft.type == VECTORTYPE
                 && (svRight.type == TEXT || svRight.type == BIGINT || svRight.type == INT32TYPE
                     || svRight.type == DOUBLETYPE)) {
        stackval_t sv;
        heapval_t *hvp;
        argsList_t *vecContent = NULL;
        expr_t *newVec;
        argsList_t *walk = NULL;
        int dummy;
        expr_t *newEntry = NULL;

        walk = svLeft.vec->content;
        while (walk != NULL) {
          stackval_t svTmp;
          evaluate_expression(walk->arg, EXPRESSION_ARGS());
          POP_VAL(&svTmp, sp, sc);

          newEntry = stackval_to_expression(&svTmp, EXPRESSION_ARGS());

          vecContent = newArgument(newEntry, vecContent);
          walk = walk->next;
        }

        sv.type = svRight.type;
        switch (svRight.type) {
          case INT32TYPE: {
            sv.i = svRight.i;
            newEntry = stackval_to_expression(&sv, EXPRESSION_ARGS());
            break;
          }
          case DOUBLETYPE: {
            sv.d = svRight.d;
            newEntry = stackval_to_expression(&sv, EXPRESSION_ARGS());
            break;
          }
          case BIGINT: {
            sv.bigInt = svRight.bigInt;
            newEntry = stackval_to_expression(&sv, EXPRESSION_ARGS());
            break;
          }
          case TEXT: {
            size_t len = 50 + strlen(svRight.t);
            char *newText = ast_emalloc(len + 1);
            snprintf(newText, len + 1, "%s", svRight.t);
            sv.t = newText;
            newEntry = stackval_to_expression(&sv, EXPRESSION_ARGS());
            break;
          }
          default:
            break;
        }

        vecContent = newArgument(newEntry, vecContent);

        newVec = newExpr_Vector(vecContent);

        sv.type = VECTORTYPE;
        sv.vec = newVec->vec;
        free(newVec);

        ALLOC_HEAP(&sv, hp, &hvp, &dummy);
        PUSH_VECTOR(sv.vec, sp, sc);
      } else if (svRight.type == VECTORTYPE && svLeft.type == VECTORTYPE) {
        stackval_t sv;
        heapval_t *hvp;
        argsList_t *vecContent = NULL;
        expr_t *newVec;
        argsList_t *walk = NULL;
        int dummy;

        walk = svLeft.vec->content;
        while (walk != NULL) {
          stackval_t svTmp;
          expr_t *newEntry;
          evaluate_expression(walk->arg, EXPRESSION_ARGS());
          POP_VAL(&svTmp, sp, sc);

          newEntry = stackval_to_expression(&svTmp, EXPRESSION_ARGS());

          vecContent = newArgument(newEntry, vecContent);
          walk = walk->next;
        }
        walk = svRight.vec->content;
        while (walk != NULL) {
          stackval_t svTmp;
          expr_t *newEntry;
          evaluate_expression(walk->arg, EXPRESSION_ARGS());
          POP_VAL(&svTmp, sp, sc);

          newEntry = stackval_to_expression(&svTmp, EXPRESSION_ARGS());

          vecContent = newArgument(newEntry, vecContent);
          walk = walk->next;
        }

        newVec = newExpr_Vector(vecContent);

        sv.type = VECTORTYPE;
        sv.vec = newVec->vec;
        free(newVec);

        ALLOC_HEAP(&sv, hp, &hvp, &dummy);
        PUSH_VECTOR(sv.vec, sp, sc);
      }

      break;
    } break;
    case EXPR_TYPE_OPSUB: {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t *)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t *)expr->add.right, EXPRESSION_ARGS());
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
        case BIGINT:
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
        case BIGINT:
          break;
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {
        PUSH_INT(*r0 - *r1, sp, sc);
      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*r0 - *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*f0 - *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        PUSH_DOUBLE(*f0 - *r1, sp, sc);
      } else if (svLeft.type == TIMETYPE && svRight.type == TIMETYPE) {
        PUSH_TIME(svLeft.time - svRight.time, sp, sc);
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        mpz_sub(*n, *svLeft.bigInt, *svRight.bigInt);
        PUSH_BIGINT(n, sp, sc);

        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        expr_t *bigIntEtmp = newExpr_BigIntFromInt(svRight.i);

        mpz_sub(*n, *svLeft.bigInt, *bigIntEtmp->bigInt);

        mpz_clear(*bigIntEtmp->bigInt);
        free(bigIntEtmp->bigInt);
        free(bigIntEtmp);

        PUSH_BIGINT(n, sp, sc);

        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        expr_t *bigIntEtmp = newExpr_BigIntFromInt(svLeft.i);

        mpz_sub(*n, *bigIntEtmp->bigInt, *svRight.bigInt);

        mpz_clear(*bigIntEtmp->bigInt);
        free(bigIntEtmp->bigInt);
        free(bigIntEtmp);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      }

      break;
    }
    case EXPR_TYPE_OPMUL: {
      stackval_t svLeft;
      stackval_t svRight;
      char *leftStr = NULL;
      char *rightStr = NULL;

      evaluate_expression((expr_t *)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t *)expr->add.right, EXPRESSION_ARGS());
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
        case VECTORTYPE:
        case BIGINT:
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

          if (leftStr != NULL) {
            fprintf(stderr, "error: Cannot multiply string with float\n");
            exit(1);
          }
          break;
        }
        case TEXT: {
          rightStr = svRight.t;
          break;
        }
        case VECTORTYPE:
        case BIGINT:
          break;
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {
        PUSH_INT(*r0 * *r1, sp, sc);
      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*r0 * *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*f0 * *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        PUSH_DOUBLE(*f0 * *r1, sp, sc);
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        mpz_mul(*n, *svLeft.bigInt, *svRight.bigInt);

        PUSH_BIGINT(n, sp, sc);

        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        mpz_mul_si(*n, *svLeft.bigInt, (long)svRight.i);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        mpz_mul_si(*n, *svRight.bigInt, (long)svLeft.i);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == TEXT && svRight.type == INT32TYPE) {
        heapval_t *hpv;
        stackval_t stv;
        size_t strLen = strlen(leftStr);
        int32_t mult = *r1;
        int32_t i = 0;
        int dummy;
        char *newStr = ast_emalloc(strLen * mult + 2);

        while (i < mult) {
          snprintf(newStr + (i * strLen), strLen + 1, "%s", leftStr);
          ++i;
        }

        if (mult == 0) newStr[0] = 0;

        newStr[(mult * strLen) + 1] = 0;

        stv.type = TEXT;
        stv.t = newStr;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);

        PUSH_STRING(stv.t, sp, sc);
      } else if (svRight.type == TEXT && svLeft.type == INT32TYPE) {
        heapval_t *hpv;
        stackval_t stv;
        size_t strLen = strlen(rightStr);
        int32_t mult = *r0;
        int32_t i = 0;
        int dummy;
        char *newStr = ast_emalloc(strLen * mult + 2);

        while (i < mult) {
          snprintf(newStr + (i * strLen), strLen + 1, "%s", rightStr);
          ++i;
        }

        if (mult == 0) newStr[0] = 0;

        newStr[(mult * strLen) + 1] = 0;

        stv.type = TEXT;
        stv.t = newStr;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);

        PUSH_STRING(stv.t, sp, sc);
      } else if ((svRight.type == VECTORTYPE && svLeft.type == INT32TYPE)
                 || (svLeft.type == VECTORTYPE && svRight.type == INT32TYPE)) {
        /* Multiply a list by a number; will make it repeat */
        expr_t *newVec = newExpr_Vector(NULL);
        void *hp = PROVIDE_CONTEXT()->hp;
        int32_t mult;
        expr_t *e = NULL;
        vector_t *vec = NULL;
        heapval_t *hvp = NULL;
        stackval_t stv;
        int dummy;

        if (svRight.type == INT32TYPE) {
          mult = svRight.i;
          vec = svLeft.vec;
        } else {
          mult = svLeft.i;
          vec = svRight.vec;
        }

        if (mult > 0) {
          e = copy_vector(vec, EXPRESSION_ARGS());
        } else {
          e = newExpr_Vector(NULL);
        }

        if (e->vec->length > 0) {
          int32_t i = 0;
          argsList_t *newContent = NULL;
          argsList_t *walk = NULL;
          argsList_t *prevArg = NULL;
          argsList_t *currentArg = NULL;
          argsList_t *nextArg;

          while (i < mult) {
            walk = e->vec->content;
            while (walk != NULL) {
              expr_t *exp = walk->arg;
              expr_t *newExp = NULL;
              stackval_t sv;
              void *sp = PROVIDE_CONTEXT()->sp;
              size_t *sc = PROVIDE_CONTEXT()->sc;

              /* Evaluate expression */
              evaluate_expression(exp, EXPRESSION_ARGS());

              /* Fetch the evaluated expression to the arguments table */
              POP_VAL(&sv, sp, sc);

              newExp = stackval_to_expression(&sv, EXPRESSION_ARGS());

              newContent = newArgument(newExp, newContent);
              newVec->vec->length++;
              newVec->vec->content = newContent;

              walk = walk->next;
            }

            i++;
          }

          walk = newVec->vec->content;
          /* Reverse the args list order */
          prevArg = NULL;
          currentArg = walk;
          while (currentArg != NULL) {
            nextArg = currentArg->next;
            currentArg->next = prevArg;
            prevArg = currentArg;
            currentArg = nextArg;
          }
          newVec->vec->content = prevArg;
        }

        /* Allocate this value on the heap, for garbage collection */
        stv.type = VECTORTYPE;
        stv.vec = newVec->vec;
        ALLOC_HEAP(&stv, hp, &hvp, &dummy);

        PUSH_VECTOR(newVec->vec, sp, sc);
        free(newVec);
        free_expression(e);
        free(e);
      } else {
        fprintf(stderr,
                "Error: Invalid operands. Type %d and %d does not fit for multiplication.\n",
                svRight.type, svLeft.type);
        exit(2);
      }

      break;
    }
    case EXPR_TYPE_OPMOD: {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t *)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t *)expr->add.right, EXPRESSION_ARGS());
      POP_VAL(&svRight, sp, sc);

      switch (svLeft.type) {
        case INT32TYPE: {
          *r0 = svLeft.i;
          break;
        }
        case DOUBLETYPE: {
          fprintf(stderr,
                  "error: Invalid expression, cannot calculate modulus on floating point.\n");
          exit(1);
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Invalid expression, cannot calculate modulus on string.\n");
          exit(1);
          break;
        }
        case BIGINT:
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
          fprintf(stderr,
                  "error: Invalid expression, cannot calculate modulus on floating point.\n");
          exit(1);
          break;
        }
        case TEXT: {
          fprintf(stderr, "error: Invalid expression, cannot calculate modulus on string.\n");
          exit(1);
          break;
        }
        case BIGINT:
          break;
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {
        PUSH_INT(*r0 % *r1, sp, sc);
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        mpz_mod(*n, *svLeft.bigInt, *svRight.bigInt);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        expr_t *bigIntEtmp = newExpr_BigIntFromInt(svRight.i);

        mpz_mod(*n, *svLeft.bigInt, *bigIntEtmp->bigInt);

        mpz_clear(*bigIntEtmp->bigInt);
        free(bigIntEtmp->bigInt);
        free(bigIntEtmp);

        PUSH_BIGINT(n, sp, sc);

        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        expr_t *bigIntEtmp = newExpr_BigIntFromInt(svLeft.i);

        mpz_mod(*n, *bigIntEtmp->bigInt, *svRight.bigInt);

        mpz_clear(*bigIntEtmp->bigInt);
        free(bigIntEtmp->bigInt);
        free(bigIntEtmp);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      }

      break;
    } break;
    case EXPR_TYPE_OPDIV: {
      stackval_t svLeft;
      stackval_t svRight;

      evaluate_expression((expr_t *)expr->add.left, EXPRESSION_ARGS());
      POP_VAL(&svLeft, sp, sc);

      evaluate_expression((expr_t *)expr->add.right, EXPRESSION_ARGS());
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
        case BIGINT:
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
          fprintf(stderr, "error: Not implemented string additions yet..\n");
          exit(1);
          break;
        }
        case BIGINT:
          break;
        default:
          fprintf(stderr, "error: Unexpected stackval_t type: %d\n", svRight.type);
          exit(1);
          break;
      }

      if (svLeft.type == INT32TYPE && svRight.type == INT32TYPE) {
        PUSH_INT(*r0 / *r1, sp, sc);
      } else if (svLeft.type == INT32TYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*r0 / *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == DOUBLETYPE) {
        PUSH_DOUBLE(*f0 / *f1, sp, sc);
      } else if (svLeft.type == DOUBLETYPE && svRight.type == INT32TYPE) {
        PUSH_DOUBLE(*f0 / *r1, sp, sc);
      } else if (svLeft.type == BIGINT && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        mpz_fdiv_q(*n, *svLeft.bigInt, *svRight.bigInt);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == BIGINT && svRight.type == INT32TYPE) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        expr_t *bigIntEtmp = newExpr_BigIntFromInt(svRight.i);

        mpz_fdiv_q(*n, *svLeft.bigInt, *bigIntEtmp->bigInt);

        mpz_clear(*bigIntEtmp->bigInt);
        free(bigIntEtmp->bigInt);
        free(bigIntEtmp);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      } else if (svLeft.type == INT32TYPE && svRight.type == BIGINT) {
        stackval_t stv;
        void *hp = PROVIDE_CONTEXT()->hp;
        heapval_t *hpv = NULL;
        int dummy;
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        mpz_init(*n);
        expr_t *bigIntEtmp = newExpr_BigIntFromInt(svLeft.i);

        mpz_fdiv_q(*n, *bigIntEtmp->bigInt, *svRight.bigInt);

        mpz_clear(*bigIntEtmp->bigInt);
        free(bigIntEtmp->bigInt);
        free(bigIntEtmp);

        PUSH_BIGINT(n, sp, sc);
        stv.type = BIGINT;
        stv.bigInt = n;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      }

      break;
    } break;
    case EXPR_TYPE_COND: {
      evaluate_condition(expr->cond, stmt, next, PROVIDE_CONTEXT(), args, argVals);
      /* Push ax to stack */
      PUSH_INT(*ax, sp, sc);
      break;
    }
    case EXPR_TYPE_FUNCCALL: {
      stackval_t sv;
      functionCallContainer_t func;

      func.type = FUNC_CALL_TYPE_GLOBAL;
      func.globalCall = expr->func;

      call_func(&func, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);
      push_stackval(&sv, PROVIDE_CONTEXT());
      break;
    }
    case EXPR_TYPE_CLASSFUNCCALL: {
      stackval_t sv;
      functionCallContainer_t func;

      func.type = FUNC_CALL_TYPE_CLASS;
      func.classCall = (classFunctionCall_t *)expr->func;

      call_func(&func, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);
      push_stackval(&sv, PROVIDE_CONTEXT());
      break;
    }
    case EXPR_TYPE_CLASSACCESSER: {
      stackval_t sv;
      classAccesser_t *access = expr->classAccess;
      expr_t *classID = access->classID;
      char *memberID = access->memberID;
      class_t *classObj = NULL;
      heapval_t *hv = NULL;

      evaluate_expression(classID, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      switch (sv.type) {
        case CLASSTYPE:
          classObj = sv.classObj;
          break;
        default: {
          ERROR("attempting to access '%s' but fails because of invalid root class ID", memberID);
          exit(1);
          break;
        }
      }

      hv = hashtable_get(classObj->varMembers, PROVIDE_CONTEXT()->syncCtx, memberID);
      if (hv == NULL) {
        ERROR("%s not found in class %s", memberID, classObj->id);
        exit(1);
      }

      push_stackval(&hv->sv, PROVIDE_CONTEXT());
      break;
    }
    case EXPR_TYPE_CLASSPTR: {
      expr_t *e = newExpr_ClassPtrCopy(expr->classObj);
      PUSH_CLASSREF(e->classObj, sp, sc);
      free(e);
      break;
    }
    case EXPR_TYPE_EMPTY:
    default:
      break;
  }
}

/* Check if ID is valid */
int evaluate_id_valid(char *id, EXPRESSION_PARAMS()) {
  locals_stack_t *varLocals = PROVIDE_CONTEXT()->varLocals;
  heapval_t *hv = NULL;
  /* Check if this ID is among the arguments */
  argsList_t *walk = args;

  if (id == NULL) return 0;

  while (walk != NULL) {
    expr_t *exp = walk->arg;
    if (exp->type == EXPR_TYPE_ID) {
      expr_t *expArg;

      /* Check among the arguments if we have it defined there */
      expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, id);

      if (expArg != NULL) {
        /* This was an argument, ID ok! */
        return 1;
      }
    }

    walk = walk->next;
  }

  if (walk == NULL) {
    functionDef_t *funcDef; // if it is a function pointer

    /* Check among the global variables if we have it defined there */
    hv = hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, id);

    if (hv == NULL) {
      /* Check among the locals if we have it defined there */
      hv = locals_lookup(varLocals, id);
    }

    if (hv != NULL) {
      return 1;
    }

    /* Check among the function declarations if we have it defined there */
    funcDef = hashtable_get(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, id);
    if (funcDef != NULL) {
      // Pushing the function definition
      return 1;
    }

    /* Check among the standard lib function declarations if we have it defined there */
    libFunction_t *libFunc = look_up_lib(id);

    if (libFunc != NULL) {
      return 1;
    }
  }

  /* Failed to find the id*/
  return 0;
}

void call_func(functionCallContainer_t *func, EXPRESSION_PARAMS()) {
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

  if (func->type == FUNC_CALL_TYPE_GLOBAL) {
    /* Calling a global function */
    funcCall = func->globalCall;
    argsWalk = funcCall->args;

    /* Evaluate id */
    evaluate_expression(funcCall->id, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    switch (sv.type) {
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
        fprintf(stderr, "%s.%d error: invalid function call (%d)\n", __FILE__, __LINE__, sv.type);
        exit(1);
        break;
    }

    /* Check if this is a class construction call */
    classRef = hashtable_get(PROVIDE_CONTEXT()->classDecs, PROVIDE_CONTEXT()->syncCtx, funcID);
    if (classRef != NULL) {
      functionDef_t *constructor = NULL;
      class_t *class = NULL;
      /* Create a new instance, place it on the heap */
      expr_t *classObj = newExpr_ClassPtr(classRef);
      class = classObj->classObj;
      free(classObj); // expression container not needed
      /* Run the initializer */
      initClass(class, EXPRESSION_ARGS());
      /* Find the constructor hook and run it if so */
      constructor = hashtable_get(class->funcDefsScript, PROVIDE_CONTEXT()->syncCtx, funcID);
      if (constructor != NULL) {
        exeCtx->classCtx = class;
        /* Moving along, interpreting function */
        int localsStackSp = varLocals->sp;
        int localsStackSb = varLocals->sb;
        varLocals->sb = varLocals->sp;
        *depth = 1; // There is only one global scope
        interpret_statements_(constructor->body, PROVIDE_CONTEXT(), NULL, NULL);
        varLocals->sb = localsStackSb;
        varLocals->sp = localsStackSp;
      }
      PUSH_CLASSREF(class, sp, sc);
      stop = 1;
      flush_arguments(newArgumentTable);
    }

    if (!stop && classCtx != NULL) {
      /* Check if this is a function member call */
      functionDef_t *classFunc =
          hashtable_get(classCtx->funcDefsScript, PROVIDE_CONTEXT()->syncCtx, funcID);
      /* Call the function */
      if (classFunc) {
        uintptr_t spBefore;
        /* Check that # parameters == # arguments */
        argsList_t *params = classFunc->params;
        int localsStackSp;
        int localsStackSb;

        /* Default return type: a zero */
        sv_ret.type = INT32TYPE;
        sv_ret.i = 0;

        spBefore = *(uintptr_t *)sp;

        if (params == NULL && argsWalk != NULL) {
          fprintf(stderr, "Error: function '%s' expected 0 arguments, got: %u\n", funcID,
                  argsWalk->length);
          exit(1);
        }

        if (params != NULL && argsWalk == NULL) {
          fprintf(stderr, "Error: function '%s' expected %u arguments, got: 0\n", funcID,
                  params->length);
          exit(1);
        }

        if (params != NULL && argsWalk != NULL) {
          /* Verifying function definition parameters and function call arguments */
          if (params->length != argsWalk->length) {
            /* print error message */
            fprintf(stderr, "Error: function '%s' expected %u arguments, got: %u\n", funcID,
                    params->length, argsWalk->length);
            exit(1);
          }

          /* Populate arguments */
          while (argsWalk != NULL && params != NULL) {
            stackval_t sv;
            expr_t *newArg = NULL;

            if (params->arg->type != EXPR_TYPE_ID) {
              /* This is not supposed to happen */
              fprintf(stderr, "Error: parameter in function definition '%s' was invalid\n",
                      funcID);
            }

            /* Evaluate expression */
            evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());

            /* Fetch the evaluated expression to the arguments table */
            POP_VAL(&sv, sp, sc);
            newArg = stackval_to_expression(&sv, EXPRESSION_ARGS());

            /* Adding expression to argument table */
            hashtable_put(newArgumentTable, PROVIDE_CONTEXT()->syncCtx, params->arg->id.id,
                          newArg);

            params = params->next;
            argsWalk = argsWalk->next;
          }
        }

        /* Moving along, interpreting function */
        localsStackSp = varLocals->sp;
        localsStackSb = varLocals->sb;
        varLocals->sb = varLocals->sp;
        *depth = 1; // There is only one global scope
        interpret_statements_(classFunc->body, PROVIDE_CONTEXT(), classFunc->params,
                              newArgumentTable);
        varLocals->sb = localsStackSb;
        varLocals->sp = localsStackSp;
        if (*(uintptr_t *)sp != spBefore) {
          /* Return statement found, pop return value */
          POP_VAL(&sv_ret, sp, sc);
        }

        /* Push function return value to the stack */
        push_stackval(&sv_ret, PROVIDE_CONTEXT());

        /* Free the argument value table */
        flush_arguments(newArgumentTable);

        stop = 1;
      }
    }

    if (!stop) {
      /* Check among the arguments if we have it defined there */
      expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, funcID);

      /* The argument might be a function! Evaluate and see ... */
      if (expArg != NULL && classRef == NULL) {
        /* This was an argument! */
        switch (expArg->type) {
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

      if (funcDef == NULL && libFunc == NULL && classRef == NULL) {
        /* Looking up the function and calling it if it exists */
        funcDef = hashtable_get(PROVIDE_CONTEXT()->funcDecs, PROVIDE_CONTEXT()->syncCtx, funcID);
        /* Looking up the function among the library */
        libFunc = look_up_lib(funcID);

        /* Check lookup status */
        if (funcDef == NULL && libFunc == NULL) {
          heapval_t *hv;
          /* Check if this is a function pointer call (lowest priority) */
          hv = hashtable_get(PROVIDE_CONTEXT()->varDecs, PROVIDE_CONTEXT()->syncCtx, funcID);

          if (hv == NULL) {
            /* Check among the arguments if we have it defined there */
            expArg = hashtable_get(argVals, PROVIDE_CONTEXT()->syncCtx, funcID);

            if (expArg == NULL) {
              fprintf(stderr, "Error: Function call undefined: '%s'.\r\n", funcID);
              exit(1);
            }

            /* The argument might be a function! Evaluate and see ... */
            if (expArg != NULL) {
              /* This was an argument! */
              switch (expArg->type) {
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

          } else if (hv->sv.type != FUNCPTRTYPE && hv->sv.type != LIBFUNCPTRTYPE) {
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

      if (funcDef != NULL) {
        uintptr_t spBefore;

        /* Check that # parameters == # arguments */
        argsList_t *params = funcDef->params;

        if (params == NULL && argsWalk != NULL) {
          fprintf(stderr, "Error: function '%s' expected 0 arguments, got: %u\n", funcID,
                  argsWalk->length);
          exit(1);
        }

        if (params != NULL && argsWalk == NULL) {
          fprintf(stderr, "Error: function '%s' expected %u arguments, got: 0\n", funcID,
                  params->length);
          exit(1);
        }

        if (params != NULL && argsWalk != NULL) {
          /* Verifying function definition parameters and function call arguments */
          if (params->length != argsWalk->length) {
            /* print error message */
            fprintf(stderr, "Error: function '%s' expected %u arguments, got: %u\n", funcID,
                    params->length, argsWalk->length);
            exit(1);
          }

          /* Populate arguments */
          while (argsWalk != NULL && params != NULL) {
            stackval_t sv;
            expr_t *newArg = NULL;

            if (params->arg->type != EXPR_TYPE_ID) {
              /* This is not supposed to happen */
              fprintf(stderr, "Error: parameter in function definition '%s' was invalid\n",
                      funcID);
            }

            /* Evaluate expression */
            evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());

            /* Fetch the evaluated expression to the arguments table */
            POP_VAL(&sv, sp, sc);
            newArg = stackval_to_expression(&sv, EXPRESSION_ARGS());

            /* Adding expression to argument table */
            hashtable_put(newArgumentTable, PROVIDE_CONTEXT()->syncCtx, params->arg->id.id,
                          newArg);

            params = params->next;
            argsWalk = argsWalk->next;
          }
        }

        /* Default return type: a zero */
        sv_ret.type = INT32TYPE;
        sv_ret.i = 0;

        spBefore = *(uintptr_t *)sp;

        /* Call the function */
        if (funcDef) {
          /* Moving along, interpreting function */
          int localsStackSp = varLocals->sp;
          int localsStackSb = varLocals->sb;
          varLocals->sb = varLocals->sp;
          *depth = 1; // There is only one global scope
          interpret_statements_(funcDef->body, PROVIDE_CONTEXT(), funcDef->params,
                                newArgumentTable);
          varLocals->sb = localsStackSb;
          varLocals->sp = localsStackSp;
        }

        if (*(uintptr_t *)sp != spBefore) {
          /* Return statement found, pop return value */
          POP_VAL(&sv_ret, sp, sc);
        }

        /* Push function return value to the stack */
        push_stackval(&sv_ret, PROVIDE_CONTEXT());

        /* Free the argument value table */
        flush_arguments(newArgumentTable);
      } else {
        /* This is a library function */
        int libfunc_ret;

        if (libFunc->nbrArgs > 0 && argsWalk == NULL) {
          fprintf(stderr, "error: library function '%s' need %d agument%s, %d provided.\n", funcID,
                  libFunc->nbrArgs, (libFunc->nbrArgs == 1 ? "" : "s"), 0);
          if (!*PROVIDE_CONTEXT()->interactive) {
            exit(1);
          }
        }

        if (argsWalk != NULL && libFunc->nbrArgs != (int)argsWalk->length) {
          fprintf(stderr, "error: library function '%s' need %d agument%s, %d provided.\n", funcID,
                  libFunc->nbrArgs, (libFunc->nbrArgs == 1 ? "" : "s"), (int)argsWalk->length);
          if (!*PROVIDE_CONTEXT()->interactive) {
            exit(1);
          }
        }

        /* Populate arguments */
        while (argsWalk != NULL) {
          stackval_t sv;

          /* Evaluate expression */
          evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());

          /* Fetch the evaluated expression to the arguments table */
          POP_VAL(&sv, sp, sc);
          push_stackval(&sv, PROVIDE_CONTEXT());

          argsWalk = argsWalk->next;
        }
        libfunc_ret = libFunc->func(funcID, EXPRESSION_ARGS());
        /* Free the argument value table */
        flush_arguments(newArgumentTable);

        if (libfunc_ret != 0) {
          fprintf(stderr, "Error during execution of library function '%s', error code: %d\n",
                  funcID, libfunc_ret);
          exit(libfunc_ret);
        }
      }
    }
  } else if (func->type == FUNC_CALL_TYPE_CLASS) {
    /* Calling a class function */
    classCall = func->classCall;
    argsWalk = classCall->args;
    class_t *classObj = NULL;
    functionDef_t *funcDef = NULL;
    libFunction_t *libFunc = NULL;
    stackval_t sv_ret;
    uintptr_t spBefore;
    char *funcID = NULL;

    /* Evaluate class id */
    evaluate_expression(classCall->classID, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    switch (sv.type) {
      case CLASSTYPE:
        classObj = sv.classObj;
        break;
      default:
        fprintf(stderr, "error: invalid class function call, ID must point to a class object.\n");
        exit(1);
        break;
    }

    if (!classObj->initialized) {
      fprintf(
          stderr,
          "error: invalid class function call, ID must point to an initialized class object.\n");
      exit(1);
    }

    /* Evaluate class func id */
    funcID = classCall->funcID;

    /* Find the class function */
    funcDef = hashtable_get(classObj->funcDefsScript, PROVIDE_CONTEXT()->syncCtx, funcID);
    libFunc = hashtable_get(classObj->funcDefsABI, PROVIDE_CONTEXT()->syncCtx, funcID);

    if (funcDef == NULL && libFunc == NULL) {
      fprintf(stderr, "error: cannot find function '%s' in class '%s'.\n", funcID, classObj->id);
      exit(1);
    }

    /* Default return type: a zero */
    sv_ret.type = INT32TYPE;
    sv_ret.i = 0;

    spBefore = *(uintptr_t *)sp;

    /* Call the function */
    if (funcDef) {
      /* Check that # parameters == # arguments */
      argsList_t *params = funcDef->params;
      int localsStackSp;
      int localsStackSb;
      class_t *tmp;

      if (params == NULL && argsWalk != NULL) {
        fprintf(stderr, "Error: function '%s' expected 0 arguments, got: %u\n", funcID,
                argsWalk->length);
        exit(1);
      }

      if (params != NULL && argsWalk == NULL) {
        fprintf(stderr, "Error: function '%s' expected %u arguments, got: 0\n", funcID,
                params->length);
        exit(1);
      }

      if (params != NULL && argsWalk != NULL) {
        /* Verifying function definition parameters and function call arguments */
        if (params->length != argsWalk->length) {
          /* print error message */
          fprintf(stderr, "Error: function '%s' expected %u arguments, got: %u\n", funcID,
                  params->length, argsWalk->length);
          exit(1);
        }

        /* Populate arguments */
        while (argsWalk != NULL && params != NULL) {
          stackval_t sv;
          expr_t *newArg = NULL;

          if (params->arg->type != EXPR_TYPE_ID) {
            /* This is not supposed to happen */
            fprintf(stderr, "Error: parameter in function definition '%s' was invalid\n", funcID);
          }

          /* Evaluate expression */
          evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());

          /* Fetch the evaluated expression to the arguments table */
          POP_VAL(&sv, sp, sc);
          newArg = stackval_to_expression(&sv, EXPRESSION_ARGS());

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
      *depth = 1; // There is only one global scope
      tmp = PROVIDE_CONTEXT()->classCtx;
      PROVIDE_CONTEXT()->classCtx = classObj; // Set class context
      interpret_statements_(funcDef->body, PROVIDE_CONTEXT(), funcDef->params, newArgumentTable);
      varLocals->sb = localsStackSb;
      varLocals->sp = localsStackSp;
      PROVIDE_CONTEXT()->classCtx = tmp;
    } else if (libFunc != NULL) {
      /* This is a library function */
      int libfunc_ret;
      class_t *tmp;

      if (libFunc->nbrArgs > 0 && argsWalk == NULL) {
        fprintf(stderr, "error: library function '%s' need %d agument%s, %d provided.\n", funcID,
                libFunc->nbrArgs, (libFunc->nbrArgs == 1 ? "" : "s"), 0);
        if (!*PROVIDE_CONTEXT()->interactive) {
          exit(1);
        } else {
          return;
        }
      }

      if (argsWalk != NULL && libFunc->nbrArgs != (int)argsWalk->length) {
        fprintf(stderr, "error: library function '%s' need %d agument%s, %d provided.\n", funcID,
                libFunc->nbrArgs, (libFunc->nbrArgs == 1 ? "" : "s"), (int)argsWalk->length);
        if (!*PROVIDE_CONTEXT()->interactive) {
          exit(1);
        } else {
          return;
        }
      }

      /* Populate arguments */
      while (argsWalk != NULL) {
        stackval_t sv;

        /* Evaluate expression */
        evaluate_expression(argsWalk->arg, EXPRESSION_ARGS());

        /* Fetch the evaluated expression to the arguments table */
        POP_VAL(&sv, sp, sc);

        push_stackval(&sv, PROVIDE_CONTEXT());

        argsWalk = argsWalk->next;
      }
      tmp = PROVIDE_CONTEXT()->classCtx;
      PROVIDE_CONTEXT()->classCtx = classObj; // Set class context
      libfunc_ret = libFunc->func(funcID, EXPRESSION_ARGS());
      PROVIDE_CONTEXT()->classCtx = tmp;

      if (libfunc_ret != 0) {
        fprintf(stderr, "Error during execution of library function '%s', error code: %d\n",
                funcID, libfunc_ret);
        exit(libfunc_ret);
      }
    }

    if (*(uintptr_t *)sp != spBefore) {
      /* Return statement found, pop return value */
      POP_VAL(&sv_ret, sp, sc);
    }

    /* Push function return value to the stack */
    push_stackval(&sv_ret, PROVIDE_CONTEXT());

    /* Free the argument value table */
    flush_arguments(newArgumentTable);
  }
}

heapval_t *locals_lookup(locals_stack_t *stack, char *id) {
  int i = stack->sb;
  while (i < stack->sp && i < MAX_NBR_LOCALS) {
    local_t local = stack->stack[i];
    if (strcmp(id, local.id) == 0) {
      /* Found it */
      return local.hpv;
    }
    ++i;
  }
  /* id not among locals */
  return NULL;
}

void locals_push(locals_stack_t *stack, char *id, heapval_t *hpv) {
  int i;
  if (stack->sp >= MAX_NBR_LOCALS) {
    fprintf(
        stderr,
        "error: You are defining over %d locals, this is more than the ric-script interpreter can handle unfortunately. Is the program heavily recursive perhaps? The interpreter will not cooperate... Sorry.\n",
        MAX_NBR_LOCALS);
    exit(1);
  }
  i = stack->sb;
  while (i < stack->sp && i < MAX_NBR_LOCALS) {
    local_t local = stack->stack[i];
    if (strcmp(id, local.id) == 0) {
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

void locals_remove(locals_stack_t *stack, char *id) {
  int i;
  if (stack->sp >= MAX_NBR_LOCALS) {
    fprintf(
        stderr,
        "You are defining over %d locals, what are you doin? I will not cooperate with you. Sorry.\n",
        MAX_NBR_LOCALS);
    exit(1);
  }
  i = stack->sb;
  while (i < stack->sp && i < MAX_NBR_LOCALS) {
    local_t local = stack->stack[i];
    if (strcmp(id, local.id) == 0) {
      /* Remove this element from the stack */
      int p = i + 1;
      while (p < stack->sp && p < MAX_NBR_LOCALS) {
        stack->stack[p - 1] = stack->stack[p];
        ++p;
      }
      stack->sp--;
      return;
    }
    ++i;
  }
}

hashtable_t *new_argstable() {
  hashtable_t *argTable = hashtable_new(20, 0.8);
  assert(argTable != NULL);
  argTable->allocated_data = 1;
  return argTable;
}

void initClass(class_t *cls, EXPRESSION_PARAMS()) {
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *sp = PROVIDE_CONTEXT()->sp;
  void *hp = PROVIDE_CONTEXT()->hp;
  statement_t *initWalk = cls->defines;

  /* Sanity check */
  if (initWalk == NULL || cls->funcDefsScript == NULL || cls->varMembers == NULL) {
    return;
  }

  /* Go through the initializer list and populate the members */
  while (initWalk != NULL) {
    switch (initWalk->entity) {
      case LANG_ENTITY_FUNCDECL: {
        functionDef_t *funcDef = initWalk->content;

        /* Placing function declaration in global function namespace */
        hashtable_put(cls->funcDefsScript, PROVIDE_CONTEXT()->syncCtx, funcDef->id.id, funcDef);
      } break;
      case LANG_ENTITY_DECL: {
        stackval_t sv;
        expr_t *id;
        heapval_t *hvp = NULL;
        declaration_t *decl = initWalk->content;
        id = decl->id;

        switch (id->type) {
          case EXPR_TYPE_ID: {
            int heapUpdated;
            char *idStr = id->id.id;

            /* Evaluating the expression among global variables */
            evaluate_expression(decl->val, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            /* Placing value on the heap */
            if (sv.type == TEXT) {
              /* Special case */
              char *c = sv.t;
              size_t len = strlen(c) + 1;
              char *newText = ast_emalloc(len);
              snprintf(newText, len, "%s", c);
              sv.t = newText;
            } else if (sv.type == VECTORTYPE) {
              expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
              sv.vec = e->vec;
              free(e);
            } else if (sv.type == DICTTYPE) {
              dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
              sv.dict = dict;
            } else if (sv.type == BIGINT) {
              expr_t *e = newExpr_BigInt(sv.bigInt);
              sv.bigInt = e->bigInt;
              free(e);
            }

            ALLOC_HEAP(&sv, hp, &hvp, &heapUpdated);

            /* Placing variable declaration in class variable member namespace */
            hashtable_put(cls->varMembers, PROVIDE_CONTEXT()->syncCtx, idStr, hvp);
          } break;
          case EXPR_TYPE_VECTOR_IDX: {
            vector_t *vec = NULL;
            dictionary_t *dict = NULL;
            int32_t arrayIndex;
            argsList_t *walk = NULL;
            expr_t **expToSet = NULL;
            expr_t *vecid = id->vecIdx->expr;
            expr_t *index = id->vecIdx->index;

            stackval_t sv;

            evaluate_expression(vecid, EXPRESSION_ARGS());
            POP_VAL(&sv, sp, sc);

            switch (sv.type) {
              case DICTTYPE: {
                dict = sv.dict;
                /* Assigning a dictionary */
                char *key = NULL;
                heapval_t *hvp = NULL;
                int dummy;

                evaluate_expression(index, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != TEXT) {
                  fprintf(stderr, "index error: Must provide a string as key\n");
                  exit(1);
                }

                key = ast_emalloc(strlen(sv.t) + 2);
                snprintf(key, strlen(sv.t) + 1, "%s", sv.t);

                /* Evaluating the expression among global variables */
                evaluate_expression(decl->val, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                /* Placing value on the heap */
                if (sv.type == TEXT) {
                  /* Special case */
                  char *c = sv.t;
                  size_t len = strlen(c) + 1;
                  char *newText = ast_emalloc(len);
                  snprintf(newText, len, "%s", c);
                  sv.t = newText;
                } else if (sv.type == VECTORTYPE) {
                  expr_t *e = copy_vector(sv.vec, EXPRESSION_ARGS());
                  sv.vec = e->vec;
                  free(e);
                } else if (sv.type == DICTTYPE) {
                  dictionary_t *dict = allocNewDictionary(sv.dict, EXPRESSION_ARGS());
                  sv.dict = dict;
                } else if (sv.type == BIGINT) {
                  expr_t *e = newExpr_BigInt(sv.bigInt);
                  sv.bigInt = e->bigInt;
                  free(e);
                }

                ALLOC_HEAP(&sv, hp, &hvp, &dummy);

                // Check if collision, if so, free key
                hashtable_put(dict->hash, PROVIDE_CONTEXT()->syncCtx, key, hvp);
              } break;
              case VECTORTYPE: {
                /* Assigning a vector */
                expr_t *newExp = NULL;
                vec = sv.vec;
                evaluate_expression(index, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != INT32TYPE) {
                  fprintf(stderr, "index error: Must provide an integer as index\n");
                  exit(1);
                }

                arrayIndex = sv.i;

                /* check the limits */
                if (arrayIndex >= vec->length) {
                  fprintf(stderr,
                          "index error: index: '%" PRIi32 "' is too large, length: '%" PRIi32
                          "'\n",
                          arrayIndex, vec->length);
                  exit(1);
                } else if (arrayIndex < 0) {
                  arrayIndex = vec->length - ((vec->length - arrayIndex) % vec->length);
                }

                walk = vec->content;
                while (walk != NULL && arrayIndex >= 0) {
                  expToSet = &walk->arg;
                  walk = walk->next;
                  --arrayIndex;
                }

                if (*expToSet == NULL) {
                  fprintf(stderr, "Unexpected index error!\n");
                  GENERAL_REPORT_ISSUE_MSG();
                  exit(1);
                }

                /* Placing this expression into the array */
                free_expression(*expToSet);
                free(*expToSet);

                evaluate_expression(decl->val, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                newExp = stackval_to_expression(&sv, EXPRESSION_ARGS());
                *expToSet = newExp;
              } break;
              case TEXT: {
                char *text = sv.t;
                size_t origLen = strlen(text);
                size_t additionLen;
                size_t diff;
                size_t q = 0;
                char *newAddition = NULL;

                evaluate_expression(index, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != INT32TYPE) {
                  fprintf(stderr, "index error: Must provide an integer as index\n");
                  exit(1);
                }

                arrayIndex = sv.i;

                if (arrayIndex < 0) {
                  arrayIndex = origLen - ((origLen - arrayIndex) % origLen);
                } else if (arrayIndex >= origLen) {
                  fprintf(stderr, "index error: index out of bounds (index: %d)\n", arrayIndex);
                  exit(1);
                }

                /* Evaluating the expression among global variables */
                evaluate_expression(decl->val, EXPRESSION_ARGS());
                POP_VAL(&sv, sp, sc);

                if (sv.type != TEXT) {
                  fprintf(stderr, "string index error: Can only assign text to text.\n");
                  exit(1);
                }

                newAddition = sv.t;
                additionLen = strlen(newAddition);

                diff = origLen - arrayIndex;

                additionLen = (diff < additionLen ? diff : additionLen);
                q = 0;
                while (q < additionLen) {
                  text[arrayIndex + q] = newAddition[q];
                  q++;
                }
              } break;
              default: {
                fprintf(stderr, "index error: '%s' is not an indexable object.\n", id->id.id);
                GENERAL_REPORT_ISSUE_MSG();
                exit(1);
                break;
              }
            }
          } break;
          default:
            GENERAL_REPORT_ISSUE_MSG();
            break;
        }
      } break;
      default:
        break;
    }

    initWalk = initWalk->next;
  }
  cls->initialized = 1;
}

void check_buf_size(char **buf, size_t *bufSize, size_t *pos, size_t require) {
  size_t expandFactor = 2; // Arbitrary
  while (*bufSize <= *pos + require) {
    size_t newSize = *bufSize * expandFactor;
    char *newBuf = (char *)ast_remalloc(buf, newSize);
    *buf = newBuf;
    *bufSize = newSize;
  }
}

dictionary_t *allocNewDictionary(dictionary_t *dict, EXPRESSION_PARAMS()) {
  void *hp = PROVIDE_CONTEXT()->hp;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  dictionary_t *newDict = ast_emalloc(sizeof(dictionary_t));
  newDict->hash = hashtable_new(DICTIONARY_STANDARD_SIZE, DICTIONARY_STANDARD_LOAD);
  newDict->hash->allocated_key = 1;

  if (dict->initialized == 0) {
    keyValList_t *walk = dict->keyVals;
    while (walk != NULL) {
      /* Dictionary already initialized, evaluate expressions in the key-value list */
      expr_t *expKey = walk->key;
      expr_t *expVal = walk->val;
      char *newKeyStr = NULL; // Storing the key
      heapval_t *hvp = NULL;  // Storing the value
      stackval_t sv;
      int dummy; // todo: remove the need for this..

      evaluate_expression(expKey, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      switch (sv.type) {
        case TEXT: {
          size_t len = strlen(sv.t);
          newKeyStr = ast_emalloc(len + 2);
          snprintf(newKeyStr, len + 2, "%s", sv.t);
          break;
        }
        default:
          fprintf(stderr,
                  "Error: Invalid dictionary expression, keys must be given as strings.\r\n");
          exit(1);
          break;
      }

      evaluate_expression(expVal, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      /* Push all values to the heap */
      switch (sv.type) {
        case DOUBLETYPE:
        case POINTERTYPE:
        case INT32TYPE:
        case LIBFUNCPTRTYPE:
        case FUNCPTRTYPE:
        case TIMETYPE:
          ALLOC_HEAP(&sv, hp, &hvp, &dummy);
          break;
        case BIGINT: {
          expr_t *e = newExpr_BigInt(sv.bigInt);
          sv.bigInt = e->bigInt;
          ALLOC_HEAP(&sv, hp, &hvp, &dummy);
          break;
        }
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

          char *newText = ast_emalloc(len + 1);
          snprintf(newText, len + 1, "%s", sv.t);

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
          fprintf(
              stderr,
              "Error: Unexpected dictionary expression, value provided not valid in dictionary expressions.\r\n");
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
    while (i < size) {
      walk = hash->table[i];
      while (walk != NULL) {
        // Time to evaluate the keys and the values
        char *key = walk->key;
        heapval_t *hpVal = (heapval_t *)walk->data;
        char *newKeyStr = NULL; // Storing the key
        heapval_t *hvp = NULL;  // Storing the value
        stackval_t sv;
        int dummy; // todo: remove the need for this..
        size_t len = strlen(key);
        newKeyStr = ast_emalloc(len + 2);
        snprintf(newKeyStr, len + 2, "%s", key);

        sv = hpVal->sv;
        /* Push all values to the heap */
        switch (sv.type) {
          case DOUBLETYPE:
          case POINTERTYPE:
          case INT32TYPE:
          case LIBFUNCPTRTYPE:
          case FUNCPTRTYPE:
          case TIMETYPE:
            ALLOC_HEAP(&sv, hp, &hvp, &dummy);
            break;
          case BIGINT: {
            expr_t *e = newExpr_BigInt(sv.bigInt);
            sv.bigInt = e->bigInt;
            ALLOC_HEAP(&sv, hp, &hvp, &dummy);
            break;
          }
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

            char *newText = ast_emalloc(len + 1);
            snprintf(newText, len + 1, "%s", sv.t);

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
            fprintf(
                stderr,
                "Error: Unexpected dictionary expression, value provided not valid in dictionary expressions.\r\n");
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
