#include <stdio.h>
#include <stdlib.h>

int main(){
    long int x, y;
    printf("\n Input 1st number (positive or negative) : ");
    scanf("%d", &x);
    printf(" Input 2nd number (positive or negative) : ");
    scanf("%d", &y);
    printf(" The absolute value of 1st number is : %d\n", labs(x));
    printf(" The absolute value of 2nd number is : %d\n\n", labs(y));

    return 0;
}