/**
 * Task 3: Prose editor - make text slightly more exciting and less numeric.
 * - Replace whole word "cat"/"cats" (case-insensitive) with "lion"/"lions".
 *   Do NOT replace "cat" inside longer words (e.g. "Catch" stays "Catch").
 * - Replace standalone digits 0-9 and the number 10 with word form.
 *   Do NOT replace digits inside longer numbers (e.g. "123") or in words (e.g. "cat2cat").
 */

%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

^[cC][aA][tT][sS]/[^a-zA-Z0-9]    { printf("lions"); }
^[cC][aA][tT]/[^a-zA-Z0-9]        { printf("lion"); }

[^a-zA-Z0-9][cC][aA][tT][sS]/[^a-zA-Z0-9]  { putchar(yytext[0]); printf("lions"); }
[^a-zA-Z0-9][cC][aA][tT]/[^a-zA-Z0-9]      { putchar(yytext[0]); printf("lion"); }

  /* ----- Standalone number 10 (must be before single-digit 1) ----- */
^10/[^0-9a-zA-Z]               { printf("ten"); }
[^0-9a-zA-Z]10/[^0-9a-zA-Z]    { putchar(yytext[0]); printf("ten"); }

  /* ----- Standalone single digits 0-9 ----- */
^0/[^0-9a-zA-Z]                { printf("zero"); }
[^0-9a-zA-Z]0/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("zero"); }

^1/[^0-9a-zA-Z]                { printf("one"); }
[^0-9a-zA-Z]1/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("one"); }

^2/[^0-9a-zA-Z]                { printf("two"); }
[^0-9a-zA-Z]2/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("two"); }

^3/[^0-9a-zA-Z]                { printf("three"); }
[^0-9a-zA-Z]3/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("three"); }

^4/[^0-9a-zA-Z]                { printf("four"); }
[^0-9a-zA-Z]4/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("four"); }

^5/[^0-9a-zA-Z]                { printf("five"); }
[^0-9a-zA-Z]5/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("five"); }

^6/[^0-9a-zA-Z]                { printf("six"); }
[^0-9a-zA-Z]6/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("six"); }

^7/[^0-9a-zA-Z]                { printf("seven"); }
[^0-9a-zA-Z]7/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("seven"); }

^8/[^0-9a-zA-Z]                { printf("eight"); }
[^0-9a-zA-Z]8/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("eight"); }

^9/[^0-9a-zA-Z]                { printf("nine"); }
[^0-9a-zA-Z]9/[^0-9a-zA-Z]     { putchar(yytext[0]); printf("nine"); }

.|\n                           { ECHO; }

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
