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
 * @def MAX_BUFFER
 * @brief maximum length of input buffer
 */
#define MAX_LENGTH 20
#define MAX_BUFFER 0xFF

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
    printf("\n\033[0;34mWelcome to Hanyang bus reservation!\033[0m\n\n\n"
           "\033[0;33m1 : \033[0mregister!!!\n"
           "\033[0;33m2 : \033[0mlogin!!!\n"
           "\033[0;33m3 : \033[0mquit\n"
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
    /** line break **/
    fprintf(log, "\n");
    fclose(log);

    printf("\033[0;32m\nYou are successfully registered!!\033[0m\n\n");
    printf("Your UserId is \033[0;33m%s\033[0m and your password is \033[0;33m%s\033[0m\n", buffer[2], buffer[3]);
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
    fscanf(stdin, "%s", user.userID);

    printf("Password : ");
    fscanf(stdin, "%s", user.password);

    if (isRegistered(user))
    {
        printf("\033[0;32m\nYou are successfully logged in, welcome :-)\033[0m\n\n");
        getchar();
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
        getchar(); //make buffer empty
        press_any_key_to_continue();
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

/**
 * @brief get user data was registered.
 * 
 * @file login.txt
 * @param user 
 * @return TRUE registered.
 * @return FALSE not registered
 */
boolean isRegistered(User user)
{
    FILE *log = fopen("login.txt", "r");
    char line[MAX_BUFFER];

    /** parse line by line **/
    while (fgets(line, sizeof(line), log) != NULL)
    {
        User temp;

        /** delimiter : ", " 
         * @see strtok();
         */
        char *buff = strtok(line, ", ");
        buff = strtok(NULL, ", ");
        buff = strtok(NULL, ", ");
        strncpy(temp.userID, buff, sizeof(temp.userID));
        buff = strtok(NULL, ", ");
        strncpy(temp.password, buff, sizeof(temp.password));

        /** compare the userID and password **/
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
    printf(""
           "\033[0;33m1 :\033[0m reserve a seat\n"
           "\033[0;33m2 :\033[0m cancel a seat\n"
           "\033[0;33m3 :\033[0m Main Menu\n"
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
    /** Header **/
    printf("\033[0;33m"
           "\tSeats\n"
           "\tWindow\tAisle\tAisle\tWindow\n"
           "\t%4d\t%4d\t%4d\t%4d\n"
           "\033[0m",
           1, 2, 3, 4);

    /** print rows line by line **/
    for (int i = 0; i < 10; i++)
    {
        printf("\033[0;33mRow %d:\033[0m", i + 1);
        for (int j = 0; j < 4; j++)
        {
            printf("%s\t%4d\033[0m", seat[i][j].reserved ? "\033[0;34m" : "", seat[i][j].reserved);
        }
        printf("\n");
    }
    printf("\n\n");
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

    /** select seats **/
    for (int i = 0; i < n; i++)
    {
        printf("Which \033[0;33mrow\033[0m do you want to choose? : ");
        int row = input_s();
        printf("Which \033[0;33mseat\033[0m do you want to select? : ");
        int col = input_s();

        Seat *seat_selected = &seat[row - 1][col - 1];

        seat_selected->reserved = TRUE;
        strcpy(seat_selected->userID, user.userID);
    }
    printf("\033[0;32mReservation complete, thank you :-)\n\033[0m");
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
    printf("Which \033[0;33mrow\033[0m do you want to cancel? : ");
    int row = input_s();
    printf("Which \033[0;33mcolumn\033[0m do you want to cancel? : ");
    int col = input_s();

    Seat *seat_selected = &seat[row - 1][col - 1];

    /** @if selected seat is user's seat **/
    if (strcmp(user.userID, seat_selected->userID) == 0)
    {
        seat_selected->reserved = FALSE;
        strcpy(seat_selected->userID, "");

        printf("\033[0;32mYour Seat is Cancelled\033[0m\n");
    }
    /** 
     * @exception for user trying to cancel the seat is not the user's.
     */
    else
    {
        printf("\033[0;31m");
        printf("[ERROR] It's not your seat!\n");
        printf("\033[0m\n");
    }
    press_any_key_to_continue();
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