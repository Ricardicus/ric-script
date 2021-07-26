#include "ast.h"
#include "eval.h"
#include "hashtable.h"

extern int yylinenor;
extern char *ParsedFile;

void *ast_emalloc(size_t size) {
  char *p = (char *)malloc(size);
  if (p == NULL) {
    fprintf(stderr,
            "%s %s error: Failed to build AST, malloc failed (%zu bytes)\n",
            __FILE__, __func__, size);
    exit(EXIT_FAILURE);
  }
  return (void *)p;
}

void *ast_remalloc(void *mem, size_t size) {
  char *p = (char *)realloc(mem, size);
  if (p == NULL) {
    fprintf(stderr,
            "%s %s error: Failed to build AST, malloc failed (%zu bytes)\n",
            __FILE__, __func__, size);
    exit(EXIT_FAILURE);
  }
  return (void *)p;
}

void *ast_ecalloc(size_t size) {
  char *p = (char *)calloc(size, 1);
  if (p == NULL) {
    fprintf(stderr,
            "%s %s error: Failed to build AST, malloc failed (%zu bytes)\n",
            __FILE__, __func__, size);
    exit(EXIT_FAILURE);
  }
  return (void *)p;
}


expr_t* newExpr_Time(time_t time) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  expr->type = EXPR_TYPE_TIME;
  expr->time = time;
  return expr;
}

expr_t* newExpr_ClassPtr(class_t *class) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  class_t *cls = ast_emalloc(sizeof(class_t));

  cls->id = class->id;
  cls->defines = class->defines;
  cls->funcDefs = hashtable_new(
    DICTIONARY_STANDARD_SIZE, DICTIONARY_STANDARD_LOAD);
  cls->varMembers = hashtable_new(
    DICTIONARY_STANDARD_SIZE, DICTIONARY_STANDARD_LOAD);

  expr->type = EXPR_TYPE_CLASSPTR;
  expr->classObj = cls;
  return expr;
}

expr_t* newExpr_ClassPtrCopy(class_t *class) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  class_t *cls = ast_emalloc(sizeof(class_t));

  cls->id = class->id;
  cls->defines = class->defines;
  cls->funcDefs = hashtable_copy(class->funcDefs);
  cls->varMembers = hashtable_copy(class->varMembers);
  cls->initialized = class->initialized;

  expr->type = EXPR_TYPE_CLASSPTR;
  expr->classObj = cls;
  return expr;
}

expr_t *newExpr_Cond(ifCondition_t *cond) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_COND;
  expr->cond = cond;

  return expr;
}

expr_t *newExpr_Pointer(uintptr_t val) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_POINTER;
  expr->p = val;

  return expr;
}

expr_t *newExpr_FuncPtr(void *func) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FUNCPTR;
  expr->func = func;

  return expr;
}

expr_t *newExpr_Logical(expr_t *prevLogical, expr_t *newAnd, expr_t *newOr) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  logical_t *logical = ast_emalloc(sizeof(logical_t));
  int appendPrev = 0;

  logical->andsLen = 0;
  logical->orsLen = 0;
  logical->ands = NULL;
  logical->ors = NULL;

  if ( prevLogical != NULL && prevLogical->type == EXPR_TYPE_LOGICAL ) {
    logical->andsLen = prevLogical->logical->andsLen;
    logical->ands = prevLogical->logical->ands;

    logical->orsLen = prevLogical->logical->orsLen;
    logical->ors = prevLogical->logical->ors;

    /* Free this logical */
    free(prevLogical->logical);
    free(prevLogical);
  } else if ( prevLogical != NULL ) {
    appendPrev = 1;
  }

  if ( newAnd != NULL ) {
    logical->andsLen++;
    logical->ands = ast_remalloc(logical->ands, logical->andsLen*sizeof(expr_t*));
    logical->ands[logical->andsLen-1] = newAnd;

    if ( appendPrev ) {
      logical->andsLen++;
      logical->ands = ast_remalloc(logical->ands, logical->andsLen*sizeof(expr_t*));
      logical->ands[logical->andsLen-1] = prevLogical; 
    }
  }

  if ( newOr != NULL ) {
    logical->orsLen++;
    logical->ors = ast_remalloc(logical->ors, logical->orsLen*sizeof(expr_t*));
    logical->ors[logical->orsLen-1] = newOr;

    if ( appendPrev ) {
      logical->orsLen++;
      logical->ors = ast_remalloc(logical->ors, logical->orsLen*sizeof(expr_t*));
      logical->ors[logical->orsLen-1] = prevLogical;
    }
  }

  expr->type = EXPR_TYPE_LOGICAL;
  expr->logical = logical;

  return expr;
}

expr_t *newExpr_Vector(argsList_t *args) {
  int32_t length = 0;
  argsList_t *walk;
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  vector_t *vec = ast_emalloc(sizeof(vector_t));

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
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  vector_t *vec = ast_emalloc(sizeof(vector_t));

  vec->length = length;
  vec->content = NULL;
  vec->forEach = forEach;

  expr->type = EXPR_TYPE_VECTOR;
  expr->vec = vec;

  return expr;
}


expr_t* newExpr_Dictionary(keyValList_t *keyVals) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  expr->dict = ast_emalloc(sizeof(dictionary_t));

  expr->type = EXPR_TYPE_DICT;

  expr->dict->initialized = 0;
  expr->dict->keyVals = keyVals;
  expr->dict->hash = NULL;

  return expr;
}

expr_t *newExpr_Text(char *text) {
  size_t textLen = strlen(text);
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_TEXT;
  expr->text = (char *)ast_emalloc(textLen + 1);

  memcpy(expr->text, text, textLen);
  expr->text[textLen] = 0;

  return expr;
}

expr_t *newExpr_Ival(int val) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_IVAL;
  expr->ival = (int32_t)val;

  return expr;
}

expr_t *newExpr_Uval(unsigned val) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_UVAL;
  expr->ival = (uint32_t)val;

  return expr;
}

expr_t *newExpr_Float(double val) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FVAL;
  expr->fval = val;

  return expr;
}

expr_t* newExpr_RawData(size_t size) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  rawdata_t *rawdata = ast_emalloc(sizeof(rawdata_t));

  rawdata->data = ast_ecalloc(size+1);
  rawdata->size = size;

  expr->type = EXPR_TYPE_RAWDATA;
  expr->rawdata = rawdata;

  return expr;
}

expr_t *newExpr_ID(char *id) {
  size_t textLen = strlen(id);
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_ID;
  expr->id.id = (char *)ast_emalloc(textLen + 1);

  memcpy(expr->id.id, id, textLen);
  expr->id.id[textLen] = 0;

  return expr;
}

expr_t *newExpr_FuncCall(functionCall_t *func) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FUNCCALL;
  expr->func = func;

  return expr;
}

expr_t *newExpr_LibFuncPtr(libFunction_t *func) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_LIBFUNCPTR;
  expr->func = func;

  return expr;
}

expr_t *newExpr_OPAdd(expr_t *left, expr_t *right) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPADD;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPSub(expr_t *left, expr_t *right) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPSUB;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPMul(expr_t *left, expr_t *right) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPMUL;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPMod(expr_t *left, expr_t *right) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPMOD;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_OPDiv(expr_t *left, expr_t *right) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPDIV;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t *newExpr_VectorIndex(expr_t *id, expr_t *index) {
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  expr->vecIdx = ast_emalloc(sizeof(vectorIndex_t));

  expr->type = EXPR_TYPE_VECTOR_IDX;
  expr->vecIdx->id = id;

  expr->vecIdx->index = index;

  return expr;
}

expr_t *newConditional(int type, expr_t *left, expr_t *right) {
  expr_t *e = ast_emalloc(sizeof(expr_t));
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

  decl->entity = LANG_ENTITY_DECL;
  decl->val = expr;
  decl->id = id;

  return decl;
}

statement_t *newStatement(int type, void *content) {
  statement_t *stmt = ast_emalloc(sizeof(statement_t));
  stmt->entity = type;
  stmt->next = NULL;
  stmt->line = yylinenor;

  stmt->file[0] = 0;
  if ( ParsedFile != NULL ) {
    snprintf(stmt->file,
      sizeof(stmt->file), "%s", ParsedFile);
  }

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
    fprintf(stderr, "%s %s error: Failed to build AST, unknown type (%d)\n",
            __FILE__, __func__, type);
    exit(EXIT_FAILURE);
    break;
  }
  return stmt;
}

class_t* newClass(char *id, body_t *body) {
  class_t *class = ast_emalloc(sizeof(class_t));
  class->id = id;
  class->defines = body->content;
  class->funcDefs = NULL;
  class->varMembers = NULL;
  class->initialized = 0;
  free(body);
  return class;
}

expr_t* newExpr_Copy(expr_t *expr) {
  expr_t *newExp = expr;

  if ( expr == NULL )
    return NULL;

  switch (expr->type) {
  case EXPR_TYPE_ID: {
    newExp = newExpr_ID(expr->id.id);
    break;
  }
  case EXPR_TYPE_FVAL:
  case EXPR_TYPE_IVAL:
  case EXPR_TYPE_UVAL:
    break;
  case EXPR_TYPE_VECTOR_IDX: {
    expr_t *id = newExpr_Copy(expr->vecIdx->id);
    expr_t *index = newExpr_Copy(expr->vecIdx->index);
    newExp = newExpr_VectorIndex(id, index);
  }
  break;
  case EXPR_TYPE_TEXT: {
    newExp = newExpr_Text(expr->text);
    break;
  }
  case EXPR_TYPE_OPADD: {
    expr_t *left = (expr_t *)expr->add.left;
    expr_t *right = (expr_t *)expr->add.right;
    newExp = newExpr_OPAdd(left, right);
    break;
  }
  case EXPR_TYPE_OPSUB: {
    expr_t *left = (expr_t *)expr->add.left;
    expr_t *right = (expr_t *)expr->add.right;
    newExp = newExpr_OPSub(left, right);
    break;
  }
  case EXPR_TYPE_OPMUL: {
    expr_t *left = (expr_t *)expr->add.left;
    expr_t *right = (expr_t *)expr->add.right;
    newExp = newExpr_OPMul(left, right);
    break;
  }
  case EXPR_TYPE_OPMOD: {
    expr_t *left = (expr_t *)expr->add.left;
    expr_t *right = (expr_t *)expr->add.right;
    newExp = newExpr_OPMod(left, right);
    break;
  } break;
  case EXPR_TYPE_OPDIV: {
    expr_t *left = (expr_t *)expr->add.left;
    expr_t *right = (expr_t *)expr->add.right;
    newExp = newExpr_OPDiv(left, right);
    break;
  }
  case EXPR_TYPE_COND: {
    ifCondition_t *cond = expr->cond;
    ifCondition_t *newCond = ast_emalloc(sizeof(ifCondition_t));
    newCond->type = cond->type;
    newCond->left = newExpr_Copy(cond->left);
    newCond->right = newExpr_Copy(cond->right);
    newExp = newExpr_Cond(newCond);
  } break;
  case EXPR_TYPE_VECTOR: {
    argsList_t *args = copy_argsList(expr->vec->content);
    newExp = newExpr_Vector(args);
    break;
  }
  case EXPR_TYPE_DICT: {
    newExp = newExpr_Dictionary(expr->dict->keyVals);
  }
  break;
  case EXPR_TYPE_EMPTY:
  default:
    break;
  }

  return newExp;
}

argsList_t *newArgument(expr_t *expr, void *next) {
  argsList_t *argl = ast_emalloc(sizeof(argsList_t));
  expr_t *copy = expr; //newExpr_Copy(expr);

  argl->entity = LANG_ENTITY_ARGS;
  argl->next = next;
  argl->arg = copy;
  argl->length = 1;

  if (argl->next != NULL) {
    argl->length = argl->next->length + 1;
  }

  return argl;
}

forEachStmt_t* newForEach(expr_t *root, char *entry, void *body) {
  static int uniqueForEachUnfoldIndex = 0;

  forEachStmt_t *stmt = ast_emalloc(sizeof(forEachStmt_t));
  expr_t *idRoot = root;
  expr_t *idEntry = newExpr_ID(entry);

  stmt->body = body;
  stmt->root = idRoot;
  stmt->entry = idEntry;
  stmt->uniqueUnfoldID = ast_emalloc(40);

  memset(stmt->uniqueUnfoldID, 0, 40);
  snprintf(stmt->uniqueUnfoldID, 40, "__UniqueShadyRicForEach%d", uniqueForEachUnfoldIndex);

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

expr_t* newClassFunCall(expr_t *classID, char *funcID, void *args) {
  expr_t *e = ast_emalloc(sizeof(expr_t));
  classFunctionCall_t *func = ast_emalloc(sizeof(classFunctionCall_t));
  char *newTxt = ast_emalloc(strlen(funcID)+2);
  snprintf(newTxt, strlen(funcID)+2, "%s", funcID);

  func->args = args;
  func->classID = classID;
  func->funcID = newTxt;

  e->type = EXPR_TYPE_CLASSFUNCCALL;
  e->func = func;

  return e;
}

expr_t *newFunCall(expr_t *id, void *args) {
  expr_t *e = ast_emalloc(sizeof(expr_t));
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
  statement_t *body = (statement_t*)bodyIn;
  statement_t *walkPrev = NULL;
  statement_t *walk = body;
  body_t *bdy = ast_emalloc(sizeof(body_t));
  
  while ( walk != NULL ) {
    walkPrev = walk;
    walk = walk->next;
  }
  /* Insert end of body at the end of body.. */
  if ( body == NULL ) {
    body = newStatement(LANG_ENTITY_BODY_END, NULL);
  } else {
    walkPrev->next = newStatement(LANG_ENTITY_BODY_END, NULL);
  }

  bdy->entity = LANG_ENTITY_BODY;
  bdy->content = body;

  return bdy;
}

void free_expression(expr_t *expr) {
  if (expr == NULL)
    return;

  switch (expr->type) {
  case EXPR_TYPE_ID: {
    free(expr->id.id);
    break;
  }
  case EXPR_TYPE_LOGICAL: {
    if ( expr->logical->andsLen > 0 ) {
      int32_t walk = 0;
      while ( walk < expr->logical->andsLen ) {
        free_expression(expr->logical->ands[walk]);
        free(expr->logical->ands[walk]);
        walk++;
      }
      free(expr->logical->ands);
    }
    if ( expr->logical->orsLen > 0 ) {
      int32_t walk = 0;
      while ( walk < expr->logical->orsLen ) {
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
  }
  break;
  case EXPR_TYPE_CLASSFUNCCALL: {
    classFunctionCall_t *cls = expr->func;
    argsList_t *args = cls->args;
    free_expression(cls->classID);
    free(cls->classID);
    while ( args != NULL ) {
      argsList_t *tmp = args;
      free_expression(args->arg);
      free(args->arg);
      args = args->next;
      free(tmp);
    }
    free(cls->funcID);
    free(cls);
  }
  break;
  case EXPR_TYPE_FVAL:
  case EXPR_TYPE_IVAL:
  case EXPR_TYPE_UVAL:
    break;
  case EXPR_TYPE_VECTOR_IDX: {
    vectorIndex_t *vecIdx = expr->vecIdx;
    free_expression(vecIdx->id);
    free(vecIdx->id);
    free_expression(vecIdx->index);
    free(vecIdx->index);
    free(vecIdx);
    break;
  }
  case EXPR_TYPE_TEXT: {
    free(expr->text);
    break;
  }
  case EXPR_TYPE_OPADD: {
    free_expression((expr_t *)expr->add.left);
    free_expression((expr_t *)expr->add.right);
    break;
  }
  case EXPR_TYPE_OPSUB: {
    free_expression((expr_t *)expr->add.left);
    free_expression((expr_t *)expr->add.right);

    break;
  }
  case EXPR_TYPE_OPMUL: {
    free_expression((expr_t *)expr->add.left);
    free_expression((expr_t *)expr->add.right);
    break;
  }
  case EXPR_TYPE_OPMOD: {
    free_expression((expr_t *)expr->add.left);
    free_expression((expr_t *)expr->add.right);
    break;
  } break;
  case EXPR_TYPE_OPDIV: {
    free_expression((expr_t *)expr->add.left);
    free_expression((expr_t *)expr->add.right);
    break;
  }
  case EXPR_TYPE_DICT: {
    dictionary_t *dict = expr->dict;

    if ( dict->initialized ) {
      hashtable_free(dict->hash);
      free(dict->hash);
    } else {
      keyValList_t *walk = dict->keyVals;
      keyValList_t *walk_next;

      while ( walk != NULL ) {
        walk_next = walk->next;
        free_expression(walk->key);
        free(walk->key);
        free_expression(walk->val);
        free(walk->val);
        free(walk);
        walk = walk_next;
      }
    }
    free(dict);
    break;
  }
  case EXPR_TYPE_FUNCCALL: {
    functionCall_t *call = expr->func;
    argsList_t *args = call->args;

    free_expression(call->id);
    free(call->id);
    while ( args != NULL ) {
      argsList_t *tmp = args;
      free_expression(args->arg);
      free(args->arg);
      args = args->next;
      free(tmp);
    }
    free(call);
  }
  break;
  case EXPR_TYPE_COND: {
    ifCondition_t *cond = expr->cond;
    free_expression((expr_t *)cond->left);
    free_expression((expr_t *)cond->right);
  } break;
  case EXPR_TYPE_VECTOR: {
    vector_t *vec = expr->vec;
    int32_t len = vec->length;
    int32_t vecWalk = 0;
    argsList_t *v = vec->content;
    argsList_t *p;

    while ( vecWalk < len ) {
      if ( v->arg != NULL ) {
        free_expression(v->arg);
        free(v->arg);
        v->arg = NULL;
      }
      p = v;
      v = v->next;
      free(p);
      ++vecWalk;
    //  printf("(2.1)\n");
    }

    if ( vec->forEach != NULL ) {
      free_ast(vec->forEach);
      free(vec->forEach);
    }

    free(vec);
    break;
  }

  case EXPR_TYPE_EMPTY:
  default:
    break;
  }

}


void free_ast(statement_t *stmt) {
  entity_eval_t *eval = (entity_eval_t *)stmt;
  void *next = NULL;

  if (stmt == NULL)
    return;

  switch (eval->entity) {
  case LANG_ENTITY_DECL:
  case LANG_ENTITY_FUNCDECL:
  case LANG_ENTITY_FUNCCALL:
  case LANG_ENTITY_CONDITIONAL:
  case LANG_ENTITY_CONTINUE:
  case LANG_ENTITY_BREAK:
  case LANG_ENTITY_SYSTEM:
  case LANG_ENTITY_CLASSDECL:
  case LANG_ENTITY_FIN:
  case LANG_ENTITY_FOREACH:
  case LANG_ENTITY_RETURN:
  case LANG_ENTITY_EXPR:
    next = ((statement_t *)stmt)->next;
    break;
  case LANG_ENTITY_EMPTY_MATH:
  case LANG_ENTITY_EMPTY_STR: {
    next = ((statement_t *)stmt)->next;
    break;
  }
  case LANG_ENTITY_BODY: {
    next = ((body_t *)stmt)->content;
  } break;
  default:
    break;
  }

  switch (eval->entity) {
  case LANG_ENTITY_DECL: {
    declaration_t *decl = ((statement_t *)stmt)->content;
    /* Evaluating the expression among global variables */
    //free_expression(decl->val);
    free_expression(decl->id);
  } break;
  case LANG_ENTITY_EXPR: {
    expr_t *e = ((statement_t *)stmt)->content;

    free_expression(e);
    free(e);
  }
  break;
  case LANG_ENTITY_FOREACH: {
    forEachStmt_t *foreach = ((statement_t *)stmt)->content;

    free_expression(foreach->root);
    free_expression(foreach->entry);
    free(foreach->uniqueUnfoldID);
    free_ast(foreach->body->content);
  }
  break;
  case LANG_ENTITY_EMPTY_STR: {
    free_expression(((statement_t *)stmt)->content);
    break;
  }
  case LANG_ENTITY_CLASSDECL: {
    class_t *class = ((statement_t *)stmt)->content;
    free(class->id);
    free_ast(class->defines);
    break;
  }
  case LANG_ENTITY_FUNCDECL: {
    functionDef_t *funcDef = ((statement_t *)stmt)->content;
    argsList_t *args = funcDef->params;
    free(funcDef->id.id);
    while ( args != NULL ) {
      free_expression(args->arg);
      args = args->next;
    }
    free_ast(funcDef->body);
  } break;
  case LANG_ENTITY_FUNCCALL: {
    functionCall_t *funcCall = ((statement_t *)stmt)->content;
    argsList_t *args = funcCall->args;

    free_expression(funcCall->id);
    while ( args != NULL ) {
      free_expression(args->arg);
      args = args->next;
    }
  } break;
  case LANG_ENTITY_CONDITIONAL: {
    ifStmt_t *ifstmt = ((statement_t *)stmt)->content;
    ifStmt_t *ifstmtWalk;
    expr_t *cond = ifstmt->cond;

    free_expression(cond);
    free_ast(ifstmt->body->content);

    // Walk through the elifs.
    ifstmtWalk = ifstmt->elif;

    while (ifstmtWalk != NULL) {
      free_expression(ifstmtWalk->cond);
      free_ast(ifstmtWalk->body->content);
      ifstmtWalk = ifstmtWalk->elif;
    }

    // Print the else if it is not NULL
    if (ifstmt->endif != NULL) {
      ifstmtWalk = ifstmt->endif;
      free_ast(ifstmtWalk->body->content);
    }
    break;
  }
  case LANG_ENTITY_SYSTEM:
    free_expression(((statement_t *)stmt)->content);
    break;
  case LANG_ENTITY_FIN:
    free(stmt);
    break;
  default:
    break;
  }

  free_ast(next);
}

argsList_t* copy_argsList(argsList_t *args) {
  argsList_t *new = NULL;
  argsList_t *walk = args;

  if ( args == NULL ) {
    return NULL;
  }

  while ( walk != NULL ) {
    new = newArgument(walk->arg, new);
    walk = walk->next;
  }

  return new;
}

