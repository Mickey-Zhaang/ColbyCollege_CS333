/**
 * Extension 2
 * Mickey Zhang
 * 2/8/26
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[]) {

    /**
     * Comment each section out to experience different runtime errors
     */

    // // ======== Example 1: free twice ========
    // unsigned char *ptr;
    // ptr = malloc(sizeof(int));

    // printf("Example 1: freeing a ptr after it's already been freed");

    // free(ptr);
    // free(ptr);

    // // ======== Example 2: division by 0 ========

    // int a = 0;
    // int b = 1;

    // printf("Example 2: Division by 0");
    // int c = b / a;

    // ======== Example 3: Stack Overflow ========

    void forever(void) {
        forever();
    }

    printf("Example 3: The forever loop: Stack Overflow!");
    forever();

    return 0;
 }