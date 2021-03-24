#include <stdio.h>

int main(){
    int apples = 1800,
        oranges = 450,
        bananas = 8500;
    
    float dpw = 0.00090; //dollar per won
    printf("total = %.02f dollars", (apples + oranges + bananas)*dpw);
}