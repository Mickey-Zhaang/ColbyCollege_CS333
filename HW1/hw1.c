#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {

    int *nums = malloc( 5*sizeof(int) );
    for (int i = 0; i < 5; i++) {
        nums[i] = i+2*i;
    }
    int *ptr = nums+4;
    float not_an_int = 2.5;
    float *ptr2 = &not_an_int;

    // Write the line of code that will print nums out as an address
    printf("nums as an address: %p\n", nums);
    
    // Write the line of code that will print ptr out as an address
    printf("ptr as an address: %p\n", ptr);

    // Write the line of code that will follow ptr and print out  the value it is pointing to in decimal integer format
    printf("what the ptr is pointing to: %d\n", *ptr);
    
    // Write the line of code that will print ptr2 out as an address
    printf("ptr3 as an address: %p\n", ptr2);

    // Write the line of code that will follow ptr2 and print out the value it is pointing to in floating point format
    printf("what ptr2 is pointing to: %f\n", *ptr2);
    
    // Mark 1
    
    ptr = nums + 5;

    // Write the line of code that will print ptr out as an address
    printf("ptr as an address: %p\n", ptr);

    // Write the line of code that will follow ptr and print out  the value it is pointing to in decimal integer format
    printf("what ptr is pointing to: %d\n", *ptr);
    
    // Mark 2
    return 0;
}