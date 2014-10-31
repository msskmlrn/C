#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    FILE * fpt;
    
    FILE * open_it(char * filename, char * filemode);
    
    void count_characters_and_words(FILE * fpointer);
    
    if (argc < 2) {
        fprintf(stdout, "You forgot the filename!\n");
        exit(1);
    }
    
    fpt = open_it(argv[1], "r");
    
    count_characters_and_words(fpt);
    
    fclose(fpt);
    return 0;
}

void count_characters_and_words(FILE * fpointer) {
    int chars = 0, words = 0;
    char c;
    
    while (1) {
        c = fgetc(fpointer);
        if (c == EOF)
            break;
        
        if (c != '\n' && c != ' ' && c != '.' && c != ',')
            ++chars;
        
        if ( c == '\n' || c == ' ')
            ++words;
    }
    printf("number of characters:%d\n ", chars);
    printf("\n");
    printf("number of words:%d\n", words);
    return;
}

FILE * open_it(char * filename, char * filemode) {
    FILE *fp;
    if ((fp=fopen(filename, filemode)) == NULL)
    {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(1);
    }
    return(fp);
}
