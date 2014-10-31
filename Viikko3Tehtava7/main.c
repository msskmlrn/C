#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

unsigned int get_file_length(char* filename) {
    FILE *fptr;
    int length = 0;
    
    fptr = fopen(filename, "rb");
    
    if (fptr != NULL) {
        fseek(fptr, 0, SEEK_END);
        length = ftell(fptr);
        fclose(fptr);
    }
    else {
        return -1; //file could not be read;
    }
    return length;
}

int main(int argc, char** argv) {
    int t;
    char* c = "7in.txt";
    
    t = get_file_length(c);
    
    printf("length: %d", t);
    
    return (EXIT_SUCCESS);
}

