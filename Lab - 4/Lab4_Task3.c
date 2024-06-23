#include <stdio.h>
#include <stdlib.h>

//OLCHLT

int main() {
    int N;
    printf("Dizinin eleman sayisini girin: ");
    scanf("%d", &N);

    int array[N]; // N elemanlý bir dizi oluþtur

    // Diziyi baþlangýç deðerleriyle doldur
    for (int i = 0; i < N; i++) {
        *(array + i) = (i + 6) * 10; 
    }

    // Her elemanýn deðerini ve adresini yazdýr
    printf("Dizi Elemanlari ve Adresleri:\n");

    int *curr = array; // Baþlangýç adresi

    while (curr <= &array[N - 1]) {
        printf("Dizi[%ld] degeri: %d, adresi: %p\n", curr - array, *curr, (void*)curr);
        curr++; // Ýþaretçiyi bir sonraki elemana taþý
    }

    return 0;
}
