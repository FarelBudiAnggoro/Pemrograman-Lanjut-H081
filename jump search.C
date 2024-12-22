// FAREL BUDI ANGGORO
// 23081010065
// PEMROGRAMAN LANJUT H081

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAKSIMAL 5

// Struct untuk data mahasiswa
typedef struct {
    char npm[20];
    char nama[50];
    char prodi[30];
    double ipk;
} Mahasiswa;

// Fungsi untuk menampilkan data mahasiswa
void printData(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%-10s %-20s %-15s %.2f\n", mhs[i].npm, mhs[i].nama, mhs[i].prodi, mhs[i].ipk);
    }
}

// Fungsi bubble sort
void bubbleSort(Mahasiswa mhs[], int n, int kriteria, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int condition = 0;
            if (kriteria == 1) { // Berdasarkan NPM
                condition = strcmp(mhs[j].npm, mhs[j + 1].npm) < 0;
            } else if (kriteria == 2) { // Berdasarkan Nama
                condition = strcmp(mhs[j].nama, mhs[j + 1].nama) < 0;
            } else if (kriteria == 3) { // Berdasarkan Prodi
                condition = strcmp(mhs[j].prodi, mhs[j + 1].prodi) < 0;
            } else if (kriteria == 4) { // Berdasarkan IPK
                condition = mhs[j].ipk < mhs[j + 1].ipk;
            }

            if ((!ascending && condition) || (ascending && !condition)) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

// Fungsi pencarian dengan jump search untuk string
int jumpSearchString(Mahasiswa mhs[], int n, const char *query, int kriteria) {
    int step = sqrt(n);
    int prev = 0;
    while (strcmp((kriteria == 1 ? mhs[MIN(step, n) - 1].npm :
                  kriteria == 2 ? mhs[MIN(step, n) - 1].nama :
                  mhs[MIN(step, n) - 1].prodi), query) < 0) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Tidak ditemukan
        }
    }

    for (int i = prev; i < step && i < n; i++) {
        if (strcmp((kriteria == 1 ? mhs[i].npm :
                    kriteria == 2 ? mhs[i].nama :
                    mhs[i].prodi), query) == 0) {
            return i; // elemen ditemukan
        }
    }
    return -1; // elemen tidak ditemukan
}

// Fungsi pencarian dengan jump search untuk double
int jumpSearchDouble(Mahasiswa mhs[], int n, double query) {
    int step = sqrt(n);
    int prev = 0;
    while (mhs[MIN(step, n) - 1].ipk < query) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Tidak ditemukan
        }
    }

    for (int i = prev; i < step && i < n; i++) {
        if (mhs[i].ipk == query) {
            return i; // elemen ditemukan
        }
    }
    return -1; // elemen tidak ditemukan
}

int main() {
    Mahasiswa mhs[MAKSIMAL] = {
        {"23081010065", "Farel Budi Anggoro", "Informatika", 4.00},
        {"23081010069", "Fernando Young", "Informatika Bisnis", 4.01},
        {"23081010114", "Muhammad Rafli Alviro", "Informatika Jaringan", 4.02},
        {"23081010700", "Amba Prasetyo", "Teknik Amba Darat", 4.03},
        {"23081010701", "Amba Saputra", "Teknik Amba", 4.04}
    };
    int jumlahMahasiswa = MAKSIMAL;
    int kriteria, ascending, opsi;
    char searchQuery[50];
    double searchIpk;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Tampilkan Data Mahasiswa\n");
        printf("2. Sorting Data Mahasiswa\n");
        printf("3. Pencarian Mahasiswa\n");
        printf("4. Keluar\n");
        printf("Masukkan opsi: ");
        scanf("%d", &opsi);

        switch (opsi) {
            case 1:
                printf("\nData Mahasiswa:\n");
                printData(mhs, jumlahMahasiswa);
                break;
            case 2:
                printf("\nPilih Kriteria Sortir:\n");
                printf("1. NPM\n2. Nama\n3. Prodi\n4. IPK\n");
                printf("Masukkan opsi (1-4): ");
                scanf("%d", &kriteria);
                printf("Pilih Urutan:\n1. Ascending\n2. Descending\n");
                printf("Masukkan opsi (1-2): ");
                scanf("%d", &ascending);
                bubbleSort(mhs, jumlahMahasiswa, kriteria, ascending == 1);
                printf("\nData Mahasiswa Setelah di-sortir:\n");
                printData(mhs, jumlahMahasiswa);
                break;
            case 3:
                printf("\nPilih Kriteria Pencarian:\n");
                printf("1. NPM\n2. Nama\n3. Prodi\n4. IPK\n");
                printf("Masukkan opsi (1-4): ");
                scanf("%d", &kriteria);
                bubbleSort(mhs, jumlahMahasiswa, kriteria, 1); // Selalu urutkan secara ascending untuk pencarian
                if (kriteria == 4) {
                    printf("\nMasukkan IPK yang ingin dicari: ");
                    scanf("%lf", &searchIpk);
                    int hasil = jumpSearchDouble(mhs, jumlahMahasiswa, searchIpk);
                    if (hasil != -1) {
                        printf("\nMahasiswa ditemukan:\n");
                        printData(&mhs[hasil], 1);
                    } else {
                        printf("\nMahasiswa dengan IPK %.2f tidak ditemukan.\n", searchIpk);
                    }
                } else {
                    printf("\nMasukkan kata kunci yang ingin dicari: ");
                    scanf(" %[^\n]", searchQuery);
                    int hasil = jumpSearchString(mhs, jumlahMahasiswa, searchQuery, kriteria);
                    if (hasil != -1) {
                        printf("\nMahasiswa ditemukan:\n");
                        printData(&mhs[hasil], 1);
                    } else {
                        printf("\nMahasiswa dengan kriteria '%s' tidak ditemukan.\n", searchQuery);
                    }
                }
                break;
            case 4:
                break;
            default:
                printf("Opsi invalid.\n");
        }
    } while (opsi != 4);

    return 0;
}
