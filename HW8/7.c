#include <stdio.h>
#define MAX_SIZE 100

//index started at 0
//val: value to find, arr: array, size: size of arr[].

int find_in(int val, int* arr, int size){
    for(int* ptr=arr; ptr<arr+size; ptr++){
        if(*ptr==val) return ptr-arr;
    }
    return -1; //value is not in the array
}

int main(){
    unsigned int size = 0;
    int arr[MAX_SIZE], val;

    //get size
    do{
        if(size>MAX_SIZE) printf("[ERROR!] MAX_SIZE defined as 100.\n");
        //get size of array
        printf("Enter size of array: ");
        scanf("%d", &size);
    }
    while(size>MAX_SIZE);

    printf("Enter elements in array: ");
    for(int i=0; i<size; i++) scanf("%d", arr+i);

    printf("Enter elements to search: ");
    scanf("%d", &val);

    printf("%d is found at %d position", val, find_in(val, arr, size)+1);
}