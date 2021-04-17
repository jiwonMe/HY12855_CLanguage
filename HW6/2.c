#include <stdio.h>

int get_max(int a, int b){
    if(a>b) return a; //if a is larger, return a.
    else return b;
}

int get_min(int a, int b){
    if(a>b) return b; //if a is larger, return b.
    else return a;
}
int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a, &b);
    printf("Maximum = %d\n",get_max(a,b));
    printf("Minimum = %d", get_min(a,b));
}