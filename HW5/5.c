#include <stdio.h>

int main(){
    int n, sum=0;
    printf("Enter upper limit: ");
    scanf("%d",&n);
    for(int i=2; i<=n; i+=2){ //add 2 in every steps.
        sum+=i;
    }
    printf("Sum of all even number between 1 to %d = %d", n, sum);
}