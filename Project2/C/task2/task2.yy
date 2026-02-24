/**
 * Task 2: Reads a text file and reports:
 *   - Number of lines (rows)
 *   - Number of characters
 *   - Count of each vowel [a, e, i, o, u] (case-insensitive)
 */

%{
#include <stdio.h>
#include <stdlib.h>

int lines = 0;
int chars = 0;
int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;
%}

%%

\n          { lines++; chars++; }
[aA]        { chars++; count_a++; }
[eE]        { chars++; count_e++; }
[iI]        { chars++; count_i++; }
[oO]        { chars++; count_o++; }
[uU]        { chars++; count_u++; }
.           { chars++; }

<<EOF>>     {
                if (chars > 0 && lines == 0) lines = 1;  /* no trailing newline => 1 line */
                printf("Lines: %d\n", lines);
                printf("Characters: %d\n", chars);
                printf("Vowels: a=%d e=%d i=%d o=%d u=%d\n",
                    count_a, count_e, count_i, count_o, count_u);
                return 0;
            }
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
