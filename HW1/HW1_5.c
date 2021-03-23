#include <stdio.h>

int main(){

    float h,w; //height, weight

    printf("Please input your Height: ");
    scanf("%f", &h);
    h=h/100; //convert unit cm to m.
    printf("Please input your Weight: ");
    scanf("%f", &w);
    printf("Your BMI index is %.02f", (float)w/(h*h));
}