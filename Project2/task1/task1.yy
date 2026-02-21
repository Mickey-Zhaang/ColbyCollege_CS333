/**
* Task 1!
*/


%%

[a-z]   { int c = yytext[0]; c = 'a' + (c - 'a' + 13) % 26; printf("%c",c);}

[A-Z]   { int c = yytext[0]; c = 'A' + (c - 'A' + 13) % 26; printf("%c", c); }

.|\n    ECHO;

%%


int main(int argc, char *argv[]) {
    yylex();
    return 0;
}