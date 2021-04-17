#include <stdio.h>

int main(){
    int n;
    printf("Enter number to print table: ");
    scanf("%d", &n);
    for(int i=1; i<=10; i++){ //1 to 10
        printf("%d * %d = %d\n", n, i, n*i);
    }
}