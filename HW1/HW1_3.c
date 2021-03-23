#include <stdio.h>

int main(){

    int n;

    printf("Enter length in centimeter: ");
    scanf("%d", &n);
    printf("Length in Meter = %.02f m\n", (float)n/100); //1m = 100cm
    printf("Length in Kilometer = %.06f km", (float)n/100000); //1km = 100000cm
}