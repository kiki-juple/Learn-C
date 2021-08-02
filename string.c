#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char kal1[100], kal2[100];
    int a, b, c, d;
    
    printf("Kalimat 1 = ");
    gets(kal1);
    //scanf("%[^\n]%*c", kal1);
	
    printf("Kalimat 2 = ");
    gets(kal2);
   // scanf("%[^\n]%*c", kal2);

    a = strlen(kal1);
    b = strlen(kal2);
    c = a + b;
    d = a * b;
    
    printf("Gabungan 2 buah inputan kalimat = %s %s\n", kal1, kal2); 
    printf("Hasil membalik kalimat gabungan = %s %s\n", strrev(kal2), strrev(kal1));
    printf("Jumlah huruf kalimat pertama = %d\n", a);
    printf("Jumlah huruf kalimat kedua = %d\n", b);
    printf("Total jumlah huruf = %d\n", c);
    printf("Total perkalian kalimat = %d\n", d);     
    return 0;
}