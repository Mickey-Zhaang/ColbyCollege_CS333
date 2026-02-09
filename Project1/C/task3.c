/**
 * Task 3
 * Mickey Zhang
 * 2/8/26
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[]) {

    // init our pointer
    unsigned char *ptr;

    // repeatedly allocate memory by reassigning ptr
    for(int i = 0; i < 20000000; i++){
        ptr = malloc(1024);
        // free my boy
        free(ptr);
    }

    return 0;
 }