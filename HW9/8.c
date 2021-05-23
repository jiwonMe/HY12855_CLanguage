#include <stdio.h>

int main()
{
    int A[3][3], B[3][3];

    printf("Enter elements in matrix A of size 3x3:\n");
    for (int i = 0; i < 3 * 3; i++)
        scanf("%d", *A + i);
    printf("Enter elements in matrix B of size 3x3:\n");
    for (int i = 0; i < 3 * 3; i++)
        scanf("%d", *B + i);
    printf("Sum of matrices A+B =\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", *(*(A + i) + j) + *(*(B + i) + j));
        }
        puts("");
    }
}