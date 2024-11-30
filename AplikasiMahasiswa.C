//Farel Budi Anggoro
//23081010065
//Pemrograman Lanjut H081
//pengurutan berdasarkan nama menggunakan bubble sort, selection sort, dan insertion sort

#include <stdio.h>
#include <string.h>
//struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    char npm[15];
    char nama[50];
    double ipk;
};
//--------------------------------------------bubble sort--------------------------------------------------
//Fungsi untuk mengurutkan data mahasiswa berdasarkan ipk menggunakan Bubble Sort
//fungsi berikut merupakan pengurutan bubble sort secara ascend
void bubbleSort_ipk(struct Mahasiswa mhs[], int n) {
    struct Mahasiswa temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}
//Fungsi untuk mengurutkan data mahasiswa berdasarkan NPM menggunakan Bubble Sort
//fungsi berikut merupakan pengurutan bubble sort secara ascend
void bubbleSort_npm(struct Mahasiswa mhs[], int n) {
    struct Mahasiswa temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (strcmp(mhs[j].nama, mhs[j + 1].nama) > 0) {
                temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}
//Fungsi untuk mengurutkan data mahasiswa berdasarkan nama menggunakan Bubble Sort
//fungsi berikut merupakan pengurutan bubble sort secara ascend
void bubbleSort_nama(struct Mahasiswa mhs[], int n) {
    struct Mahasiswa temp;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (strcmp(mhs[j].nama, mhs[j + 1].nama) > 0) {
                temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}
//kode strcmp(str1, str2)
//jika str1 == str2, maka mengembalikkan nilai 0
//jika str1 > str2, maka mengembalikkan nilai > 0
//jika str2 < str1, maka mengembalikkan nilai < 0
// Fungsi untuk mencetak data mahasiswa

//-----------------------------------------selection sort--------------------------------------------------
//diurutkan secara ascend (default)

void selectionSort_ipk(struct Mahasiswa mhs[], int n){
    struct Mahasiswa temp;
    for(int i = 1; i<n; i++){
        int posisi = i-1;
        for(int j = posisi; j<n-1; j++){//j = posisi, hanya berlaku untuk nilai awal saja, setelahnya diincrement-kan
            if(mhs[posisi].ipk > mhs[j+1].ipk){
                temp = mhs[posisi];
                mhs[posisi] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
}
void selectionSort_npm(struct Mahasiswa mhs[], int n){
    struct Mahasiswa temp;
    for(int i = 1; i<n; i++){
        int posisi = i-1;
        for(int j = posisi; j<n-1; j++){//j = posisi, hanya berlaku untuk nilai awal saja, setelahnya diincrement-kan
            if(strcmp(mhs[posisi].npm, mhs[j+1].npm) >0){
                temp = mhs[posisi];
                mhs[posisi] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
}
void selectionSort_nama(struct Mahasiswa mhs[], int n){
    struct Mahasiswa temp;
    for(int i = 1; i<n; i++){
        int posisi = i-1;
        for(int j = posisi; j<n-1; j++){//j = posisi, hanya berlaku untuk nilai awal saja, setelahnya diincrement-kan
            if(strcmp(mhs[posisi].nama, mhs[j+1].nama) >0){
                temp = mhs[posisi];
                mhs[posisi] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
}
//-----------------------------------------------insertion sort--------------------------------------------------
//diurutkan secara ascend (default)

void insertionSort_ipk(struct Mahasiswa mhs[], int n){
    struct Mahasiswa temporary;
    struct Mahasiswa temp;
    for(int i = 1; i<n; i++){
        temporary = mhs[i];
        for(int j = i-1; j>=0; j--){
            if(temporary.ipk < mhs[j].ipk){
                temp = mhs[j];
                mhs[j] = temporary;
                mhs[j+1] = temp;
            }
            else break;
        }
    }
}
void insertionSort_npm(struct Mahasiswa mhs[], int n){
    struct Mahasiswa temporary;
    struct Mahasiswa temp;
    for(int i = 1; i<n; i++){
        temporary = mhs[i];
        for(int j = i-1; j>=0; j--){
            if(strcmp(temporary.npm, mhs[j].npm) < 0){
                temp = mhs[j];
                mhs[j] = temporary;
                mhs[j+1] = temp;
            }
            else break;
        }
    }
}
void insertionSort_nama(struct Mahasiswa mhs[], int n){
    struct Mahasiswa temporary;
    struct Mahasiswa temp;
    for(int i = 1; i<n; i++){
        temporary = mhs[i];
        for(int j = i-1; j>=0; j--){
            if(strcmp(temporary.nama, mhs[j].nama) < 0){
                temp = mhs[j];
                mhs[j] = temporary;
                mhs[j+1] = temp;
            }
            else break;
        }
    }
}
//---------------------------------------------mencetak data------------------------------------------------
void printMahasiswaAscend(struct Mahasiswa mhs[], int n, int decision2) {
    if(decision2 == 1) printf("\ndata mahasiswa dengan bubble sort\n");
    else if(decision2 == 2) printf("data mahasiswa dengan selection sort\n");
    else if(decision2 == 3) printf("ndata mahasiswa dengan insertion sort\n");
    else printf("maaf, tidak valid\n");
    for (int i = 0; i < n; i++) {
        printf("NPM: %s, Nama: %s, IPK: %lf\n", mhs[i].npm, mhs[i].nama, mhs[i].ipk);
    }
}
void printMahasiswaDescend(struct Mahasiswa mhs[], int n, int decision2) {
    if(decision2 == 1) printf("\ndata mahasiswa dengan bubble sort\n");
    else if(decision2 == 2) printf("data mahasiswa dengan selection sort\n");
    else if(decision2 == 3) printf("ndata mahasiswa dengan insertion sort\n");
    else printf("maaf, tidak valid\n");
    for (int i = n-1; i >=0; i--) {
        printf("NPM: %s, Nama: %s, IPK: %lf\n", mhs[i].npm, mhs[i].nama, mhs[i].ipk);
    }
}
int main() {
    struct Mahasiswa mhs[100];
    int n;
    int decision1, decision2, decision3;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        printf("Masukkan NPM, Nama, dan IPK mahasiswa ke-%d:\n", i + 1);
        printf("NPM: ");
        scanf("%s", mhs[i].npm);
        printf("Nama: ");
        scanf(" %[^\n]", mhs[i].nama); // Membaca string dengan spasi
        printf("IPK: ");
        scanf("%lf", &mhs[i].ipk);
    }
    // Mengurutkan mahasiswa berdasarkan nama menggunakan bubble sort
    printf("mau mengurutkan berdasarkan apa? :\n");
    printf("1. nama\n");
    printf("2. NPM\n");
    printf("3. ipk\n");
    printf("masukkan jawaban: ");
    scanf("%d", &decision1);
    
    printf("mau memakai metode apa? : \n");
    printf("1. bubble sort\n");
    printf("2. selection sort\n");
    printf("3. insertion sort\n");
    printf("masukkan jawaban: ");
    scanf("%d", &decision2);
    
    if(decision2 == 1){
        if(decision1 == 1) bubbleSort_nama(mhs, n);
        else if(decision1 == 2) bubbleSort_npm(mhs, n);
        else if(decision1 == 3) bubbleSort_ipk(mhs, n);
    }
    else if(decision2 == 2){
        if(decision1 == 1) selectionSort_nama(mhs, n);
        else if(decision1 == 2) selectionSort_npm(mhs, n);
        else if(decision1 == 3) selectionSort_ipk(mhs, n);
        
    }
    else if(decision2 == 3){
        if(decision1 == 1) insertionSort_nama(mhs, n);
        else if(decision1 == 2) insertionSort_npm(mhs, n);
        else if(decision1 == 3) insertionSort_ipk(mhs, n);
    }
    else{
        printf("pilihan tidak valid\n");
    }
    

    // Mencetak mahasiswa setelah pengurutan
    printf("===pilih ascending/descending===\n");
    printf("1. ascending\n");
    printf("2. descending\n");
    printf("==========================\n");
    scanf("%d", &decision3);
    printf("==========================\n");

    if(decision3 == 1 && (decision2 >=1 && decision2 <= 3)){
        printMahasiswaAscend(mhs, n, decision2);
    }
    else if(decision3 == 2 && (decision2 >=1 && decision2 <=3)){
        printMahasiswaDescend(mhs, n, decision2);
    }
    else {
        printf("YANG BENER DONG BAMBANG\n");
    }
}
