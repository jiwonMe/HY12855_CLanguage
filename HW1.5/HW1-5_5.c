#include <stdio.h>

int main(){
    int n,m,d,y;
    float p;
    printf("Enter item number: ");
    scanf("%d", &n);
    printf("Enter unit price: ");
    scanf("%f", &p);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&m,&d,&y);
    printf("Item\tUnit price\tPurchase date\n");
    printf("%d\t%.02f\t\t%02d/%02d/%d",n,p,m,d,y); //text aligned
}