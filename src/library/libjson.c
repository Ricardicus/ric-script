#include "libjson.h"

static void loadCJSON(cJSON *json, int depth, expr_t **out, EXPRESSION_PARAMS()) {
  cJSON *walk = json;
  int i = 0;
  keyValList_t *keyVals = NULL;
  keyValList_t *keyValsHead = NULL;
  int isArray = 0;

  walk = json;
  i = 0;
  while (walk != NULL) {
    expr_t *val = NULL;
    keyValList_t *keyVal = ast_ecalloc(sizeof(keyValList_t));
    keyVal->next = NULL;
    keyVal->key = NULL;
    keyVal->val = NULL;

    if (walk->string) {
      keyVal->key = newExpr_Text(walk->string);
    }
    switch (walk->type) {
      case cJSON_False:
        val = newExpr_Ival(0);
        break;
      case cJSON_True:
        val = newExpr_Ival(1);
        break;
      case cJSON_NULL:
        val = newExpr_Ival(0);
        break;
      case cJSON_Number:
        val = newExpr_Float(walk->valuedouble);
        break;
      case cJSON_String:
        val = newExpr_Text(walk->valuestring);
        break;
      case cJSON_Array:
        loadCJSON(walk->child, depth + 1, &val, EXPRESSION_ARGS());
        break;
      case cJSON_Object: {
        loadCJSON(walk->child, depth + 1, &val, EXPRESSION_ARGS());
        if (depth == 0) {
          *out = val;
          free(keyVal);
          return;
        }
      } break;
      case cJSON_Raw:
        val = newExpr_Text(walk->valuestring);
        break; /* raw json */
      default:
        break;
    }

    if (val) {
      keyVal->val = val;
    }

    if (val && keyVal->key == NULL) {
      /* This is an array */
      isArray = 1;
    }

    if (keyVals != NULL) {
      keyVals->next = keyVal;
    }

    keyVals = keyVal;

    if (i == 0) {
      keyValsHead = keyVals;
    }

    walk = walk->next;
    i++;
  }

  keyVals = keyValsHead;

  if (isArray && out != NULL) {
    expr_t *newVec = NULL;
    stackval_t stv;
    int dummy;
    heapval_t *hpv = NULL;
    heapval_t *hp = PROVIDE_CONTEXT()->hp;
    argsList_t *args = NULL;
    argsList_t *argsHead = NULL;
    keyValList_t *keyValsWalk = keyVals;

    i = 0;
    while (keyValsWalk) {
      argsList_t *arg = ast_ecalloc(sizeof(argsList_t));
      arg->arg = keyValsWalk->val;
      arg->next = NULL;

      if (args != NULL) {
        args->next = arg;
      }

      args = arg;

      if (i == 0) {
        argsHead = args;
      }

      keyValsWalk = keyValsWalk->next;
      i++;
    }

    args = argsHead;
    if (args != NULL) {
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
    while (keyValsWalk) {
      keyValList_t *kvw = keyValsWalk;
      keyValsWalk = keyValsWalk->next;
      free(kvw);
    }
    newVec = newExpr_Vector(args);
    stv.type = VECTORTYPE;
    stv.vec = newVec->vec;

    ALLOC_HEAP(&stv, hp, &hpv, &dummy);
    *out = newVec;
  } else if (out != NULL) {
    expr_t *outE = newExpr_Dictionary(keyVals);
    dictionary_t *outEHead = allocNewDictionary(outE->dict, EXPRESSION_ARGS());
    free(outE->dict);
    expr_t *newExp = ast_emalloc(sizeof(expr_t));
    newExp->type = EXPR_TYPE_DICT;
    newExp->dict = outEHead;
    free(outE);
    *out = newExp;
  }
}

int ric_json_convert(LIBRARY_PARAMS()) {
  stackval_t stv;
  dictionary_t *argDict = NULL;
  class_t *argClass = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  int dummy;
  heapval_t *hpv = NULL;
  void *hp = PROVIDE_CONTEXT()->hp;
  char *resultBuf = NULL;
  size_t resultSize = 0;
  size_t resultEndPos = 0;

  // Pop arg1
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case DICTTYPE:
      argDict = stv.dict;
      break;
    case CLASSTYPE:
      argClass = stv.classObj;
      break;
    default: {
      fprintf(
          stderr,
          "error: function '%s' got unexpected data type as argument, expected string or file.\n",
          LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  /* Convert the object into a JSON formatted string */
  if (argDict != NULL) {
    snprint_dictionary(&resultBuf, &resultSize, &resultEndPos, argDict, EXPRESSION_ARGS());
  } else if (argClass != NULL) {
    dictionary_t tmpDict;

    tmpDict.initialized = 1;
    tmpDict.hash = argClass->varMembers;
    tmpDict.keyVals = NULL;

    snprint_dictionary(&resultBuf, &resultSize, &resultEndPos, &tmpDict, EXPRESSION_ARGS());
  }

  stv.type = TEXT;
  stv.t = resultBuf;

  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  PUSH_STRING(stv.t, sp, sc);
  return 0;
}

int ric_json_load(LIBRARY_PARAMS()) {
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
      fp = (FILE *)stv.p;
      break;
    default: {
      fprintf(
          stderr,
          "error: function '%s' got unexpected data type as argument, expected string or file.\n",
          LIBRARY_FUNC_NAME());
      return 1;
    } break;
  }

  if (fp != NULL) {
    size_t sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    argText = ast_ecalloc(sz + 2);
    fread(argText, 1, sz, fp);
    json = cJSON_Parse(argText);
    free(argText);
  } else if (argText != NULL) {
    json = cJSON_Parse(argText);
  }

  if (json == NULL) {
    /* Pushing result, failed to parse */
    PUSH_INT(-1, sp, sc);
    return 0;
  }

  /* Convert the cJSON object */
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
