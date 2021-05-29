/**
 * Hanyang bus reservation program.
 * 2021 Jiwon Park
 * https://github.com/jiwonMe/HY12855_CLanguage
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM_NAME "windows"
#elif defined(__unix__) || defined(__APPLE__) || defined(__linux__)
#define PLATFORM_NAME "unix"
#else
#define PLATFORM_NAME "unknown"
#endif

#define MAX_LENGTH 20

//define boolean type
typedef enum _boolean
{
    FALSE,
    TRUE
} boolean;

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
void reservation(User user);

int main()
{
    while (TRUE)
        //if FALSE is returned, quit program.
        main_menu() ? 0 : exit(0);
}

boolean main_menu()
{
    printf("\nWelcome to Hanyang bus reservation!\n\n\n");
    printf("1 : register!!!\n");
    printf("2 : login!!!\n");
    printf("3 : quit\n");
    printf("Enter your choice :\n");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch (choice)
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

void registration()
{
    FILE *log = fopen("login.txt", "a+");
    char **buffer = (char **)malloc(4 * sizeof(char *)); //input buffer

    for (int i = 0; i < 4; i++)
        buffer[i] = (char *)malloc(MAX_LENGTH * sizeof(char)); //allocating memory

    getchar(); //cleaning buffer

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
    fprintf(log, "\n"); //line break
    fclose(log);

    printf("You are successfully registered!!\n");
    printf("Your UserId is %s and your password is %s\n", buffer[2], buffer[3]);
    printf("Now login with your username and password!!\n");
    back_to_main();

    //free memory
    for (char **ptr = buffer; ptr < buffer + 4; ptr++)
        free(*ptr);
    free(buffer);
}

void login()
{
    User *user = (User *)malloc(sizeof(User));

    printf("\nUserID : ");
    fgets(user->userID, MAX_LENGTH, stdin);
    printf("\nPassword : ");
    fgets(user->password, MAX_LENGTH, stdin);

    if (isRegistered(*user))
        registration(user);
    else
        printf("\nYour UserID or password is incorrect, please try again :-(");
    free(user);
    back_to_main();
}

void quit()
{
    printf("Thank you for your registration !!");
}

void back_to_main()
{
    //implementation of 'press any key to continue' by platform.
    printf("press any key to continue...\n");
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
        char *buff = strtok(line, ", ");
        User temp;
        while (buff != NULL)
        {
            printf("%s\n", buff);
            buff = strtok(NULL, ", ");
        }

        if (strcmp(temp.userID, user.userID) == 0 && strcmp(temp.password, user.password) == 0)
            return TRUE;
    }

    return FALSE;
}