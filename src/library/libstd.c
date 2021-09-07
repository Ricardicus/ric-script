#include "libstd.h"

int ric_exit(LIBRARY_PARAMS())
{
  stackval_t stv;
  int exitCode = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    exitCode = (int) stv.i;
    break;
    default: {
      fprintf(stderr, "error: function call '%s' expects a single integer as argument.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  exit(exitCode);
  return 1;
}

int ric_type(LIBRARY_PARAMS())
{
  stackval_t stv;
  int result = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  result = stv.type;

  PUSH_INT(result, sp, sc);
  return 0;
}

int ric_type_text(LIBRARY_PARAMS())
{
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
  case INT32TYPE: snprintf(resultText, strSize, "%s", "i32"); break;
  case DOUBLETYPE: snprintf(resultText, strSize, "%s", "double"); break;
  case TEXT: snprintf(resultText, strSize, "%s", "text"); break;
  case POINTERTYPE: snprintf(resultText, strSize, "%s", "pointer"); break;
  case FUNCPTRTYPE: snprintf(resultText, strSize, "%s", "function-pointer"); break;
  case LIBFUNCPTRTYPE: snprintf(resultText, strSize, "%s", "standard-library-function-pointer"); break;
  case VECTORTYPE: snprintf(resultText, strSize, "%s", "list"); break;
  case DICTTYPE: snprintf(resultText, strSize, "%s", "dictionary"); break;
  case CLASSTYPE: snprintf(resultText, strSize, "%s", "class"); break;
  case TIMETYPE: snprintf(resultText, strSize, "%s", "time"); break;
  case RAWDATATYPE: snprintf(resultText, strSize, "%s", "data"); break;
  default:
  snprintf(resultText, strSize, "%s%s", "Unknown? Please file an error report at: ", GENERAL_ERROR_ISSUE_URL);
  break;
  }

  stv.type = TEXT;
  stv.t = resultText;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_create_list(LIBRARY_PARAMS())
{
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
    ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, LIBRARY_FUNC_NAME());
  exit(1);
  break;
  }

  if ( inText != NULL ) {
    c = inText;
    while ( *c ) {
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
  } else if ( inSize > 0 ) {
    int32_t i = 0;
    while ( i < inSize ) {
      expr_t *e;
      argsList_t *a;

      e = newExpr_Ival(0);
      a = newArgument(e, vecContent);
      vecContent = a;

      ++i;
    }
  } else if ( rawdata != NULL ) {
    size_t i = 0;
    while ( i < rawdata->size ) {
      expr_t *e;
      argsList_t *a;
      int val = (int)((unsigned char*)rawdata->data)[i];

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

int ric_create_data(LIBRARY_PARAMS())
{
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
    ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, LIBRARY_FUNC_NAME());
  exit(1);
  break;
  }

  if ( inText != NULL ) {
    size_t textlen = strlen(inText);
    newRawData = newExpr_RawData(textlen);

    newRawData->rawdata->size = textlen;
    memcpy(newRawData->rawdata->data, inText, newRawData->rawdata->size);
  } else if ( vec != NULL ) {
    argsList_t *content = vec->content;
    size_t i = 0;
    size_t contentSize = (size_t)vec->length;

    newRawData = newExpr_RawData(contentSize);
    i = 0;
    while ( content != NULL ) {
      /* Evaluate expression */
      int32_t val;
      evaluate_expression(content->arg, EXPRESSION_ARGS());
      POP_VAL(&stv, sp, sc);
      
      if ( stv.type != INT32TYPE ) {
        /* This is not ok */
        fprintf(stderr, "error %s.%d: Cannot create data out of this list, only integer values acceptable\n",
          ((statement_t*)stmt)->file, ((statement_t*)stmt)->line);
        exit(1);
      }

      val = stv.i;

      if ( val > 255 || val < 0 ) {
        fprintf(stderr, "error %s.%d: Cannot create data out of this list, only integer values in the range [0, 255] acceptable\n",
          ((statement_t*)stmt)->file, ((statement_t*)stmt)->line);
        exit(1);
      }

      ((unsigned char*)newRawData->rawdata->data)[i] = (unsigned char) (val & ((1<<8) - 1));
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

int ric_create_text(LIBRARY_PARAMS())
{
  stackval_t stv;
  int dummy;
  heapval_t *hpv;
  char *inText = NULL;
  int32_t inInt;
  bool isInt = false;
  vector_t *vec = NULL;
  rawdata_t *rawData = NULL;
  expr_t *newText = NULL;
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
  case RAWDATATYPE:
  rawData = stv.rawdata;
  break;
  default:
  fprintf(stderr, "error %s.%d: %s unexpected input argument; expected vector, data or text\n",
    ((statement_t*)stmt)->file, ((statement_t*)stmt)->line, LIBRARY_FUNC_NAME());
  exit(1);
  break;
  }

  if ( inText != NULL ) {
    newText = newExpr_Text(inText);
  } else if ( rawData != NULL ) {
    newText = newExpr_Text(rawData->data);
  } else if ( isInt ) {
    char intCharBuf[100];
    memset(intCharBuf, 0, sizeof(intCharBuf));
    snprintf(intCharBuf, sizeof(intCharBuf), "%" PRIi32 "", inInt);
    newText = newExpr_Text(intCharBuf);
  } else if ( vec != NULL ) {
    argsList_t *content = vec->content;
    size_t i = 0;
    size_t contentSize = (size_t)vec->length;
    char *buffer = ast_ecalloc(contentSize+1);

    i = 0;
    while ( content != NULL ) {
      /* Evaluate expression */
      int32_t val;
      evaluate_expression(content->arg, EXPRESSION_ARGS());
      POP_VAL(&stv, sp, sc);

      if ( stv.type != INT32TYPE ) {
        /* This is not ok */
        fprintf(stderr, "error %s.%d: Cannot create text out of this list, only integer values acceptable\n",
          ((statement_t*)stmt)->file, ((statement_t*)stmt)->line);
        exit(1);
      }

      val = stv.i;

      if ( val > 255 || val < 0 ) {
        fprintf(stderr, "error %s.%d: Cannot create text out of this list, only integer values in the range [0, 255] acceptable\n",
          ((statement_t*)stmt)->file, ((statement_t*)stmt)->line);
        exit(1);
      }

      buffer[i] = (char) (val & ((1<<8) - 1));
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

int ric_print(LIBRARY_PARAMS())
{
  stackval_t stv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT: 
    {
      char *c = stv.t;
      int backslash = 0;

      /* 
      * Parsing the string,
      * some character combos (such as: '\r','\n)
      * should be interpreted disctincly
      */
      while ( *c ) {

        if ( !backslash && *c == '\\' ) {
          backslash = 1;
          ++c;
          continue;
        }

        if ( backslash ) {
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
    }
    break;
    case INT32TYPE:
    printf("%d\n", stv.i);
    break;
    case TIMETYPE: {
      struct tm *info;
      if ( stv.time < 0 ) {
        /* Relative time to now */
        time_t nowTime;
        time_t result;
        time(&nowTime);
        result = nowTime + stv.time;
        info = localtime( &result );
      } else {
        info = localtime( &stv.time );
      }
      printf("%s\n", asctime(info));
      break;
    }
    case DOUBLETYPE:
    printf("%lf\n", stv.d);
    break;
    case CLASSTYPE: {
      if ( ! stv.classObj->initialized ) {
        printf("<Class: '%s'>\n", stv.classObj->id);
      } else {
        printf("<Class object: '%s'>\n", stv.classObj->id);
      }
    }
    break;
    case POINTERTYPE:
    printf("<%" PRIuPTR ">\n", stv.p);
    break;
    case DICTTYPE: {
      print_dictionary(stv.dict, EXPRESSION_ARGS());
      printf("\n");
      break;
    }
    case FUNCPTRTYPE:
    printf("<Function: '%s'>\n", stv.func->id.id);
    break;
    case VECTORTYPE:
    {
      print_vector(stv.vec, EXPRESSION_ARGS());
      printf("\n");
    }
    break;
    case RAWDATATYPE:
    {
      size_t i = 0;
      while ( i < stv.rawdata->size ) {
        printf("%c", ((char*)stv.rawdata->data)[i]);
        ++i;
      }
      printf("\n");
    }
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  return 0;
}

int ric_printf(LIBRARY_PARAMS())
{
  stackval_t stv;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT: 
    {
      char *c = stv.t;
      int backslash = 0;

      /* 
      * Parsing the string,
      * some character combos (such as: '\r','\n)
      * should be interpreted disctincly
      */
      while ( *c ) {

        if ( !backslash && *c == '\\' ) {
          backslash = 1;
          ++c;
          continue;
        }

        if ( backslash ) {
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

    }
    break;
    case INT32TYPE:
    printf("%d", stv.i);
    break;
    case CLASSTYPE:
    {
      if ( ! stv.classObj->initialized ) {
        printf("<Class: '%s'>", stv.classObj->id);
      } else {
        printf("<Class object: '%s'>", stv.classObj->id);
      }
    }
    break;
    case TIMETYPE: {
      struct tm *info;
      if ( stv.time < 0 ) {
        /* Relative time to now */
        time_t nowTime;
        time_t result;
        time(&nowTime);
        result = nowTime + stv.time;
        info = localtime( &result );
      } else {
        info = localtime( &stv.time );
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
    case VECTORTYPE:
    {
      print_vector(stv.vec, EXPRESSION_ARGS());
    }
    break;
    case RAWDATATYPE:
    {
      size_t i = 0;
      while ( i < stv.rawdata->size ) {
        printf("%c", ((char*)stv.rawdata->data)[i]);
        ++i;
      }
    }
    break;
    default: {
      fprintf(stderr, "error: function call '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  return 0;
}


int ric_append(LIBRARY_PARAMS())
{
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
      fprintf(stderr, "error: function call '%s' got an unexpected first argument.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  /* Get what to append */
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
    entry = newExpr_FuncPtr((void*)stv.p);
    break;
  case LIBFUNCPTRTYPE:
    entry = newExpr_LibFuncPtr((void*)stv.p);
    break;
  case VECTORTYPE: {
      entry = copy_vector(stv.vec, EXPRESSION_ARGS());
    }
    break;
  default: {
      fprintf(stderr, "error: function call '%s' got an unexpected first argument.\n",
        LIBRARY_FUNC_NAME());
      exit(1);
    }
    break;
  }

  addition = newArgument(entry, NULL);
  walk = vec->content;
  if ( walk == NULL ) {
    // Special case
    vec->content = addition;
  } else {
    while ( walk->next != NULL ) {
      walk = walk->next;
    }
    walk->next = addition;
  }
  // Increase vector size
  vec->length++;

  return 0;
}

int ric_contains(LIBRARY_PARAMS())
{
  stackval_t stv;
  vector_t *argVec = NULL;
  dictionary_t *argDict = NULL;
  char *argText = NULL;
  char *containText = NULL;
  int32_t containInt = 0;
  int32_t result = 0;
  int searchForInt = 0;  // Lazy, search for int or text.
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
    default: {
      fprintf(stderr, "error: function '%s' expected string, dictionary or list as first argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
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
    default: {
      fprintf(stderr, "error: function '%s' expected text or integer as first argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  if ( argVec != NULL ) {
    /* Search in a vector */
    argsList_t *walk = argVec->content;

    while ( walk != NULL ) {
      /* Evaluate expression */
      evaluate_expression(walk->arg, EXPRESSION_ARGS());
      POP_VAL(&stv, sp, sc);

      if ( searchForInt ) {
        /* Check if is int and number match */
        if ( stv.type == INT32TYPE && stv.i == containInt ) {
          result = 1;
          break;
        }
      } else {
        /* Check if is text */
        if ( stv.type == TEXT && strcmp(stv.t, containText) == 0 ) {
          result = 1;
          break;
        }
      }
      walk = walk->next;
    }
  } else if ( argDict != NULL ) {
    /* Search in a dictionary */
    hashtable_t *hash = argDict->hash;
    int hashSize = hash->size;
    struct key_val_pair *ptr;
    int i = 0;

    if ( searchForInt ) {
      /* all keys are strings */
      result = 0;
    } else {
      while ( i < hashSize && result == 0 ) {
        ptr = hash->table[i];
        while (ptr != NULL) {
          /* Check if match */
          if ( strcmp((char*)ptr->key, containText) == 0 ) {
            result = 1;
            break;
          }
          ptr = ptr->next;
        }
        i++;
      }
    }
  } else if ( argText != NULL ) {
    if ( searchForInt ) {
      /* Check if int is in the text */
      char buffer[50];

      snprintf(buffer, sizeof(buffer), "%" PRIi32 "", containInt);
      
      if ( strstr(argText, buffer) != NULL ) {
        result = 1;
      }
    } else {
      /* Check if is text */
      if ( strstr(argText, containText) != NULL ) {
        result = 1;
      }
    }
  }

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_len(LIBRARY_PARAMS())
{
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
    argVec = (vector_t*) stv.vec;
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
    }
    break;
  }

  if ( argVec != NULL ) {
    result = argVec->length;
  } else if ( argText != NULL ) {
    result = (int32_t) strlen(argText);
  } else if ( rawdata != NULL ) {
    result = rawdata->size;
  } else {
    /* The switch above should have taken care avout this */
    return 1;
  }

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

int ric_keys(LIBRARY_PARAMS())
{
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
    }
    break;
  }

  if ( argDict != NULL ) {
    /* list the dictionary */
    hashtable_t *hash = argDict->hash;
    int hashSize = hash->size;
    struct key_val_pair *ptr;
    int i = 0;

    while ( i < hashSize && result == 0 ) {
      ptr = hash->table[i];
      while (ptr != NULL) {
        /* Add this key to the list */
        expr_t *e;
        argsList_t *a;
        e = newExpr_Text((char*)ptr->key);
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

int ric_is_defined(LIBRARY_PARAMS())
{
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
      fprintf(stderr, "error: function '%s' got unexpected data type as argument, expected string.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  result = evaluate_id_valid(arg1, EXPRESSION_ARGS());

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

extern libFunction_t ric_library[];

int ric_help(LIBRARY_PARAMS())
{
  int32_t result = 0;
  int walk = 0;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  dl_handle_t *dynLibs;
  int nbrDynLibs = 0;

  printf("These are the functions I know:\nfunction-name ( number-of-arguments)\n");

  /* Output what this interpreter can do */
  while ( walk < ric_lib_calls() ) {
    printf("- %s ( %d )\n", ric_library[walk].libFuncName, ric_library[walk].nbrArgs);
    ++walk;
  }

  /* Print dynamically loaded libraries */
  ric_get_dynamic_libraries(&dynLibs, &nbrDynLibs);
  if ( nbrDynLibs > 0 ) {
    printf("These are the modules and functions I have loaded dynamically:\nfunction-name ( number-of-arguments)\n");
    walk = 0;
    while ( walk < nbrDynLibs ) {
      dl_print_mod_info(stdout, &dynLibs[walk]);
      walk++;
    }
  }

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

static void loadCJSON(cJSON *json, int depth,
  expr_t **out, EXPRESSION_PARAMS()) {
  cJSON *walk = json;
  int count = 0;
  int i = 0;
  keyValList_t *keyVals = NULL;
  keyValList_t *keyValsHead = NULL;
  int isArray = 0;

  /* Get number of elements */
  while ( walk != NULL ) {
    walk = walk->next;
    count++;
  }

  walk = json;
  i = 0;
  while ( walk != NULL ) {
    expr_t *val = NULL;
    keyValList_t *keyVal = ast_ecalloc(sizeof(keyValList_t));
    keyVal->next = NULL;
    keyVal->key = NULL;
    keyVal->val = NULL;

    if ( walk->string ) {
      stackval_t stv;
      heapval_t *hpv;
      int dummy;
      void *hp = PROVIDE_CONTEXT()->hp;

      keyVal->key = newExpr_Text(walk->string);

      stv.type = TEXT;
      stv.t = keyVal->key->text;
      ALLOC_HEAP(&stv, hp, &hpv, &dummy);
    }
    switch ( walk->type ) {
      case cJSON_False:
      val = newExpr_Ival(0);
      break;
      case cJSON_True:
      val = newExpr_Ival(1);
      break; 
      case cJSON_NULL:
      val = newExpr_Ival(0);
      break;
      case cJSON_Number :
      val = newExpr_Float(walk->valuedouble);
      break;
      case cJSON_String : {
        stackval_t stv;
        heapval_t *hpv;
        int dummy;
        void *hp = PROVIDE_CONTEXT()->hp;

        val = newExpr_Text(walk->valuestring);

        stv.type = TEXT;
        stv.t = val->text;
        ALLOC_HEAP(&stv, hp, &hpv, &dummy);
      }
      break;
      case cJSON_Array  :
      loadCJSON(walk->child, depth + 1, &val, EXPRESSION_ARGS());
      break;
      case cJSON_Object : {
        loadCJSON(walk->child, depth + 1, &val, EXPRESSION_ARGS());
        if (depth == 0 ) {
          *out = val;
          free(keyVal);
          return;
        }
      }
      break;
      case cJSON_Raw    :
      val = newExpr_Text(walk->valuestring);
      break; /* raw json */
      default:
      break;
    }

    if ( val ) {
      keyVal->val = val;
    }

    if ( val && keyVal->key == NULL ) {
      /* This is an array */
      isArray = 1;
    }

    if ( keyVals != NULL ) {
      keyVals->next = keyVal;
    }

    keyVals = keyVal;

    if ( i == 0 ) {
      keyValsHead = keyVals;
    }

    walk = walk->next;
    i++;
  }

  keyVals = keyValsHead;

  if ( isArray && out != NULL ) {
    argsList_t *args = NULL;
    argsList_t *argsHead = NULL;
    keyValList_t *keyValsWalk = keyVals;

    i = 0;
    while ( keyValsWalk ) {
      argsList_t *arg = ast_ecalloc(sizeof(argsList_t));
      arg->arg = keyValsWalk->val;
      arg->next = NULL;

      if ( args != NULL ) {
        args->next = arg;
      }

      args = arg;

      if ( i == 0 ) {
        argsHead = args;
      }

      keyValsWalk = keyValsWalk->next;
      i++;
    }

    args = argsHead;
    if ( args != NULL ) {
      /* Reverse the args list order */
      argsList_t *prev = NULL;
      argsList_t *current = args;
      argsList_t *next;
      while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }

      args = prev;
    }

    keyValsWalk = keyVals;
    while ( keyValsWalk ) {
      keyValList_t *kvw = keyValsWalk;
      keyValsWalk = keyValsWalk->next;
      free(kvw);
    }
    *out = newExpr_Vector(args);
  } else if ( out != NULL ) {
    expr_t *outE = newExpr_Dictionary(keyVals);
    outE->dict->type = RIC_DICTIONARY_DYN;
    *out = outE;
  }

}

int ric_json_load(LIBRARY_PARAMS())
{
  stackval_t stv;
  expr_t *result = NULL;
  cJSON *json = NULL;
  FILE *fp = NULL;
  char *argText = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  int dummy;
  heapval_t *hpv = NULL;
  void *hp = PROVIDE_CONTEXT()->hp;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    argText = stv.t;
    break;
    case POINTERTYPE:
    fp = (FILE*)stv.p;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument, expected string or file.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  if ( fp != NULL ) {
    size_t sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    argText = ast_ecalloc(sz + 2);
    fread(argText, 1, sz, fp);
    json = cJSON_Parse(argText);
    free(argText);
  } else if ( argText != NULL ) {
    json = cJSON_Parse(argText);
  }

  if (json == NULL) {
    /* Pushing result, failed to parse */
    PUSH_INT(0, sp, sc);
    return 0;
  }
  
  /* Print the cJSON object */
  result = NULL;
  loadCJSON(json, 0, &result, EXPRESSION_ARGS());

  stv.type = DICTTYPE;
  stv.dict = result->dict;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  PUSH_DICTIONARY(result->dict, sp, sc);
  free(result);

  cJSON_Delete(json);

  return 0;
}

