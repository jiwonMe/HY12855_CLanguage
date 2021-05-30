#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @union for string
typedef union
{
    char str[100];
} String;

int main()
{
    /// @initialize String pointer
    String *s = (String *)malloc(sizeof(String));
    strcpy(s->str, "Henry Wong");

    printf("\n\n\n  Pointer : Show a pointer to union : ");
    printf("\n-----------------------------------------");
    printf("\n  %s %s\n\n", s->str, (*s).str);
    /// @free the memory
    free(s);
}