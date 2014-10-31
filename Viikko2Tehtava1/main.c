#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    int i, j=25;
    int *pi, *pj=&j;
    
    *pj=j+5;
    i= *pj+5;
    pi=pj;
    *pi=i+j;
    
    return (EXIT_SUCCESS);
}

/*
 * a)
 *  i = ei määritelty
 * j = 25
 * &i = -1186556308
 * &j = -1186556312
 * 
 * b)
 * pi = 4195344
 * pj = -1946137288
 * *pi = -199164855
 * *pj = 25
 * 
 * c)
 * pj = 1859457884
 * *pj = 30
 * 
 * d)
 * i = 35
 * 
 * e)
 * pi = -1466952104
 * *pi = 30
 * 
 * f)
 * pi = 739482488
 * *pi = 65
 * 
 */