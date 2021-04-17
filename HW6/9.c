#include <stdio.h>

int fib(int n){
    if(n==0) return 0; //exit condition: fib(0)=0
    if(n==1) return 1; //exit condition: fib(1)=1
    return fib(n-1)+fib(n-2); //recursion
}

int main(){
    int n;
    printf("Enter any number to find nth fibonacci term:");
    scanf("%d", &n);
    printf("%d fibonacci term is %d", n, fib(n));
}