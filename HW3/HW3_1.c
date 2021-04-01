#include <stdio.h>

int main(){

    //declare
    int int_;
    long long_;
    long long llong_;
    double double_;
    long double ldouble_;

    //print output
    printf("Demonstrate the working of keyword long\n");
    printf("----------------------------------------\n");
    printf("The size of int = %d bytes\n", (int)sizeof(int_)); //type casting
    printf("The size of long = %d bytes\n", (int)sizeof(long_));
    printf("The size of long long = %d bytes\n", (int)sizeof(llong_));
    printf("The size of double = %d bytes\n", (int)sizeof(double_));
    printf("The size of long double = %d bytes\n", (int)sizeof(ldouble_));
}