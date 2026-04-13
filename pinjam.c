#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pinjam.h"

//pinjaman alat
void pinjamAlat(char username[]) {
FILE *fp = fopen("pinjam.txt", "a");
if (fp == NULL) {
    printf("file tidak bisa dibuka!\n");
    return;
}

int id, jumlah;

printf("Masukkan ID alat: ");
scanf("%d", &id);

printf("jumlah pinjam: ");
scanf("%d", &jumlah);

fprintf(fp, "%s,%d,%d\n", username, id, jumlah);
fclose(fp);
printf("alat berhasil dipinjam!\n");
}

//Lihat Pinjaman
void lihatPinjaman(char username[]) {
FILE *fp = fopen("pinjam.txt", "r");

if (fp == NULL) {
    printf("belum ada data pinjaman!\n");
    return;
}

char user[50];
int id, jumlah;

printf("\n=== Daftar Pinjaman ===\n");

while (fscanf(fp, "%[^,],%d,%d\n", user, &id, &jumlah) != EOF) {
    if (strcmp(user, username) == 0) {
        printf("ID Alat: %d, Jumlah: %d\n", id, jumlah);
    } 
}
fclose(fp);
}

//Kembalikan Alat
void kembalikanAlat(char username[]) {
    FILE *fp = fopen("pinjam.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("file error!\n");
        return;
    }

    char user[50];
    int id, jumlah, idkembali;
    int ditemukan = 0;

    printf("Masukkan ID alat yang ingin dikembalikan: ");
    scanf("%d", &idkembali);

    printf("Masukkan ID alat yang ingin dikembalikan: ");
    scanf("%d", &idkembali);

    while (fscanf(fp, "%[^,],%d,%d\n", user, &id, &jumlah) != EOF) {
        if (strcmp(user, username) == 0 && id == idkembali) {
            ditemukan = 1;
            continue; // skip data (hapus)

        }
        fprintf(temp, "%s,%d,%d\n", user, id, jumlah); 
    }
    fclose(fp);
    fclose(temp);

    remove("pinjam.txt");
    rename("temp.txt", "pinjam.txt");

    if (ditemukan) {
        printf("alat berhasil dikembalikan!\n");
    } else {
        printf("data tidak ditemukan!\n");

    }
    
}
