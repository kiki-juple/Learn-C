#include <stdio.h>

int add(int x, int y){
    int result = x + y;
    return result;
}

void main(){
    int a, b;
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &a);
    printf("Masukkan bilangan kedua: ");
    scanf("%d", &b);
    printf("\nHasil penjumlahannya adalah: %d", add(a, b));
}