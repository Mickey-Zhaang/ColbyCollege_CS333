/** 
 * Read in from a specified file and 
 * print out a list of all the integers in the file
 * 
 * flex -o q2_file1.c q2_file1.yy
 * gcc -o q2_file1 q2_file1.c -ll

 */

%%

AB  printf( "Just the first part: %s\n", yytext );
ABBA    printf( "Swedish band: %s\n", yytext );
AB+A printf( "Found a match!: %s\n", yytext );
[[:space:]]   printf( "space: |%s|\n", yytext );
.   printf( "nonspace: |%s|\n", yytext );

%%

int main( int argc, char *argv[] ) {
		
    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input 
        
    yylex(); // a function of flex that read input till it is exhausted
        
    return 0;
}
