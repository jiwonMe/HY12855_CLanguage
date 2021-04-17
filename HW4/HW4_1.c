#include <stdio.h>

int main(){
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Number is ");
    if(n>0) printf("POSITIVE"); //if n>0
    else if(n<0) printf("NEGATIVE");// or n<0
    else printf("ZERO"); //other: only 0
}