#include <stdio.h>
#define MAX_SIZE 100

int main(){
    unsigned int size = 0;
    int arr[100];
    //get size
    do{
        if(size>MAX_SIZE) printf("[ERROR!] MAX_SIZE defined as 100.\n");
        //get size of array
        printf("Enter size of array: ");
        scanf("%d", &size);
    }
    while(size>MAX_SIZE);

    printf("Enter elements in array: \n");
    for(int i=0; i<size; i++) scanf("%d", arr+i);
    
    printf("Array elements: ");
    for(int* ptr=arr; ptr<arr+size; ptr++)
        printf("%d, ", *ptr);
}