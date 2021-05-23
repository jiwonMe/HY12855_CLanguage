#include <stdio.h>
#define MAX 100

int c[MAX][MAX];

int combination(int n, int k)
{
    if (c[n][k])
        return c[n][k];
    if (n == 0 || k == 0 || n == k)
        return 1;
    return c[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
}

void print_pascal(int n)
{
    if (n < 0)
        return;
    print_pascal(n - 1);
    for (int k = 0; k <= n; k++)
        printf("\t%d", combination(n, k));
    puts("");
}

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    print_pascal(n);
}