#include <stdio.h>
#include <math.h>

int main()
{
    int first_number, second_number, mod1, mod2, total, square;
    float mean;
    
    do{
        printf("Bilangan pertama: ");
        scanf("%d", &first_number);
        mod1 = first_number%2;
        if(mod1!=1){
            printf("Bilangan pertama harus ganjil\n");
        }
    }while(mod1!=1);
    
    do{
        printf("Bilangan kedua: ");
        scanf("%d", &second_number);
        mod2 = second_number%2;
        if(mod2!=0){
            printf("Bilangan kedua harus genap\n");
        }
    }while(mod2!=0);
    
    total = first_number+second_number;
    mean = (float)total/2;
    square = pow(total,2);
    
    printf("Jumlah : %d\n", total);
    printf("Rata-Rata : %.1f\n", mean);
    printf("Kuadrat : %d\n", square);
    return 0;
}