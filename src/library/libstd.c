#include "libstd.h"

int ric_exit(LIBRARY_PARAMS())
{
  stackval_t stv;
  int exitCode = 0;

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

int ric_print(LIBRARY_PARAMS())
{
  stackval_t stv;

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
          // Ignoring this backslashed one, since I don't understand it..
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
          // Ignoring this backslashed one, since I don't understand it..
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
  int32_t result = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case VECTORTYPE:
    argVec = (vector_t*) stv.vec;
    break;
    case TEXT:
    argText = stv.t;
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

  printf("These are the functions I know:\nfunction-name ( number-of-arguments)\n");

  /* Output what this interpreter can do */
  while ( walk < ric_lib_calls() ) {
    printf("- %s ( %d )\n", ric_library[walk].libFuncName, ric_library[walk].nbrArgs);
    ++walk;
  }

  /* Pushing result */
  PUSH_INT(result, sp, sc);

  return 0;
}

