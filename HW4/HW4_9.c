#include <stdio.h>

int main(){
    int a,b,c;
    printf("Enter three angles of triangles:\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("Triangle is ");
    if(a+b+c!=180) printf("not ");
    printf("valid.");
}