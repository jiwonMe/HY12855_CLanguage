#include <stdio.h>

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=n; j>i; j--){ //print spaces
            printf(" "); 
        }
        for(int j=1; j<=i; j++){ //print numbers
            printf("%d",j);
        }
        puts("");
    }
}