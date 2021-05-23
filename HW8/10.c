#include <stdio.h>
#define MAX_SIZE 100

int compare(char* str1, char* str2);

int main(){
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int res;

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    res = compare(str1, str2);

    if(res==0){
        printf("Both string are equal.");
    }
    else if (res < 0){
        printf("First string is lexicographically smaller than second.");
    }
    else{
        printf("First string is lexicographically greater than second.");
    }
    return 0;
}

int compare(char * str1, char * str2){

    ///////////////////

    //if character is same, check next. if not, end the loop.
    for(;(*str1==*str2)&&(*str1!='\0')&&(*str2!='\0');str1++,str2++)

    return *str2-*str1; //difference of ascii codes of two first diffrent characters.

    ///////////////////
}

