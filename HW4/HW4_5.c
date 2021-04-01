#include <stdio.h>

int main(){
    char c;
    printf("Enter any character: ");
    scanf("%c", &c);

    //using ascii code
    if((c<91&c>64)|(c<123&c>96)) printf("'%c' is alphabet.", c);
    else if(c<58&c>47) printf("'%c' is digit.", c);
    else printf("'%c' is special character.", c);
}