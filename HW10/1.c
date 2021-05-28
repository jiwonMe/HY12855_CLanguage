#include <stdio.h>

int main()
{
    //create and declare and Initialize
    struct Person
    {
        char *name;
        int id;
        float salary;
    } person = {"Henry", 1112, 95743};

    printf("Name: %s\n", person.name);
    printf("Id: %d\n", person.id);
    printf("Salary: %f\n", person.salary);
}