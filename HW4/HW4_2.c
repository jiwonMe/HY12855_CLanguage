#include <stdio.h>

int main(){
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Number is ");

    switch((n>0)-(n<0)){
        case 1: printf("POSITIVE"); break;
        case 0: printf("ZERO"); break;
        case -1: printf("NEGATIVE"); break;
    }
}