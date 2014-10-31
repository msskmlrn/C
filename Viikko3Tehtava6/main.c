#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int is_line_break(char c) {
    
    if (c == ('\n') || c == ('\r')) {
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    int t, c;
    char ch;
    FILE *fptr;
    
    if ((fptr = fopen("test.txt", "r")) == NULL) {
        printf("Failed to open file: test\n");
        exit(1);
    }
    
    while((ch = fgetc(fptr)) != EOF) {
        if (is_line_break(ch) == 1) {
            //if (ch == '\n') {
            printf("juu\n");
        }
    }
    
    ch = '\n';
    t = is_line_break(ch);
    printf("%d\n", t);
    
    ch = '\r';
    t = is_line_break(ch);
    printf("%d\n", t);
    
    ch = 't';
    t = is_line_break(ch);
    printf("%d\n", t);
    
    return (EXIT_SUCCESS);
}

