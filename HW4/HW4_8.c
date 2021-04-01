#include <stdio.h>

int main(){
    int a,b,c,d,e;
    float marks;
    printf("Enter five subjects marks: ");
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("%.02f\n", marks=(a+b+c+d+e)/5.0);
    printf("Grade ");
    marks/=10;
    switch((int)marks){
        case 10:
        case 9: printf("A"); break;
        case 8: printf("B"); break;
        case 7: printf("C"); break;
        case 6: printf("D"); break;
        case 5: printf("E"); break;
        default: printf("F");
    }
}