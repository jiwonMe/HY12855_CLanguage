#include <stdio.h>

int main(){
    int a, b, c, d, e, f; //coefficients are integer.
    float x, y; //intersection's coordinate is in R^2 space.
    printf("input coefficient a,b,c:");
    scanf("%d, %d, %d", &a, &b, &c);
    printf("input coefficient d,e,f:");
    scanf("%d, %d, %d", &d, &e, &f);

    //calculate intersection.
    x=(float)(b*f-c*e)/(a*e-b*d);
    y=(float)(c*d-a*f)/(a*e-b*d);

    printf("The two linear equations are:\n");
    printf("%dx+%dy+%d=0\n%dx+%dy+%d=0\n",a,b,c,d,e,f);
    printf("Intersection point is <%.02f,%.02f>", x, y);
}