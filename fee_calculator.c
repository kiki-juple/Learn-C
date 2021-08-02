#include <stdio.h>

int main()
{
    //inisialisasi variabel
    char nama[100];
    int g_jabatan = 0, g_pendidikan = 0;
    int jam_kerja;
    float t_jabatan, t_pendidikan, lembur, total;

    printf("PROGRAM MENGHITUNG GAJI KARYAWAN \n");
    printf("================================ \n");
    printf("   KIKI ABDULLAH - 2401997690    \n");
    printf("\n");

    //proses input
    start:
    printf("Nama Karyawan: ");
    scanf("%[^\n]", nama);

    printf("Masukkan Golongan Jabatan: \n");
    printf("1. Golongan 1 \n");
    printf("2. Golongan 2 \n");
    printf("3. Golongan 3 \n");
    printf("Pilihan: ");
    scanf("%d", &g_jabatan);
    if (g_jabatan == 1)
    {
        t_jabatan = 0.05 * 2000000;
    }
    else if (g_jabatan == 2)
    {
        t_jabatan = 0.1 * 2000000;
    }
    else if (g_jabatan == 3)
    {
        t_jabatan = 0.15 * 2000000;
    }

    printf("Masukkan Golongan Pendidikan: \n");
    printf("1. SMA \n");
    printf("2. D3 \n");
    printf("3. S1 \n");
    printf("Pilihan: ");
    scanf("%d", &g_pendidikan);
    if (g_pendidikan == 1)
    {
        t_pendidikan = 0.025 * 2000000;
    }
    else if (g_pendidikan == 2)
    {
        t_pendidikan = 0.05 * 2000000;
    }
    else if (g_pendidikan == 3)
    {
        t_pendidikan = 0.1 * 2000000;
    }
    printf("Jam kerja: ");
    scanf("%d", &jam_kerja);

    lembur = ((jam_kerja - 8) * 24) * 3000;
    total = 2000000 + t_jabatan + t_pendidikan + lembur;

    //proses output
    printf("\n");
    printf("================================ \n");
    printf("Nama Karyawan: %s\n", nama);
    printf("Tunjangan Jabatan: Rp %.0f \n", t_jabatan);
    printf("Tunjangan Pendidikan: Rp %.0f \n", t_pendidikan);
    printf("Honor Lembur: Rp %.0f \n", lembur);
    printf("Total Gaji: Rp %.0f \n", total);
    
    return 0;
}
