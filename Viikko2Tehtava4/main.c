#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 * 
 */
void shuffle_ints(int* array, int len) {
    
    int i, randomPosition, temp;
    
    for (i = 0; i < len; i++) {
        srand (time (0));
        randomPosition = rand() % len;
        temp = array[i];
        array[i] = array[randomPosition];
        array[randomPosition] = temp;
    }
}

int main() {
    int i;
    int nums[] = { 0, 1, 2, 3, 4, 5, 6 };
    
    for (i = 0; i < 7; i++) {
        printf("%d\n", nums[i]);
    }
    
    printf("\n");
    
    shuffle_ints(nums, 7);
    
    for (i = 0; i < 7; i++) {
        printf("%d\n", nums[i]);
    }
    
    return (EXIT_SUCCESS);
}

