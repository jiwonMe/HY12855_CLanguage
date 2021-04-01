#include <stdio.h>

int main(){
    float a, b, result;
    char c;
    printf("SIMPLE CALCULATOR\nEnter [number 1] [+ - * /] [number 2]\n");
    scanf("%f %c %f", &a, &c, &b);
    printf("%.02f %c %.02f = ", a, c, b);
    switch(c){
        case '+': result=a+b; break;
        case '-': result=a-b; break;
        case '*': result=a*b; break;
        case '/': result=a/b; break;
    }
    printf("%.02f", result);
}