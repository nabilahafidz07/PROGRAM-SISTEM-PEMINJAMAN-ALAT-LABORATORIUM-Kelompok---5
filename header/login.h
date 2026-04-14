#ifndef LOGIN_H
#define LOGIN_H

#define MAX 50

typedef struct {
    char username[MAX];
    char password[MAX];
    char role[MAX]; // "admin" atau "user"
} User;

// fungsi login
int loginUser(char *username, char *password, char *role);

// validasi login dari file
int cekLogin(char *username, char *password, char *role);

#endif