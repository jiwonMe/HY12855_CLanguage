#include <stdio.h>

int main(){
    int y,m,d; //year, month, days
    printf("enter year (XXXX): ");
    scanf("%d",&y);
    printf("enter month (in number): ");
    scanf("%d", &m);
    printf("enter birth date: ");
    scanf("%d", &d);
    printf("I was born in %d %d %d\n",y,m,d);
}