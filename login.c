#include <stdio.h>
#include <string.h>

int login(char role[]) {
    char username[50], password[50];
    char fileUser[50], filePass[50], fileRole[10];

    FILE *fp = fopen("akun.txt", "r");
    if (fp == NULL) {
        printf("File akun tidak ditemukan!\n");
        return 0;
    }

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    while (fscanf(fp, "%[^,],%[^,],%s\n", fileUser, filePass, fileRole) != EOF) {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            strcpy(role, fileRole); 
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
