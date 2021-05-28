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

int main_menu();
void registration();
void login();
void seat_reservation();
void seat_cancelation();
void back_to_main();
void quit();

int main()
{
    while (1)
        //if 0 is returned, quit programm.
        main_menu() ? 0 : exit(0);
}

int main_menu()
{
    printf("\nWelcome to Hanyang bus reservation!\n\n\n");
    printf("1 : register!!!\n");
    printf("2 : login!!!\n");
    printf("3 : quit\n");
    printf("Enter your choice :\n");
    int choice;
    scanf("%d", &choice);
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
        return 0;
    default:
        break;
    }
    return 1;
}

void registration()
{
    FILE *log = fopen("login.txt", "a+");
    char **buffer = (char **)malloc(4 * sizeof(char *)); //input buffer

    for (int i = 0; i < 4; i++)
        buffer[i] = (char *)malloc(100 * sizeof(char)); //allocating memory

    getchar(); //cleaning buffer

    printf("Enter first name : ");
    fgets(buffer[0], 100, stdin);
    printf("Enter last name : ");
    fgets(buffer[1], 100, stdin);
    printf("Enter your Username : ");
    fgets(buffer[2], 100, stdin);
    printf("Enter your password : ");
    fgets(buffer[3], 100, stdin);

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
    FILE *log = fopen("login.txt", "r");
    char **buffer = (char **)malloc(2 * sizeof(char *)); //input buffer

    printf("\nUserID : ");
    printf("\nPassword : ");

    printf("\nYour UserID or password is incorrect, please try again :-(");
    back_to_main();
}

void quit()
{
    printf("Thank you for your registration !!");
}

void back_to_main()
{
    printf("PLATFORM: %s\n", PLATFORM_NAME);
    printf("press any key to continue...\n");
    if (strcmp(PLATFORM_NAME, "windows") == 0)
        system("PAUSE");
    else if (strcmp(PLATFORM_NAME, "unix") == 0)
        system("read -n 1 -s -r");
    else
        getchar();
}