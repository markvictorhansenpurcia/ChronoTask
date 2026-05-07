#ifndef USER_H
#define USER_H

#define MAX_USERS 10

typedef struct {
    char username[50];
    char password[50];
} User;

extern User users[MAX_USERS];
extern int userCount;

void loadUsers();
void saveUsers();

int findUser(char uname[]);

void createAccount();
int login();
void updateAccount();
void deleteAccount();

void startSystem();

#endif