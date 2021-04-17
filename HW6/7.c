#include <stdio.h>

int factorial(int n){
    if(n==0) return 1; //exit condition: 0! = 1
    return n*factorial(n-1); //recursion
}

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("%d", factorial(n));
}