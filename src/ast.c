#include "ast.h"
#include "eval.h"
#include "hashtable.h"
#include "prioqueue.h"
#include <stdarg.h>

void *ast_emalloc(size_t size) {
  char *p = (char *)malloc(size);
  if (p == NULL) {
    fprintf(stderr, "%s %s error: Failed to build AST, malloc failed (%zu bytes)\n", __FILE__,
            __func__, size);
    exit(EXIT_FAILURE);
  }
  return (void *)p;
}

void *ast_remalloc(void *mem, size_t size) {
  char *p = (char *)realloc(mem, size);
  if (p == NULL) {
    fprintf(stderr, "%s %s error: Failed to build AST, malloc failed (%zu bytes)\n", __FILE__,
            __func__, size);
    exit(EXIT_FAILURE);
  }
  return (void *)p;
}

void *ast_ecalloc(size_t size) {
  char *p = (char *)calloc(size, 1);
  if (p == NULL) {
    fprintf(stderr, "%s %s error: Failed to build AST, malloc failed (%zu bytes)\n", __FILE__,
            __func__, size);
    exit(EXIT_FAILURE);
  }
  return (void *)p;
}

expr_t *newExpr_Time(time_t time) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  expr->type = EXPR_TYPE_TIME;
  expr->time = time;
  return expr;
}

expr_t *newExpr_ClassPtr(class_t *class) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  class_t *cls = ast_emalloc(sizeof(class_t));

  cls->id = class->id;
  cls->defines = class->defines;
  cls->funcDefsScript = hashtable_new(DICTIONARY_STANDARD_SIZE, DICTIONARY_STANDARD_LOAD);
  cls->funcDefsABI = hashtable_new(DICTIONARY_STANDARD_SIZE, DICTIONARY_STANDARD_LOAD);
  cls->varMembers = hashtable_new(DICTIONARY_STANDARD_SIZE, DICTIONARY_STANDARD_LOAD);

  expr->type = EXPR_TYPE_CLASSPTR;
  expr->classObj = cls;
  return expr;
}

expr_t *newExpr_ClassPtrCopy(class_t *class) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  class_t *cls = ast_emalloc(sizeof(class_t));

  cls->id = class->id;
  cls->defines = class->defines;
  cls->funcDefsScript = hashtable_copy(class->funcDefsScript);
  cls->funcDefsABI = hashtable_copy(class->funcDefsABI);
  cls->varMembers = hashtable_copy(class->varMembers);
  cls->initialized = class->initialized;

  expr->type = EXPR_TYPE_CLASSPTR;
  expr->classObj = cls;
  return expr;
}

expr_t *newExpr_Cond(ifCondition_t *cond) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_COND;
  expr->cond = cond;

  return expr;
}

expr_t *newExpr_Pointer(uintptr_t val) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_POINTER;
  expr->p = val;

  return expr;
}

expr_t *newExpr_FuncPtr(void *func) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FUNCPTR;
  expr->func = func;

  return expr;
}

expr_t *newExpr_BigIntFromStr(const char *intStr) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  mpz_t *n = ast_emalloc(sizeof(mpz_t));

  mpz_init_set_str(*n, intStr, 10);

  expr->type = EXPR_TYPE_BIGINT;
  expr->bigInt = n;

  return expr;
}

expr_t *newExpr_BigIntFromInt(intptr_t val) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  mpz_t *n = ast_emalloc(sizeof(mpz_t));

  mpz_init_set_si(*n, (signed long)val);

  expr->type = EXPR_TYPE_BIGINT;
  expr->bigInt = n;

  return expr;
}

expr_t *newExpr_BigInt(mpz_t *n_) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  mpz_t *n = ast_emalloc(sizeof(mpz_t));

  mpz_init_set(*n, *n_);

  expr->type = EXPR_TYPE_BIGINT;
  expr->bigInt = n;

  return expr;
}

expr_t *newExpr_Indexer(expr_t *left, expr_t *right, expr_t *offset) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  indexer_t *indexer = ast_emalloc(sizeof(indexer_t));

  indexer->left = left;
  indexer->right = right;
  indexer->offset = offset;

  expr->type = EXPR_TYPE_INDEXER;
  expr->indexer = indexer;
  return expr;
}

expr_t *newExpr_Logical(expr_t *prevLogical, expr_t *newAnd, expr_t *newOr) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  logical_t *logical = ast_emalloc(sizeof(logical_t));
  int appendPrev = 0;

  logical->andsLen = 0;
  logical->orsLen = 0;
  logical->ands = NULL;
  logical->ors = NULL;

  if (prevLogical != NULL && prevLogical->type == EXPR_TYPE_LOGICAL) {
    logical->andsLen = prevLogical->logical->andsLen;
    logical->ands = prevLogical->logical->ands;

    logical->orsLen = prevLogical->logical->orsLen;
    logical->ors = prevLogical->logical->ors;

    /* Free this logical */
    free(prevLogical->logical);
    free(prevLogical);
  } else if (prevLogical != NULL) {
    appendPrev = 1;
  }

  if (newAnd != NULL) {
    logical->andsLen++;
    logical->ands = ast_remalloc(logical->ands, logical->andsLen * sizeof(expr_t *));
    logical->ands[logical->andsLen - 1] = newAnd;

    if (appendPrev) {
      logical->andsLen++;
      logical->ands = ast_remalloc(logical->ands, logical->andsLen * sizeof(expr_t *));
      logical->ands[logical->andsLen - 1] = prevLogical;
    }
  }

  if (newOr != NULL) {
    logical->orsLen++;
    logical->ors = ast_remalloc(logical->ors, logical->orsLen * sizeof(expr_t *));
    logical->ors[logical->orsLen - 1] = newOr;

    if (appendPrev) {
      logical->orsLen++;
      logical->ors = ast_remalloc(logical->ors, logical->orsLen * sizeof(expr_t *));
      logical->ors[logical->orsLen - 1] = prevLogical;
    }
  }

  expr->type = EXPR_TYPE_LOGICAL;
  expr->logical = logical;

  return expr;
}

expr_t *newExpr_Vector(argsList_t *args) {
  int32_t length = 0;
  argsList_t *walk;
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  vector_t *vec = ast_emalloc(sizeof(vector_t));

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

    walk = args;
    /* Counting the vectors length */
    while (walk != NULL) {
      length++;
      walk = walk->next;
    }
  }

  vec->length = length;
  vec->content = args;
  vec->forEach = NULL;

  expr->type = EXPR_TYPE_VECTOR;
  expr->vec = vec;

  return expr;
}

expr_t *newExpr_VectorFromForEach(statement_t *forEach) {
  int32_t length = 0;
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  vector_t *vec = ast_emalloc(sizeof(vector_t));

  vec->length = length;
  vec->content = NULL;
  vec->forEach = forEach;

  expr->type = EXPR_TYPE_VECTOR;
  expr->vec = vec;

  return expr;
}

expr_t *newExpr_Dictionary(keyValList_t *keyVals) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  expr->dict = ast_emalloc(sizeof(dictionary_t));

  expr->type = EXPR_TYPE_DICT;

  expr->dict->initialized = 0;
  expr->dict->keyVals = keyVals;
  expr->dict->hash = NULL;
  expr->dict->type = RIC_DICTIONARY_AST;

  return expr;
}

expr_t *newExpr_Cachepot(void) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  cachepot_t *cachepot = ast_emalloc(sizeof(expr_t));

  cachepot->hash = hashtable_new(CACHEPOT_STANDARD_SIZE, CACHEPOT_STANDARD_LOAD);
  expr->type = EXPR_TYPE_CACHEPOT;
  expr->cachepot = cachepot;

  return expr;
}

expr_t *newExpr_PriorityQueue(int capacity, int is_minimum) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  priority_queue_t *prioqueue = new_priority_queue(capacity, is_minimum);

  expr->type = EXPR_TYPE_PRIOQUEUE;
  expr->prioqueue = prioqueue;

  return expr;
}

expr_t *newExpr_Text(char *text) {
  size_t textLen = strlen(text);
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_TEXT;
  expr->text = (char *)ast_emalloc(textLen + 1);

  memcpy(expr->text, text, textLen);
  expr->text[textLen] = 0;

  return expr;
}

expr_t *newExpr_Ival(int val) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_IVAL;
  expr->ival = (int32_t)val;

  return expr;
}

expr_t *newExpr_Uval(unsigned val) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_UVAL;
  expr->ival = (uint32_t)val;

  return expr;
}

expr_t *newExpr_Float(double val) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FVAL;
  expr->fval = val;

  return expr;
}

expr_t *newExpr_RawData(size_t size) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  rawdata_t *rawdata = ast_emalloc(sizeof(rawdata_t));

  rawdata->data = ast_ecalloc(size + 1);
  rawdata->size = size;

  expr->type = EXPR_TYPE_RAWDATA;
  expr->rawdata = rawdata;

  return expr;
}

expr_t *newExpr_ID(char *id) {
  size_t textLen = strlen(id);
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_ID;
  expr->id.id = (char *)ast_emalloc(textLen + 1);

  memcpy(expr->id.id, id, textLen);
  expr->id.id[textLen] = 0;

  return expr;
}

expr_t *newExpr_FuncCall(functionCall_t *func) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FUNCCALL;
  expr->func = func;

  return expr;
}

expr_t *newExpr_LibFuncPtr(libFunction_t *func) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_LIBFUNCPTR;
  expr->func = func;

  return expr;
}

expr_t *newExpr_OPAdd(expr_t *left, expr_t *right) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPADD;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPSub(expr_t *left, expr_t *right) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPSUB;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPMul(expr_t *left, expr_t *right) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPMUL;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPMod(expr_t *left, expr_t *right) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPMOD;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPDiv(expr_t *left, expr_t *right) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPDIV;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_VectorIndex(expr_t *id_expr, expr_t *index) {
  expr_t *expr = ast_ecalloc(sizeof(expr_t));
  expr->vecIdx = ast_emalloc(sizeof(vectorIndex_t));

  expr->type = EXPR_TYPE_VECTOR_IDX;
  expr->vecIdx->expr = id_expr;

  expr->vecIdx->index = index;

  return expr;
}

expr_t *newConditional(int type, expr_t *left, expr_t *right) {
  expr_t *e = ast_ecalloc(sizeof(expr_t));
  ifCondition_t *cond = ast_emalloc(sizeof(ifCondition_t));

  cond->type = type;
  cond->left = left;
  cond->right = right;

  e->type = EXPR_TYPE_COND;
  e->cond = cond;

  return e;
}

declaration_t *newDeclaration(expr_t *id, expr_t *expr) {
  declaration_t *decl = ast_emalloc(sizeof(declaration_t));

  decl->val = expr;
  decl->id = id;

  return decl;
}

statement_t *newStatement(int type, void *content) {
  statement_t *stmt = ast_emalloc(sizeof(statement_t));
  stmt->entity = type;
  stmt->next = NULL;
  stmt->line = 0;
  stmt->file = "<runtime>";
  stmt->location = (source_location_t){0};

  switch (type) {
    case LANG_ENTITY_DECL:
    case LANG_ENTITY_FUNCDECL:
    case LANG_ENTITY_FUNCCALL:
    case LANG_ENTITY_CONDITIONAL:
    case LANG_ENTITY_EMPTY_MATH:
    case LANG_ENTITY_EMPTY_STR:
    case LANG_ENTITY_CONTINUE:
    case LANG_ENTITY_BREAK:
    case LANG_ENTITY_FIN:
    case LANG_ENTITY_SYSTEM:
    case LANG_ENTITY_RETURN:
    case LANG_ENTITY_EXPR:
    case LANG_ENTITY_BODY_END:
    case LANG_ENTITY_CLASSDECL:
    case LANG_ENTITY_FOREACH:
      stmt->content = content;
      break;
    default:
      fprintf(stderr, "%s %s error: Failed to build AST, unknown type (%d)\n", __FILE__, __func__,
              type);
      exit(EXIT_FAILURE);
      break;
  }
  return stmt;
}

class_t *newClass(char *id, body_t *body) {
  size_t idLen = strlen(id) + 1;
  class_t *class = ast_emalloc(sizeof(class_t));
  class->id = ast_ecalloc(idLen);
  snprintf(class->id, idLen, "%s", id);
  class->defines = body->content;
  class->funcDefsScript = NULL;
  class->funcDefsABI = NULL;
  class->varMembers = NULL;
  class->initialized = 0;
  free(body);
  return class;
}

expr_t *newExpr_Copy(expr_t *expr, int alloc, EXPRESSION_PARAMS()) {
  expr_t *newExp = expr;

  if (expr == NULL) return NULL;

  switch (expr->type) {
    case EXPR_TYPE_ID: {
      newExp = newExpr_ID(expr->id.id);
      break;
    }
    case EXPR_TYPE_BIGINT: {
      newExp = newExpr_BigInt(expr->bigInt);
      break;
    }
    case EXPR_TYPE_FVAL:
      newExp = newExpr_Ival(expr->fval);
      break;
    case EXPR_TYPE_IVAL:
      newExp = newExpr_Ival(expr->ival);
      break;
    case EXPR_TYPE_UVAL:
      break;
    case EXPR_TYPE_VECTOR_IDX: {
      expr_t *id = newExpr_Copy(expr->vecIdx->expr, alloc, EXPRESSION_ARGS());
      expr_t *index = newExpr_Copy(expr->vecIdx->index, alloc, EXPRESSION_ARGS());
      newExp = newExpr_VectorIndex(id, index);
    } break;
    case EXPR_TYPE_TEXT: {
      newExp = newExpr_Text(expr->text);
      break;
    }
    case EXPR_TYPE_OPADD: {
      expr_t *left = newExpr_Copy(expr->add.left, alloc, EXPRESSION_ARGS());
      expr_t *right = newExpr_Copy(expr->add.right, alloc, EXPRESSION_ARGS());
      newExp = newExpr_OPAdd(left, right);
      break;
    }
    case EXPR_TYPE_OPSUB: {
      expr_t *left = newExpr_Copy(expr->add.left, alloc, EXPRESSION_ARGS());
      expr_t *right = newExpr_Copy(expr->add.right, alloc, EXPRESSION_ARGS());
      newExp = newExpr_OPSub(left, right);
      break;
    }
    case EXPR_TYPE_OPMUL: {
      expr_t *left = newExpr_Copy(expr->add.left, alloc, EXPRESSION_ARGS());
      expr_t *right = newExpr_Copy(expr->add.right, alloc, EXPRESSION_ARGS());
      newExp = newExpr_OPMul(left, right);
      break;
    }
    case EXPR_TYPE_OPMOD: {
      expr_t *left = newExpr_Copy(expr->add.left, alloc, EXPRESSION_ARGS());
      expr_t *right = newExpr_Copy(expr->add.right, alloc, EXPRESSION_ARGS());
      newExp = newExpr_OPMod(left, right);
      break;
    } break;
    case EXPR_TYPE_OPDIV: {
      expr_t *left = newExpr_Copy(expr->add.left, alloc, EXPRESSION_ARGS());
      expr_t *right = newExpr_Copy(expr->add.right, alloc, EXPRESSION_ARGS());
      newExp = newExpr_OPDiv(left, right);
      break;
    }
    case EXPR_TYPE_COND: {
      ifCondition_t *cond = expr->cond;
      ifCondition_t *newCond = ast_emalloc(sizeof(ifCondition_t));
      newCond->type = cond->type;
      newCond->left = newExpr_Copy(cond->left, alloc, EXPRESSION_ARGS());
      newCond->right = newExpr_Copy(cond->right, alloc, EXPRESSION_ARGS());
      newExp = newExpr_Cond(newCond);
    } break;
    case EXPR_TYPE_VECTOR: {
      newExp = copy_vector(expr->vec, alloc, EXPRESSION_ARGS());
      break;
    }
    case EXPR_TYPE_DICT: {
      newExp = ast_ecalloc(sizeof(expr_t));
      newExp->type = EXPR_TYPE_DICT;
      if (alloc == EXPR_ALLOC) {
        newExp->dict = allocNewDictionary(expr->dict, EXPRESSION_ARGS());
      } else {
        newExp->dict = copyNewDictionary(expr->dict, EXPRESSION_ARGS());
      }
    } break;
    case EXPR_TYPE_PRIOQUEUE: {
      priority_queue_t *pq = expr->prioqueue;
      newExp = newExpr_PriorityQueue(pq->capacity, pq->minimum);
      newExp->prioqueue->size = pq->size;
      for (int i = 0; i < pq->size; i++) {
        newExp->prioqueue->items[i].value =
            newExpr_Copy(pq->items[i].value, alloc, EXPRESSION_ARGS());
        newExp->prioqueue->items[i].priority = pq->items[i].priority;
      }
    } break;
    case EXPR_TYPE_EMPTY:
    default:
      break;
  }

  if (newExp != NULL) newExp->location = expr->location;
  return newExp;
}

argsList_t *newArgument(expr_t *expr, void *next) {
  argsList_t *argl = ast_emalloc(sizeof(argsList_t));
  expr_t *copy = expr; // newExpr_Copy(expr);

  argl->next = next;
  argl->arg = copy;
  argl->length = 1;

  if (argl->next != NULL) {
    argl->length = argl->next->length + 1;
  }

  return argl;
}

forEachStmt_t *newForEach(expr_t *root, char *entry, void *body) {
  static int uniqueForEachUnfoldIndex = 0;

  forEachStmt_t *stmt = ast_emalloc(sizeof(forEachStmt_t));
  expr_t *idRoot = root;
  expr_t *idEntry = newExpr_ID(entry);

  stmt->body = body;
  stmt->root = idRoot;
  stmt->entry = idEntry;
  stmt->uniqueUnfoldIncID = ast_emalloc(40);
  memset(stmt->uniqueUnfoldIncID, 0, 40);
  snprintf(stmt->uniqueUnfoldIncID, 40, "__UniqueShadyRicForEachInc%d", uniqueForEachUnfoldIndex);
  stmt->uniqueUnfoldRootID = ast_emalloc(40);
  memset(stmt->uniqueUnfoldRootID, 0, 40);
  snprintf(stmt->uniqueUnfoldRootID, 40, "__UniqueShadyRicForEachRoot%d",
           uniqueForEachUnfoldIndex);

  uniqueForEachUnfoldIndex++;
  return stmt;
}

functionDef_t *newFunc(const char *id, void *params, void *body) {
  size_t idLen = strlen(id);
  functionDef_t *func = ast_emalloc(sizeof(functionDef_t));

  func->entity = LANG_ENTITY_FUNCDECL;

  func->params = params;
  func->body = body;
  func->body->entity = LANG_ENTITY_BODY;

  func->id.id = ast_emalloc(idLen + 1);

  memcpy(func->id.id, id, idLen);

  func->id.id[idLen] = 0;

  return func;
}

expr_t *newClassFunCall(expr_t *classID, char *funcID, void *args) {
  expr_t *e = ast_ecalloc(sizeof(expr_t));
  classFunctionCall_t *func = ast_emalloc(sizeof(classFunctionCall_t));
  char *newTxt = ast_emalloc(strlen(funcID) + 2);
  snprintf(newTxt, strlen(funcID) + 2, "%s", funcID);

  func->args = args;
  func->classID = classID;
  func->funcID = newTxt;

  e->type = EXPR_TYPE_CLASSFUNCCALL;
  e->func = func;

  return e;
}

expr_t *newClassAccesser(expr_t *classID, char *memberID) {
  expr_t *e = ast_ecalloc(sizeof(expr_t));
  classAccesser_t *func = ast_emalloc(sizeof(classAccesser_t));
  char *newTxt = ast_emalloc(strlen(memberID) + 2);
  snprintf(newTxt, strlen(memberID) + 2, "%s", memberID);

  func->classID = classID;
  func->memberID = newTxt;

  e->type = EXPR_TYPE_CLASSACCESSER;
  e->func = func;

  return e;
}

expr_t *newFunCall(expr_t *id, void *args) {
  expr_t *e = ast_ecalloc(sizeof(expr_t));
  functionCall_t *func = ast_emalloc(sizeof(functionCall_t));

  func->entity = LANG_ENTITY_FUNCCALL;
  func->args = args;
  func->id = id;

  e->type = EXPR_TYPE_FUNCCALL;
  e->func = func;

  return e;
}

ifStmt_t *newIfStatement(int ifType, void *cond, void *body) {
  ifStmt_t *ifstmt = ast_emalloc(sizeof(ifStmt_t));

  ifstmt->ifType = ifType;
  ifstmt->cond = cond;
  ifstmt->body = body;
  ifstmt->elif = NULL;
  ifstmt->endif = NULL;

  return ifstmt;
}

body_t *newBody(void *bodyIn) {
  statement_t *body = (statement_t *)bodyIn;
  statement_t *walkPrev = NULL;
  statement_t *walk = body;
  body_t *bdy = ast_emalloc(sizeof(body_t));

  while (walk != NULL) {
    walkPrev = walk;
    walk = walk->next;
  }
  /* Insert end of body at the end of body.. */
  if (body == NULL) {
    body = newStatement(LANG_ENTITY_BODY_END, NULL);
  } else {
    walkPrev->next = newStatement(LANG_ENTITY_BODY_END, NULL);
  }

  bdy->entity = LANG_ENTITY_BODY;
  bdy->content = body;

  return bdy;
}

void free_expression(expr_t *expr) {
  if (expr == NULL) return;

  switch (expr->type) {
    case EXPR_TYPE_DICT: {
      free_dictionary(expr->dict);
      break;
    }
    case EXPR_TYPE_ID: {
      free(expr->id.id);
      break;
    }
    case EXPR_TYPE_BIGINT: {
      mpz_clear(*expr->bigInt);
      free(expr->bigInt);
      break;
    }
    case EXPR_TYPE_LOGICAL: {
      if (expr->logical->andsLen > 0) {
        int32_t walk = 0;
        while (walk < expr->logical->andsLen) {
          free_expression(expr->logical->ands[walk]);
          free(expr->logical->ands[walk]);
          walk++;
        }
        free(expr->logical->ands);
      }
      if (expr->logical->orsLen > 0) {
        int32_t walk = 0;
        while (walk < expr->logical->orsLen) {
          free_expression(expr->logical->ors[walk]);
          free(expr->logical->ors[walk]);
          walk++;
        }
        free(expr->logical->ors);
      }
      free(expr->logical);
      break;
    }
    case EXPR_TYPE_CLASSPTR: {
      free(expr->classObj);
    } break;
    case EXPR_TYPE_CLASSFUNCCALL: {
      classFunctionCall_t *cls = expr->func;
      argsList_t *args = cls->args;
      free_expression(cls->classID);
      free(cls->classID);
      while (args != NULL) {
        argsList_t *tmp = args;
        free_expression(args->arg);
        free(args->arg);
        args = args->next;
        free(tmp);
      }
      free(cls->funcID);
      free(cls);
    } break;
    case EXPR_TYPE_CLASSACCESSER: {
      classAccesser_t *cls = expr->classAccess;
      free_expression(cls->classID);
      free(cls->classID);
      free(cls->memberID);
      free(cls);
    } break;

    case EXPR_TYPE_FVAL:
    case EXPR_TYPE_IVAL:
    case EXPR_TYPE_UVAL:
      break;
    case EXPR_TYPE_INDEXER: {
      indexer_t *index = expr->indexer;
      free_expression(index->left);
      free(index->left);
      free_expression(index->right);
      free(index->right);
      free_expression(index->offset);
      free(index->offset);
      free(index);
      break;
    }
    case EXPR_TYPE_RAWDATA:
      free(expr->rawdata->data);
      free(expr->rawdata);
      break;
    case EXPR_TYPE_VECTOR_IDX: {
      vectorIndex_t *vecIdx = expr->vecIdx;
      free_expression(vecIdx->expr);
      free(vecIdx->expr);
      free_expression(vecIdx->index);
      free(vecIdx->index);
      free(vecIdx);
      break;
    }
    case EXPR_TYPE_TEXT: {
      free(expr->text);
      break;
    }
    case EXPR_TYPE_OPADD:
    case EXPR_TYPE_OPSUB:
    case EXPR_TYPE_OPMUL:
    case EXPR_TYPE_OPMOD:
    case EXPR_TYPE_OPDIV: {
      free_expression((expr_t *)expr->add.left);
      free(expr->add.left);
      free_expression((expr_t *)expr->add.right);
      free(expr->add.right);
      break;
    }
    case EXPR_TYPE_PRIOQUEUE: {
      free_priority_queue(expr->prioqueue);
    } break;
    case EXPR_TYPE_CACHEPOT: {
      cachepot_t *cachepot = expr->cachepot;
      hashtable_t *hash = cachepot->hash;
      {
        int size;
        int i = 0;
        struct key_val_pair *ptr1;
        struct key_val_pair *ptr2;

        if (hash != NULL) {
          size = hash->size;
          while (i < size) {
            ptr1 = hash->table[i];
            while (ptr1 != NULL) {
              expr_t *e = ptr1->data;
              ptr2 = ptr1;
              ptr1 = ptr1->next;
              free(ptr2->key);
              free_expression(e);
              free(e);
            }
            i++;
          }
        }
      }
      hashtable_free(hash);
      free(cachepot);
    } break;
    case EXPR_TYPE_FUNCCALL: {
      functionCall_t *call = expr->func;
      argsList_t *args = call->args;

      free_expression(call->id);
      free(call->id);
      while (args != NULL) {
        argsList_t *tmp = args;
        free_expression(args->arg);
        free(args->arg);
        args = args->next;
        free(tmp);
      }
      free(call);
    } break;
    case EXPR_TYPE_COND: {
      ifCondition_t *cond = expr->cond;
      free_expression((expr_t *)cond->left);
      free(cond->left);
      free_expression((expr_t *)cond->right);
      free(cond->right);
      free(cond);
    } break;
    case EXPR_TYPE_VECTOR: {
      vector_t *vec = expr->vec;
      int32_t len = vec->length;
      int32_t vecWalk = 0;
      argsList_t *v = vec->content;
      argsList_t *p;

      while (vecWalk < len) {
        if (v->arg != NULL) {
          free_expression(v->arg);
          free(v->arg);
          v->arg = NULL;
        }
        p = v;
        v = v->next;
        free(p);
        ++vecWalk;
      }

      if (vec->forEach != NULL) {
        free_ast(vec->forEach);
      }

      free(vec);
      break;
    }

    case EXPR_TYPE_EMPTY:
    default:
      break;
  }
}

static void free_arguments(argsList_t *args) {
  while (args != NULL) {
    argsList_t *next = args->next;
    free_expression(args->arg);
    free(args->arg);
    free(args);
    args = next;
  }
}

static void free_if_statement(ifStmt_t *stmt) {
  if (stmt == NULL) return;
  free_expression(stmt->cond);
  free(stmt->cond);
  free_ast((statement_t *)stmt->body);
  free_if_statement(stmt->elif);
  free_if_statement(stmt->endif);
  free(stmt);
}

void free_ast(statement_t *stmt) {
  while (stmt != NULL) {
    if (stmt->entity == LANG_ENTITY_BODY) {
      body_t *body = (body_t *)stmt;
      free_ast(body->content);
      free(body);
      return;
    }
    statement_t *next = stmt->next;
    switch (stmt->entity) {
      case LANG_ENTITY_DECL: {
        declaration_t *decl = stmt->content;
        /* Compound assignments share their target with the left operand. */
        expr_t *value = decl->val;
        int sharedTarget = value != NULL &&
            (value->type == EXPR_TYPE_OPADD || value->type == EXPR_TYPE_OPSUB ||
             value->type == EXPR_TYPE_OPMUL || value->type == EXPR_TYPE_OPDIV) &&
            value->add.left == decl->id;
        if (!sharedTarget) {
          free_expression(decl->id);
          free(decl->id);
        }
        free_expression(decl->val);
        free(decl->val);
        free(decl);
        break;
      }
      case LANG_ENTITY_EXPR:
      case LANG_ENTITY_RETURN:
      case LANG_ENTITY_SYSTEM:
      case LANG_ENTITY_EMPTY_MATH:
      case LANG_ENTITY_EMPTY_STR:
        free_expression(stmt->content);
        free(stmt->content);
        break;
      case LANG_ENTITY_FOREACH: {
        forEachStmt_t *foreach = stmt->content;
        free_expression(foreach->root);
        free(foreach->root);
        free_expression(foreach->entry);
        free(foreach->entry);
        free(foreach->uniqueUnfoldIncID);
        free(foreach->uniqueUnfoldRootID);
        free_ast((statement_t *)foreach->body);
        free(foreach);
        break;
      }
      case LANG_ENTITY_CLASSDECL: {
        class_t *class = stmt->content;
        free_ast(class->defines);
        free(class->id);
        free(class);
        break;
      }
      case LANG_ENTITY_FUNCDECL: {
        functionDef_t *func = stmt->content;
        free(func->id.id);
        free_arguments(func->params);
        free_ast(func->body);
        free(func);
        break;
      }
      case LANG_ENTITY_FUNCCALL: {
        functionCall_t *call = stmt->content;
        free_expression(call->id);
        free(call->id);
        free_arguments(call->args);
        free(call);
        break;
      }
      case LANG_ENTITY_CONDITIONAL:
        free_if_statement(stmt->content);
        break;
      default:
        break;
    }
    free(stmt);
    stmt = next;
  }
}

argsList_t *copy_argsList(argsList_t *args) {
  argsList_t *new = NULL;
  argsList_t *walk = args;

  if (args == NULL) {
    return NULL;
  }

  while (walk != NULL) {
    new = newArgument(walk->arg, new);
    walk = walk->next;
  }

  return new;
}

void free_keyvals(dictionary_t *dict) {
  keyValList_t *keyVals = dict->keyVals;
  while (keyVals != NULL) {
    keyValList_t *next = keyVals->next;
    free_expression(keyVals->key);
    free(keyVals->key);
    free_expression(keyVals->val);
    free(keyVals->val);
    free(keyVals);
    keyVals = next;
  }
  dict->keyVals = NULL;
}

void free_dictionary(dictionary_t *dict) {
  if (dict == NULL) return;
  if (!dict->initialized) {
    free_keyvals(dict);
  } else if (dict->hash != NULL) {
    /* Copies own their values; runtime dictionaries reference GC heap values. */
    if (dict->hash->allocated_data) {
      for (int i = 0; i < dict->hash->size; ++i) {
        for (entry_t *entry = dict->hash->table[i]; entry != NULL; entry = entry->next) {
          heapval_t *value = entry->data;
          expr_t expr = {0};
          switch (value->sv.type) {
            case TEXT:
              expr.type = EXPR_TYPE_TEXT;
              expr.text = value->sv.t;
              break;
            case BIGINT:
              expr.type = EXPR_TYPE_BIGINT;
              expr.bigInt = value->sv.bigInt;
              break;
            case VECTORTYPE:
              expr.type = EXPR_TYPE_VECTOR;
              expr.vec = value->sv.vec;
              break;
            case DICTTYPE:
              expr.type = EXPR_TYPE_DICT;
              expr.dict = value->sv.dict;
              break;
            default:
              continue;
          }
          free_expression(&expr);
        }
      }
    }
    hashtable_free(dict->hash);
  }
  free(dict);
}

/* Source names outlive loaded strings and interactive command buffers. */
typedef struct source_file_t {
  char *name;
  struct source_file_t *next;
} source_file_t;
static source_file_t *source_files;

static void free_source_files(void) {
  while (source_files != NULL) {
    source_file_t *next = source_files->next;
    free(source_files->name);
    free(source_files);
    source_files = next;
  }
}

const char *sourceFile(const char *file) {
  source_file_t *entry;
  if (file == NULL) file = "<stdin>";
  for (entry = source_files; entry != NULL; entry = entry->next) {
    if (strcmp(entry->name, file) == 0) return entry->name;
  }
  if (source_files == NULL) atexit(free_source_files);
  entry = ast_emalloc(sizeof(*entry));
  entry->name = ast_emalloc(strlen(file) + 1);
  strcpy(entry->name, file);
  entry->next = source_files;
  source_files = entry;
  return entry->name;
}

static void report_source_error(const source_location_t *location,
                                const char *format, va_list args) {
  if (location != NULL && location->file != NULL && location->first_line > 0) {
    fprintf(stderr, "%s:%d:%d: ", location->file,
            location->first_line, location->first_column);
  }
  vfprintf(stderr, format, args);
}

void reportSourceError(const source_location_t *location, const char *format, ...) {
  va_list args;
  va_start(args, format);
  report_source_error(location, format, args);
  va_end(args);
}

void reportRuntimeError(context_full_t *context, const char *format, ...) {
  va_list args;
  if (context != NULL) ++context->diagnostic_count;
  va_start(args, format);
  report_source_error(context != NULL ? &context->location : NULL, format, args);
  va_end(args);
}
