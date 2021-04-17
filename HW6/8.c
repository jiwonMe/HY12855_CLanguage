#include <stdio.h>
// tip: register variable can't be global variable.
int main(){
    register int sum = 0, i; //register variable
    for(i=1; i<10e4; i++){
        sum+=i;
    }
    printf("%d", sum);
}