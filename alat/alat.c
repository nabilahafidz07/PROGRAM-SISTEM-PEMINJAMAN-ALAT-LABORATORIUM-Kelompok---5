#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alat.h"

#define FILE_DATA "data_alat.txt"
#define FILE_TEMP "temp.txt"

void inputAlat(Alat *a, int dengan_id) {
    if (dengan_id) {
        printf("ID: ");
        scanf("%u", &a->id);
    }
    printf("Nama: "); scanf(" %[^\n]", a->nama);
    printf("Merek: "); scanf(" %[^\n]", a->merek);
    printf("Model: "); scanf(" %[^\n]", a->model);
    printf("Tahun: "); scanf("%u", &a->tahun);
    printf("Jumlah: "); scanf("%u", &a->jumlah);
}

int bacaAlat(FILE *fp, Alat *a) {
    return fscanf(fp, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
                  &a->id, a->nama, a->merek, a->model, 
                  &a->tahun, &a->jumlah) != EOF;
}

void simpanAlat(FILE *fp, Alat *a) {
    fprintf(fp, "%u|%s|%s|%s|%u|%u\n",
            a->id, a->nama, a->merek, a->model, a->tahun, a->jumlah);
}

void tambahAlat() {
    FILE *fp = fopen(FILE_DATA, "a");
    Alat a;
    
    inputAlat(&a, 1);
    simpanAlat(fp, &a);
    fclose(fp);
    
    printf("Data berhasil ditambah!\n");
}

void tampilAlat() {
    FILE *fp = fopen(FILE_DATA, "r");
    Alat a;

    if (!fp) {
        printf("Data kosong!\n");
        return;
    }

    printf("\n=== DATA ALAT ===\n");
    while (bacaAlat(fp, &a)) {
        printf("ID: %u | %s | %s | %s | %u | %u\n",
               a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }
    fclose(fp);
}

void hapusAlat() {
    FILE *fp = fopen(FILE_DATA, "r");
    FILE *tmp = fopen(FILE_TEMP, "w");
    Alat a;
    unsigned int id;
    int ketemu = 0;

    printf("ID yg mau dihapus: ");
    scanf("%u", &id);

    while (bacaAlat(fp, &a)) {
        if (a.id == id) {
            ketemu = 1;
        } else {
            simpanAlat(tmp, &a);
        }
    }

    fclose(fp);
    fclose(tmp);
    remove(FILE_DATA);
    rename(FILE_TEMP, FILE_DATA);

    printf(ketemu ? "Dihapus!\n" : "ID ga ada!\n");
}

void editAlat() {
    FILE *fp = fopen(FILE_DATA, "r");
    FILE *tmp = fopen(FILE_TEMP, "w");
    Alat a;
    unsigned int id;
    int ketemu = 0;

    printf("ID yg mau diedit: ");
    scanf("%u", &id);

    while (bacaAlat(fp, &a)) {
        if (a.id == id) {
            ketemu = 1;
            printf("Masukkan data baru:\n");
            inputAlat(&a, 0);
        }
        simpanAlat(tmp, &a);
    }

    fclose(fp);
    fclose(tmp);
    remove(FILE_DATA);
    rename(FILE_TEMP, FILE_DATA);

    printf(ketemu ? "Diedit!\n" : "ID ga ada!\n");
}
