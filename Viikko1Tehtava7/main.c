#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int absolute(int x);

int absolute(int x) {
    if (x < 0)
        return x * -1;
    else
        return x;
}

int main(int argc, char** argv) {
    
    int x;
    int tulos;
    
    printf("Anna luku, jonka itseisarvon haluat tietää: ");
    scanf("%d", &x);
    
    tulos = absolute(x);
    printf("%d", tulos);
    
    return (EXIT_SUCCESS);
}

