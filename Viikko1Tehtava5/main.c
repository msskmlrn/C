#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    char loppu[] = "loppu";
    char nimi[20];
    
    do {
        printf("Anna nimi, 'loppu' lopettaa: ");
        scanf("%s", nimi);
        printf("%s\n", nimi);
    } while (strcmp (nimi,loppu) != 0);
    
    return (EXIT_SUCCESS);
}

