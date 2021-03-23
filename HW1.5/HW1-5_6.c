#include <stdio.h>

int main(){
    int n;
    printf("Enter a dollar amount: ");
    scanf("%d", &n);
    printf("$20 bills: %d\n",n/20); //how many $20 bills in n
    printf("$10 bills: %d\n",(n/10)%2); //how many $10 bills in n except $20 bills
    printf("$5 bills: %d\n",(n%10)/5); //0 or 1
    printf("$1 bills: %d\n",n%10); //etc
}