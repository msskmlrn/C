#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int vuosi;
    char etunimi[20];
    char sukunimi[20];
    
    printf("Anna syntymävuotesi: ");
    scanf("%d", &vuosi);
    
    printf("Anna etunimesi: ");
    scanf("%s", etunimi);
    
    printf("Anna sukunimesi: ");
    scanf("%s", sukunimi);
    
    printf("%d\n", vuosi);
    printf("%s\n", etunimi);
    printf("%s\n", sukunimi);
    
    return (EXIT_SUCCESS);
}

