#include <stdio.h>
#define MAX_SIZE 100

void delete_by_position(int pos, int* arr, int size){
    for(int i=pos-1; i<size; i++){
        arr[i]=arr[i+1];
    }
    return;
}
int main(){
    int arr[MAX_SIZE];
    int size, pos;
    printf("Enter size of the array : ");
    scanf("%d", &size);
    printf("Enter elements in array : ");
    //input array
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    printf("Enter the element position to delete : ");
    scanf("%d", &pos);
    delete_by_position(3,arr,size);
    size--; //size decreased.
    printf("Elements of array after delete are : ");
    //print array
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}