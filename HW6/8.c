#include <stdio.h>
typedef unsigned long long u64;

// tip: register variable can't be global variable.
int main(){
    register u64 sum = 0, i; //register variable
    for(i=1; i<10e4; i++){
        sum+=i;
    }
    printf("%llu", sum);
}