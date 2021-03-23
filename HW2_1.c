#include <stdio.h>

int main(){
    int n;
    printf("Enter 3-digit number : ");
    scanf("%d", &n);
    printf("1st digit : %d\n", n/100);
    printf("2nd digit : %d\n", (n%100)/10);
    printf("3rd digit : %d\n", n%10);
}