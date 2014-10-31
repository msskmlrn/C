#include <stdio.h>
#include <stdlib.h>

double maxi(double x, double y, double (*f)(double)) {
    x = f(x);
    y = f(y);
    
    if (x > y)
        return x;
    
    return y;
}

void maxi1(double x, double y, double (*f)(double), double* answer) {
    x = f(x);
    y = f(y);
    
    if (x > y)
        *answer = x;
    else
        *answer = y;
}

double double_function(double x) {
    return 10*x;
}

int maxi2(const void* x, const void* y) {
    if (*(double*)x > *(double*)y)
        return 1;
    if (*(double*)x == *(double*)y)
        return 0;
    
    return -1;
}

int compareGen(const void *block1, const void *block2, size_t elemSize,
        size_t block1Size, size_t block2Size, int (*compareIt) (const void*, const void*)) {
    
    for (unsigned int i = 0; i < block1Size && i < block2Size; i++) {
        if (compareIt((void*)((char*)block1 + elemSize * i), (void*)((char*)block2 + elemSize * i)) != 0)
            return compareIt((void*)((char*)block1 + i * elemSize), (void*)((char*)block2 + i * elemSize));
    }
    
    if (block1Size > block2Size)
        return 1;
    
    else if (block2Size > block1Size)
        return -1;
    
    return 0;
}

int main(void) {
    
    double luku = maxi(1, 2, double_function);
    printf("%f\n", luku);
    
    maxi1(1, 3, double_function, &luku);
    printf("%f\n", luku);
    
    double luvut1[] = {1, 2.5, 3, 2};
    double luvut2[] = {1, 2.5, 3.4, 2};
    
    int tulos = compareGen(luvut1, luvut2, sizeof(double), 4, 4, maxi2);
    printf("%d\n", tulos);
    
    tulos = compareGen(luvut2, luvut1, sizeof(double), 4, 4, maxi2);
    printf("%d\n", tulos);
    
    return (EXIT_SUCCESS);
}