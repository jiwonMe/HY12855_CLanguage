#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *integer = (int *)malloc(sizeof(int));
    char *character = (char *)malloc(sizeof(char));
    float *floatNumber = (float *)malloc(sizeof(float));

    printf("Enter integer value: ");
    scanf("%d", integer);
    printf("Enter character value: ");
    scanf("%s", character);
    printf("Enter float value: ");
    scanf("%f", floatNumber);
    printf("Inputted value are: %d, %c, %.02f", *integer, *character, *floatNumber);

    free(integer);
    free(character);
    free(floatNumber);
}