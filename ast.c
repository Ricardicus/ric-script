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
	exp->id.ID = (char*)ast_emalloc(textLen+1);

	memcpy(exp->id.ID, id, textLen);
	exp->id.ID[textLen] = 0;

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

	decl->val = exp;
	decl->id.ID = ast_emalloc(idLen+1);

	memcpy(decl->id.ID, id, idLen);

	decl->id.ID[idLen] = 0;

	return decl;
}

statement_t* newStatement(int type, void *content)
{
	statement_t* stmt = ast_emalloc(sizeof(statement_t));
	stmt->type = type;
	switch ( type ) {
		case STMT_TYPE_DECL:
		stmt->decl = (declaration_t*)content;
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
}