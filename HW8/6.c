#include <stdio.h>
#define MAX_SIZE 100

int main(){
    char str[MAX_SIZE], reverse[MAX_SIZE];
    char *s = str;
    char *r = reverse;
    int len = 0;

    printf("Enter any string: ");
    gets(str);

    ///////////////////

    //get the length of str, reverse pointer(r) move to reverse[len]
    for(;*(s+len)!='\0';len++,r++);

    //reverse string
    for(s ;*s!='\0';s++,r--){
        *(r-1)=*s;
    }

    *(r+len)='\0'; //end of string

    ///////////////////

    printf("\nOriginal string = %s\n", str);
    printf("Reverse string = %s", reverse);

    return 0;
}