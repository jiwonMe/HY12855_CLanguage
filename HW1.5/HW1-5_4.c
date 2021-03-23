#include <stdio.h>

int main(){
    float p=123.456;
    int q=89;


    printf("float value = %.6f\n", p);
    printf("int value = %d\n", q);
    printf("Product between float and int: %.6f\n",(float)p*q);
}