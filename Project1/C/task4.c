/**
 * Task 4
 * Mickey Zhang
 * 2/8/26
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[]) {

    struct structA {
        char a;
        short b;
        int c;
    };

    struct structB {
        short b;
        int c;
        char a;
    };

    struct structC {
        int c;
        char a;
        short b;
    };

    struct structA a = { .a = 0xAA, .b = 0xBBBB, .c = 0xCCCCCCCC};
    struct structB b = { .b = 0xBBBB, .c = 0xCCCCCCCC, .a = 0xAA};
    struct structC c = { .c = 0xCCCCCCCC, .a = 0xAA, .b = 0xBBBB};

    // set up ptr to look through each structure
    unsigned char *ptr;
    ptr = (unsigned char *)&b;

    // log what's on the stack
    printf("Struct B: b ->\n");
    for(int i = 0; i < sizeof(b); i++) {
        printf("%d) %02X\n", i, ptr[i]);
    }

    return 0;

 }