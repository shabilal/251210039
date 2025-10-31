#include <stdio.h>
#include <string.h>

#define MAX_MOBIL 100

// Definisi struktur data mobil
typedef struct {
    char merk[50];
    char model[50];
    int tahun;
    char warna[30];
} Mobil;

// Variabel global untuk menyimpan data mobil
Mobil dataMobil[MAX_MOBIL];
int jumlahMobil = 0;

void inisialisasiData() {
    jumlahMobil = 0;
    printf("Data mobil telah diinisialisasi.\n");
}

void inputDataMobil() {
    if (jumlahMobil >= MAX_MOBIL) {
        printf("Data mobil sudah penuh.\n");
        return;
    }

    printf("Masukkan merk mobil: ");
    scanf("%s", dataMobil[jumlahMobil].merk);
    printf("Masukkan model mobil: ");
    scanf("%s", dataMobil[jumlahMobil].model);
    printf("Masukkan tahun pembuatan: ");
    scanf("%d", &dataMobil[jumlahMobil].tahun);
    printf("Masukkan warna mobil: ");
    scanf("%s", dataMobil[jumlahMobil].warna);

    jumlahMobil++;
    printf("Data mobil berhasil disimpan.\n");
}

void tampilkanData() {
    if (jumlahMobil == 0) {
        printf("Tidak ada data mobil untuk ditampilkan.\n");
        return;
    }

    printf("Data Mobil:\n");
    for (int i = 0; i < jumlahMobil; i++) {
        printf("Mobil %d:\n", i + 1);
        printf("Merk: %s\n", dataMobil[i].merk);
        printf("Model: %s\n", dataMobil[i].model);
        printf("Tahun: %d\n", dataMobil[i].tahun);
        printf("Warna: %s\n", dataMobil[i].warna);
        printf("------------------------\n");
    }
}

int main() {
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Inisialisasi Data\n");
        printf("2. Input Data Mobil\n");
        printf("3. Tampilkan Data Mobil\n");
        printf("0. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                inisialisasiData();
                break;
            case 2:
                inputDataMobil();
                break;
            case 3:
                tampilkanData();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while(pilihan != 0);

    return 0;
}