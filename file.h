#ifndef FILE_H
#define FILE_H

#include <stdio.h>

// LOGIN
int cekLogin(char username[], char password[], char role[]);

// ALAT
void bacaAlat();
void tambahAlatFile(int id, char nama[], char merek[], char model[], int tahun, int jumlah);

// PINJAM
void bacaPinjam();
void tambahPinjam(char user[], int id_alat);

#endif