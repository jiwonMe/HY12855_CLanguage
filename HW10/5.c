#include <stdio.h>
#include <stdlib.h>

///union
union Union
{
    char a[32];
    int b;
    int c;
} u;

///struct
struct Struct
{
    char a[32];
    int b;
    int c;
} s;

int main()
{
    printf("size of union = %u bytes\n", sizeof(u));
    printf("size of structure = %u bytes", sizeof(s));
}