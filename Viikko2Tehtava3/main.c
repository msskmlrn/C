#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void print_doubles(double* array, int len) {
    int i;
    
    for (i = 0; i < len; i++) {
        printf("%f\n", array[i]);
    }
    
}


int main() {
    
    double nums[5] = { 3.14159, 2.71828, 1.41421, 1.61803, 4.66920 };
    print_doubles(nums, 5);
    
    return (EXIT_SUCCESS);
}

