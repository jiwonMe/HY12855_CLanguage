#include <stdio.h>

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n); //input n
    for(int i=1; i<=n; i++){ //lines
        for(int j=1; j<=i; j++){ //numbers in each line
            printf("%d",j);
        }
        puts(""); //line break
    }
}