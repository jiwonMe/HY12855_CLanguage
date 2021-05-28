#include <stdio.h>
typedef unsigned char byte_t;

typedef union
{
    unsigned long hex;
    float var;
} MyUnion;

typedef struct
{
    MyUnion id;
    MyUnion gpa;
} Student;

int main()
{
    // Student student[2] = {{1, 2.9}, {2, 3.7}};
    Student student[2] = {{0x00000001, 0x4039999a}, {0x00000002, 0x406ccccd}};
    printf("First Student ID = %u and GPA = %f\n", student[0].id, student[0].gpa.var);
    printf("Second Student ID = %d and GPA = %f\n", student[1].id, student[1].gpa.var);
}