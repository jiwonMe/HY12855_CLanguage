#include <stdio.h>

int main(){
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Number is ");

    //if n is positive, n>0 will be 1, n<0 will be 0
    //if n is negative, n>0 will be 0, n<0 will be 1
    //if n is zero, n>0 and n<0 will be 0.
    switch((n>0)-(n<0)){
        case 1: printf("POSITIVE"); break;
        case 0: printf("ZERO"); break;
        case -1: printf("NEGATIVE"); break;
    }
}