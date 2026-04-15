#ifndef ALAT_H
#define ALAT_H

typedef struct {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int jumlah;
} Alat;

void tambahAlat();
void tampilAlat();
void hapusAlat();
void editAlat();
void login(char role[]);

#endif