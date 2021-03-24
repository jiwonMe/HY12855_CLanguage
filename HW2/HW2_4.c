#include <stdio.h>

int main(){
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Original number = %d (in decimal)\n", n);
    printf("Number after bits are flipped = %d (in decimal)", ~n);

}