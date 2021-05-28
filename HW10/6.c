#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int id;
    float gpa;
} Student;

Student *makeStudent(int id, float gpa)
{
    Student *s = (Student *)malloc(sizeof(Student));
    s->id = id;
    s->gpa = gpa;
    return s;
}

int main()
{
    Student **students = (Student **)malloc(sizeof(Student *) * 2);

    students[0] = makeStudent(1, 2.9);
    students[1] = makeStudent(2, 3.7);

    printf("Student1: ID =%d\n", students[0]->id);
    printf("Student1: GPA=%f\n", students[0]->gpa);
    printf("Student2: ID =%d\n", students[1]->id);
    printf("Student2: GPA=%f\n", students[1]->gpa);
}