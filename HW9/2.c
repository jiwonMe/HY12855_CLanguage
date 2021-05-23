#include <stdio.h>
#include <stdlib.h>

float largest(float *array)
{
    float result = INT32_MIN;
    for (float *ptr = array; ptr <= array + sizeof(array); ptr++)
        result = result > *ptr ? result : *ptr;
    return result;
}

int main()
{
    int n;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    float *numbers = (float *)calloc(n, sizeof(float));

    for (int i = 0; i < n; i++)
    {
        printf("Enter Number %d: ", i + 1);
        scanf("%f", numbers + i);
    }

    printf("Largest number = %.02f", largest(numbers));
}