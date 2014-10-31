#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    char c = 'c';
    int x = 0;
    float y = 4.25;
    
    printf("%c\n", c);
    printf("%d\n", x);
    printf("%f\n", y);
    
    c = 'a';
    x = 1;
    y = 456546.3516855;
    
    printf("%c\n", c);
    printf("%d\n", x);
    printf("%f\n", y);
    
    return (EXIT_SUCCESS);
}

