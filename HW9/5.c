#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;
    int *array;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    array = (int *)calloc(n, sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element\t%d: ", i + 1);
        scanf("%d", array + i);
    }
    printf("Array elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
        sum += array[i];
    }
    printf("\nSum of all elements: %d", sum);
}