#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int i = 0, j = 0, c, row = 20, col = 20;
    char ch;
    FILE *fptr;
    
    char array[20][20];
    
    if ((fptr = fopen("5in.txt", "r")) == NULL) {
        printf("Failed to open file: 5in\n");
        exit(1);
    }
    
    while((c = fgetc(fptr)) != EOF) {
        if (c != '#' && c != '\n' && c != '\r') {
            array[i][j] = c;
            if (++j >= col) {
                j = 0;
                
                if (++i >= row) {
                    break;
                }    
            }
        }
        fclose(fptr);
    }     
    
    i = 0;
    j = 0;
    
    for (i; i < row; i++) {
        for (j; j < col; j++) {
            printf("%c", array[i][j]);
        }
        // printf('\n');
        
    }
    
    return (EXIT_SUCCESS);
}

