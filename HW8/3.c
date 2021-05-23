#include <stdio.h>

//call by reference
void swap(int* num1, int* num2){

    //swap logic
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;

    //print status in function
    printf("After swapping in swap function nValue of num1 = %d\n", *num1);
    printf("Value of num2 = %d\n\n", *num2);
}

int main(){
    printf("Enter two numbers: ");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("Before swapping in main nValue of num1 = %d\n", num1);
    printf("Value of num2 = %d\n\n", num2);

    swap(&num1, &num2);

    printf("After swapping in main nValue of num1 = %d\n", num1);
    printf("Value of num2 = %d\n\n", num2);
}