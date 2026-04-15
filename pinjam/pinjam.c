#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pinjam.h"

/* pinjam alat berdasarkan username yang lagi login */
void pinjamAlat(char username[]) {
    FILE *fp = fopen("pinjam.txt", "a");
    if (fp == NULL) {
        printf("Gagal buka file, coba lagi.\n");
        return;
    }

    int id, jumlah;

    printf("ID alat: ");
    scanf("%d", &id);

    printf("Jumlah pinjam: ");
    scanf("%d", &jumlah);

    // 🔥 tambah status
    fprintf(fp, "%s,%d,%d,dipinjam\n", username, id, jumlah);

    fclose(fp);
    printf("Oke, alat sudah tercatat sebagai dipinjam.\n");
}

/* tampilkan semua pinjaman milik username ini */
void lihatPinjaman(char username[]) {
    FILE *fp = fopen("pinjam.txt", "r");
    if (fp == NULL) {
        printf("Belum ada data pinjaman.\n");
        return;
    }

    char user[50], status[20];
    int id, jumlah;

    printf("\n=== Daftar Pinjaman ===\n");

    while (fscanf(fp, "%[^,],%d,%d,%[^ \n]\n", user, &id, &jumlah, status) != EOF) {
        if (strcmp(user, username) == 0) {
            printf("ID Alat: %d | Jumlah: %d | Status: %s\n", id, jumlah, status);
        }
    }

    fclose(fp);
}

/* hapus record pinjaman setelah alat dikembalikan */
void kembalikanAlat(char username[]) {
    FILE *fp   = fopen("pinjam.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Gagal buka file.\n");
        return;
    }

    char user[50], status[20];
    int id, jumlah, idkembali;
    int ditemukan = 0;

    printf("ID alat yang mau dikembalikan: ");
    scanf("%d", &idkembali);

    while (fscanf(fp, "%[^,],%d,%d,%[^ \n]\n", user, &id, &jumlah, status) != EOF) {

        if (strcmp(user, username) == 0 && id == idkembali && strcmp(status, "dipinjam") == 0) {
            ditemukan = 1;

            // 🔥 ubah jadi dikembalikan
            fprintf(temp, "%s,%d,%d,dikembalikan\n", user, id, jumlah);
        } else {
            fprintf(temp, "%s,%d,%d,%s\n", user, id, jumlah, status);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("pinjam.txt");
    rename("temp.txt", "pinjam.txt");

    if (ditemukan)
        printf("Alat sudah dikembalikan.\n");
    else
        printf("Data tidak ditemukan atau sudah dikembalikan.\n");
}