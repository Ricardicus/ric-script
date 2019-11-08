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

	exp->type = EXPR_TYPE_ADDOP;
	exp->add.left = left;
	exp->add.right = right;

	return exp;
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
		stmt->content = content;
		break;
		case LANG_ENTITY_FUNCDECL:
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
		printf("ID(%s)", exp->id.id);
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
		printf("%s", exp->text);
		break;
		case EXPR_TYPE_ADDOP:
		print_expr((expr_t*)exp->add.left);
		printf(" + ");
		print_expr((expr_t*)exp->add.right);
		break;
		case EXPR_TYPE_EMPTY:
		default:
		break;
	}

}

static void print_statements_(void *stmt, int indent)
{
	int i = 0;

	entity_eval_t *eval = (entity_eval_t*)stmt;
	void *next;

	if ( stmt == NULL )
		return;

	switch ( eval->entity ) {
		case LANG_ENTITY_DECL:
		case LANG_ENTITY_FUNCDECL:
			while ( i < indent*4 ){
				printf(" ");
				++i;
			}
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
			printf("Declaration, ID: %s, Expr: ", decl->id.id);
			print_expr(decl->val);
			printf("\n");
		}
		break;
		case LANG_ENTITY_FUNCDECL:
		{
			functionDef_t *funcDef = ((statement_t*)stmt)->content;
			printf("Function: ID(%s) args(", funcDef->id.id);
			argsList_t *args = funcDef->args;
			int i = 0;
			while ( args != NULL ) {
				printf("%sID(%s)", (i==0?"":","), args->id.id);
				args=args->next;
				i=1;
			}
			printf(")\n");
			print_statements_(funcDef->body,indent+1);
		}
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