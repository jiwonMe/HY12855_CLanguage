#include <stdio.h>
#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter %d elements in the array :",size);

    //get values to array
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    printf("Elements in array are: ");

    //print all elements in array
    for(int i=0; i<size; i++){
        printf("%d, ",arr[i]);
    }
    return 0;
}