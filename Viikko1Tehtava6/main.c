#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int i,j;
    long ix;
    short s;
    float x;
    double dx;
    char c;
    unsigned long ux;
    int a;
    float b;
    double cee;
    long d;
    float e;
    int f;
    long g;
    int h;
    long ii;
    unsigned long jii;
    
    /*
     * a) i + c; char konvertataan intiksi
     * b) x + c; char konvertataan floatiksi
     * c) dx + x; float konvertataan doubleksi
     * d) ((int)dx) + ix; intiksi castattu konvertataan longiksi
     * e) i + x; int konvertaan floatiksi
     * f) s + j; short konvertataan intiksi
     * g) ix + j; int konvertataan longiksi
     * h) s + c; short ja char konvertataan intiksi
     * i) ix + c; char konvertataan intin kautta longiksi
     * j) ix + ux; long konvertataan unsigned longiksi
     */
    
    i = 1;
    j = 2;
    ix = 1251251251;
    s = 32;
    x = 57448848864;
    dx = 44.545;
    c = 'A';
    ux = 45454848;
    
    printf("a-kohta: ");
    a = i + c;
    printf("%i\n", a);
    
    printf("b-kohta: ");
    b = x + c;
    printf("%f\n", b);
    
    printf("c-kohta: ");
    cee = dx + x;
    printf("%d\n", c);
    
    printf("d-kohta: ");
    d = ((int)dx) + ix;
    printf("%ld\n", d);
    
    printf("e-kohta: ");
    e = i + x;
    printf("%f\n", e);
    
    printf("f-kohta: ");
    f = s + j;
    printf("%i\n", f);
    
    printf("g-kohta: ");
    g = ix + j;
    printf("%ld\n", g);
    
    printf("h-kohta: ");
    h = s + c;
    printf("%i\n", h);
    
    printf("i-kohta: ");
    ii = ix + c;
    printf("%ld\n", i);
    
    printf("j-kohta: ");
    jii = ix + ux;
    printf("%ld\n", j);
    
    return (EXIT_SUCCESS);
}

