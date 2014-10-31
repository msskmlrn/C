#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    FILE *in, *out;
    int c, ch;
    char lastc="\n";
    
    if ( (in = fopen("3in.txt","r")) == NULL) {
	printf ("Can't open file: in for reading.\n");
        return 1;
    }
    
    if ( (out = fopen("3out.txt","w")) == NULL) {
	printf ("Can't open file: out for writing.\n");
        return 1;
    }
    
    while((ch = fgetc(in)) != EOF) {
        if (ch == '\n') {
            if (c = fgetc(in) != EOF) {
                if (c != '\n') {
                    fputc(ch, out);    
                    fputc(c, out);    
                }
            }
        }
        else {
            fputc(ch, out);
        }
    }
    
    fclose(in);
    fclose(out);
    
    return (EXIT_SUCCESS);
}

