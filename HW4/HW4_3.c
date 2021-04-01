#include <stdio.h>

int main(){
    char c;
    printf("Enter any character: ");
    scanf("%c", &c);
    if(c<'a') c+=32; //if c is UpperCase, convert to lower.
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') printf("Vowel");
    else printf("Consonant");

}