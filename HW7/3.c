#include <stdio.h>
#define MAX_SIZE 1000

//swap: using pointer
void swap(int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//selection sort: descending
void selection_sort(int* arr, int size){
    if(size==0) return;
    int m=0;
    for(int i=0; i<size; i++){
        if(arr[m]<arr[i]) m=i; 
    }
    swap(&arr[0],&arr[m]);
    selection_sort(arr+1, size-1);
    return;
}

//get nth largest value from given array
int get_nth_largest(int n, int* arr, int size){
    selection_sort(arr, size);
    return arr[n-1];
}

int main(){
    int arr[MAX_SIZE];
    int size;
    printf("Enter size of the array (1-1000): ");
    scanf("%d", &size);
    printf("Enter elements in the array: ");

    //get values to array
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    printf("First largest = %d\n", get_nth_largest(1, arr, size));
    printf("Second largest = %d", get_nth_largest(2, arr, size));
}