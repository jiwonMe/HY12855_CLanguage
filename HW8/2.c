#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter any two numbers:");
    //using pointer variable
    int* a = (int*)malloc(sizeof(int));
    int* b = (int*)malloc(sizeof(int));
    scanf("%d %d", a, b);
    //a, b is pointer, *a, *b is the value.
    printf("Sum = %d", (*a)+(*b));
}