#include <stdio.h>
#include <string.h>
#define MAX 2

typedef struct {
    char namaJalan[30];
    int noRumah;
    char kota[30];
    char provinsi[30];
} Alamat;

typedef struct {
    int tanggal;
    int bulan;
    int tahun;
} tanggalLahir;

typedef struct {
    int noDosen;
    int nidn;
    char nama[30];
    char tempat[30];
    Alamat alamat;
    tanggalLahir tglLahir;
} dataDosen;

int main() {
    Alamat a;
    tanggalLahir t;
    dataDosen d[MAX];
    for (int i = 0; i < MAX; i++) {
        printf("\nData dosen ke %d\n", i+1);
        printf("No. Dosen: ");
        scanf("%d", &d[i].noDosen);
        printf("NIDN: ");
        scanf("%d", &d[i].nidn);
        printf("Nama (*spasi menggunakan underscore): ");
        scanf("%s", d[i].nama);
        printf("========ALAMAT========\n");
        printf("Nama Jalan (*spasi menggunakan underscore): ");
        scanf("%s", d[i].alamat.namaJalan);
        printf("Nomor Rumah: ");
        scanf("%d", &d[i].alamat.noRumah);
        printf("Kota (*spasi menggunakan underscore): ");
        scanf("%s", d[i].alamat.kota);
        printf("Provinsi (*spasi menggunakan underscore): ");
        scanf("%s", d[i].alamat.provinsi);
        printf("======================\n");
        printf("Tempat lahir (*spasi menggunakan underscore): ");
        scanf("%s", d[i].tempat);
        printf("=====TANGGAL LAHIR=====\n");
        printf("Tanggal: ");
        scanf("%d", &d[i].tglLahir.tanggal);
        printf("Bulan: ");
        scanf("%d", &d[i].tglLahir.bulan);
        printf("Tahun: ");
        scanf("%d", &d[i].tglLahir.tahun);
    }
    printf("=============================================== DATA DOSEN ==================================================");
    printf("\n");
    //printf("NO\tNIDN\tNAMA\t\tALAMAT\t\t\t\t\t\t\tTEMPAT LAHIR\tTANGGAL LAHIR");
    for (int i = 0; i < MAX; i++) {
        printf("Nomor: %d\nNIDN: %d\nNama: %s\nALamat: Jalan %s No.%d, %s, %s\nTempat lahir: %s\nTanggal lahir: %d/%d/%d\n",
        d[i].noDosen, d[i].nidn, d[i].nama, d[i].alamat.namaJalan, d[i].alamat.noRumah, d[i].alamat.kota, d[i].alamat.provinsi, d[i].tempat, d[i].tglLahir.tanggal, d[i].tglLahir.bulan, d[i].tglLahir.tahun);
    }
    return 0;
}