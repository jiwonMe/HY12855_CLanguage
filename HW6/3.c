#include <stdio.h>

void print_oddity(int n){
    if(n%2) printf("The number is odd."); //if n%2 is 1, n is odd.
    else printf("The number is even.");
}

int main(){
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    print_oddity(n);
}