/**
 * @file main.c
 * @author Jiwon Park (jwon0615@hanyang.ac.kr)
 * @brief Hanyang bus reservation
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
 * @brief Preprocess MACROS for different codes by OS.
 * seperate windows or unix-like OS.
 */

#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM_NAME "windows"
#elif defined(__unix__) || defined(__APPLE__) || defined(__linux__)
#define PLATFORM_NAME "unix"
#else
#define PLATFORM_NAME "unknown"
#endif

/**
 * @def MAX_LENGTH
 * @brief maximum length of strings
 * 
 */
#define MAX_LENGTH 20

/**
 * @typedef boolean
 * 
 */
typedef enum
{
    FALSE,
    TRUE
} boolean;

/**
 * @typedef Seat
 * structure for Seat information.
 * @a reserved boolean, mark the seat was reserved.
 * @a userID[MAX_LENGTH] char array, userID whose reserved.
 * 
 */
typedef struct
{
    boolean reserved;
    char userID[MAX_LENGTH];
} Seat;

/**
 * @typedef User
 * structure for user information.
 * @a first_name
 * @a last_name
 * @a userID
 * @a password
 * 
 */
typedef struct
{
    char first_name[MAX_LENGTH];
    char last_name[MAX_LENGTH];
    char userID[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

//requirements
boolean main_menu();
void registration();
void login();
void seat_reservation();
void seat_cancelation();
void back_to_main();
void quit();

//add
boolean isRegistered(User user);
int reservation(User user);
void display_seats();
void press_any_key_to_continue();
//for safe input
int input_s();

/**
 * @brief bus seat reservation database.
 * 
 */
Seat seat[10][4] = {};

int main()
{
    while (TRUE)
        /** if menu() returned FALSE, exit the program.**/
        main_menu() ? 0 : exit(0);
}

/**
 * @brief 
 * main menu
 * @return TRUE to continue
 * @return FALSE to exit
 */
boolean main_menu()
{
    printf("\nWelcome to Hanyang bus reservation!\n\n\n"
           "1 : register!!!\n"
           "2 : login!!!\n"
           "3 : quit\n"
           "Enter your choice :\n");

    switch (input_s())
    {
    case 1:
        registration();
        break;
    case 2:
        login();
        break;
    case 3:
        quit();
        return FALSE;
    default:
        break;
    }
    return TRUE;
}

/**
 * @brief registration
 * - save as .csv format
 * 
 * @file login.txt
 * 
 */
void registration()
{
    FILE *log = fopen("login.txt", "a+");
    char **buffer = (char **)malloc(4 * sizeof(char *)); //input buffer

    for (int i = 0; i < 4; i++)
        buffer[i] = (char *)malloc(MAX_LENGTH * sizeof(char)); //allocating memory

    printf("Enter first name : ");
    fgets(buffer[0], MAX_LENGTH, stdin);
    printf("Enter last name : ");
    fgets(buffer[1], MAX_LENGTH, stdin);
    printf("Enter your Username : ");
    fgets(buffer[2], MAX_LENGTH, stdin);
    printf("Enter your password : ");
    fgets(buffer[3], MAX_LENGTH, stdin);

    for (char **ptr = buffer; ptr < buffer + 4; ptr++)
    {
        (*ptr)[strlen(*ptr) - 1] = '\0';
        fprintf(log, "%s, ", *ptr);
    }
    fprintf(log, "\n");
    fclose(log);

    printf("You are successfully registered!!\n");
    printf("Your UserId is %s and your password is %s\n", buffer[2], buffer[3]);
    printf("Now login with your username and password!!\n");
    back_to_main();

    /** free the memories **/
    for (char **ptr = buffer; ptr < buffer + 4; ptr++)
        free(*ptr);
    free(buffer);
}

/**
 * @brief function for login menu.
 * @if login successed, start reservation.
 * @ref @fn reservation();
 * TODO: encryption for password
 */
void login()
{
    User user;

    printf("\nUserID : ");
    gets(user.userID);
    char *line_p;
    if ((line_p = strchr(user.userID, '\n')) != NULL)
        *line_p = '\0';

    printf("\nPassword : ");
    gets(user.password);
    if ((line_p = strchr(user.userID, '\n')) != NULL)
        *line_p = '\0';

    if (isRegistered(user))
    {
        printf("You are successfully logged in, welcome :-)\n\n");
        while (TRUE)
        {
            if (!reservation(user))
                break;
        }
    }
    else
    {
        printf("\033[0;31m");
        printf("\nYour UserID or password is incorrect, please try again :-(\n");
        printf("\033[0m");
        back_to_main();
    }
}

void quit()
{
    printf("Thank you for your registration !!");
}

void back_to_main()
{
    press_any_key_to_continue();
}

/**
 * press any key to continue
 */
void press_any_key_to_continue()
{
    //implementation of 'press any key to continue' by platform.
    printf("Press any key to continue...\n");
    if (strcmp(PLATFORM_NAME, "windows") == 0)
        system("PAUSE");
    else if (strcmp(PLATFORM_NAME, "unix") == 0)
        system("read -n 1 -s -r");
    else
        getchar();
}

boolean isRegistered(User user)
{
    FILE *log = fopen("login.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    //parse line by line
    while ((read = getline(&line, &len, log)) != -1)
    {
        User temp;
        char *buff = strtok(line, ", ");
        buff = strtok(NULL, ", ");
        buff = strtok(NULL, ", ");
        strncpy(temp.userID, buff, sizeof(buff));
        buff = strtok(NULL, ", ");
        strncpy(temp.password, buff, sizeof(buff));

        printf("", strcmp(temp.userID, user.userID), strcmp(temp.password, user.password));

        if ((strcmp(temp.userID, user.userID) == 0) && (strcmp(temp.password, user.password) == 0))
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief reservation menu.
 * 1. reserve @ref seat_reservation(User).
 * 2. cancel @ref seat_cancelation(User).
 * 
 * @param user user information who reservating.
 * @return TRUE continue reservation menu.
 * @return FALSE exit reservation menu.
 */
int reservation(User user)
{
    printf("\nReservation Menu\n\n");
    display_seats();
    printf("1 : reserve a seat\n"
           "2 : cancel a seat\n"
           "3 : Main Menu\n"
           "Enter your choice :\n");

    switch (input_s())
    {
    case 1:
        seat_reservation(user);
        break;
    case 2:
        seat_cancelation(user);
        break;
    /**
     * @brief Main menu or wrong input,
     * return FALSE to go Main menu.
     */
    default:
        return FALSE;
    }
    return TRUE;
}

/**
 * @brief display bus seat reservation status.
 * 
 */
void display_seats()
{
    printf("\tSeats\n"
           "\tWindow\tAisle\tAisle\tWindow\n"
           "\t%4d\t%4d\t%4d\t%4d\n",
           1, 2, 3, 4);
    for (int i = 0; i < 10; i++)
    {
        printf("Row %d:\t%4d\t%4d\t%4d\t%4d\n", i + 1, seat[i][0].reserved, seat[i][1].reserved, seat[i][2].reserved, seat[i][3].reserved);
    }
}

/**
 * @brief reservating the bus seat.
 * can reserve several seats.
 * @param user 
 * TODO: exception for reservating the seat already reserved.
 */
void seat_reservation(User user)
{
    printf("How many seats do you want to reserve?\n");
    int n = input_s();
    display_seats();
    for (int i = 0; i < n; i++)
    {
        printf("Which row do you want to choose? : ");
        int row = input_s();
        printf("Which seat do you want to select? : ");
        int col = input_s();

        Seat *seat_selected = &seat[row - 1][col - 1];

        seat_selected->reserved = TRUE;
        strcpy(seat_selected->userID, user.userID);
    }
    printf("Reservation complete, thank you :-)\n");
    press_any_key_to_continue();
}

/**
 * @brief 
 * cancelation the reserved bus seat.
 * @param user 
 */
void seat_cancelation(User user)
{
    display_seats();
    printf("Which row do you want to cancel? : ");
    int row = input_s();
    printf("Which column do you want to cancel? :");
    int col = input_s();

    Seat *seat_selected = &seat[row - 1][col - 1];

    if (strcmp(user.userID, seat_selected->userID) == 0)
    {
        seat_selected->reserved = FALSE;
        strcpy(seat_selected->userID, NULL);

        printf("Your Seat is Cancelled\n");
    }
    else
    {
        printf("[CAUTION] It's not your seat!\n");
    }
}

/**
 * @brief For safe input.
 * get number as string and convert to int using atoi().
 * @see @fn atoi()
 * @warning maximum length of input is 255(0xFF).
 * @return int - inputted number.
 */
int input_s()
{
    char *buff = (char *)malloc(sizeof(char));
    fgets(buff, 0xFF, stdin);
    return atoi(buff);
}