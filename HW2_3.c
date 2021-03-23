#include <stdio.h>

int main(){
    int a=0xAF; //  1010 1111
    int b=0XB5; //  1011 0101
    printf("%x\n",a&b); 
    printf("%x\n",a|b);
    printf("%x\n",a^b);
    printf("%x\n",~a);
    printf("%x\n",a<<2);
    printf("%x\n",b>>3);
}