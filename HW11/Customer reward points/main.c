/**
 * @file main.c
 * @author Jiwon Park (jwon0615@hanyang.ac.kr)
 * @brief Customer reward points program.
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021 Jiwon Park
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @typedef boolean
 * 
 */
typedef enum _boolean
{
    FALSE,
    TRUE
} boolean;

/**
 * @typedef Customer
 * @struct
 * @param id Customer's ID
 * @param name Customer Name
 * @param point Reward point
 * 
 */
typedef struct
{
    unsigned int id;
    char name[100];
    float point;
} Customer;

/**
 * @brief
 * functions for menu.
 *  
 */
int menu();
int __1_add();
int __2_display();
int __3_update();
int __4_exit();

/**
 * @brief 
 * functions for utility.
 */
double input_s();
Customer *find_by_ID(int id);

/**
 * @brief Customer Database,
 * @var number : number of customers.
 * 
 */
Customer DB[100];
int number = 0;

int main()
{
    /** if menu() returned FALSE, exit the program.**/
    while (TRUE)
        menu() ? 0 : exit(0);
}

/**
 * @brief 
 * \b MENU
 * function for main menu.
 * 
 * @return TRUE continue the program
 * @return FALSE exit the program
 */
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

/**
 * @brief 
 * \b ADD
 * function for add menu.
 * - add a new customer
 * 
 * @return int 
 */
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

    /** select Customer in DB **/
    Customer *selected = &DB[number];
    selected->id = _id;
    strcpy(selected->name, s);
    selected->point = rewards;
    number++;
    free(s);
}

/**
 * @brief 
 * \b DISPLAY
 * function for display menu.
 * - display all customer data
 * 
 * @return int - return code 200
 */
int __2_display()
{
    printf("\nID\tName\t\tReward_point\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d\t%s\t\t%f\n", DB[i].id, DB[i].name, DB[i].point);
    }

    return 200;
}

/**
 * @brief 
 * \b UPDATE
 * function for update menu.
 * 
 * @return int updated customer's ID
 * @see @typedef Customer
 */
int __3_update()
{

    printf("Enter the customer ID to edit the record :");
    int id = (int)input_s();

    /** 
     * @brief find the customer by ID.
     * @ref @fn find_by_ID()
     */
    Customer *selected = find_by_ID(id);

    /** if the customer is not exist, @return with code -1. */
    if (selected == NULL)
    {
        printf("There is no customer ID %d", id);
        return -1;
    }

    /** print customer data **/
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

    return id;
}

/**
 * @brief 
 * \b EXIT 
 * function for exit menu.
 * 
 * @return int return code 0.
 */
int __4_exit()
{
    printf("\nBye!");
    return 0;
}

/**
 * @brief For safe input.
 * get number as string and convert to double by using atof().
 * @see @fn atof()
 * @warning maximum length of input is 255(0xFF).
 * @return double - inputted number.
 */
double input_s()
{
    char *buff = (char *)malloc(0xFF * sizeof(char));
    fgets(buff, 0xFF, stdin);
    float inputted = atof(buff);
    free(buff);
    return inputted;
}

/**
 * @brief find customer by id from DB 
 * linear search.
 * @param id customer ID
 * @return Customer* a pointer to customer be found.
 */
Customer *find_by_ID(int id)
{
    for (int i = 0; i < number; i++)
    {
        if (DB[i].id == id)
            return &DB[i];
    }

    /** didn't found, NULL pointer will be returned. **/
    return NULL;
}