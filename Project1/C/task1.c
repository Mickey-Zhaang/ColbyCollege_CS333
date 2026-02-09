/**
 * Task 1
 * Mickey Zhang
 * 2/8/26
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[]) {

    // init the basic var types
     int myInt = 0x01234567; 
     char myChar = 'a';
     short myShort = 0x0101;
     long myLong = 0x012345676;
     float myFloat = 1.0f;
     double myDouble = 1.0;
    
     // init our one pointer to do all the work
     unsigned char *ptr;
 
     /**
      * Life Cycle
      * ----------
      * 1) point the pointer
      * 2) examine new pointer's addrress's value
      * 2) print it out for every i-th index in sizeof(type)
      */

    // Cyccle for (int)
     ptr = (unsigned char *)&myInt;
 
     printf("\nExamining int (size: %lu bytes):\n", sizeof(int));
 
     for(int i = 0; i < sizeof(int); i++) {
         printf("Byte %d: %02X\n", i, ptr[i]);
     }

     // Cycle for myChar
     ptr = (unsigned char *)&myChar;
     printf("\nExamining char (size: %lu bytes):\n", sizeof(char));
     for(int i = 0; i < sizeof(char); i++) {
        printf("Byte %d: %02X\n", i, ptr[i]);
     }

     // cycle for short
     ptr = (unsigned char * )&myShort;
     printf("\nExamining short (size: %lu bytes):\n", sizeof(short));
     for(int i = 0; i < sizeof(short); i++) {
        printf("Byte %d: %02X\n", i, ptr[i]);
     }

     // Cycle for long
     ptr = (unsigned char *)&myLong;
     printf("\nExamining long (size: %zu bytes):\n", sizeof(long));
     for (int i = 0; i < sizeof(long); i++) {
        printf("Byte %d: %02X\n", i, ptr[i]);
     }

     // Cycle for float
     ptr = (unsigned char *)&myFloat;
     printf("\nExamining float (size: %zu bytes):\n", sizeof(float));
     for (int i = 0; i < sizeof(float); i++) {
        printf("Byte %d: %02X\n", i, ptr[i]);
     }

     // Cycle for double
     ptr = (unsigned char *)&myDouble;
     printf("\nExamining double (size: %zu bytes):\n", sizeof(double));
     for (int i = 0; i < sizeof(double); i++) {
        printf("Byte %d: %02X\n", i, ptr[i]);
     }

     return 0;
 }