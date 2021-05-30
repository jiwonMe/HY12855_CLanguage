#include <stdio.h>

/// @struct for Birthday data
typedef struct Birth
{
    int day;
    int month;
    int year;
} Birth;

/// @struct for Person data. (nested)
typedef struct Person
{
    char name[100];
    int roll_number;
    Birth birth;
} Person;

int main()
{
    ///@initialize person
    Person person;

    printf("Enter name: ");
    scanf("%s", person.name);
    printf("Enter roll number: ");
    scanf("%d", &person.roll_number);
    printf("Enter Date of Birth [DD MM YY] format: ");
    scanf("%02d %02d %04d", &person.birth.day, &person.birth.month, &person.birth.year);

    puts("");

    printf("Name : %s\n", person.name);
    printf("RollNo : %d\n", person.roll_number);
    printf("Date of birth : %02d/%02d/%04d\n", person.birth.day, person.birth.month, person.birth.year);
}