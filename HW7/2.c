#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size, sum=0;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter %d elements in the array :",size);

    //get values to array and sum of all elements
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
        sum+=arr[i]; //add every elements in array to 'sum'
    }
    printf("Sum of all elements of array = %d", sum);
    return 0;
}