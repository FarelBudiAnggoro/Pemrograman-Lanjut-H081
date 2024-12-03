//Farel Budi Anggoro
//23081010065
//Pemrograman Lanjut H081
//Aplikasi Manajemen Mahasiswa (AMM) menggunakan Merge Sort

#include <stdio.h>
#include <string.h>

typedef struct {
    char npm[15];
    char nama[50];
    float ipk;
} Mahasiswa;

// Fungsi perbandingan NPM
int compare_npm(Mahasiswa a, Mahasiswa b) {
    return strcmp(a.npm, b.npm);  // Ascending by default
}

// Fungsi perbandingan Nama
int compare_nama(Mahasiswa a, Mahasiswa b) {
    return strcmp(a.nama, b.nama);  // Ascending by default
}

// Fungsi perbandingan IPK
int compare_ipk(Mahasiswa a, Mahasiswa b) {
    if (a.ipk < b.ipk) return -1;  // a sebelum b
    if (a.ipk > b.ipk) return 1;   // a setelah b
    return 0;  // IPK sama, urutan tidak berubah
}

// Fungsi untuk merge dua bagian data
void merge(Mahasiswa data[], int low, int mid, int high, int order, int choice) {
    Mahasiswa temp[high + 1];
    int left = low, right = mid + 1, i = 0;

    while (left <= mid && right <= high) {
        int comparison;
        if(choice == 1){
            comparison = compare_npm(data[left], data[right]);  
        }
        else if(choice == 2){
            comparison = compare_nama(data[left], data[right]); 
        } 
        else if(choice == 3){
            comparison = compare_ipk(data[left], data[right]);
        } 
        
        if (order == 2) {  // Untuk descending, balikkan hasil perbandingan
            comparison = -comparison;
        }

        if (comparison <= 0) {
            temp[i] = data[left];
            left++;
        } else {
            temp[i] = data[right];
            right++;
        }
        i++;
    }

    // Salin sisa elemen dari left dan right
    while (left <= mid) {
        temp[i] = data[left];
        left++;
        i++;
    }

    while (right <= high) {
        temp[i] = data[right];
        right++;
        i++;
    }

    // Salin kembali data yang sudah diurutkan ke array data
    for (int x = low; x <= high; x++) {
        data[x] = temp[x - low];
    }
}

// Fungsi merge_sort
void merge_sort(Mahasiswa data[], int low, int high, int order, int choice) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    merge_sort(data, low, mid, order, choice);
    merge_sort(data, mid + 1, high, order, choice);
    merge(data, low, mid, high, order, choice);
}

int main() {
    Mahasiswa data[] = {
        {"23081010065", "Farel Budi Anggoro", 4.0},
        {"23081010069", "Fernando Young", 4.0},
        {"23081010114", "Muhammad Rafli Alviro", 4.0},
        {"23081010400", "Muhammad Amba Saputra", 4.0},
        {"23081010500", "Muhammad Amba Prasetyo", 4.0}
    };

    int low = 0;
    int high = sizeof(data) / sizeof(data[0]) - 1;
    int choice, order;

    // Input pilihan pengurutan
    printf("Pilih kriteria pengurutan:\n1. NPM\n2. Nama\n3. IPK\n");
    printf("Masukkan nomor: ");
    scanf("%d", &choice);

    printf("Pilih urutan pengurutan:\n1. Ascending\n2. Descending\n");
    printf("Masukkan nomor: ");
    scanf("%d", &order);

    // Menentukan fungsi perbandingan berdasarkan pilihan kriteria
    if (choice == 1) {
        merge_sort(data, low, high, order, choice);  // NPM
    } else if (choice == 2) {
        merge_sort(data, low, high, order, choice);  // Nama
    } else if (choice == 3) {
        merge_sort(data, low, high, order, choice);  // IPK
    } else {
        printf("Pilihan tidak valid.\n");
    }

    // Menampilkan data yang sudah diurutkan
    printf("\nData setelah diurutkan:\n");
    for (int i = 0; i <= high; i++) {
        printf("%s %s %.2f\n", data[i].npm, data[i].nama, data[i].ipk);
    }
}
