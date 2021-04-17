/*
    no global variable
*/

#include <stdio.h>

void swap(int* x, int*y){
    int tmp= *x;
    *x = *y;
    *y = tmp;
    return;
}

int main(){
    int x, y;
    printf("Enter Value of x\n");
    scanf("%d", &x);
    printf("Enter Value of y\n");
    scanf("%d", &y);
    swap(&x, &y); //call by reference
    printf("After Swapping: x = %d,y = %d", x, y);
}