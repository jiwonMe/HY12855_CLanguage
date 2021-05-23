#include <stdio.h>

int main(){
    int arr[5]={1,2,3,4,5};
    for(int i=0; i<5; i++){
        printf("%d value in the ith array : %d\n", i, *(arr+i)+2);
        // 'arr' is a pointer for 'arr[0]', 'arr+i' is a pointer ith element in the array.
        // *(arr+i) is the value at 'arr+i'
    }
}