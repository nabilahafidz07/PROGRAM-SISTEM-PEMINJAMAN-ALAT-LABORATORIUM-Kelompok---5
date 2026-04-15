#include <stdio.h>
#include <string.h>
#include "header/login.h"

struct User {
    char username[50];
    char password[50];
    char role[10];
};

int login(char username[], char role[]) {
    char inputUser[50];
    char password[50];

    struct User users[] = {
        {"admin", "admin123", "admin"},
        {"dwiky", "123", "user"},
        {"nabila", "123", "user"},
        {"raisul", "123", "user"},
        {"syifa", "123", "user"}
    };

    int jumlahUser = 5;

    printf("=== LOGIN ===\n");
    printf("Username: ");
    scanf("%s", inputUser);
    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < jumlahUser; i++) {
        if (strcmp(inputUser, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {

            strcpy(username, users[i].username);
            strcpy(role, users[i].role);
            printf("Login berhasil sebagai %s!\n", role);
            return 1;
        }
    }

    return 0;
}