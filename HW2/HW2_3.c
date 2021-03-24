#include <stdio.h>

int main(){
    int a=0xAF;         //              1010 1111
    int b=0XB5;         //              1011 0101
    printf("%x\n",a&b); // a5           1010 0101
    printf("%x\n",a|b); // bf           1011 1111
    printf("%x\n",a^b); // 1a           0001 1010
    printf("%x\n",~a);  // ffffff50     1111 1111 1111 1111 1111 1111 0101 0000
    printf("%x\n",a<<2);// 2bc          0010 1011 1100
    printf("%x\n",b>>3);// 16           0001 0110
}

