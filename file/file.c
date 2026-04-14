#include <stdio.h>
#include <string.h>
#include "file.h"

// ================= LOGIN =================
int cekLogin(char username[], char password[], char role[]) {
    FILE *file = fopen("akun.txt", "r");
    char u[50], p[50], r[10];

    if (file == NULL) {
        printf("File akun tidak ditemukan!\n");
        return 0;
    }

    while (fscanf(file, "%s %s %s", u, p, r) != EOF) {
        if (strcmp(username, u) == 0 && strcmp(password, p) == 0) {
            strcpy(role, r);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

// ================= ALAT =================
void bacaAlat() {
    FILE *file = fopen("alat.txt", "r");
    int id, tahun, jumlah;
    char nama[50], merek[50], model[50];

    if (file == NULL) {
        printf("File alat tidak ditemukan!\n");
        return;
    }

    while (fscanf(file, "%d %s %s %s %d %d", &id, nama, merek, model, &tahun, &jumlah) != EOF) {
        printf("ID:%d | %s | %s | %s | %d | %d\n", id, nama, merek, model, tahun, jumlah);
    }

    fclose(file);
}

void tambahAlatFile(int id, char nama[], char merek[], char model[], int tahun, int jumlah) {
    FILE *file = fopen("alat.txt", "a");

    fprintf(file, "%d %s %s %s %d %d\n", id, nama, merek, model, tahun, jumlah);

    fclose(file);
}

// ================= PINJAM =================
void bacaPinjam() {
    FILE *file = fopen("pinjam.txt", "r");
    char user[50];
    int id;

    if (file == NULL) {
        printf("File pinjam tidak ditemukan!\n");
        return;
    }

    while (fscanf(file, "%s %d", user, &id) != EOF) {
        printf("User: %s pinjam alat ID: %d\n", user, id);
    }

    fclose(file);
}

void tambahPinjam(char user[], int id_alat) {
    FILE *file = fopen("pinjam.txt", "a");

    fprintf(file, "%s %d\n", user, id_alat);

    fclose(file);
}