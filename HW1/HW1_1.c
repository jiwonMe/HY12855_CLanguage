#include <stdio.h>

int main(){

    int h,m,s,n=43267; //hours, minutes, seconds

    h=n/3600;   //1 hour is 3600 seconds
    m=(n%3600)/60; 
    s=n%60;

    printf("%d seconds is %d hours %d minutes %d seconds",n,h,m,s);
}