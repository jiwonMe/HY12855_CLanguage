#include <stdio.h>

float npow(float x, int n){ //x is the base, n is the exponent
    if(n==0) return 1;  //exit condition
    return x*npow(x,n-1); //recursion
}

int main(){
    float base;
    int exp;
    printf("Enter base: ");
    scanf("%f", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);
    printf("%.02f ^ %d = %.06f",base, exp, npow(base,exp));
}