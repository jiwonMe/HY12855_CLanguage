#include <stdio.h>

int main(){
    printf("Alphabets from a - z are:");
    for(char c=97; c<123; c++){ //ascii code
        printf("\n%c",c);
    }
}