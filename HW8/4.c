#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

//swap function (call by reference)
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//swap every elements
void arraySwap(int a[], int b[], int n){
    for(int i=0; i<n; i++){
        swap(a+i,b+i);
    }
}

int main(){
    unsigned int size = 0;

    //get size
    do{
        if(size>MAX_SIZE) printf("[ERROR!] MAX_SIZE defined as 100.\n");
        //get size of array
        printf("Enter size of array: ");
        scanf("%d", &size);
    }
    while(size>MAX_SIZE);

    //declare arrays
    int* s = (int*)malloc(sizeof(int)*size);
    int* d = (int*)malloc(sizeof(int)*size);

    printf("Enter %d elements in source array: ", size);
    for(int i=0; i<size; i++) scanf("%d", s+i);
    printf("Enter %d elements in destination array: ", size);
    for(int i=0; i<size; i++) scanf("%d", d+i);

    printf("\n\n");

    printf("Source array before swapping: ");
    for(int i=0; i<size; i++) printf("%d, ", s[i]);
    puts("");
    printf("Destination array before swapping: ");
    for(int i=0; i<size; i++) printf("%d, ", d[i]);

    printf("\n\n");

    arraySwap(s,d,size);

    printf("Source array after swapping: ");
    for(int i=0; i<size; i++) printf("%d, ", s[i]);
    puts("");
    printf("Destination array after swapping: ");
    for(int i=0; i<size; i++) printf("%d, ", d[i]);

}

