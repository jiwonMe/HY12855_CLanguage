#include <stdio.h>
#define MAX_SIZE 100

int main(){
    char str1[MAX_SIZE], str2[MAX_SIZE];
    char* s1 = str1;
    char* s2 = str2;

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    ///////////////////

    unsigned int len1 = 0;
    unsigned int len2 = 0;

    for(;*s1!='\0';s1++,len1++);
    for(;*s2!='\0';s2++,len2++);

    //s1 = str1 + len   : after the loop, value of s1 is str1 + len.
    s2 = str2;

    //copy str2 to str1's back
    for(;s1<str1+len1+len2; s1++,s2++){
        *(s1)=*(s2);
    }

    //end
    *(str1+len1+len2)='\0';

    ///////////////////
    
    printf("Concatenated string = %s", str1);

    return 0;
}