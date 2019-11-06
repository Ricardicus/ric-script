%option noyywrap
%{
#include <stdlib.h>
#include <string.h>

#include "y.tab.h"

int yylinenor=1;

%}

DIGIT_VAL        [0-9]
FLOAT_VAL        [0-9]+"."[0-9]*
KEYWORD_PROCESS  process
HASHTAG          [#]
ID_TOKEN         [_[:alnum:]]
RETURN_AS_IS     [\"\'+<>:\-/]

%%

[ \t]*#.* {
	printf("Comment.... (%s)\n", yytext);
}

-?{DIGIT_VAL}+ {
	yylval.val_int = atoi(yytext);
	printf("DIGIT %s\n", yytext);
	return DIGIT;
}
-?{FLOAT_VAL} {
	yylval.val_double = atof(yytext);
	printf("DOUBLE [%s]\n", yytext);
	return DOUBLE;
}

{RETURN_AS_IS} {
	printf("RETURN_AS_IS: '%c'\n", yytext[0]);
	yylval.id[0] = yytext[0];
	yylval.id[1] = 0;
	return yytext[0];
}

{ID_TOKEN}+ {
	printf("ID (%s)\n", yytext);
	memset(yylval.id,0,sizeof(yylval.id));
	memcpy(
		yylval.id, yytext,
		sizeof(yylval.id) > strlen(yytext) ?
		strlen(yytext) : sizeof(yylval.id)
	);
	return ID;
}

\n {
	printf("NEWLINE\n");
	yylinenor++;
}

= {
	printf("EQ\n");
	return '=';
}

.                printf("eat . (%s)\n", yytext);

%%