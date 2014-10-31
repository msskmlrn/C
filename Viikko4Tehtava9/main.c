#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_ints(int* array, int len) {
    
    int i, randomPosition, temp;
    
    for (i = 0; i < len; i++) {
        randomPosition = rand() % len;
        temp = array[i];
        array[i] = array[randomPosition];
        array[randomPosition] = temp;
    }
}

int main(int argc, char** argv) {
    
    FILE *fptr;
    char c;
    int lines = 0;
    int i = 0;
    int array[100];
    char line[256];
    int test;
    int number1, number2, number3;
    
    if ((fptr = fopen("test.txt","r")) == NULL) {
	printf ("Can't open file for reading.\n");
        return 1;
    }
    
    
    while ((c = fgetc(fptr)) != EOF) {
	if (c == '\n') {
            lines++;
        }    
    }
    
    rewind(fptr);
    
    while(!feof(fptr)) {
        if (fgets(line, 254, fptr)) {
            //printf("%s", line);
            test = atoi (line);
            // printf("%d\n", test);
            array[i] = test;
            i++;
        }    
    }
    
    fclose(fptr);
    
    printf("\n");
    
    i = 0;
    for (i; i < lines; i++) {
        printf("%d\n", array[i]);
    }
    
    srand (time (0));
    
    printf("\n");
    
    shuffle_ints(array, lines);
    
    i = 0;
    for (i; i < lines; i++) {
        printf("%d\n", array[i]);
    }
    
    number1 = array[0];
    number2 = array[1];
    number3 = array[2];
    
    printf("\n");
    
    printf("numero 1: %d\n", number1);
    printf("numero 2: %d\n", number2);
    printf("numero 3: %d\n", number3);
    
    return (EXIT_SUCCESS);
}

