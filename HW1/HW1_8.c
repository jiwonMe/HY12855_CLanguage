#include <stdio.h>

int main(){
    int n;
    printf("Enter number of columns:");
    scanf("%d", &n);
    //upper pyramid
    for(int i=1; i<n; i++){
        for(int j=1; j<=i; j++){
            printf("*");
        }
        puts("");
    }
    //lower pyramid
    for(int i=n; i>0; i--){
        for(int j=1; j<=i; j++){
            printf("*");
        }
        puts("");
    }
}