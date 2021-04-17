#include <stdio.h>

int main(){
    int n;
    printf("Enter number of columns:");
    scanf("%d", &n);
    for(int i=1; i<n; i++){ //n-1 size upper pyrimid
        for(int j=0; j<i; j++){
            printf("*");
        }
        puts("");
    }
    for(int i=n; i>0; i--){ //n size lower pyrimid
        for(int j=0; j<i; j++){
            printf("*");
        }
        puts("");
    }
}