#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int gcd(int num1,int num2) {
    int temp1, temp2;
    
    if (num1 < num2) {
        temp1 = num1;
        num1 = num2;
        num2 = temp1;
    }
    
    if (num2 == 0)
    	return num1;
    
    if (num1 % num2 == 0)
    	return num2;
    else {
    	while (num1 % num2 != 0) {
            temp2= num1 % num2;
            num1 = num2;
            num2 = temp2;
    	}
        return temp2;
    }
    return 0;
}

int gcdr(int num1, int num2) {
    if (num1 == num2)
        return num1;
    
    else if (num1 > num2)
        return gcdr (num1 - num2, num2);
    else
        return gcdr (num1, num2 - num1);
}

int main(int argc, char** argv) {
    
    int a, b;
    a = 299792458;
    b = 6447287;
    
    printf("gcd(a,b)=gcd(%d,%d)=%d\n", a, b, gcd(a,b));
    printf("gcdr(a,b)=gcdr(%d,%d)=%d\n", a, b, gcdr(a,b));
    
    return (EXIT_SUCCESS);
}

