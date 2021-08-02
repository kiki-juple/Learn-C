#include <stdio.h>

int main(){
    int fee = 2000, time;
    float noDisc, withDisc, disc;

    printf("BILLING GAME ONLINE\n");
    printf("=========================================\n");

    //proses input
    printf("Masukkan lama bermain (jam): ");
    scanf("%d", &time);

    //perhitungan
    disc = (float) fee * time * 0.2;
    noDisc = (float) fee * time;
    withDisc = noDisc - disc;
    
    //proses output
    printf("=========================================\n");
    if (time <= 5){
        printf("Jumlah yang harus dibayar adalah: Rp%.0f", noDisc);
    }
    else{
        printf("Jumlah yang harus dibayar adalah: Rp%.0f", withDisc);
    }
    return 0;
}