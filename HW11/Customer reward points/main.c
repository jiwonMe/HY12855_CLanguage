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
    unsigned int id;
    char name[100];
    float point;
} Customer;

//menu functions
int menu();
int __1_add();
int __2_display();
int __3_update();
int __4_exit();

//utils
double input_s();
Customer *find_by_ID(int id);

//database
Customer DB[100];
int number = 0;

int main()
{
    //if menu() returned FALSE, exit the program.
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
        return FALSE;
    default:
        break;
    }
    return TRUE;
}

int __1_add()
{

    printf("Enter ID: ");
    int _id = (int)input_s();

    printf("Enter Name: ");
    char *s = (char *)malloc(100 * sizeof(char));
    fscanf(stdin, "%s", s);
    getchar();

    printf("Enter Reward_point: ");
    float rewards = input_s();

    //select Customer memory in DB
    Customer *selected = &DB[number];
    selected->id = _id;
    strcpy(selected->name, s);
    selected->point = rewards;
    number++;
    free(s);
}

int __2_display()
{
    printf("\nID\tName\t\tReward_point\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d\t%s\t\t%f\n", DB[i].id, DB[i].name, DB[i].point);
    }

    return 200;
}

int __3_update()
{

    printf("Enter the customer ID to edit the record :");
    int id = (int)input_s();

    //find the customer by ID.
    Customer *selected = find_by_ID(id);

    //if the customer is not exist, return with code -1.
    if (selected == NULL)
    {
        printf("There is no customer ID %d", id);
        return -1;
    }

    //print customer data
    printf("\n"
           "ID : %d\n"
           "Name : %s\n"
           "Reward_point : %f\n",
           selected->id, selected->name, selected->point);

    printf("Enter new name : ");
    char *s = (char *)malloc(100 * sizeof(char));
    fscanf(stdin, "%s", s);
    getchar();

    printf("Enter new reward_point : ");
    float rewards = input_s();

    strcpy(selected->name, s);
    selected->point = rewards;

    free(s);

    //return the updated customer id
    return id;
}

int __4_exit()
{
    printf("\nBye!");
    return 0;
}

//for safe input
double input_s()
{
    char *buff = (char *)malloc(0xFF * sizeof(char));
    fgets(buff, 0xFF, stdin);
    float inputted = atof(buff);
    free(buff);
    return inputted;
}

//find by ID : linear search
Customer *find_by_ID(int id)
{
    for (int i = 0; i < number; i++)
    {
        if (DB[i].id == id)
            return &DB[i];
    }
    //if didn't find, return NULL
    return NULL;
}