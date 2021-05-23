#include <stdio.h>
#define MAX_SIZE 100

//swap
void swap(int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//selection_sort: ascending
void selection_sort(int* arr, int size){
    if(size==0) return;
    int m=0;
    for(int i=0; i<size; i++){
        if(arr[m]>arr[i]) m=i; 
    }
    swap(&arr[0],&arr[m]);
    selection_sort(arr+1, size-1);
    return;
}

int main(){
    int arr[MAX_SIZE];
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements in array: ");
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    selection_sort(arr,size);
    printf("Elements of array in ascending order: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}