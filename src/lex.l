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
#include "hooks.h"

int yylinenor=1;
static int yycolumn = 1;

/* Track one-based character columns, including skipped whitespace/comments. */
#define YY_USER_ACTION do { \
  yylloc.first_line = yylinenor; \
  yylloc.first_column = yycolumn; \
  for (int i = 0; i < yyleng; ++i) { \
    unsigned char byte = (unsigned char)yytext[i]; \
    if ((byte & 0xc0) != 0x80) { \
      yylloc.last_line = yylinenor; \
      yylloc.last_column = yycolumn; \
      if (byte == '\n') { ++yylinenor; yycolumn = 1; } \
      else { ++yycolumn; } \
    } \
  } \
} while (0);


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

 /* Keep compound operators atomic so arithmetic and slices are unambiguous. */
"::"|"+="|"-="|"*="|"/=" {
    strcpy(yylval.id, yytext);
    if (double_citation || simple_citation) {
        return QUOTED_CHAR;
    }
    switch (yytext[0]) {
        case ':': return MEMBER;
        case '+': return ADD_ASSIGN;
        case '-': return SUB_ASSIGN;
        case '*': return MUL_ASSIGN;
        case '/': return DIV_ASSIGN;
    }
}

{RETURN_AS_IS} {
	yylval.id[0] = yytext[0];
	yylval.id[1] = 0;

	if ( (yytext[0] == '\'' && double_citation) ||
         (yytext[0] == '\"' && simple_citation) ) {
        return QUOTED_CHAR;
    }
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

	if ( commenting ) {
		commenting = 0;
	} else if ( double_citation|| simple_citation ) {
		return ' ';
	} else {
		return NEWLINE;
	}
}

[\t\r]         ;
"\302\240"      ; /* Non-breaking spaces occur in existing sample programs. */
<<EOF>> {
  yylloc.first_line = yylloc.last_line = yylinenor;
  yylloc.first_column = yylloc.last_column = yycolumn;
  return 0;
}
.               { return (unsigned char)yytext[0]; }

%%

void resetLexerLocation(void) {
  yylinenor = yycolumn = 1;
  yylloc.first_line = yylloc.last_line = 1;
  yylloc.first_column = yylloc.last_column = 1;
  double_citation = simple_citation = commenting = 0;
}

/* Parsing a loaded file must not consume or overwrite the caller's scanner. */
int parseSourceFile(FILE *input, const char *file, statement_t **result) {
  if (input == NULL) input = stdin;
  extern char *ParsedFile;
  extern statement_t *root;
  YY_BUFFER_STATE previous_buffer = YY_CURRENT_BUFFER;
  FILE *previous_input = yyin;
  char *previous_file = ParsedFile;
  statement_t *previous_root = root;
  YYLTYPE previous_location = yylloc;
  int previous_line = yylinenor, previous_column = yycolumn;
  int previous_double = double_citation, previous_simple = simple_citation;
  int previous_comment = commenting;
  YY_BUFFER_STATE buffer = yy_create_buffer(input, YY_BUF_SIZE);
  yy_switch_to_buffer(buffer);
  ParsedFile = (char*)file;
  root = NULL;
  resetLexerLocation();
  int status = getParser()();
  *result = status == 0 ? root : NULL;
  yy_delete_buffer(buffer);
  if (previous_buffer != NULL) yy_switch_to_buffer(previous_buffer);
  yyin = previous_input;
  ParsedFile = previous_file;
  root = previous_root;
  yylloc = previous_location;
  yylinenor = previous_line;
  yycolumn = previous_column;
  double_citation = previous_double;
  simple_citation = previous_simple;
  commenting = previous_comment;
  return status;
}
