#include <stdio.h>
#include <string.h>

#define MAX 256

FILE *fp1, *fp2;
char history[MAX];
char file[] = "dataminuman.txt";
char temp[] = "temp.txt";

struct Data
{
    char namaMinuman[10];
    char size[10];
    char serving[10];
    int price;
} d;

void inputData()
{
    char c;
    printf("\n===== INPUT DATA =====\n");
    do
    {
        printf("Nama Minuman: ");
        scanf("%s", d.namaMinuman);
        if (strcmp(d.namaMinuman, "Kopi") != 0 && strcmp(d.namaMinuman, "Teh") != 0 && strcmp(d.namaMinuman, "Coklat") != 0 && strcmp(d.namaMinuman, "Soda") != 0 &&
            strcmp(d.namaMinuman, "kopi") != 0 && strcmp(d.namaMinuman, "teh") != 0 && strcmp(d.namaMinuman, "coklat") != 0 && strcmp(d.namaMinuman, "soda") != 0)
        {
            printf("Maaf minuman tidak tersedia, silahkan masukkan minuman lain\n");
        }
    } while (strcmp(d.namaMinuman, "Kopi") != 0 && strcmp(d.namaMinuman, "Teh") != 0 && strcmp(d.namaMinuman, "Coklat") != 0 && strcmp(d.namaMinuman, "Soda") != 0 &&
             strcmp(d.namaMinuman, "kopi") != 0 && strcmp(d.namaMinuman, "teh") != 0 && strcmp(d.namaMinuman, "coklat") != 0 && strcmp(d.namaMinuman, "soda") != 0);
    do
    {
        printf("Size: ");
        scanf("%s", d.size);
        if (strcmp(d.size, "Small") != 0 && strcmp(d.size, "Medium") != 0 && strcmp(d.size, "Largest") != 0 &&
            strcmp(d.size, "small") != 0 && strcmp(d.size, "medium") != 0 && strcmp(d.size, "largest") != 0)
        {
            printf("Maaf size tidak tersedia, silahkan masukkan size lain\n");
        }
    } while (strcmp(d.size, "Small") != 0 && strcmp(d.size, "Medium") != 0 && strcmp(d.size, "Largest") != 0 &&
             strcmp(d.size, "small") != 0 && strcmp(d.size, "medium") != 0 && strcmp(d.size, "largest") != 0);
    do
    {
        printf("Penyajian: ");
        scanf("%s", d.serving);
        if (strcmp(d.serving, "Panas") != 0 && strcmp(d.serving, "Dingin") != 0 && strcmp(d.serving, "Hangat") != 0 &&
            strcmp(d.serving, "panas") != 0 && strcmp(d.serving, "dingin") != 0 && strcmp(d.serving, "hangat") != 0)
        {
            printf("Maaf penyajian tidak tersedia, silahkan masukkan penyajian lain\n");
        }
    } while (strcmp(d.serving, "Panas") != 0 && strcmp(d.serving, "Dingin") != 0 && strcmp(d.serving, "Hangat") != 0 &&
             strcmp(d.serving, "panas") != 0 && strcmp(d.serving, "dingin") != 0 && strcmp(d.serving, "hangat") != 0);

    d.price = strlen(d.namaMinuman) * strlen(d.size) * strlen(d.serving) * 100;
    printf("======== DETAIL PESANAN ========\n");
    printf("\nNama minuman: %s", d.namaMinuman);
    printf("\nSize: %s", d.size);
    printf("\nPenyajian: %s", d.serving);
    printf("\nHarga: %d", d.price);
    printf("\n============================");

    while (!0)
    {
        printf("\nSimpan pesanan? [y/n]: ");
        scanf(" %c", &c);
        switch (c)
        {
        case 'Y':
        case 'y':
            fp1 = fopen(file, "a");
            fprintf(fp1, "Nama minuman: %s, Size: %s, Penyajian: %s, Harga: %d\n", d.namaMinuman, d.size, d.serving, d.price);
            fclose(fp1);
            printf("Data telah disimpan kedalam history.\n");
            return;
        case 'N':
        case 'n':
            return;
        default:
            printf("Pilihan salah");
            break;
        }
    }
}

void viewHistory()
{
    int line = 0;
    printf("\n=== VIEW HISTORY ===\n");
    fp1 = fopen(file, "r");
    if (fp1 == NULL)
    {
        printf("File tidak ditemukan.\n");
    }
    else
    {
        while (fgets(history, MAX, fp1) != NULL)
        {
            ++line;
            printf("%i. %s", line, history);
        }
        fclose(fp1);
    }
}

void deleteHistory()
{
    int index, ctr = 0;
    printf("\n=== DELETE HISTORY ===\n");
    fp1 = fopen(file, "r");
    if (fp1 == NULL)
    {
        printf("File tidak ditemukan.\n");
        return;
    }
    fp2 = fopen(temp, "w");
    if (fp2 == NULL)
    {
        printf("Gagal mengubah indeks file.\n");
        fclose(fp1);
        return;
    }

    printf("Masukkan indeks data yang akan dihapus: ");
    scanf("%d", &index);
    while (!feof(fp1))
    {
        strcpy(history, "\0");
        fgets(history, MAX, fp1);
        if (!feof(fp1))
        {
            ctr++;
            if (ctr != index)
            {
                fprintf(fp2, "%s", history);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove(file);
    rename(temp, file);
    printf("Indeks berhasil dihapus.\n");
}

int main(void)
{

    int s;
    fp1 = fopen(file, "r");
    if (fp1 == NULL)
    {
        printf("Gagal membuka file dataminuman.txt.\n");
    }
    fclose(fp1);
    do
    {
        printf("MENU:\n");
        printf("1. INPUT DATA\n");
        printf("2. VIEW HISTORY\n");
        printf("3. DELETE HISTORY\n");
        printf("4. EXIT\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            inputData();
            break;
        case 2:
            viewHistory();
            break;
        case 3:
            deleteHistory();
            break;
        case 4:
            printf("Terimakasih");
            return 0;
        default:
            printf("Salah memasukkan menu, coba lagi.\n");
            break;
        }
    } while (s != 4);
}