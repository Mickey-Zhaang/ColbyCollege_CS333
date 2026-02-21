/*
 * Task 4: Clite lexer.
 * Output: one line per token: Integer, Float, Keyword, Identifier,
 * Assignment, Comparison, Operator, Open-bracket, Close-bracket,
 * Open-paren, Close-paren. Ignores whitespace and comments.
 */

%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

  /* ----- Whitespace: skip ----- */
[ \t\n\r]+   { /* skip */ }

  /* ----- Line comment: skip ----- */
"//"[^\n]*   { /* skip */ }

  /* ----- Block comment: skip ----- */
"/*"([^*]|"*"[^/])*"*"+"/"  { /* skip */ }

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

int yywrap(void) { return 1; }

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
