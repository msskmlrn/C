#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int converged;

double f(double x) {
    //return x*x + 3*x -3;
    return x*x - 4;
}

double f_deriv(double x) {
    //return 2*x + 3;
    return 2*x;
}

double newton(double x0, double tol, int max_iters, 
        int* iters_p) {
    
    double x = x0;
    double x_prev;
    int iter = 1;
    double f_deriv_x;
    double f_x;
    
    do { 
        iter++;
        x_prev = x;
        f_deriv_x = f_deriv(x_prev);
        if (f_deriv_x == 0) {
            printf("Nollalla jako, suoritus päättyy\n");
            converged = 0;
            break;
        }
        f_x = f(x_prev);
        x = x_prev - f_x / f_deriv_x;
        
        printf("iteraatio %d\n", iter);
        printf("x_i %f\n", x_prev);
        printf("x %f\n", x);
        printf("f(x_i) %f\n", f_x);
    } while (fabs(x - x_prev) > tol && iter < max_iters);
    
    if (fabs(x - x_prev) <= tol)
        converged = 1;
    else
        converged = 0;
    
    *iters_p = iter;
    
    return x;
}

int main() {
    double x0 = 10; //alkuarvaus
    double x; //arvio
    double tol =  0.000001; //virheraja
    int max_iters = 100; //iteraatioita maksimissaaan
    int iters; //oikea iteraatioiden määrä
    
    x = newton(x0, tol, max_iters, &iters);
    
    if (converged == 1) {
        printf("Ratkaisun löytämiseen kului %d askelta.\n", iters);
        printf("Ratkaisun likiarvo on %19.16e\n", x);
        printf("f(%19.16e) = %19.16e\n", x, f(x));
    } else {
        printf("Ratkaisua ei löytynyt %d askeleen jälkeen.\n", iters);
        printf("Viimeinen arvaus oli %19.16e\n", x);
        printf("f(%19.16e) = %19.16e\n", x, f(x));
    }
    
    return 0;
}

