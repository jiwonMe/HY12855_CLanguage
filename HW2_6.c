#include <stdio.h>
int main()
{
    int a= 10, b=5;
    int num;

    num = (a/b)*2;
    printf("num= %d\n", num);

    num = (++a) * 3;
    printf("num= %d\n", num);

    num = (a > b) && (a != 5);
    printf("num= %d\n", num);

    num = (a % 3) == 0;
    printf("num= %d\n", num);

    return 0;
}