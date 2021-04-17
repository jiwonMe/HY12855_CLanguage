#include <stdio.h>

int dsum(int n){
    if(!n) return 0; //exit condition
    return n%10 + dsum(n/10); //recursion
}

int main(){
    int n;
    printf("Enter any number to find sum of digits: ");
    scanf("%d", &n);
    printf("Sum of digits of %d = %d",n,dsum(n));
}