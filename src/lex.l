%option noyywrap
%{
#include <stdlib.h>
#include <string.h>

#include "y.tab.h"

int yylinenor=1;

int return_spaces = 0;
int double_citation = 0;
int simple_citation = 0;

%}

DIGIT_VAL        [0-9]
FLOAT_VAL        [0-9]+"."[0-9]*
KEYWORD_PROCESS  process
HASHTAG          [#]
RETURN_TOKEN     "->"
ID_TOKEN         [_[:alnum:]]
RETURN_AS_IS     [\"\'+<>:;?\-/()\.{}\*%\[\]^~!=,@$\\]

%%

[ \t]*#.* {
	// Comment
}

{DIGIT_VAL}+ {
	yylval.val_int = atoi(yytext);
	return DIGIT;
}
{FLOAT_VAL} {
	if ( double_citation || simple_citation ) {
		memset(yylval.id,0,sizeof(yylval.id));
		memcpy(
			yylval.id, yytext,
			sizeof(yylval.id) > strlen(yytext) ?
			strlen(yytext) : sizeof(yylval.id)
		);
		/* I am being lazy, I just want to send a string, not ID, but it will work the same */
		return ID;
	}
	yylval.val_double = atof(yytext);
	return DOUBLE;
}

{RETURN_AS_IS} {
	yylval.id[0] = yytext[0];
	yylval.id[1] = 0;

	if ( yytext[0] == '\'' && !double_citation ){
		simple_citation = (simple_citation+1) % 2;
	} else if ( yytext[0] == '\"' && !simple_citation ) {
		double_citation = (double_citation+1) % 2;
	}

	return yytext[0];
}

{RETURN_TOKEN} {
	return RETURN;
}

{ID_TOKEN}+ {
	memset(yylval.id,0,sizeof(yylval.id));
	memcpy(
		yylval.id, yytext,
		sizeof(yylval.id) > strlen(yytext) ?
		strlen(yytext) : sizeof(yylval.id)
	);
	return ID;
}

\n {
	yylinenor++;
}

[ ] {
	// return spaces only if within a citation
	if ( double_citation|| simple_citation ) {
		return ' ';
	}
}

.               ;

%%
