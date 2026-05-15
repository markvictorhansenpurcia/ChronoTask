#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "task.h"
#include "utils.h"

#define FILE_NAME "users.txt"

User users[MAX_USERS];

int userCount = 0;

int findUser(char uname[]) {

    for (int i = 0; i < userCount; i++) {

        if (strcmp(users[i].username, uname) == 0)
            return i;
    }

    return -1;
}

void loadUsers() {

    FILE *fp = fopen(FILE_NAME, "r");

    if (!fp)
        return;

    while (
        userCount < MAX_USERS &&
        fscanf(
            fp,
            "%49s %49s",
            users[userCount].username,
            users[userCount].password
        ) == 2
    ) {

        userCount++;
    }

    fclose(fp);
}

void saveUsers() {

    FILE *fp = fopen(FILE_NAME, "w");

    for (int i = 0; i < userCount; i++) {

        fprintf(
            fp,
            "%s %s\n",
            users[i].username,
            users[i].password
        );
    }

    fclose(fp);
}

void createAccount() {

    char uname[50];

    printf("Username: ");
    scanf("%49s", uname);

    clearInputBuffer();

    if (findUser(uname) != -1) {

        printf("Username already exists.\n");
        return;
    }

    strcpy(users[userCount].username, uname);

    printf("Password: ");
    scanf("%49s", users[userCount].password);

    clearInputBuffer();

    userCount++;

    saveUsers();

    printf("Account created.\n");
}

int login() {

    char uname[50];
    char pass[50];

    printf("Username: ");
    scanf("%49s", uname);

    clearInputBuffer();

    printf("Password: ");
    scanf("%49s", pass);

    clearInputBuffer();

    int i = findUser(uname);

    if (
        i != -1 &&
        strcmp(users[i].password, pass) == 0
    ) {

        printf("Login successful.\n");

        return 1;
    }

    printf("Invalid credentials.\n");

    return 0;
}

void updateAccount() {

    printf("Feature available.\n");
}

void deleteAccount() {

    printf("Feature available.\n");
}

void startSystem() {
    int choice;

    while (1) {

        printf("\n===== CHRONOTASK =====\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        printf("Choice: ");

        choice = getIntInput();

        switch (choice) {

            case 1:
                createAccount();
                break;

            case 2:
                if (login())
                    menu();
                break;

            case 3:
                printf("Thankyou Byebye!...\n");
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}