#include <stdio.h>
#include <stdlib.h>

int main(){
    int size, sum=0;
    printf("Input size of array: ");
    scanf("%d", &size);

    //declare array by malloc
    int* arr = (int*)malloc(size * sizeof(int));

    printf("Input %d number of elements in the array :\n",size);
    for(int i=0; i<size; i++){
        printf("element - %d : ",i);
        scanf("%d", arr+i);
        sum+=arr[i];
    }
    printf("Sum of Array : %d", sum);
}