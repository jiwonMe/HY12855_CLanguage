#include <stdio.h>

int main(){
    int a=0xAF, b=0XB5;
    printf("%x\n",a&b);
    printf("%x\n",a|b);
    printf("%x\n",a^b);
    printf("%x\n",~a);
    printf("%x\n",a<<2);
    printf("%x\n",a&a);
}