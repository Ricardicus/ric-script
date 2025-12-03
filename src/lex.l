%option noyywrap
%{
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_MSC_VER)
  #include <io.h>
  #define isatty _isatty
#else
  #include <unistd.h>
#endif

#include "y.tab.h"

int yylinenor=1;

int return_spaces = 0;
int double_citation = 0;
int simple_citation = 0;

int commenting = 0;

%}

DIGIT_VAL        [0-9]
FLOAT_VAL        [0-9]+"."[0-9]*
HASHTAG          [#]
RETURN_TOKEN     "->"
FOREACH_TOKEN    "..."
LOOP_START "*"
ID_TOKEN         [_[:alnum:]åäöÅÄÖ]
RETURN_AS_IS     [\"\'&|+<>:;?\-/()\.{}\*%\[\]^~!=_,@$\\{}]

%%

[ \t]*#.* {
	// Comment
	commenting = 1;
}

{DIGIT_VAL}+ {
  memset(yylval.id,0,sizeof(yylval.id));
  memcpy(
    yylval.id, yytext,
    sizeof(yylval.id) > strlen(yytext) ?
    strlen(yytext) : sizeof(yylval.id)
  );
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

{FOREACH_TOKEN} {
	return FOREACH;
}

[ ] {
	// return spaces only if within a citation
	if ( double_citation|| simple_citation ) {
		return ' ';
	}
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
	if ( commenting ) {
		commenting = 0;
	} else if ( double_citation|| simple_citation ) {
		return ' ';
	} else {
		return NEWLINE;
	}
}

.               ;

%%
