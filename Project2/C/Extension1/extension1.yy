/*
 * Extension 1: Clite lexer but with comments.
 */

%{
#include <stdio.h>
#include <stdlib.h>
#define COMMENT_BUF_MAX 4096
static char comment_buf[COMMENT_BUF_MAX];
static size_t comment_len;
%}

%option noyywrap
%x COMMENT


%%

  /* ----- Whitespace: skip ----- */
[ \t\n\r]+   { /* skip */ }

  /* ----- Line comment: print with indicator ----- */
"//"[^\n]*   { printf("Line-comment: %s\n", yytext); }

  /* ----- Block comment: print with indicator (closed); or enter COMMENT for unclosed ----- */
"/*"([^*]|"*"[^/])*"*"+"/"  { printf("Block-comment: %s\n", yytext); }
"/*"  { comment_len = 0; comment_buf[0] = '\0'; BEGIN(COMMENT); }

<COMMENT>"*/"   {
    printf("Block-comment: /*%s*/\n", comment_buf);
    BEGIN(INITIAL);
}
<COMMENT>.    {
    if (comment_len + 1 < COMMENT_BUF_MAX) { comment_buf[comment_len++] = yytext[0]; comment_buf[comment_len] = '\0'; }
}
<COMMENT>\n   {
    if (comment_len + 1 < COMMENT_BUF_MAX) { comment_buf[comment_len++] = '\n'; comment_buf[comment_len] = '\0'; }
}

<COMMENT><<EOF>>   {
    printf("Block-comment (unclosed): /*%s\n", comment_buf);
    fprintf(stderr, "Error: unclosed block comment\n");
    return 0;
}

  /* ----- Keywords (before identifiers; require non-id char after) ----- */
"if"/[^a-zA-Z0-9_]      { printf("Keyword-if\n"); }
"else"/[^a-zA-Z0-9_]    { printf("Keyword-else\n"); }
"while"/[^a-zA-Z0-9_]   { printf("Keyword-while\n"); }
"for"/[^a-zA-Z0-9_]     { printf("Keyword-for\n"); }
"int"/[^a-zA-Z0-9_]     { printf("Keyword-int\n"); }
"float"/[^a-zA-Z0-9_]    { printf("Keyword-float\n"); }

  /* ----- Float before Integer (so 3.14 is one token) ----- */
[0-9]+\.[0-9]+   { printf("Float-%s\n", yytext); }

  /* ----- Integer ----- */
[0-9]+          { printf("Integer-%s\n", yytext); }

  /* ----- Comparison (longer first: ==, <=, >= then <, >) ----- */
"=="    { printf("Comparison-==\n"); }
"<="    { printf("Comparison-<=\n"); }
">="    { printf("Comparison->=\n"); }
"<"     { printf("Comparison-<\n"); }
">"     { printf("Comparison->\n"); }

  /* ----- Assignment ----- */
"="     { printf("Assignment\n"); }

  /* ----- Arithmetic operators ----- */
"+"     { printf("Operator-+\n"); }
"-"     { printf("Operator--\n"); }
"*"     { printf("Operator-*\n"); }
"/"     { printf("Operator-/\n"); }

  /* ----- Brackets and parens ----- */
"{"     { printf("Open-bracket\n"); }
"}"     { printf("Close-bracket\n"); }
"("     { printf("Open-paren\n"); }
")"     { printf("Close-paren\n"); }

  /* ----- Identifier (letters/underscore, then alphanumeric/underscore) ----- */
[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identifier-%s\n", yytext); }

  /* ----- Anything else: echo as unrecognized (optional; or skip) ----- */
.       { /* skip / report error */ }

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open %s\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }
    yylex();
    if (argc > 1) fclose(yyin);
    return 0;
}
