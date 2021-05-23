#include <stdio.h>
#define MAX_SIZE 100

void insert_by_position(int ele, int pos, int* arr, int size){
    //push back one by one
    for(int i=size-1; i>=pos-1; i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=ele;
    return;
}

int main()
{
    int arr[MAX_SIZE];
    int size, ele, pos; //size, element to insert, insert position
    printf("Enter size of the array : ");
    scanf("%d", &size);
    printf("Enter elements in array : ");
    //array in
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    printf("Enter element to insert : ");
    scanf("%d", &ele);
    printf("Enter the element position : ");
    scanf("%d", &pos);
    insert_by_position(ele,pos,arr,size);
    size++; //size increased.
    printf("Array elements after insertion : ");
    //print array
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}
