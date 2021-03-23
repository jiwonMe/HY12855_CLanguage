#include <stdio.h>

int main(){
    char c;

    printf("Our university missed one character\n");
    printf("H_NYANG UNIVERSITY\n");
    printf("please enter character to complete word:\n");
    scanf("%c", &c); //save char to c
    printf("Thank you for filling, this is your fulfill word\n");
    printf("H%cNYANG UNIVERSITY",c);
}