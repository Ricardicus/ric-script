#include "print.h"

int print_args(argsList_t *args) {
  if (args == NULL) return 0;

  if (print_args(args->next)) {
    printf(",");
  }

  print_expr(args->arg);
  return 1;
}

void print_statements_(void *stmt, int indent) {
  entity_eval_t *eval = (entity_eval_t *)stmt;
  void *next = NULL;

  if (stmt == NULL) return;

  switch (eval->entity) {
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
      printf("[0x%lx] %d ", (uintptr_t)stmt, ((statement_t *)stmt)->line);
      print_indents(indent);
      next = ((statement_t *)stmt)->next;
      break;
    case LANG_ENTITY_BODY:
      next = ((body_t *)stmt)->content;
      indent++;
      break;
    default:
      break;
  }

  switch (eval->entity) {
    case LANG_ENTITY_EMPTY_MATH:
    case LANG_ENTITY_EMPTY_STR:
    case LANG_ENTITY_EXPR:
      {
        printf("Expr(");
        print_expr(((statement_t *)stmt)->content);
        printf(");\n");
      }
      break;
    case LANG_ENTITY_FOREACH:
      {
        forEachStmt_t *festmt = (forEachStmt_t *)((statement_t *)stmt)->content;
        body_t *bd = festmt->body;
        printf("For each: Expr(");
        print_expr(festmt->entry);
        printf(") <- Expr(");
        print_expr(festmt->root);
        printf(")\n");

        print_indents(indent);
        print_statements_(bd->content, indent + 1);
      }
      break;
    case LANG_ENTITY_CLASSDECL:
      {
        class_t *class = ((statement_t *)stmt)->content;
        printf("Class('%s')\n", class->id);
        printf("CLASS DEFINES START\n");
        print_statements_(class->defines, indent + 1);
        printf("CLASS DEFINES END\n");
      }
      break;
    case LANG_ENTITY_DECL:
      {
        declaration_t *decl = ((statement_t *)stmt)->content;
        expr_t *declId = decl->id;

        switch (declId->type) {
          case EXPR_TYPE_ID:
            {
              printf("Declaration: ID('%s'), Expr(", declId->id.id);
              break;
            }
          case EXPR_TYPE_VECTOR_IDX:
            {
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
        expr_t *sys_txt = ((statement_t *)stmt)->content;

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
        expr_t *retVal = (expr_t *)((statement_t *)stmt)->content;
        printf("RETURN ->");
        print_expr(retVal);
        printf("\n");
      }
      break;
    case LANG_ENTITY_FUNCDECL:
      {
        functionDef_t *funcDef = ((statement_t *)stmt)->content;
        printf("Function Declaration: ID('%s') args(", funcDef->id.id);
        argsList_t *params = funcDef->params;
        print_args(params);
        printf(")\n");
        print_statements_(funcDef->body, indent + 1);
      }
      break;
    case LANG_ENTITY_CONDITIONAL:
      {
        ifStmt_t *ifstmt = ((statement_t *)stmt)->content;
        ifStmt_t *ifstmtWalk;
        expr_t *cond = ifstmt->cond;

        if (ifstmt->ifType & LANG_CONDITIONAL_CTX) {
          printf("loop-if-statement - condition: ");
        } else {
          printf("if-statement - condition: ");
        }

        print_expr(cond);
        printf("\n");
        print_statements_(ifstmt->body, indent);

        // Walk through the elifs.
        ifstmtWalk = ifstmt->elif;

        while (ifstmtWalk != NULL) {
          print_indents(indent);
          printf("else-if-statement - condition: ");
          print_expr(ifstmtWalk->cond);
          printf("\n");
          print_statements_(ifstmtWalk->body, indent + 1);
          ifstmtWalk = ifstmtWalk->elif;
        }

        // Print the else if it is not NULL
        if (ifstmt->endif != NULL) {
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

void print_statements(statement_t *stmt) { print_statements_(stmt, 0); }

void print_condition(ifCondition_t *cond) {
  if (cond == NULL) return;

  printf("[");
  print_expr(cond->left);
  printf("]");

  switch (cond->type) {
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
  while (i < indent) {
    printf("    ");
    ++i;
  }
}

int print_dictionary(dictionary_t *dict, EXPRESSION_PARAMS()) {
  hashtable_t *hash = dict->hash;
  // dictionary_t *newDict = NULL;
  int size;
  int i;
  int keyCount = 0;
  int keyCountTotal = 0;
  struct key_val_pair *ptr;

  if (dict->initialized == 0) {
    // stackval_t sv;
    keyValList_t *walk = dict->keyVals;
    i = 0;
    printf("{");
    while (walk != NULL) {
      stackval_t sv;
      void *sp = PROVIDE_CONTEXT()->sp;
      size_t *sc = PROVIDE_CONTEXT()->sc;
      /* Dictionary already initialized, evaluate expressions in the key-value list */
      expr_t *expKey = walk->key;
      expr_t *expVal = walk->val;

      if (expKey->type != EXPR_TYPE_TEXT) {
        walk = walk->next;
        continue;
      }

      printf("%s'%s' : ", (i == 0 ? "" : ", "), expKey->text);

      evaluate_expression(expVal, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      switch (sv.type) {
        case INT32TYPE:
          {
            printf("%" PRIi32 "", sv.i);
          }
          break;
        case BIGINT:
          {
            char buf[128];
            char *c = NULL;

            c = mpz_get_str(buf, 10, *sv.bigInt);
            printf("%s\n", c);
          }
          break;
        case DOUBLETYPE:
          {
            printf("%lf", sv.d);
          }
          break;
        case TEXT:
          {
            printf("'%s'", sv.t);
          }
          break;
        case POINTERTYPE:
          {
            printf("<Pointer: %" PRIxPTR ">", sv.p);
          }
          break;
        case FUNCPTRTYPE:
          {
            functionDef_t *funcDec = sv.func;
            printf("<FuncPointer: '%s'>", funcDec->id.id);
          }
          break;
        case LIBFUNCPTRTYPE:
          {
            libFunction_t *libFunc = sv.libfunc;
            printf("<LibFuncPointer: '%s'>", libFunc->libFuncName);
          }
          break;
        case VECTORTYPE:
          {
            print_vector(sv.vec, EXPRESSION_ARGS());
          }
          break;
        case DICTTYPE:
          {
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
  while (i < size) {
    ptr = hash->table[i];
    while (ptr != NULL) {
      keyCount++;
      ptr = ptr->next;
    }
    i++;
  }

  keyCountTotal = keyCount;

  if (keyCountTotal > 0) {
    printf("{");
    keyCount = 0;
    i = 0;
    while (i < size) {
      heapval_t *hpv;
      stackval_t sv;
      ptr = hash->table[i];

      if (ptr == NULL) {
        ++i;
        continue;
      }

      printf("%s'%s' : ", (keyCount > 0 ? ", " : ""), ptr->key);
      hpv = ptr->data;
      sv = hpv->sv;

      switch (sv.type) {
        case INT32TYPE:
          {
            printf("%" PRIi32 "", sv.i);
          }
          break;
        case DOUBLETYPE:
          {
            printf("%lf", sv.d);
          }
          break;
        case BIGINT:
          {
            char buf[128];
            char *c = NULL;

            c = mpz_get_str(buf, 10, *sv.bigInt);
            printf("%s\n", c);
          }
          break;
        case TEXT:
          {
            printf("'%s'", sv.t);
          }
          break;
        case POINTERTYPE:
          {
            printf("<Pointer: %" PRIxPTR ">", sv.p);
          }
          break;
        case FUNCPTRTYPE:
          {
            functionDef_t *funcDec = sv.func;
            printf("<FuncPointer: '%s'>", funcDec->id.id);
          }
          break;
        case LIBFUNCPTRTYPE:
          {
            libFunction_t *libFunc = sv.libfunc;
            printf("<LibFuncPointer: '%s'>", libFunc->libFuncName);
          }
          break;
        case VECTORTYPE:
          {
            print_vector(sv.vec, EXPRESSION_ARGS());
          }
          break;
        case DICTTYPE:
          {
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

void print_expr(expr_t *expr) {
  if (expr == NULL) return;

  switch (expr->type) {
    case EXPR_TYPE_ID:
      printf("ID('%s')", expr->id.id);
      break;
    case EXPR_TYPE_FVAL:
      printf("%lf", expr->fval);
      break;
    case EXPR_TYPE_TIME:
      printf("TIME");
      break;
    case EXPR_TYPE_BIGINT:
      {
        char buf[128];
        char *c = NULL;

        c = mpz_get_str(buf, 10, *expr->bigInt);
        printf("%s\n", c);
      }
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
    case EXPR_TYPE_LOGICAL:
      {
        int32_t walk;
        logical_t *logic = expr->logical;
        if (logic->orsLen > 0) {
          printf("(");
          walk = 0;
          while (walk < logic->orsLen) {
            if (walk > 0) {
              printf(" || ");
            }
            print_expr(logic->ors[walk]);
            walk++;
          }
          printf(")");
        }
        if (logic->andsLen > 0) {
          if (logic->orsLen > 0) {
            printf(" && ");
          }
          printf("(");
          walk = 0;
          while (walk < logic->andsLen) {
            if (walk > 0) {
              printf(" && ");
            }
            print_expr(logic->ands[walk]);
            walk++;
          }
          printf(")");
        }
        break;
      }
    case EXPR_TYPE_VECTOR_IDX:
      {
        vectorIndex_t *vecIdx = expr->vecIdx;
        printf("ListIdx, Expr: ");
        print_expr(vecIdx->expr);
        printf(", index: ");
        print_expr(vecIdx->index);
      }
      break;
    case EXPR_TYPE_CLASSPTR:
      printf("Class Object <'%s'>", expr->classObj->id);
      break;
    case EXPR_TYPE_OPADD:
      printf("ADD(");
      print_expr((expr_t *)expr->add.left);
      printf(",");
      print_expr((expr_t *)expr->add.right);
      printf(")");
      break;
    case EXPR_TYPE_OPSUB:
      printf("SUB(");
      print_expr((expr_t *)expr->add.left);
      printf(",");
      print_expr((expr_t *)expr->add.right);
      printf(")");
      break;
    case EXPR_TYPE_OPMUL:
      printf("MUL(");
      print_expr((expr_t *)expr->add.left);
      printf(",");
      print_expr((expr_t *)expr->add.right);
      printf(")");
      break;
    case EXPR_TYPE_OPMOD:
      printf("MOD(");
      print_expr((expr_t *)expr->add.left);
      printf(",");
      print_expr((expr_t *)expr->add.right);
      printf(")");
      break;
    case EXPR_TYPE_OPDIV:
      printf("DIV(");
      print_expr((expr_t *)expr->add.left);
      printf(",");
      print_expr((expr_t *)expr->add.right);
      printf(")");
      break;
    case EXPR_TYPE_COND:
      printf("Conditional(");
      print_condition((ifCondition_t *)expr->cond);
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

int snprint_dictionary(char **buf, size_t *bufSize, size_t *pos, dictionary_t *dict,
                       EXPRESSION_PARAMS()) {
  hashtable_t *hash = dict->hash;
  // dictionary_t *newDict = NULL;
  int size;
  int i;
  int keyCount = 0;
  int keyCountTotal = 0;
  struct key_val_pair *ptr;

  if (*buf == NULL) {
    const size_t startSize = 128;
    *buf = ast_emalloc(startSize);
    *bufSize = startSize;
    *pos = 0;
  }

  if (dict->initialized == 0) {
    // stackval_t sv;
    keyValList_t *walk = dict->keyVals;
    i = 0;
    check_buf_size(buf, bufSize, pos, 1);
    snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", "{");
    *pos = *pos + 1;
    while (walk != NULL) {
      char tmpBuf[256];
      size_t tmpLen;
      stackval_t sv;
      void *sp = PROVIDE_CONTEXT()->sp;
      size_t *sc = PROVIDE_CONTEXT()->sc;
      /* Dictionary already initialized, evaluate expressions in the key-value list */
      expr_t *expKey = walk->key;
      expr_t *expVal = walk->val;

      if (expKey->type != EXPR_TYPE_TEXT) {
        walk = walk->next;
        continue;
      }

      snprintf(tmpBuf, sizeof(tmpBuf), "%s\"%s\" : ", (i == 0 ? "" : ", "), expKey->text);
      tmpLen = strlen(tmpBuf);

      check_buf_size(buf, bufSize, pos, tmpLen);
      snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", tmpBuf);
      *pos += tmpLen;

      evaluate_expression(expVal, EXPRESSION_ARGS());
      POP_VAL(&sv, sp, sc);

      tmpLen = 0;

      switch (sv.type) {
        case INT32TYPE:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "%" PRIi32 "", sv.i);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case BIGINT:
          {
            char buf[128];
            char *c = NULL;

            c = mpz_get_str(buf, 10, *sv.bigInt);
            snprintf(tmpBuf, sizeof(tmpBuf), "%s", c);
          }
          break;
        case DOUBLETYPE:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "%lf", sv.d);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case TEXT:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "\"%s\"", sv.t);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case POINTERTYPE:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "<Pointer: %" PRIxPTR ">", sv.p);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case FUNCPTRTYPE:
          {
            functionDef_t *funcDec = sv.func;
            snprintf(tmpBuf, sizeof(tmpBuf), "<Function: '%s'>", funcDec->id.id);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case LIBFUNCPTRTYPE:
          {
            libFunction_t *libFunc = sv.libfunc;
            snprintf(tmpBuf, sizeof(tmpBuf), "<Function: '%s'>", libFunc->libFuncName);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case VECTORTYPE:
          {
            snprint_vector(buf, bufSize, pos, sv.vec, EXPRESSION_ARGS());
          }
          break;
        case DICTTYPE:
          {
            snprint_dictionary(buf, bufSize, pos, sv.dict, EXPRESSION_ARGS());
          }
          break;
        default:
          break;
      }

      if (tmpLen > 0) {
        check_buf_size(buf, bufSize, pos, tmpLen);
        snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", tmpBuf);

        *pos += tmpLen;
      }

      walk = walk->next;
      ++i;
    }
    check_buf_size(buf, bufSize, pos, 1);
    snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", "}");
    *pos = *pos + 1;
    return 0;
  }

  size = hash->size;

  i = 0;
  while (i < size) {
    ptr = hash->table[i];
    while (ptr != NULL) {
      keyCount++;
      ptr = ptr->next;
    }
    i++;
  }

  keyCountTotal = keyCount;

  if (keyCountTotal > 0) {

    check_buf_size(buf, bufSize, pos, 1);
    snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", "{");
    *pos = *pos + 1;

    keyCount = 0;
    i = 0;
    while (i < size) {
      char tmpBuf[256];
      size_t tmpLen;
      heapval_t *hpv;
      stackval_t sv;
      ptr = hash->table[i];

      if (ptr == NULL) {
        ++i;
        continue;
      }

      snprintf(tmpBuf, sizeof(tmpBuf), "%s\"%s\" : ", (keyCount > 0 ? ", " : ""), ptr->key);
      tmpLen = strlen(tmpBuf);

      check_buf_size(buf, bufSize, pos, tmpLen);
      snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", tmpBuf);
      *pos += tmpLen;

      hpv = ptr->data;
      sv = hpv->sv;

      tmpLen = 0;

      switch (sv.type) {
        case INT32TYPE:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "%" PRIi32 "", sv.i);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case BIGINT:
          {
            char buf[128];
            char *c = NULL;

            c = mpz_get_str(buf, 10, *sv.bigInt);
            snprintf(tmpBuf, sizeof(tmpBuf), "%s", c);
          }
          break;
        case DOUBLETYPE:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "%lf", sv.d);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case TEXT:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "\"%s\"", sv.t);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case POINTERTYPE:
          {
            snprintf(tmpBuf, sizeof(tmpBuf), "<Pointer: %" PRIxPTR ">", sv.p);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case FUNCPTRTYPE:
          {
            functionDef_t *funcDec = sv.func;
            snprintf(tmpBuf, sizeof(tmpBuf), "<Function: '%s'>", funcDec->id.id);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case LIBFUNCPTRTYPE:
          {
            libFunction_t *libFunc = sv.libfunc;
            snprintf(tmpBuf, sizeof(tmpBuf), "<Function: '%s'>", libFunc->libFuncName);
            tmpLen = strlen(tmpBuf);
          }
          break;
        case VECTORTYPE:
          {
            snprint_vector(buf, bufSize, pos, sv.vec, EXPRESSION_ARGS());
          }
          break;
        case DICTTYPE:
          {
            snprint_dictionary(buf, bufSize, pos, sv.dict, EXPRESSION_ARGS());
          }
          break;
        default:
          break;
      }

      if (tmpLen > 0) {
        check_buf_size(buf, bufSize, pos, tmpLen);
        snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", tmpBuf);

        *pos += tmpLen;
      }

      keyCount++;
      i++;
    }
    check_buf_size(buf, bufSize, pos, 1);
    snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", "}");
    *pos = *pos + 1;
  } else {
    check_buf_size(buf, bufSize, pos, 2);
    snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", "{}");
    *pos += 2;
  }

  return 0;
}

int snprint_vector(char **buf, size_t *bufSize, size_t *pos, vector_t *vec, EXPRESSION_PARAMS()) {
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  argsList_t *walk = vec->content;
  expr_t *vec_e = NULL;

  if (*buf == NULL) {
    const size_t startSize = 128;
    *buf = ast_emalloc(startSize);
    *bufSize = startSize;
    *pos = 0;
  }

  if (vec->content == NULL && vec->forEach != NULL) {
    vec_e = copy_vector(vec, EXPRESSION_ARGS());
    if (vec_e != NULL) {
      walk = vec_e->vec->content;
    }
  }

  check_buf_size(buf, bufSize, pos, 1);
  snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", "[");
  *pos = *pos + 1;
  while (walk != NULL) {
    char tmpBuf[256];
    size_t tmpLen = 0;
    stackval_t sv;
    evaluate_expression(walk->arg, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    switch (sv.type) {
      case INT32TYPE:
        {
          snprintf(tmpBuf, sizeof(tmpBuf), "%" PRIi32 "", sv.i);
          tmpLen = strlen(tmpBuf);
          break;
        }
      case BIGINT:
        {
          char buf[128];
          char *c = NULL;

          c = mpz_get_str(buf, 10, *sv.bigInt);
          snprintf(tmpBuf, sizeof(tmpBuf), "%s", c);
        }
        break;
      case DOUBLETYPE:
        {
          snprintf(tmpBuf, sizeof(tmpBuf), "%lf", sv.d);
          tmpLen = strlen(tmpBuf);
          break;
        }
      case TEXT:
        {
          snprintf(tmpBuf, sizeof(tmpBuf), "\"%s\"", sv.t);
          tmpLen = strlen(tmpBuf);
          break;
        }
      case TIMETYPE:
        {
          struct tm *info;
          if (sv.time < 0) {
            /* Relative time to now */
            time_t nowTime;
            time_t result;
            time(&nowTime);
            result = nowTime + sv.time;
            info = localtime(&result);
          } else {
            info = localtime(&sv.time);
          }
          snprintf(tmpBuf, sizeof(tmpBuf), "%s", asctime(info));
          tmpLen = strlen(tmpBuf);
          break;
        }
      case POINTERTYPE:
        snprintf(tmpBuf, sizeof(tmpBuf), "<%" PRIuPTR ">", sv.p);
        tmpLen = strlen(tmpBuf);
        break;
      case FUNCPTRTYPE:
        snprintf(tmpBuf, sizeof(tmpBuf), "<Function: '%s'>", sv.func->id.id);
        tmpLen = strlen(tmpBuf);
        break;
      case LIBFUNCPTRTYPE:
        snprintf(tmpBuf, sizeof(tmpBuf), "<Function: '%s'>", sv.func->id.id);
        tmpLen = strlen(tmpBuf);
        break;
      case VECTORTYPE:
        snprint_vector(buf, bufSize, pos, sv.vec, EXPRESSION_ARGS());
        break;
      case DICTTYPE:
        snprint_dictionary(buf, bufSize, pos, sv.dict, EXPRESSION_ARGS());
        break;
      default:
        break;
    }

    if (tmpLen > 0) {
      check_buf_size(buf, bufSize, pos, tmpLen);
      snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", tmpBuf);
      *pos += tmpLen;
    }

    walk = walk->next;
    if (walk != NULL) {
      check_buf_size(buf, bufSize, pos, 1);
      snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", ",");
      *pos = *pos + 1;
    }
  }

  check_buf_size(buf, bufSize, pos, 1);
  snprintf(&(*buf)[*pos], (*bufSize - *pos), "%s", "]");
  *pos = *pos + 1;

  if (vec_e != NULL) {
    free_expression(vec_e);
    free(vec_e);
  }

  return 0;
}

int print_vector(vector_t *vec, EXPRESSION_PARAMS()) {
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  argsList_t *walk = vec->content;
  expr_t *vec_e = NULL;

  if (vec->content == NULL && vec->forEach != NULL) {
    vec_e = copy_vector(vec, EXPRESSION_ARGS());
    if (vec_e != NULL) {
      walk = vec_e->vec->content;
    }
  }

  printf("[");
  while (walk != NULL) {
    stackval_t sv;
    evaluate_expression(walk->arg, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);

    switch (sv.type) {
      case INT32TYPE:
        printf("%" PRIi32 "", sv.i);
        break;
      case BIGINT:
        {
          char buf[128];
          char *c = NULL;

          c = mpz_get_str(buf, 10, *sv.bigInt);
          printf("%s", c);
        }
        break;
      case DOUBLETYPE:
        printf("%lf", sv.d);
        break;
      case TEXT:
        printf("'%s'", sv.t);
        break;
      case TIMETYPE:
        {
          struct tm *info;
          if (sv.time < 0) {
            /* Relative time to now */
            time_t nowTime;
            time_t result;
            time(&nowTime);
            result = nowTime + sv.time;
            info = localtime(&result);
          } else {
            info = localtime(&sv.time);
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
        printf("%s.error: unknown type of value on the stack (%d)\n", __func__, sv.type);
        break;
    }

    walk = walk->next;
    if (walk != NULL) {
      printf(",");
    }
  }

  printf("]");

  if (vec_e != NULL) {
    free_expression(vec_e);
    free(vec_e);
  }

  return 0;
}

void locals_print(locals_stack_t *stack) {
  int i = stack->sb;
  while (i < stack->sp && i < MAX_NBR_LOCALS) {
    local_t local = stack->stack[i];
    printf("locals[%d]: %s\n", i, local.id);
    ++i;
  }
}
