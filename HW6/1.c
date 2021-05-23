#include <stdio.h>

double cube(double n){
    return n*n*n;
}

int main(){
    double p;
    printf("Enter any number: ");
    scanf("%lf", &p);
    printf("Cube of %0f is %.02f",p,cube(p)); //cube
}