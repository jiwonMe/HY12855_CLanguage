#include <stdio.h>

int main(){
    int a, b, c;
    printf("Enter score of three subjects:\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("Total = %.2f\n", (float)a+b+c);
    printf("Average = %.2f\n", (float)(a+b+c)/3);
    printf("Percentage = %.2f\n", (float)(a+b+c)/3);
}