#include <stdio.h>

int main(){
    char c;
    printf("input an alphabet: ");
    scanf("%c", &c);
    printf("%d", (int)c); //convert char to int
}