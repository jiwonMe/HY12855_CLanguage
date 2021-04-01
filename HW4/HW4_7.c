#include <stdio.h>

int main(){
    int a,b,c,d,e;
    float marks;
    printf("Enter five subjects marks: ");
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("%.02f\n", marks=(a+b+c+d+e)/5.0);
    printf("Grade ");
    marks/=10;
    if(marks>=9) printf("A");
    else if(marks>=8) printf("B");
    else if(marks>=7) printf("C");
    else if(marks>=6) printf("D");
    else if(marks>=5) printf("E");
    else printf("F");
}