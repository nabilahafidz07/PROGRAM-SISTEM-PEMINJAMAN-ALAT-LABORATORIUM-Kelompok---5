#include <stdio.h>
#include <stdlib.h>


int login(char role[]);
void menuAdmin();
void menuUser();

int main(int argc, char *argv[]) {
    char role[10];
    int status;
    int def;

    status = login(role);

    if (status == 0) {
        printf("Login gagal!\n");
        return 0;
    }

    // cek role
    if (strcmp(role, "admin") == 0) {
        menuAdmin();
    } else {
        menuUser();
    }

    return 0;
}



