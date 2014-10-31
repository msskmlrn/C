#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int i;
    
    for (i = 0; i <= argc; ++i) {
        printf("%s\n", argv[i]);
    }
    
    return (EXIT_SUCCESS);
}

/*
 
 #include <stdlib.h>
 #include <stdio.h>
 int main(int argc, char* argv[])
 {
 
 for (int i = 0; i <= argc; ++i) {
 printf("%s\n", argv[i]);
 }
 
 exit(EXIT_SUCCESS);
 }
 
 ../src/Tehtava13.c:6:2: error: ‘for’ loop initial declarations are only allowed in C99 mode
 make: *** [src/Tehtava13.o] Error 1
 
 Multiple markers at this line
 - use option -std=c99 or -std=gnu99 to compile your code
 - ‘for’ loop initial declarations are only allowed in C99
 mode
 
 
 
 */
