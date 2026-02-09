/**
 * Task 2
 * Mickey Zhang
 * 2/8/26
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[]) {

    // init our stack place holders
    int myInt = 0xAAAAAAAA;
    long myLong = 0xBBBBBBBB;
    short myShort = 0xCCCC;

    // make a ptr that points to itself
    unsigned char *ptr = (unsigned char *)&ptr;

    // investigate stack
    for(int i = 0; i < 100; i++){
        printf("%d) : %p -> %02X\n", i, &ptr[i], ptr[i]);
    }


    return 0;
 }