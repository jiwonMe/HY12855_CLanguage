#include <stdio.h>
#define PI 3.14 //declare PI=3.14

int main(){
    int r, h, v;

    printf("Enter radius of rectangle: ");
    scanf("%d", &r);
    printf("Enter height of rectangle: ");
    scanf("%d", &h);
    printf("Volume of cone = %.6f\n", (float)(PI*h*r*r)/3); //calculate Volume of cone. type cast
}