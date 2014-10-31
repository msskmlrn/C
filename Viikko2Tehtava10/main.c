#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(void* array, int len, size_t elem_size) {
    char* cp = array;
    
    int randomPosition;
    size_t i;
    
    for (i = 0; i < len * elem_size; i = i + elem_size) {
        srand (time (0));
        randomPosition = rand() % (len * elem_size);
        
        swap(&cp[randomPosition], &cp[i], sizeof(elem_size));
    }
    
}

void swap(void* a, void* b, size_t elem_size) {
    char* ca = a;
    char* cb = b;
    
    size_t i;
    for (i = 0; i < elem_size; i++) {
        char temp = ca[i];
        ca[i] = cb[i];
        cb[i] = temp;
    }
    return;
}

void print_doubles(double* array, int len) {
    int i;
    
    for (i = 0; i < len; i++) {
        printf("%f\n", array[i]);
    }
    
}

int main() {
    
    double nums[5] = { 1.5, 3.5, 5.5, 7.5, 9.5 };
    print_doubles(nums, 5);
    shuffle(nums, 5, sizeof(double));
    printf("\n");
    print_doubles(nums, 5);
    
    return (EXIT_SUCCESS);
}