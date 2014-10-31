#include <stdio.h>
#include <stdlib.h>

char* load_data(char* filename) {
    int length;
    char * buffer = 0;
    FILE *fptr;
    
    length = get_file_length(filename);
    
    if (length > 0) {
        fptr = fopen(filename, "rb");
        
        if (fptr != NULL) {
            fseek (fptr, 0, SEEK_SET);
            buffer = (char *)malloc (length+1);
            
            if (!buffer) {
                printf("Memory error!");
                fclose(fptr);
                return;
            }
            fread(buffer, length, 1, fptr);
            fclose(fptr);
        }
    }
    return buffer;
}

int get_file_length(char* filename) {
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

/*
 * 
 */
int main(int argc, char** argv) {
    char* c = "8in.txt";
    char *buffer;
    int i, length;
    
    length = get_file_length(c);
    buffer = load_data(c);
    
    i = 0;
    
    for(i; i < length; ++i) {
        printf("%c\n", ((char *)buffer)[i]);
    }
    
    return (EXIT_SUCCESS);
}

