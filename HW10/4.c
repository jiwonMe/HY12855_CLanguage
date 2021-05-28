#include <stdio.h>

typedef union
{
    char str[100];
} String;

int main()
{
    String s = {"Henry Wong Henry Wong"};

    printf("\n\n\n  Pointer : Show a pointer to union : ");
    printf("\n-----------------------------------------");
    printf("\n  %s\n\n", s.str);
}