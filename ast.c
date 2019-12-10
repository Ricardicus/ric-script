#include "ast.h"

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

expr_t* newExpr_Text(char *text)
{
	size_t textLen = strlen(text);
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_TEXT;
	exp->text = (char*)ast_emalloc(textLen+1);
	exp->textLen = textLen;

	memcpy(exp->text, text, textLen);
	exp->text[textLen] = 0;

	return exp;
}

expr_t* newExpr_Ival(int val)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_IVAL;
	exp->ival = (int32_t) val;

	return exp;
}

expr_t* newExpr_Uval(unsigned val)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_UVAL;
	exp->ival = (uint32_t) val;

	return exp;
}

expr_t* newExpr_Float(double val)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_FVAL;
	exp->fval = val;

	return exp;
}

expr_t* newExpr_ID(char *id)
{
	size_t textLen = strlen(id);
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_ID;
	exp->id.id = (char*)ast_emalloc(textLen+1);

	memcpy(exp->id.id, id, textLen);
	exp->id.id[textLen] = 0;

	return exp;
}

expr_t* newExpr_OPAdd(expr_t *left, expr_t *right)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_OPADD;
	exp->add.left = left;
	exp->add.right = right;

	return exp;
}

expr_t* newExpr_OPSub(expr_t *left, expr_t *right)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_OPSUB;
	exp->add.left = left;
	exp->add.right = right;

	return exp;
}

expr_t* newExpr_OPMul(expr_t *left, expr_t *right)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_OPMUL;
	exp->add.left = left;
	exp->add.right = right;

	return exp;
}

expr_t* newExpr_OPMod(expr_t *left, expr_t *right)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_OPMOD;
	exp->add.left = left;
	exp->add.right = right;

	return exp;
}

expr_t* newExpr_OPDiv(expr_t *left, expr_t *right)
{
	expr_t *exp = ast_emalloc(sizeof(expr_t));

	exp->type = EXPR_TYPE_OPDIV;
	exp->add.left = left;
	exp->add.right = right;

	return exp;
}

ifCondition_t *newConditional(int type, expr_t *left, expr_t *right)
{
  ifCondition_t *cond = ast_emalloc(sizeof(ifCondition_t));

  cond->type  = type;
  cond->left  = left;
  cond->right = right;

  return cond;
}

declaration_t* newDeclaration(const char *id, expr_t *exp)
{
	size_t idLen = strlen(id);
	declaration_t* decl = ast_emalloc(sizeof(declaration_t));

	decl->entity = LANG_ENTITY_DECL;
	decl->val = exp;
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

argsList_t* newArgument(const char *id, void *next)
{
	size_t idLen = strlen(id);
	argsList_t* argl = ast_emalloc(sizeof(argsList_t));

	argl->entity = LANG_ENTITY_ARGS;

	argl->next = next;
	argl->id.id = ast_emalloc(idLen+1);

	memcpy(argl->id.id, id, idLen);

	return argl;
}

functionDef_t* newFunc(const char *id, void *args, void *body)
{
	size_t idLen = strlen(id);
	functionDef_t* func = ast_emalloc(sizeof(functionDef_t));

	func->entity = LANG_ENTITY_FUNCDECL;

	func->args = args;
	func->body = body;
	func->body->entity = LANG_ENTITY_BODY;

	func->id.id = ast_emalloc(idLen+1);

	memcpy(func->id.id, id, idLen);

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

static void print_expr(expr_t *exp)
{
	if ( exp == NULL )
		return;

	switch (exp->type) 
	{
		case EXPR_TYPE_ID:
		printf("ID('%s')", exp->id.id);
		break;
		case EXPR_TYPE_FVAL:
		printf("%lf", exp->fval);
		break;
		case EXPR_TYPE_IVAL:
		printf("%d", exp->ival);
		break;
		case EXPR_TYPE_UVAL:
		printf("%u", exp->uval);
		break;
		case EXPR_TYPE_TEXT:
		printf("'%s'", exp->text);
		break;
		case EXPR_TYPE_OPADD:
		printf("ADD(");
		print_expr((expr_t*)exp->add.left);
		printf(",");
		print_expr((expr_t*)exp->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPSUB:
		printf("SUB(");
		print_expr((expr_t*)exp->add.left);
		printf(",");
		print_expr((expr_t*)exp->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPMUL:
		printf("MUL(");
		print_expr((expr_t*)exp->add.left);
		printf(",");
		print_expr((expr_t*)exp->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPMOD:
		printf("MOD(");
		print_expr((expr_t*)exp->add.left);
		printf(",");
		print_expr((expr_t*)exp->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPDIV:
		printf("DIV(");
		print_expr((expr_t*)exp->add.left);
		printf(",");
		print_expr((expr_t*)exp->add.right);
		printf(")");
		break;
		case EXPR_TYPE_EMPTY:
		default:
		break;
	}

}

static void print_indents(int indent) {
	int i = 0;
	while ( i < indent ){
		printf("    ");
		++i;
	}
}

static void print_condition(ifCondition_t *cond)
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

static void print_statements_(void *stmt, int indent)
{
	int i = 0;

	entity_eval_t *eval = (entity_eval_t*)stmt;
	void *next = NULL;

	if ( stmt == NULL )
		return;

	switch ( eval->entity ) {
		case LANG_ENTITY_DECL:
		case LANG_ENTITY_FUNCDECL:
		case LANG_ENTITY_FUNCCALL:
		case LANG_ENTITY_CONDITIONAL:
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
		case LANG_ENTITY_DECL:
		{
			declaration_t* decl = ((statement_t*)stmt)->content;
			printf("Declaration: ID('%s'), Expr(", decl->id.id);
			print_expr(decl->val);
			printf(")\n");
		}
		break;
		case LANG_ENTITY_FUNCDECL:
		{
			functionDef_t *funcDef = ((statement_t*)stmt)->content;
			printf("Function Declaration: ID('%s') args(", funcDef->id.id);
			argsList_t *args = funcDef->args;
			int i = 0;
			while ( args != NULL ) {
				printf("%sID('%s')", (i==0?"":","), args->id.id);
				args=args->next;
				i=1;
			}
			printf(")\n");
			print_statements_(funcDef->body,indent+1);
		}
		break;
		case LANG_ENTITY_FUNCCALL:
		{
			functionCall_t *funcCall = ((statement_t*)stmt)->content;
			printf("Function Call: ID('%s') args(", funcCall->id.id);
			argsList_t *args = funcCall->args;
			int i = 0;
			while ( args != NULL ) {
				printf("%sID('%s')", (i==0?"":","), args->id.id);
				args=args->next;
				i=1;
			}
			printf(")\n");
		}
		break;
		case LANG_ENTITY_CONDITIONAL:
		{
			ifStmt_t *ifstmt = ((statement_t*)stmt)->content;
			ifStmt_t *ifstmtWalk;
      ifCondition_t *cond = ifstmt->cond;

      printf("if-statement - condition: ");
			print_condition(cond);
			printf("\n");
      print_statements_(ifstmt->body, indent);

			// Walk through the elifs.
			ifstmtWalk = ifstmt->elif;

			while ( ifstmtWalk != NULL ) {
				print_indents(indent);
				printf("else-if-statement - condition: ");
				print_condition(ifstmtWalk->cond);
        printf("\n");
        print_statements_(ifstmtWalk->body, indent+1);
				ifstmtWalk = ifstmtWalk->elif;
			}

			// Print the else if it is not NULL
			if ( ifstmt->endif != NULL ){
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
	printf("\n\nPROGRAM:\n\n");
	print_statements_(stmt, 0);
	printf("\n\n");
}