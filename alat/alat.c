#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alat.h"

#define FILE_NAME "data_alat.txt"

void tambahAlat() {
    FILE *fp = fopen(FILE_NAME, "a");
    Alat a;

    printf("ID: "); scanf("%u", &a.id);
    printf("Nama: "); scanf(" %[^\n]", a.nama);
    printf("Merek: "); scanf(" %[^\n]", a.merek);
    printf("Model: "); scanf(" %[^\n]", a.model);
    printf("Tahun: "); scanf("%u", &a.tahun);
    printf("Jumlah: "); scanf("%u", &a.jumlah);

    fprintf(fp, "%u|%s|%s|%s|%u|%u\n",
            a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);

    fclose(fp);
    printf("Data berhasil ditambah!\n");
}

void tampilAlat() {
    FILE *fp = fopen(FILE_NAME, "r");
    Alat a;

    if (fp == NULL) {
        printf("Data kosong!\n");
        return;
    }

    printf("\n=== DATA ALAT ===\n");

    while (fscanf(fp, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
                  &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        printf("ID: %u\nNama: %s\nMerek: %s\nModel: %s\nTahun: %u\nJumlah: %u\n\n",
               a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }

    fclose(fp);
}

void hapusAlat() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    Alat a;
    unsigned int id;
    int found = 0;

    printf("Masukkan ID yang ingin dihapus: ");
    scanf("%u", &id);

    while (fscanf(fp, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
                  &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        if (a.id != id) {
            fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
                    a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("Data berhasil dihapus!\n");
    else
        printf("ID tidak ditemukan!\n");
}

void editAlat() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    Alat a;
    unsigned int id;
    int found = 0;

    printf("Masukkan ID yang ingin diedit: ");
    scanf("%u", &id);

    while (fscanf(fp, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
                  &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        if (a.id == id) {
            found = 1;
            printf("Data baru:\n");

            printf("Nama: "); scanf(" %[^\n]", a.nama);
            printf("Merek: "); scanf(" %[^\n]", a.merek);
            printf("Model: "); scanf(" %[^\n]", a.model);
            printf("Tahun: "); scanf("%u", &a.tahun);
            printf("Jumlah: "); scanf("%u", &a.jumlah);
        }

        fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
                a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("Data berhasil diedit!\n");
    else
        printf("ID tidak ditemukan!\n");
}