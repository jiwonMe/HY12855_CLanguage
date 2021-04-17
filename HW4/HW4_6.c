#include <stdio.h>

int main(){
    char c;
    printf("Enter any character: ");
    scanf("%c", &c);

    //using ascii code like (5), 
    // but if c is alphabet, (c<91&c>64)|(c<123&c>96) will be 1 and 2*(c<58&c>47) will be 0.
    // and if c is digit, (c<91&c>64)|(c<123&c>96) will be 0 and 2*(c<58&c>47) will be 2.
    // other case, both will be 0.
    switch(
        (c<91&c>64)|(c<123&c>96)+2*(c<58&c>47)
    ){
        case 1: printf("'%c' is alphabet.", c); break;
        case 2: printf("'%c' is digit.", c); break;
        default: printf("'%c' is special character.", c);
    }
}