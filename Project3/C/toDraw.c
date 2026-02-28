/**
 * Test code for Stack 
 *
 * Ying Li
 * 08/01/2016
 */

 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 #include "cstack.c"


int main(int argc, char **argv) {
	Stack *s = stk_create(3);
	int i;

	printf( "s is at %p\n", &s);
	printf( "s is storing %p\n", s);
	printf( "i is at %p\n", &i);

	for(i = 0; i < 3; i++) {
		stk_push(s, i+1);
	} 
    // Mark 1 (first memory picture)
	
	printf("The original list: ");
	stk_display(s, 0);
	
	printf("The reversed list: ");
	stk_display(s, 1);
	
	stk_destroy(s);
    // Mark 2 (first memory picture)
	
	return 0;
}
