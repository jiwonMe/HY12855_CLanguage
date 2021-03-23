#include <stdio.h>

int main(){
    float al[3], ir, mir, mp; //al[]: amount of loan, ir: interest rate, mir: monthly interest rate, mp: monthly payment
    printf("Enter amount of loan: ");
    scanf("%f", &al[0]);
    printf("Enter interest rate: ");
    scanf("%f", &ir);
    //convert the interest rate entered by the user to a percentage and divide it by 12.
    mir=ir/100/12; 
    printf("Enter monthly payment: ");
    scanf("%f", &mp);
    printf("balance remaining after first payment: $%.02f\n",al[1]=(al[0]*(1+mir))-mp);
    printf("balance remaining after second payment: $%.02f\n",al[2]=(al[1]*(1+mir))-mp);
}