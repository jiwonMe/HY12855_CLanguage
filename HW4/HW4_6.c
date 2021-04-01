#include <stdio.h>

int main(){
    char c;
    printf("Enter any character: ");
    scanf("%c", &c);

    switch(
        (c<91&c>64)|(c<123&c>96)+2*(c<58&c>47)
    ){
        case 1: printf("'%c' is alphabet.", c); break;
        case 2: printf("'%c' is digit.", c); break;
        default: printf("'%c' is special character.", c);
    }
}