#include <stdio.h>
#define MAX_SIZE 100

int main(){
    int arr[MAX_SIZE];
    int size, count_even=0; //number of odd is same as 'the number of all elements in array' - 'number of even elements'
    printf("Enter size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements in array: ", size);

    ///get values to array
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
        if(arr[i]%2==0) count_even++;
    }
    printf("Total even elements: %d\n", count_even);
    printf("Total odd elements: %d", size-count_even);

}