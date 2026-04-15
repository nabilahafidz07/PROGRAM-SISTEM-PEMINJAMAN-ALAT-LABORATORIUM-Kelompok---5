#include <stdio.h>
#include <string.h>
#include "header/login.h"
#include "header/menu.h"

int main() {
    char username[50];
    char role[10];
    int status;

    status = login(username, role);

    if (status == 0) {
        printf("Login gagal!\n");
        return 0;
    }

    if (strcmp(role, "admin") == 0) {
        menuAdmin();
    } else {
        menuUser(username);
    }

    return 0;
}