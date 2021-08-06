#include <stdio.h>
#include <string.h>
#define MAX 5

FILE *filePointer;
char history[1000];

typedef struct
{
    char namaMinuman[10];
    char size[10];
    char serving[10];
    int price;
} Data;

void inputData()
{
    Data d[MAX];
    printf("\n===== INPUT DATA =====");
    for (int i = 0; i <= 5; i++)
    {
        do
        {
            printf("\nNama Minuman: ");
            scanf("%s", d[i].namaMinuman);
            if (strcmp(d[i].namaMinuman, "Kopi") != 0 && strcmp(d[i].namaMinuman, "Teh") != 0 && strcmp(d[i].namaMinuman, "Coklat") != 0 && strcmp(d[i].namaMinuman, "Soda") != 0)
            {
                printf("Maaf minuman tidak tersedia, silahkan pilih minuman lain\n");
            }
        } while (strcmp(d[i].namaMinuman, "Kopi") != 0 && strcmp(d[i].namaMinuman, "Teh") != 0 && strcmp(d[i].namaMinuman, "Coklat") != 0 && strcmp(d[i].namaMinuman, "Soda") != 0);
        do
        {
            printf("Size: ");
            scanf("%s", d[i].size);
            if (strcmp(d[i].size, "Small") != 0 && strcmp(d[i].size, "Medium") != 0 && strcmp(d[i].size, "Large") != 0)
            {
                printf("Maaf size tidak tersedia, silahkan masukkan size lain\n");
            }
        } while (strcmp(d[i].size, "Small") != 0 && strcmp(d[i].size, "Medium") != 0 && strcmp(d[i].size, "Large") != 0);
        do
        {
            printf("Penyajian: ");
            scanf("%s", d[i].serving);
            if (strcmp(d[i].serving, "Panas") != 0 && strcmp(d[i].serving, "Dingin") != 0 && strcmp(d[i].serving, "Hangat") != 0)
            {
                printf("maaf Penyajian tidak tersedia, silahkan masukkan penyajian lain\n");
            }
        } while (strcmp(d[i].serving, "Panas") != 0 && strcmp(d[i].serving, "Dingin") != 0 && strcmp(d[i].serving, "Hangat") != 0);

        d[i].price = strlen(d[i].namaMinuman) * strlen(d[i].size) * strlen(d[i].serving) * 100;
        printf("============================\n");
        printf("Detail pesanan: %d", i + 1);
        printf("\nNama Minuman: %s", d[i].namaMinuman);
        printf("\nSize: %s", d[i].size);
        printf("\nPenyajian: %s", d[i].serving);
        printf("\nHarga: %d", d[i].price);
        printf("\n============================");

        char k;
        do
        {
            printf("\nIngin pesan lagi? [y/n]: ");
            scanf("%c", &k);
            switch (k)
            {
            case 'y':
                filePointer = fopen("dataminuman.txt", "a");
                fprintf(filePointer, "No: \nNama minuman: \nSize: \nPenyajian: \nHarga: ", i + 1, d[i].namaMinuman, d[i].size, d[i].serving, d[i].price);
                break;
            case 'n':
                return;
            default:
                printf("Hanya masukkan y/n\n");
                break;
            }
        } while (k != 'y' || k != 'n');
    }
}

void viewHistory()
{
    printf("\n===== History Penjualan =====");
    filePointer = fopen("dataminuman.txt", "r");
    if (filePointer == NULL)
    {
        printf("\nTidak ada history.");
    }
    else
    {
        printf("\n");
        while (fgets(history, 50, filePointer) != NULL)
        {
            printf("%s", history);
        }
        fclose(filePointer);
    }
}

void deleteHistory()
{
    fopen("dataminuman.txt", "wb");
    printf("History berhasil dihapus.");
}

void main()
{
    filePointer = fopen("dataminuman.txt", "w");
    int s;
    do
    {
        printf("\nMENU:\n");
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
            fopen("dataminuman.txt", "a");
            printf("Terimakasih");
            return;
        default:
            printf("Salah memasukkan menu, coba lagi.\n");
            break;
        }
    } while (s != 4);
}