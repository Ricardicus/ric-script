#include "ast.h"
#include "hashtable.h"
#include "eval.h"

void* ast_emalloc(size_t size)
{
  char *p = (char*)malloc(size);
  if ( p == NULL ) {
    fprintf(
      stderr,
      "%s %s error: Failed to build AST, malloc failed (%zu bytes)\n",
      __FILE__,
      __func__,
      size
    );
    exit(EXIT_FAILURE);
  }
  return (void*)p;
}

expr_t* newExpr_Cond(ifCondition_t *cond)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_COND;
  expr->cond = cond;

  return expr;
}

expr_t* newExpr_Pointer(uintptr_t val)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_POINTER;
  expr->p = val;

  return expr;
}

expr_t* newExpr_FuncPtr(void *func)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FUNC_PTR;
  expr->func = func;

  return expr;
}

expr_t* newExpr_Vector(argsList_t *args)
{
  int32_t length = 0;
  argsList_t *walk;
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  vector_t *vec = ast_emalloc(sizeof(vector_t));

  /* Reverse the args list order */
  argsList_t *prev = NULL;
  argsList_t *current = args;
  argsList_t *next;
  while (current != NULL) 
  { 
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  args = prev;

  walk = args;
  /* Counting the vectors length */
  while ( walk != NULL ) {
    length++;
    walk = walk->next;
  }

  vec->length = length;
  vec->content = args;

  expr->type = EXPR_TYPE_VECTOR;
  expr->vec = vec;

  return expr;
}

expr_t* newExpr_Text(char *text)
{
  size_t textLen = strlen(text);
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_TEXT;
  expr->text = (char*)ast_emalloc(textLen+1);
  expr->textLen = textLen;

  memcpy(expr->text, text, textLen);
  expr->text[textLen] = 0;

  return expr;
}

expr_t* newExpr_Ival(int val)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_IVAL;
  expr->ival = (int32_t) val;

  return expr;
}

expr_t* newExpr_Uval(unsigned val)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_UVAL;
  expr->ival = (uint32_t) val;

  return expr;
}

expr_t* newExpr_Float(double val)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FVAL;
  expr->fval = val;

  return expr;
}

expr_t* newExpr_ID(char *id)
{
  size_t textLen = strlen(id);
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_ID;
  expr->id.id = (char*)ast_emalloc(textLen+1);

  memcpy(expr->id.id, id, textLen);
  expr->id.id[textLen] = 0;

  return expr;
}

expr_t* newExpr_FuncCall(functionCall_t *func)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_FUNCCALL;
  expr->func = func;

  return expr;
}

expr_t* newExpr_OPAdd(expr_t *left, expr_t *right)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPADD;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t* newExpr_OPSub(expr_t *left, expr_t *right)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPSUB;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t* newExpr_OPMul(expr_t *left, expr_t *right)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPMUL;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t* newExpr_OPMod(expr_t *left, expr_t *right)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPMOD;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t* newExpr_OPDiv(expr_t *left, expr_t *right)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));

  expr->type = EXPR_TYPE_OPDIV;
  expr->add.left = left;
  expr->add.right = right;

  return expr;
}

expr_t* newExpr_VectorIndex(expr_t *id, expr_t *index)
{
  expr_t *expr = ast_emalloc(sizeof(expr_t));
  expr->vecIdx = ast_emalloc(sizeof(vectorIndex_t));

  expr->type = EXPR_TYPE_VECTOR_IDX;
  expr->vecIdx->id = id;

  expr->vecIdx->index = index;

  return expr;
}

ifCondition_t *newConditional(int type, expr_t *left, expr_t *right)
{
  ifCondition_t *cond = ast_emalloc(sizeof(ifCondition_t));

  cond->type  = type;
  cond->left  = left;
  cond->right = right;

  return cond;
}

declaration_t* newDeclaration(const char *id, expr_t *expr)
{
  size_t idLen = strlen(id);
  declaration_t* decl = ast_emalloc(sizeof(declaration_t));

  decl->entity = LANG_ENTITY_DECL;
  decl->val = expr;
  decl->id.id = ast_emalloc(idLen+1);

  memcpy(decl->id.id, id, idLen);

  decl->id.id[idLen] = 0;

  return decl;
}

statement_t* newStatement(int type, void *content)
{
  statement_t* stmt = ast_emalloc(sizeof(statement_t));
  stmt->entity = type;

  switch ( type ) {
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
      stmt->content = content;
      break;
    default:
      fprintf(stderr, "%s %s error: Failed to build AST, unknown type (%d)\n",
        __FILE__,
        __func__,
        type
      );
      exit(EXIT_FAILURE);
      break;
  }
  return stmt;
}

argsList_t* newArgument(expr_t *expr, void *next)
{
  argsList_t* argl = ast_emalloc(sizeof(argsList_t));

  argl->entity = LANG_ENTITY_ARGS;
  argl->next = next;
  argl->arg = expr;
  argl->length = 1;

  if ( argl->next != NULL ) {
    argl->length = argl->next->length + 1;
  }

  return argl;
}

functionDef_t* newFunc(const char *id, void *params, void *body)
{
  size_t idLen = strlen(id);
  functionDef_t* func = ast_emalloc(sizeof(functionDef_t));

  func->entity = LANG_ENTITY_FUNCDECL;

  func->params = params;
  func->body = body;
  func->body->entity = LANG_ENTITY_BODY;

  func->id.id = ast_emalloc(idLen+1);

  memcpy(func->id.id, id, idLen);

  func->id.id[idLen] = 0;

  return func;
}

functionCall_t* newFunCall(const char *id, void *args)
{
  size_t idLen = strlen(id);
  functionCall_t* func = ast_emalloc(sizeof(functionCall_t));

  func->entity = LANG_ENTITY_FUNCCALL;

  func->args = args;

  func->id.id = ast_emalloc(idLen+1);

  memcpy(func->id.id, id, idLen);

  func->id.id[idLen] = 0;

  return func;
}

ifStmt_t*  newIfStatement(int ifType, ifCondition_t *cond, void *body)
{
  ifStmt_t* ifstmt = ast_emalloc(sizeof(ifStmt_t));

  ifstmt->ifType = ifType;
  ifstmt->cond  = cond;
  ifstmt->body  = body;
  ifstmt->elif  = NULL;
  ifstmt->endif = NULL;

  return ifstmt;
}

body_t* newBody(void *body)
{
  body_t* bdy = ast_emalloc(sizeof(body_t));
  bdy->entity = LANG_ENTITY_BODY;
  bdy->content = body;

  return bdy;
}

void free_expression(expr_t *expr) {
  if ( expr == NULL )
    return;

  switch (expr->type) 
  {
  case EXPR_TYPE_ID:
  {
    free(expr->id.id);
    break;
  }
  case EXPR_TYPE_FVAL:
  case EXPR_TYPE_IVAL:
  case EXPR_TYPE_UVAL:
    break;
  case EXPR_TYPE_TEXT: {
    free(expr->text);
    break;
  }
  break;
  case EXPR_TYPE_OPADD:
  {
    free_expression((expr_t*)expr->add.left);
    free_expression((expr_t*)expr->add.right);
    break;
  }
  break;
  case EXPR_TYPE_OPSUB:
  {
    free_expression((expr_t*)expr->add.left);
    free_expression((expr_t*)expr->add.right);

    break;
  }
  case EXPR_TYPE_OPMUL:
  {
    free_expression((expr_t*)expr->add.left);
    free_expression((expr_t*)expr->add.right);
    break;
  }
  case EXPR_TYPE_OPMOD:
  {
    free_expression((expr_t*)expr->add.left);
    free_expression((expr_t*)expr->add.right);
    break;
  }
  break;
  case EXPR_TYPE_OPDIV:
  {
    free_expression((expr_t*)expr->add.left);
    free_expression((expr_t*)expr->add.right);
    break;
  }
  case EXPR_TYPE_EMPTY:
  default:
    break;
  }
}

static void free_cond(ifCondition_t *cond)
{
  free_expression(cond->left);
  free_expression(cond->right);
}

void free_ast(statement_t *stmt)
{
  entity_eval_t *eval = (entity_eval_t*)stmt;
  void *next = NULL;

  if ( stmt == NULL )
    return;

  switch ( eval->entity ) {
  case LANG_ENTITY_DECL:
  case LANG_ENTITY_FUNCDECL: 
  case LANG_ENTITY_FUNCCALL:
    break;
  case LANG_ENTITY_CONDITIONAL:
    next = ((statement_t*)stmt)->next;
    break;
  case LANG_ENTITY_EMPTY_MATH:
  case LANG_ENTITY_EMPTY_STR:
  {
    expr_t *e = ((statement_t*)stmt)->content;
    free_expression(e);
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
    declaration_t* decl = ((statement_t*)stmt)->content;
    /* Evaluating the expression among global variables */
    free_expression(decl->val);
    }
    break;
    case LANG_ENTITY_FUNCDECL: 
    {
    functionDef_t *funcDef = ((statement_t*)stmt)->content;
    free(funcDef->id.id);
    }
    break;
    case LANG_ENTITY_FUNCCALL:
    {
    functionCall_t *funcCall = ((statement_t*)stmt)->content;
    free(funcCall->id.id);
    }
    break;
    case LANG_ENTITY_CONDITIONAL:
    {
      ifStmt_t *ifstmt = ((statement_t*)stmt)->content;
      ifStmt_t *ifstmtWalk;
      ifCondition_t *cond = ifstmt->cond;

      free_cond(cond);
      free_ast(ifstmt->body->content);

      // Walk through the elifs.
      ifstmtWalk = ifstmt->elif;

      while ( ifstmtWalk != NULL ) {
        free_cond(ifstmtWalk->cond);
        free_ast(ifstmtWalk->body->content);
        ifstmtWalk = ifstmtWalk->elif;
      }

      // Print the else if it is not NULL
      if ( ifstmt->endif != NULL ) {
        ifstmtWalk = ifstmt->endif;
        free_ast(ifstmtWalk->body->content);
      }
      break;
    }
    default:
    break;
  }

  free_ast(next);
}
