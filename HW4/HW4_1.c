#include <stdio.h>

int main(){
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Number is ");
    if(n>0) printf("POSITIVE");
    else if(n<0) printf("NEGATIVE");
    else printf("ZERO");
}