#include <stdio.h>

int main(){
    int n;
    printf("Print all even numbers till: ");
    scanf("%d", &n);
    printf("All even numbers from 1 to %d are:\n", n);
    int i=2;
    while(i<=n){
        printf("%d\n",i);
        i+=2; //add 2 in every steps.
    }
}