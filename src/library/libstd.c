#include "libstd.h"

int ric_exit(LIBRARY_PARAMS()) {
  stackval_t stv;
  int exitCode = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      exitCode = (int)stv.i;
      break;
    default: {
      fprintf(stderr, "error: function call '%s' expects a single integer as argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  exit(exitCode);
  return 1;
}

int ric_type(LIBRARY_PARAMS()) {
  stackval_t stv;
  int result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  result = stv.type;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_type_text(LIBRARY_PARAMS()) {
  stackval_t stv;
  int dummy;
  heapval_t *hpv;
  size_t strSize = 100;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  char *resultText = ast_ecalloc(strSize);
  void *hp = PROVIDE_CONTEXT()->hp;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      snprintf(resultText, strSize, "%s", "i32");
      break;
    case BIGINT:
      snprintf(resultText, strSize, "%s", "bigInt");
      break;
    case DOUBLETYPE:
      snprintf(resultText, strSize, "%s", "double");
      break;
    case TEXT:
      snprintf(resultText, strSize, "%s", "text");
      break;
    case POINTERTYPE:
      snprintf(resultText, strSize, "%s", "pointer");
      break;
    case FUNCPTRTYPE:
      snprintf(resultText, strSize, "%s", "function-pointer");
      break;
    case LIBFUNCPTRTYPE:
      snprintf(resultText, strSize, "%s", "standard-library-function-pointer");
      break;
    case VECTORTYPE:
      snprintf(resultText, strSize, "%s", "list");
      break;
    case DICTTYPE:
      snprintf(resultText, strSize, "%s", "dictionary");
      break;
    case CLASSTYPE:
      snprintf(resultText, strSize, "%s", "class");
      break;
    case TIMETYPE:
      snprintf(resultText, strSize, "%s", "time");
      break;
    case RAWDATATYPE:
      snprintf(resultText, strSize, "%s", "data");
      break;
    default:
      snprintf(resultText, strSize, "%s%s",
               "Unknown? Please file an error report at: ", GENERAL_ERROR_ISSUE_URL);
      break;
  }

  stv.type = TEXT;
  stv.t = resultText;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_create_list(LIBRARY_PARAMS()) {
  stackval_t stv;
  int dummy;
  heapval_t *hpv;
  char *inText = NULL;
  char *c;
  int32_t inSize = 0;
  rawdata_t *rawdata = NULL;
  expr_t *vec;
  argsList_t *vecContent = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  /* Read argument */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      inText = stv.t;
      break;
    case INT32TYPE:
      inSize = stv.i;
      break;
    case RAWDATATYPE:
      rawdata = stv.rawdata;
      break;
    default:
      fprintf(stderr, "error %s.%d: %s unexpected input argument; expected text, int or data\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME());
      exit(1);
      break;
  }

  if (inText != NULL) {
    c = inText;
    while (*c) {
      expr_t *e;
      argsList_t *a;
      char buf[2];

      buf[0] = *c;
      buf[1] = 0;
      e = newExpr_Text(buf);
      a = newArgument(e, vecContent);
      vecContent = a;

      ++c;
    }
  } else if (inSize > 0) {
    int32_t i = 0;
    while (i < inSize) {
      expr_t *e;
      argsList_t *a;

      e = newExpr_Ival(0);
      a = newArgument(e, vecContent);
      vecContent = a;

      ++i;
    }
  } else if (rawdata != NULL) {
    size_t i = 0;
    while (i < rawdata->size) {
      expr_t *e;
      argsList_t *a;
      int val = (int)((unsigned char *)rawdata->data)[i];

      e = newExpr_Ival(val);
      a = newArgument(e, vecContent);
      vecContent = a;

      ++i;
    }
  }

  vec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = vec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(vec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

int ric_create_data(LIBRARY_PARAMS()) {
  stackval_t stv;
  int dummy;
  heapval_t *hpv;
  char *inText = NULL;
  vector_t *vec = NULL;
  expr_t *newRawData = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  /* Read argument */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      inText = stv.t;
      break;
    case VECTORTYPE:
      vec = stv.vec;
      break;
    default:
      fprintf(stderr, "error %s.%d: %s unexpected input argument; expected text or list\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME());
      exit(1);
      break;
  }

  if (inText != NULL) {
    size_t textlen = strlen(inText);
    newRawData = newExpr_RawData(textlen);

    newRawData->rawdata->size = textlen;
    memcpy(newRawData->rawdata->data, inText, newRawData->rawdata->size);
  } else if (vec != NULL) {
    argsList_t *content = vec->content;
    size_t i = 0;
    size_t contentSize = (size_t)vec->length;

    newRawData = newExpr_RawData(contentSize);
    i = 0;
    while (content != NULL) {
      /* Evaluate expression */
      int32_t val;
      evaluate_expression(content->arg, EXPRESSION_ARGS());
      POP_VAL(&stv, sp, sc);

      if (stv.type != INT32TYPE) {
        /* This is not ok */
        fprintf(
            stderr,
            "error %s.%d: Cannot create data out of this list, only integer values acceptable\n",
            ((statement_t *)stmt)->file, ((statement_t *)stmt)->line);
        exit(1);
      }

      val = stv.i;

      if (val > 255 || val < 0) {
        fprintf(
            stderr,
            "error %s.%d: Cannot create data out of this list, only integer values in the range [0, 255] acceptable\n",
            ((statement_t *)stmt)->file, ((statement_t *)stmt)->line);
        exit(1);
      }

      ((unsigned char *)newRawData->rawdata->data)[i] = (unsigned char)(val & ((1 << 8) - 1));
      ++i;
      content = content->next;
    }
  }

  stv.type = RAWDATATYPE;
  stv.rawdata = newRawData->rawdata;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(newRawData);
  /* Pushing the parsed value */
  PUSH_RAWDATA(stv.rawdata, sp, sc);

  return 0;
}

int ric_create_text(LIBRARY_PARAMS()) {
  stackval_t stv;
  int dummy;
  heapval_t *hpv;
  char *inText = NULL;
  int32_t inInt;
  bool isInt = false;
  vector_t *vec = NULL;
  rawdata_t *rawData = NULL;
  expr_t *newText = NULL;
  mpz_t *bigIntArg = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  /* Read argument */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      inText = stv.t;
      break;
    case INT32TYPE:
      inInt = stv.i;
      isInt = true;
      break;
    case VECTORTYPE:
      vec = stv.vec;
      break;
    case BIGINT:
      bigIntArg = stv.bigInt;
      break;
    case RAWDATATYPE:
      rawData = stv.rawdata;
      break;
    default:
      fprintf(stderr, "error %s.%d: %s unexpected input argument; expected vector, data or text\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME());
      exit(1);
      break;
  }

  if (inText != NULL) {
    newText = newExpr_Text(inText);
  } else if (rawData != NULL) {
    newText = newExpr_Text(rawData->data);
  } else if (bigIntArg != NULL) {
    char *buf = ast_ecalloc(RIC_BIG_INT_MAX_SIZE);
    char *c = NULL;

    c = mpz_get_str(buf, 10, *stv.bigInt);
    newText = newExpr_Text(c);

    free(buf);
  } else if (isInt) {
    char intCharBuf[100];
    memset(intCharBuf, 0, sizeof(intCharBuf));
    snprintf(intCharBuf, sizeof(intCharBuf), "%" PRIi32 "", inInt);
    newText = newExpr_Text(intCharBuf);
  } else if (vec != NULL) {
    argsList_t *content = vec->content;
    size_t i = 0;
    size_t contentSize = (size_t)vec->length;
    char *buffer = ast_ecalloc(contentSize + 1);

    i = 0;
    while (content != NULL) {
      /* Evaluate expression */
      int32_t val;
      evaluate_expression(content->arg, EXPRESSION_ARGS());
      POP_VAL(&stv, sp, sc);

      if (stv.type != INT32TYPE) {
        /* This is not ok */
        fprintf(
            stderr,
            "error %s.%d: Cannot create text out of this list, only integer values acceptable\n",
            ((statement_t *)stmt)->file, ((statement_t *)stmt)->line);
        exit(1);
      }

      val = stv.i;

      if (val > 255 || val < 0) {
        fprintf(
            stderr,
            "error %s.%d: Cannot create text out of this list, only integer values in the range [0, 255] acceptable\n",
            ((statement_t *)stmt)->file, ((statement_t *)stmt)->line);
        exit(1);
      }

      buffer[i] = (char)(val & ((1 << 8) - 1));
      ++i;
      content = content->next;
    }
    newText = newExpr_Text(buffer);
    free(buffer);
  }

  stv.type = TEXT;
  stv.t = newText->text;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  free(newText);

  /* Pushing the parsed value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_print(LIBRARY_PARAMS()) {
  stackval_t stv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  POP_VAL(&stv, sp, sc);
  switch (stv.type) {
    case TEXT: {
      char *c = stv.t;
      int backslash = 0;

      /*
       * Parsing the string,
       * some character combos (such as: '\r','\n)
       * should be interpreted disctincly
       */
      while (*c) {

        if (!backslash && *c == '\\') {
          backslash = 1;
          ++c;
          continue;
        }

        if (backslash) {
          switch (*c) {
            case 'n':
              // Print a new line
              printf("\n");
              break;
            case 'r':
              // print the other one windows likes
              printf("\r");
              break;
            case '\\':
              // print a backslash
              printf("\\");
              break;
            case 't':
              // print a tab
              printf("\t");
              break;
            default:
              printf("\\%c", *c);
              break;
          }
        } else {
          printf("%c", *c);
        }

        ++c;
        backslash = 0;
      }

      // end with new line
      printf("\n");
    } break;
    case BIGINT: {
      char *buf = ast_ecalloc(RIC_BIG_INT_MAX_SIZE);
      char *c = NULL;

      c = mpz_get_str(buf, 10, *stv.bigInt);
      printf("%s\n", c);

      free(buf);
    } break;
    case INT32TYPE:
      printf("%d\n", stv.i);
      break;
    case TIMETYPE: {
      struct tm *info;
      if (stv.time < 0) {
        /* Relative time to now */
        time_t nowTime;
        time_t result;
        time(&nowTime);
        result = nowTime + stv.time;
        info = localtime(&result);
      } else {
        info = localtime(&stv.time);
      }
      printf("%s\n", asctime(info));
      break;
    }
    case DOUBLETYPE:
      printf("%lf\n", stv.d);
      break;
    case CLASSTYPE: {
      if (!stv.classObj->initialized) {
        printf("<Class: '%s'>\n", stv.classObj->id);
      } else {
        printf("<Class object: '%s'>\n", stv.classObj->id);
      }
    } break;
    case POINTERTYPE:
      printf("<%" PRIuPTR ">\n", stv.p);
      break;
    case DICTTYPE: {
      print_dictionary(stv.dict, EXPRESSION_ARGS());
      printf("\n");
      break;
    }
    case CACHEPOT: {
      print_cachepot(stv.cachepot, EXPRESSION_ARGS());
      printf("\n");
      break;
    }
    case FUNCPTRTYPE:
      printf("<Function: '%s'>\n", stv.func->id.id);
      break;
    case VECTORTYPE: {
      print_vector(stv.vec, EXPRESSION_ARGS());
      printf("\n");
    } break;
    case RAWDATATYPE: {
      size_t i = 0;
      while (i < stv.rawdata->size) {
        printf("%c", ((char *)stv.rawdata->data)[i]);
        ++i;
      }
      printf("\n");
    } break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  return 0;
}

int ric_printf(LIBRARY_PARAMS()) {
  stackval_t stv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT: {
      char *c = stv.t;
      int backslash = 0;

      /*
       * Parsing the string,
       * some character combos (such as: '\r','\n)
       * should be interpreted disctincly
       */
      while (*c) {

        if (!backslash && *c == '\\') {
          backslash = 1;
          ++c;
          continue;
        }

        if (backslash) {
          switch (*c) {
            case 'n':
              // Print a new line
              printf("\n");
              break;
            case 'r':
              // print the other one windows likes
              printf("\r");
              break;
            case '\\':
              // print a backslash
              printf("\\");
              break;
            case 't':
#ifdef _WIN32
              printf("\\t");
#else
              // print a tab
              printf("\t");
#endif
              break;
            default:
#ifdef _WIN32
              printf("%c", *c);
#endif
              break;
          }
        } else {
          printf("%c", *c);
        }

        ++c;
        backslash = 0;
      }
    } break;
    case INT32TYPE:
      printf("%d", stv.i);
      break;
    case BIGINT: {
      char *buf = ast_ecalloc(RIC_BIG_INT_MAX_SIZE);
      char *c = NULL;

      c = mpz_get_str(buf, 10, *stv.bigInt);
      printf("%s", c);

      free(buf);
    } break;
    case CLASSTYPE: {
      if (!stv.classObj->initialized) {
        printf("<Class: '%s'>", stv.classObj->id);
      } else {
        printf("<Class object: '%s'>", stv.classObj->id);
      }
    } break;
    case TIMETYPE: {
      struct tm *info;
      if (stv.time < 0) {
        /* Relative time to now */
        time_t nowTime;
        time_t result;
        time(&nowTime);
        result = nowTime + stv.time;
        info = localtime(&result);
      } else {
        info = localtime(&stv.time);
      }
      printf("%s", asctime(info));
      break;
    }
    case DOUBLETYPE:
      printf("%lf", stv.d);
      break;
    case POINTERTYPE:
      printf("<%" PRIuPTR ">", stv.p);
      break;
    case FUNCPTRTYPE:
      printf("<Function: '%s'>", stv.func->id.id);
      break;
    case DICTTYPE: {
      print_dictionary(stv.dict, EXPRESSION_ARGS());
      break;
    }
    case CACHEPOT: {
      print_cachepot(stv.cachepot, EXPRESSION_ARGS());
    } break;
    case VECTORTYPE: {
      print_vector(stv.vec, EXPRESSION_ARGS());
    } break;
    case RAWDATATYPE: {
      size_t i = 0;
      while (i < stv.rawdata->size) {
        printf("%c", ((char *)stv.rawdata->data)[i]);
        ++i;
      }
    } break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }
  fflush(stdout);

  return 0;
}

int ric_append(LIBRARY_PARAMS()) {
  stackval_t stv;
  vector_t *vec = NULL;
  expr_t *entry = NULL;
  argsList_t *addition = NULL;
  argsList_t *walk;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Get vector reference */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      vec = stv.vec;
      break;
    default: {
      fprintf(stderr, "error: function call '%s' got an unexpected first argument. (%d)\n",
              LIBRARY_FUNC_NAME(), stv.type);
      exit(1);
    } break;
  }

  /* Get what to append */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      entry = newExpr_Ival((int)stv.i); // This.. is not so good! Remind me to fix :)
      break;
    case BIGINT: {
      entry = newExpr_BigInt(stv.bigInt);
      break;
    }
    case DOUBLETYPE:
      entry = newExpr_Float(stv.d);
      break;
    case TEXT:
      entry = newExpr_Text(stv.t);
      break;
    case POINTERTYPE:
      entry = newExpr_Pointer(stv.p);
      break;
    case CLASSTYPE:
      entry = newExpr_ClassPtrCopy(stv.classObj);
      break;
    case DICTTYPE: {
      entry = ast_emalloc(sizeof(expr_t));
      entry->type = EXPR_TYPE_DICT;
      entry->dict = allocNewDictionary(stv.dict, EXPRESSION_ARGS());
    } break;
    case FUNCPTRTYPE:
      entry = newExpr_FuncPtr((void *)stv.p);
      break;
    case LIBFUNCPTRTYPE:
      entry = newExpr_LibFuncPtr((void *)stv.p);
      break;
    case VECTORTYPE: {
      entry = copy_vector(stv.vec, EXPR_ALLOC, EXPRESSION_ARGS());
    } break;
    default: {
      fprintf(stderr, "error: function call '%s' got an unexpected first argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  addition = newArgument(entry, NULL);
  walk = vec->content;
  if (walk == NULL) {
    // Special case
    vec->content = addition;
  } else {
    while (walk->next != NULL) {
      walk = walk->next;
    }
    walk->next = addition;
  }
  // Increase vector size
  vec->length++;

  return 0;
}

int ric_push(LIBRARY_PARAMS()) {
  stackval_t stv;
  vector_t *vec = NULL;
  expr_t *entry = NULL;
  argsList_t *addition = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Get vector reference */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      vec = stv.vec;
      break;
    default: {
      fprintf(stderr, "error: function call '%s' got an unexpected first argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  /* Get what to push */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      entry = newExpr_Ival((int)stv.i); // This.. is not so good! Remind me to fix :)
      break;
    case DOUBLETYPE:
      entry = newExpr_Float(stv.d);
      break;
    case TEXT:
      entry = newExpr_Text(stv.t);
      break;
    case POINTERTYPE:
      entry = newExpr_Pointer(stv.p);
      break;
    case FUNCPTRTYPE:
      entry = newExpr_FuncPtr((void *)stv.p);
      break;
    case LIBFUNCPTRTYPE:
      entry = newExpr_LibFuncPtr((void *)stv.p);
      break;
    case VECTORTYPE: {
      entry = copy_vector(stv.vec, EXPR_ALLOC, EXPRESSION_ARGS());
    } break;
    default: {
      fprintf(stderr, "error: function call '%s' got an unexpected first argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  addition = newArgument(entry, vec->content);
  vec->content = addition;

  // Increase vector size
  vec->length++;

  return 0;
}

int ric_pop(LIBRARY_PARAMS()) {
  stackval_t stv;
  vector_t *vec = NULL;
  argsList_t *walk;
  argsList_t *prev;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  heapval_t *hpv = NULL;
  int dummy;

  /* Get vector reference */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      vec = stv.vec;
      break;
    default: {
      fprintf(stderr, "error: function call '%s' got an unexpected first argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  if (vec->length == 0) {
    /* This is not very good.. Guess I will return 0 then. */
    PUSH_INT(0, sp, sc);
    return 0;
  }

  walk = vec->content;
  prev = NULL;
  while (walk->next != NULL) {
    prev = walk;
    walk = walk->next;
  }

  if (prev == NULL) {
    vec->content = walk->next;
  } else {
    prev->next = NULL;
  }
  evaluate_expression(walk->arg, EXPRESSION_ARGS());
  POP_VAL(&stv, sp, sc);

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  push_stackval(&stv, PROVIDE_CONTEXT());

  // Decrease vector size
  vec->length--;
  return 0;
}

int ric_pop_first(LIBRARY_PARAMS()) {
  stackval_t stv;
  vector_t *vec = NULL;
  argsList_t *walk;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  heapval_t *hpv;
  int dummy;
  void *hp = PROVIDE_CONTEXT()->hp;

  /* Get vector reference */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      vec = stv.vec;
      break;
    default: {
      fprintf(stderr, "error: function call '%s' got an unexpected first argument.\n",
              LIBRARY_FUNC_NAME());
      exit(1);
    } break;
  }

  if (vec->length == 0) {
    /* This is not very good.. Guess I will return 0 then. */
    PUSH_INT(0, sp, sc);
    return 0;
  }

  walk = vec->content;

  vec->content = walk->next;

  evaluate_expression(walk->arg, EXPRESSION_ARGS());
  POP_VAL(&stv, sp, sc);

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  push_stackval(&stv, PROVIDE_CONTEXT());

  // Decrease vector size
  vec->length--;
  return 0;
}

int ric_contains(LIBRARY_PARAMS()) {
  stackval_t stv;
  vector_t *argVec = NULL;
  dictionary_t *argDict = NULL;
  char *argText = NULL;
  cachepot_t *cachepot = NULL;
  char *containText = NULL;
  vector_t *containVec = NULL;
  int32_t containInt = 0;
  int32_t result = 0;
  int searchForInt = 0; // Lazy, search for int or text.
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      argVec = stv.vec;
      break;
    case DICTTYPE:
      argDict = stv.dict;
      break;
    case TEXT:
      argText = stv.t;
      break;
    case CACHEPOT:
      cachepot = stv.cachepot;
      break;
    default: {
      fprintf(stderr,
              "error: function '%s' expected string, dictionary or list as first argument.\n",
              LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  // Pop arg2
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      containText = stv.t;
      searchForInt = 0;
      break;
    case INT32TYPE:
      containInt = stv.i;
      searchForInt = 1;
      break;
    case VECTORTYPE:
      searchForInt = 0;
      containVec = stv.vec;
      break;
    default: {
      fprintf(stderr, "error: function '%s' expected text or integer as first argument.\n",
              LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  if (argVec != NULL) {
    /* Search in a vector */
    argsList_t *walk = argVec->content;

    while (walk != NULL) {
      evaluate_expression(walk->arg, EXPRESSION_ARGS());
      POP_VAL(&stv, sp, sc);

      if (searchForInt) {
        /* Check if is int and number match */
        if (stv.type == INT32TYPE && stv.i == containInt) {
          result = 1;
          break;
        }
      } else if (containText != NULL) {
        /* Check if is text */
        if (stv.type == TEXT && strcmp(stv.t, containText) == 0) {
          result = 1;
          break;
        }
      } else if (containVec != NULL) {
        if (stv.type == VECTORTYPE) {
          expr_t a, b;

          a.type = EXPR_TYPE_VECTOR;
          b.type = EXPR_TYPE_VECTOR;

          a.vec = stv.vec;
          b.vec = containVec;

          if (evaluate_equal(&a, &b, EXPRESSION_ARGS())) {
            result = 1;
            break;
          }
        }
      }
      walk = walk->next;
    }
  } else if (argDict != NULL) {
    /* Search in a dictionary */
    hashtable_t *hash = argDict->hash;

    if (searchForInt) {
      /* all keys are strings */
      result = 0;
    } else {
      heapval_t *hvp = hashtable_get(hash, PROVIDE_CONTEXT()->syncCtx, containText);
      if (hvp != NULL) {
        result = 1;
      }
    }
  } else if (cachepot != NULL) {
    /* Search in a cachepot */
    hashtable_t *hash = cachepot->hash;

    if (searchForInt) {
      /* all keys are strings */
      result = 0;
    } else {
      expr_t *e = hashtable_get(hash, PROVIDE_CONTEXT()->syncCtx, containText);
      if (e != NULL) {
        result = 1;
      }
    }
  } else if (argText != NULL) {
    if (searchForInt) {
      /* Check if int is in the text */
      char buffer[50];

      snprintf(buffer, sizeof(buffer), "%" PRIi32 "", containInt);

      if (strstr(argText, buffer) != NULL) {
        result = 1;
      }
    } else {
      /* Check if is text */
      if (strstr(argText, containText) != NULL) {
        result = 1;
      }
    }
  }

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_len(LIBRARY_PARAMS()) {
  stackval_t stv;
  vector_t *argVec = NULL;
  char *argText = NULL;
  rawdata_t *rawdata = NULL;
  int32_t result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      argVec = (vector_t *)stv.vec;
      break;
    case TEXT:
      argText = stv.t;
      break;
    case RAWDATATYPE:
      rawdata = stv.rawdata;
      break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
              LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  if (argVec != NULL) {
    result = argVec->length;
  } else if (argText != NULL) {
    result = (int32_t)strlen(argText);
  } else if (rawdata != NULL) {
    result = rawdata->size;
  } else {
    /* The switch above should have taken care avout this */
    return 1;
  }

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_keys(LIBRARY_PARAMS()) {
  stackval_t stv;
  dictionary_t *argDict = NULL;
  argsList_t *vecContent = NULL;
  expr_t *resultVec = NULL;
  int32_t result = 0;
  heapval_t *hpv = NULL;
  int dummy;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case DICTTYPE:
      argDict = stv.dict;
      break;
    default: {
      fprintf(stderr, "error: function '%s' expected dictionary as first argument.\n",
              LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  if (argDict != NULL) {
    /* list the dictionary */
    hashtable_t *hash = argDict->hash;
    int hashSize = hash->size;
    struct key_val_pair *ptr;
    int i = 0;

    while (i < hashSize && result == 0) {
      ptr = hash->table[i];
      while (ptr != NULL) {
        /* Add this key to the list */
        expr_t *e;
        argsList_t *a;
        e = newExpr_Text((char *)ptr->key);
        a = newArgument(e, vecContent);
        vecContent = a;
        ptr = ptr->next;
      }
      i++;
    }

  } else {
    fprintf(stderr, "error %s: unexpected error\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  resultVec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = resultVec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(resultVec);

  /* Pushing the list of keys */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

int ric_is_defined(LIBRARY_PARAMS()) {
  stackval_t stv;
  int32_t result;
  char *arg1 = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      arg1 = stv.t;
      break;
    default: {
      fprintf(stderr,
              "error: function '%s' got unexpected data type as argument, expected string.\n",
              LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  result = evaluate_id_valid(arg1, EXPRESSION_ARGS());

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_sum(LIBRARY_PARAMS()) {
  stackval_t stv;
  int32_t result = 0;
  mpz_t *resultBigInt = NULL;
  argsList_t *walk = NULL;
  vector_t *arg1 = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  // Pop arg1
  POP_VAL(&stv, sp, sc);
  switch (stv.type) {
    case VECTORTYPE:
      arg1 = stv.vec;
      break;
    default: {
      fprintf(stderr,
              "error: function '%s' got unexpected data type as argument, expected vector\n",
              LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  walk = arg1->content;
  while (walk != NULL) {
    stackval_t sv;
    evaluate_expression(walk->arg, EXPRESSION_ARGS());
    POP_VAL(&sv, sp, sc);
    if (sv.type == INT32TYPE) {
      result += sv.i;
      if (resultBigInt != NULL) {
        mpz_add_ui(*resultBigInt, *resultBigInt, sv.i);
      }
    } else if (sv.type == BIGINT) {
      mpz_t left;
      if (resultBigInt == NULL) {
        resultBigInt = ast_emalloc(sizeof(mpz_t));
        mpz_init_set_ui(*resultBigInt, 0);
      }

      mpz_init_set(left, *resultBigInt);
      mpz_add(*resultBigInt, left, *sv.bigInt);
      mpz_clear(left);
    } else {
      fprintf(stderr,
              "error: function '%s' got unexpected data type in vector, expected integers\n",
              LIBRARY_FUNC_NAME());
    }
    walk = walk->next;
  }

  /* Pushing result */
  if (resultBigInt != NULL) {
    PUSH_BIGINT(resultBigInt, sp, sc);
  } else {
    PUSH_INT(result, sp, sc);
  }
  return 0;
}

extern libFunction_t ric_library[];

int ric_help(LIBRARY_PARAMS()) {
  int32_t result = 0;
  int walk = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  dl_handle_t *dynLibs;
  int nbrDynLibs = 0;

  printf("These are the functions I know:\nfunction-name ( number-of-arguments)\n");

  /* Output what this interpreter can do */
  while (walk < ric_lib_calls()) {
    printf("- %s ( %d )\n", ric_library[walk].libFuncName, ric_library[walk].nbrArgs);
    ++walk;
  }

  /* Print dynamically loaded libraries */
  ric_get_dynamic_libraries(&dynLibs, &nbrDynLibs);
  if (nbrDynLibs > 0) {
    printf(
        "These are the modules and functions loaded dynamically:\nfunction-name ( number-of-arguments)\n");
    walk = 0;
    while (walk < nbrDynLibs) {
      dl_print_mod_info(stdout, &dynLibs[walk]);
      walk++;
    }
  }

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_print_env(LIBRARY_PARAMS()) {
  hashtable_t *varDecs = PROVIDE_CONTEXT()->varDecs;
  int i = 0;
  int size = varDecs->size;
  struct key_val_pair *ptr;

  while (i < size) {
    if (varDecs->table[i] != NULL) {
      ptr = varDecs->table[i];
      while (ptr != NULL) {
        printf("%s\n", ptr->key);
        ptr = ptr->next;
      }
    }
    i++;
  }

  return 0;
}

static int _cmp_func_mpz(const void *a, const void *b) {
  return (int)(mpz_cmp(**(mpz_t **)a, **(mpz_t **)b));
}

static int _cmp_func_int32(const void *a, const void *b) {
  return (int)(*(int32_t *)a - *(int32_t *)b);
}

static int _cmp_func_chars(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

int ric_sort(LIBRARY_PARAMS()) {
  stackval_t stv;
  int dummy;
  heapval_t *hpv;
  int i = 0;
  vector_t *vec = NULL;
  expr_t *newVec = NULL;
  argsList_t *vecContent = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  int32_t *outSort = NULL;
  mpz_t **outSortBigInt = NULL;
  char **outSortChars = NULL;

  /* Read argument */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      vec = stv.vec;
      break;
    default:
      fprintf(stderr, "error %s.%d: %s unexpected input argument; expected list\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME());
      exit(1);
      break;
  }

  vecContent = vec->content;

  if (vecContent->length > 0) {

    if (vecContent->arg->type == EXPR_TYPE_IVAL) {

      outSort = ast_emalloc(vec->length * sizeof(int32_t));
      while (vecContent != NULL) {
        if (vecContent->arg->type != EXPR_TYPE_IVAL) {
          free(outSort);
          fprintf(stderr, "error %s.%d: %s unexpected datatype in list (%d)",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME(),
                  vecContent->arg->type);
          exit(1);
        }

        outSort[i] = vecContent->arg->ival;
        vecContent = vecContent->next;
        i++;
      }

      qsort(outSort, vec->length, sizeof(int32_t), _cmp_func_int32);
    } else if (vecContent->arg->type == EXPR_TYPE_BIGINT) {

      outSortBigInt = ast_emalloc(vec->length * sizeof(mpz_t *));

      while (vecContent != NULL) {
        mpz_t *n = ast_emalloc(sizeof(mpz_t));
        if (vecContent->arg->type != EXPR_TYPE_BIGINT) {
          free(outSortBigInt);
          fprintf(stderr, "error %s.%d: %s unexpected datatype in list (%d)",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME(),
                  vecContent->arg->type);
          exit(1);
        }

        mpz_init_set(*n, *vecContent->arg->bigInt);

        outSortBigInt[i] = n;
        vecContent = vecContent->next;
        i++;
      }

      qsort(outSortBigInt, vec->length, sizeof(mpz_t *), _cmp_func_mpz);
    } else if (vecContent->arg->type == EXPR_TYPE_TEXT) {
      outSortChars = ast_emalloc(vec->length * sizeof(char *));

      while (vecContent != NULL) {
        if (vecContent->arg->type != EXPR_TYPE_TEXT) {
          free(outSortBigInt);
          fprintf(stderr, "error %s.%d: %s unexpected datatype in list (%d)",
                  ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME(),
                  vecContent->arg->type);
          exit(1);
        }

        outSortChars[i] = vecContent->arg->text;
        vecContent = vecContent->next;
        i++;
      }

      qsort(outSortChars, vec->length, sizeof(char *), _cmp_func_chars);
    }
    vecContent = NULL;
  }
  i = 0;
  while (i < vec->length) {
    expr_t *e = NULL;
    argsList_t *a;

    if (outSort != NULL) {
      e = newExpr_Ival(outSort[i]);
    } else if (outSortBigInt != NULL) {
      e = newExpr_BigInt(outSortBigInt[i]);
      free(outSortBigInt[i]);
    } else if (outSortChars != NULL) {
      e = newExpr_Text(outSortChars[i]);
    }

    a = newArgument(e, vecContent);
    vecContent = a;

    ++i;
  }

  if (outSort != NULL) {
    free(outSort);
  } else if (outSortBigInt != NULL) {
    free(outSortBigInt);
  } else if (outSortChars != NULL) {
    free(outSortChars);
  }

  newVec = newExpr_Vector(vecContent);

  stv.type = VECTORTYPE;
  stv.vec = newVec->vec;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);
  free(newVec);

  /* Pushing the parsed value */
  PUSH_VECTOR(stv.vec, sp, sc);

  return 0;
}

int ric_join(LIBRARY_PARAMS()) {
  stackval_t stv;
  int dummy;
  heapval_t *hpv;
  int i = 0;
  int first_iteration = 1;
  char *joinArg = NULL;
  size_t joinArgLen = 0;
  vector_t *vec = NULL;
  argsList_t *vecContent = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  char *outChars = NULL;
  size_t outputStringSize = 0;

  /* Read argument */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
      vec = stv.vec;
      break;
    default:
      fprintf(stderr, "error %s.%d: %s unexpected input argument; expected list\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME());
      exit(1);
      break;
  }

  /* Read argument */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      joinArg = stv.t;
      joinArgLen = strlen(joinArg);
      break;
    default:
      fprintf(stderr, "error %s.%d: %s unexpected input argument; expected string\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME());
      exit(1);
      break;
  }
  vecContent = vec->content;
  // Calculate total string size
  while (vecContent != NULL) {
    stackval_t stv;
    evaluate_expression(vecContent->arg, EXPRESSION_ARGS());
    POP_VAL(&stv, sp, sc);
    if (stv.type != TEXT) {
      fprintf(stderr, "error %s.%d: %s unexpected list member type; expected string\n",
              ((statement_t *)stmt)->file, ((statement_t *)stmt)->line, LIBRARY_FUNC_NAME());
      exit(1);
    }
    if (outputStringSize == 0) {
      // First iteration
      outputStringSize += strlen(stv.t);
    } else {
      outputStringSize += strlen(stv.t) + joinArgLen;
    }
    vecContent = vecContent->next;
  }

  outChars = ast_emalloc(outputStringSize + 1);
  vecContent = vec->content;
  i = 0;
  // Calculate total string size
  while (vecContent != NULL) {
    size_t bytesToWrite = 0;
    stackval_t stv;
    evaluate_expression(vecContent->arg, EXPRESSION_ARGS());
    POP_VAL(&stv, sp, sc);

    if (first_iteration) {
      // first iteration
      bytesToWrite = strlen(stv.t);
      if (bytesToWrite > 0) {
        snprintf(&outChars[i], bytesToWrite + 1, "%s", stv.t);
      }
    } else {
      bytesToWrite = strlen(stv.t) + joinArgLen;
      if (strlen(stv.t) > 0) {
        snprintf(&outChars[i], bytesToWrite + 1, "%s%s", joinArg, stv.t);
      } else {
        snprintf(&outChars[i], bytesToWrite + 1, "%s", joinArg);
      }
    }
    first_iteration = 0;
    i += bytesToWrite;
    vecContent = vecContent->next;
  }

  stv.type = TEXT;
  stv.t = outChars;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the parsed value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_cachepot(LIBRARY_PARAMS()) {
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  expr_t *e = newExpr_Cachepot();

  cachepot_t *cachepot = e->cachepot;
  free(e);

  PUSH_CACHEPOT(cachepot, sp, sc);
  return 0;
}
