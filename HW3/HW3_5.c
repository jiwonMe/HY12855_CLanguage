#include <stdio.h>
#include <stdlib.h> //for using abs()

int main(){
    int num;
    printf("\n Input a positive or negative number :");
    scanf("%d",&num);
    printf(" The absolute value of the given number is : %d\n\n",abs(num));
    return 0;
}