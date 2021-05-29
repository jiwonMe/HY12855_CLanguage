/**
 * Customer reward points program.
 * 2021 Jiwon Park
 * https://github.com/jiwonMe/HY12855_CLanguage
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define boolean type
typedef enum _boolean
{
    FALSE,
    TRUE
} boolean;

typedef struct
{
    int id;
    char name[100];
    float point;
} Customer;

int menu();
int __1_add();
int __2_display();
int __3_update();
int __4_exit();

double input_s();

Customer *find_by_ID(int id);

Customer DB[100];
int number = 0;

int main()
{
    while (TRUE)
        menu() ? 0 : exit(0);
}

int menu()
{
    printf("\n"
           "1: Add\n"
           "2: Display\n"
           "3: Update\n"
           "4: Exit\n");
    switch ((int)input_s())
    {
    case 1:
        __1_add();
        break;
    case 2:
        __2_display();
        break;
    case 3:
        __3_update();
        break;
    case 4:
        __4_exit();
        return 0;
    default:
        break;
    }
    return 1;
}

int __1_add()
{

    printf("Enter ID: ");
    int _id = (int)input_s();
    printf("Enter Name: ");
    char *s = (char *)malloc(100 * sizeof(char));
    gets(s);
    printf("Enter Reward_point: ");
    float rewards = input_s();

    Customer *selected = &DB[number];
    selected->id = _id;
    strcpy(selected->name, s);
    selected->point = rewards;
    number++;
}

int __2_display()
{
    printf("ID\tName\tReward_point\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d\t\t%s\t%f\n", DB[i].id, DB[i].name, DB[i].point);
    }
}

int __3_update()
{
    printf("Enter the customer ID to edit the record :");
    int id = (int)input_s();

    Customer *selected = find_by_ID(id);
    if (selected == NULL)
    {
        printf("There is no customer ID %d", id);
        return -1;
    }

    printf("ID : %d\n"
           "Name : %s\n"
           "Reward_point : %f\n",
           selected->id, selected->name, selected->point);
    printf("Enter new name : ");
    char *s = (char *)malloc(100 * sizeof(char));
    gets(s);
    printf("Enter new reward_point : ");
    float rewards = input_s();

    strcpy(selected->name, s);
    selected->point = rewards;
}

int __4_exit()
{
    printf("\nBye!");
    return 0;
}

double input_s()
{
    char *buff = (char *)malloc(0xFF * sizeof(char));
    fgets(buff, 0xFF, stdin);
    return atof(buff);
}

Customer *find_by_ID(int id)
{
    for (int i = 0; i < number; i++)
    {
        if (DB[i].id == id)
            return &DB[i];
    }
    return NULL;
}