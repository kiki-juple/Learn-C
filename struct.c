#include <stdio.h>
#include <string.h>

float nilaiTotal1, nilaiTotal2;

struct Mahasiswa
{
    int nim;
    float nilaiHadir, nilaiTugas, nilaiQuiz, nilaiForum, nilaiUas;
    char nama[50], mataKuliah[50];
} s1, s2;

void menu1()
{
    if (s1.nim == 0) {
    printf("\n=========== INPUT DATA MAHASISWA ===========\n");
    printf("Data mahasiswa 1:\n");
    printf("NIM: ");
    scanf("%d", &s1.nim);
    printf("Nama: ");
    scanf("%s", s1.nama);
    printf("Mata Kuliah: ");
    scanf("%s", s1.mataKuliah);
    return;
    }
    do
    {
        printf("\n=========== INPUT DATA MAHASISWA ===========\n");
        printf("Data mahasiswa 2:\n");
        printf("NIM: ");
        scanf("%d", &s2.nim);
        if (s1.nim == s2.nim)
        {
            printf("Maaf, data mahasiswa tersebut sudah dimasukkan. Silakan masukkan data lain.\n");
        }
    } while (s1.nim == s2.nim);
    printf("Nama: ");
    scanf("%s", s2.nama);
    printf("Mata Kuliah: ");
    scanf("%s", s2.mataKuliah);
}

void menu2()
{
    int nim3;
    printf("\n===========INPUT NILAI MAHASISWA ===========\n");
    printf("Masukkan NIM yang akan diinput: ");
    scanf("%d", &nim3);
    if (nim3 == s1.nim) {
    printf("Nilai %s - %d:\n", s1.nama, s1.nim);
    printf("Nilai Hadir: ");
    scanf("%f", &s1.nilaiHadir);
    printf("Nilai Tugas: ");
    scanf("%f", &s1.nilaiTugas);
    printf("Nilai Quiz: ");
    scanf("%f", &s1.nilaiQuiz);
    printf("Nilai Keaktifan Forum: ");
    scanf("%f", &s1.nilaiForum);
    printf("Nilai UAS: ");
    scanf("%f", &s1.nilaiUas);
    }
    else if (nim3 == s2.nim) {
    printf("Nilai %s - %d:\n", s2.nama, s2.nim);
    printf("Nilai Hadir: ");
    scanf("%f", &s2.nilaiHadir);
    printf("Nilai Tugas: ");
    scanf("%f", &s2.nilaiTugas);
    printf("Nilai Quiz: ");
    scanf("%f", &s2.nilaiQuiz);
    printf("Nilai Keaktifan Forum: ");
    scanf("%f", &s2.nilaiForum);
    printf("Nilai UAS: ");
    scanf("%f", &s2.nilaiUas);
    }
    else {
        printf("NIM yang Anda masukkan tidak terdaftar.");
    }

    nilaiTotal1 = (float)(s1.nilaiHadir * 0.1) + (s1.nilaiTugas * 0.2) + (s1.nilaiQuiz * 0.1) + (s1.nilaiForum * 0.1) + (s1.nilaiUas * 0.5);
    nilaiTotal2 = (float)(s2.nilaiHadir * 0.1) + (s2.nilaiTugas * 0.2) + (s2.nilaiQuiz * 0.1) + (s2.nilaiForum * 0.1) + (s2.nilaiUas * 0.5);
}

void menu3()
{
    int nim2;
    printf("Masukkan NIM: ");
    scanf("%d", &nim2);
    if (nim2 == s1.nim)
    {
        if (nilaiTotal1 <= 100 && nilaiTotal1 >= 90)
        {
            printf("Nilai = %.1f", nilaiTotal1);
            printf("\nStatus Grade = A (LULUS)");
        }
        else if (nilaiTotal1 <= 89 && nilaiTotal1 >= 80)
        {
            printf("Nilai = %.1f", nilaiTotal1);
            printf("\nStatus Grade = B (LULUS)");
        }
        else if (nilaiTotal1 <= 79 && nilaiTotal1 >= 70)
        {
            printf("Nilai = %.1f", nilaiTotal1);
            printf("\nStatus Grade = C (LULUS)");
        }
        else if (nilaiTotal1 <= 69 && nilaiTotal1 >= 60)
        {
            printf("Nilai = %.1f", nilaiTotal1);
            printf("\nStatus Grade = D (LULUS)");
        }
        else if (nilaiTotal1 <= 59)
        {
            printf("Nilai = %.1f", nilaiTotal1);
            printf("\nStatus Grade = E (TIDAK LULUS)");
        }
    }
    else if (nim2 == s2.nim)
    {
        if (nilaiTotal2 <= 100 && nilaiTotal2 >= 90)
        {
            printf("Nilai = %.1f", nilaiTotal1);
            printf("\nStatus Grade = A (LULUS)");
        }
        else if (nilaiTotal2 <= 89 && nilaiTotal2 >= 80)
        {
            printf("Nilai = %.1f", nilaiTotal2);
            printf("\nStatus Grade = B (LULUS)");
        }
        else if (nilaiTotal2 <= 79 && nilaiTotal2 >= 70)
        {
            printf("Nilai = %.1f", nilaiTotal2);
            printf("\nStatus Grade = C (LULUS)");
        }
        else if (nilaiTotal2 <= 69 && nilaiTotal2 >= 60)
        {
            printf("Nilai = %.1f", nilaiTotal1);
            printf("\nStatus Grade = D (LULUS)");
        }
        else if (nilaiTotal2 <= 59)
        {
            printf("Nilai = %.1f", nilaiTotal2);
            printf("\nStatus Grade = E (TIDAK LULUS)");
        }
    }
    else
    {
        printf("Data tidak ditemukan, silakan periksa lagi.\n");
    }
}

void main()
{
    int pilihan;
    do
    {
        printf("\n");
        printf("=================== MENU ===================\n");
        printf("1. INPUT DATA MAHASISWA\n");
        printf("2. INPUT NILAI MAHASISWA\n");
        printf("3. MELIHAT NILAI MAHASISWA\n");
        printf("4. KELUAR\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        case 4:
            printf("Terimakasih");
            return;
        default:
            printf("Salah memasukkan menu, coba lagi.\n");
            break;
        }
    } while (pilihan != 4);
}