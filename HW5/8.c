#include <stdio.h>

int main(){
    float n, sum=0;
    do{
        printf("Enter a number: ");
        scanf("%f",&n);
        sum+=n;
    }while(n!=0); //receive input until 0 was received.

    printf("Sum = %.2f", sum);
}