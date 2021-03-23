#include <stdio.h>

int main(){
    char s, r; //s: first char, r: last char
    printf("_ A R _\n");
    printf("Enter any character to make a word that have meaning\n");
    printf("enter first and last character:\n");
    scanf("%c %c", &s, &r);
    printf("This is your word %c A R %c",s, r);
}