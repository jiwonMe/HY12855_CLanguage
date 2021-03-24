#include <stdio.h>
int main()
{
    int a= 10, b=5;
    int num;

    num = (a/b)*2;
    printf("num= %d\n", num); //output: (10 / 5 ) * 2 = 4

    num = (++a) * 3;
    printf("num= %d\n", num); //output: (10 + 1) * 3 = 33
    
	//@CAUTION: the value of a was changed by ++ operator.
    num = (a > b) && (a != 5);
    printf("num= %d\n", num); //output: (11 > 1) AND (11 != 5) <=> TRUE(1)

    num = (a % 3) == 0;
    printf("num= %d\n", num); //output: (11 % 3) == 0 <=> FALSE(0)

    return 0;
}