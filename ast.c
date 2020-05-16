#include "ast.h"
#include "hashtable.h"

/* Namespace (all global) */
hashtable_t *funcDecs = NULL;
hashtable_t *varDecs = NULL;
hashtable_t *parameters = NULL;

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

static void flush_parameters()
{
	if ( parameters != NULL ) {
		hashtable_free(parameters);
		parameters = hashtable_new(20, 0.8);
		assert(parameters != NULL);
	}
}

static void print_expr(expr_t *expr)
{
	if ( expr == NULL )
		return;

	switch (expr->type) 
	{
		case EXPR_TYPE_ID:
		printf("ID('%s')", expr->id.id);
		break;
		case EXPR_TYPE_FVAL:
		printf("%lf", expr->fval);
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
		case EXPR_TYPE_OPADD:
		printf("ADD(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPSUB:
		printf("SUB(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPMUL:
		printf("MUL(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPMOD:
		printf("MOD(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPDIV:
		printf("DIV(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
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
				printf("%s", (i==0?"":","));
				print_expr(args->arg);
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
				printf("%s", (i==0?"":","));
				print_expr(args->arg);
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

static void evaluate_expression(
	expr_t *expr,
	PROVIDE_CONTEXT_ARGS(),
	argsList_t* args)
{
	if ( expr == NULL )
		return;

	switch (expr->type) 
	{
		case EXPR_TYPE_ID:

		printf("ID('%s')", expr->id.id);
		break;
		case EXPR_TYPE_FVAL:
		printf("%lf", expr->fval);
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
		case EXPR_TYPE_OPADD:
		printf("ADD(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPSUB:
		printf("SUB(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPMUL:
		printf("MUL(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPMOD:
		printf("MOD(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_OPDIV:
		printf("DIV(");
		print_expr((expr_t*)expr->add.left);
		printf(",");
		print_expr((expr_t*)expr->add.right);
		printf(")");
		break;
		case EXPR_TYPE_EMPTY:
		default:
		break;
	}
}

#if 0
int evaluate_condition(ifCondition_t *cond)
{
	switch (expr->type) 
	{
		case EXPR_TYPE_ID:
		break;
		case EXPR_TYPE_FVAL:
		break;
		case EXPR_TYPE_IVAL:
		break;
		case EXPR_TYPE_UVAL:
		break;
		case EXPR_TYPE_TEXT:
		break;
		case EXPR_TYPE_OPADD:
		print_expr((expr_t*)expr->add.left);
		print_expr((expr_t*)expr->add.right);
		break;
		case EXPR_TYPE_OPSUB:
		print_expr((expr_t*)expr->add.left);
		print_expr((expr_t*)expr->add.right);
		break;
		case EXPR_TYPE_OPMUL:
		print_expr((expr_t*)expr->add.left);
		print_expr((expr_t*)expr->add.right);
		break;
		case EXPR_TYPE_OPMOD:
		print_expr((expr_t*)expr->add.left);
		print_expr((expr_t*)expr->add.right);
		break;
		case EXPR_TYPE_OPDIV:
		print_expr((expr_t*)expr->add.left);
		print_expr((expr_t*)expr->add.right);
		break;
		case EXPR_TYPE_EMPTY:
		default:
		break;
	}

	return 0;
}

static void interpret_statements_(void *stmt,
	PROVIDE_CONTEXT_ARGS(),
	argsList_t *args
)
{
	entity_eval_t *eval = (entity_eval_t*)stmt;
	void *next = NULL;

	if ( stmt == NULL )
		return;

	switch ( eval->entity ) {
		case LANG_ENTITY_DECL:
		case LANG_ENTITY_FUNCDECL:
		case LANG_ENTITY_FUNCCALL:
		case LANG_ENTITY_CONDITIONAL:
			next = ((statement_t*)stmt)->next;
		break;
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

			/* Placing variable declaration in global variable namespace */
			put(varDecs, decl->id.id, decl->val);
		}
		break;
		case LANG_ENTITY_FUNCDECL:
		{
			functionDef_t *funcDef = ((statement_t*)stmt)->content;

			/* Placing funciton declaration in global function namespace */
			put(funcDecs, funcDef->id.id, funcDef->body);
		}
		break;
		case LANG_ENTITY_FUNCCALL:
		{
			statement_t *body;
			functionCall_t *funcCall = ((statement_t*)stmt)->content;

			/* Looking up the function and calling it if it exists */
			body = get(funcDecs, funcCall->id.id)

			/* Check lookup status */
			if ( body == NULL ) {
				fprintf(stderr, "Error: Function call undefined: '%s'.\r\n", funcCall->id.id);
				exit(1);
			}

			/* Call the function */
			interpret_statements_(body, PROVIDE_CONTEXT(), funcCall->args);
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
			interpret_statements_(ifstmt->body, PROVIDE_CONTEXT());

			// Walk through the elifs.
			ifstmtWalk = ifstmt->elif;

			while ( ifstmtWalk != NULL ) {
				printf("else-if-statement - condition: ");
				print_condition(ifstmtWalk->cond);
				printf("\n");
				interpret_statements_(ifstmtWalk->body, PROVIDE_CONTEXT());
				ifstmtWalk = ifstmtWalk->elif;
			}

			// Print the else if it is not NULL
			if ( ifstmt->endif != NULL ){
				ifstmtWalk = ifstmt->endif;
				printf("else-statment:\n");
				interpret_statements_(ifstmtWalk->body, PROVIDE_CONTEXT());
			}

		}
		break;
		default:
		break;
	}

	interpret_statements_(next, PROVIDE_CONTEXT());
}
#endif

static void interpret_statements_(void *stmt,
	PROVIDE_CONTEXT_ARGS(),
	argsList_t *args
){}

void setup_namespaces() {
	funcDecs = hashtable_new(100, 0.8);
	assert(funcDecs != NULL);
	varDecs = hashtable_new(200, 0.8);
	assert(varDecs != NULL);
	parameters = hashtable_new(20, 0.8);
	assert(parameters != NULL);
}

void close_namespaces() {
	hashtable_free(funcDecs);
	hashtable_free(varDecs);
}

void interpret_statements(statement_t *stmt)
{
	// "CPU" registers definitions
	DEF_NEW_CONTEXT();

	// Setup stack
	SETUP_STACK(&sp, &sb);

	// Setup namespaces
	setup_namespaces();

	interpret_statements_(stmt, PROVIDE_CONTEXT_INIT(), NULL);

	// Close namespaces
	close_namespaces();

	free(sb);
}