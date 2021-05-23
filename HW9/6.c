#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int smallest = INT32_MAX;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        smallest = smallest < tmp ? smallest : tmp;
    }
    printf("Smallest element is %d", smallest);
}