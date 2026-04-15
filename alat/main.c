#include <stdio.h>
#include "alat.h"
#include "header/menu.h"
#include "header/login.h"

int main() {
    int pilih;

    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Tambah Alat\n");
        printf("2. Tampilkan Alat\n");
        printf("3. Edit Alat\n");
        printf("4. Hapus Alat\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1: tambahAlat(); break;
            case 2: tampilAlat(); break;
            case 3: editAlat(); break;
            case 4: hapusAlat(); break;
        }
    } while(pilih != 0);

    return 0;
}