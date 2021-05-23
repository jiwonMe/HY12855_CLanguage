#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int limit;
    char *str;
    printf("Enter limit of the text: ");
    scanf("%d", &limit);

    str = (char *)malloc(limit * sizeof(char));
    printf("Enter text: ");
    getchar(); //buffer cleaning
    fgets(str, limit - 1, stdin);
    str[strlen(str) - 1] = '\0';
    printf("Inputted text is: %s", str);

    free(str);
}