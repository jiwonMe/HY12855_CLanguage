#include <stdio.h>

int isEqual(int P[], int Q[])
{
    for (int i = 0; i < 3 * 3; i++)
        if (P[i] != Q[i])
            return 0;
    return 1;
}

int main()
{
    int A[3 * 3], B[3 * 3];

    printf("Enter elements in matrix A of size 3x3:\n");
    for (int i = 0; i < 3 * 3; i++)
        scanf("%d", &A[i]);
    printf("Enter elements in matrix B of size 3x3:\n");
    for (int i = 0; i < 3 * 3; i++)
        scanf("%d", &B[i]);

    printf("Matrix A is %sequal to Matrix B", isEqual(A, B) ? "" : "not ");
}