#include <stdio.h>

int main(){
    int n;
    printf("Print all even numbers till: ");
    scanf("%d", &n);
    printf("All even numbers from 1 to %d are:\n", n);
    for(int i=2; i<=n; i+=2){ //same logic as Q3.
        printf("%d\n",i);
    }
}