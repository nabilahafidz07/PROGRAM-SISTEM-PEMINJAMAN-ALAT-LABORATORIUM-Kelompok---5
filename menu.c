#include <stdio.h>
#include "header/menu.h"
#include "alat/alat.h"
#include "pinjam/pinjam.h"

void menuAdmin() {
    int pilihan;

    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Tambah Alat\n");
        printf("2. Lihat Alat\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahAlat();   // 🔥 panggil fungsi
                break;
            case 2:
                tampilAlat();   // 🔥 panggil fungsi
                break;
            case 3:
                printf("Keluar dari menu admin...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 3);
}


void menuUser(char username[]) {
    int pilihan;

    do {
        printf("\n=== MENU USER ===\n");
        printf("1. Pinjam Alat\n");
        printf("2. Kembalikan Alat\n");
        printf("3. Lihat Pinjaman\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                pinjamAlat(username);        // 🔥 beda dari admin
                break;
            case 2:
                kembalikanAlat(username);    // 🔥 beda dari admin
                break;
            case 3:
                lihatPinjaman(username);     // 🔥 tambahan
                break;
            case 4:
                printf("Keluar dari menu user...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 4);
}