/*
it works in N<93.
- memoization
*/

#include <stdio.h>
typedef unsigned long long u64;

u64 d[100];

u64 fib(int n){
    if(n==0) return 0; //exit condition: fib(0)=0
    if(n==1) return 1; //exit condition: fib(1)=1
    if(d[n]) return d[n];
    return d[n]=fib(n-1)+fib(n-2); //recursion
}

int main(){
    int n;
    printf("Enter any number to find nth fibonacci term:");
    scanf("%d", &n);
    printf("%d fibonacci term is %llu", n, fib(n-1));
}