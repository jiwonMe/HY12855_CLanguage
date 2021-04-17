#include <stdio.h>

int main(){
    int n, cnt=0;
    printf("Enter any number: ");
    scanf("%d", &n);
    do{
        n/=10; //n divide by 10 := delete last digit.
        cnt++;
    }while(n);
    printf("Total digits: %d", cnt);
}