#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int random;
    srand( time(NULL) );
    random = (rand()%39+11);

    printf("%d\n", random);

    return 0;
}