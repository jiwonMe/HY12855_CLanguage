#include <stdio.h>

//XOR Swap Algorithm

int main(){
    int num1, num2;
    printf("Enter any two numbers: ");
    scanf("%d, %d", &num1, &num2);
    printf("Original value of num1 = %d\n", num1); //num1 <- A
    printf("Original value of num2 = %d\n", num2); //num2 <- B
    num1=num1^num2; //num1 <- A XOR B
    num2=num2^num1; //num2 <- B XOR (A XOR B) = A
    num1=num1^num2; //num1 <- (A XOR B) XOR A = B
    printf("Num1 after swapping = %d\n", num1);
    printf("Num2 after swapping = %d\n", num2);

}