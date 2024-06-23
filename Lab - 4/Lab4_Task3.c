#include <stdio.h>
#include <stdlib.h>

//OLCHLT

int main() {
    int N;
    printf("Dizinin eleman sayisini girin: ");
    scanf("%d", &N);

    int array[N]; // N elemanl� bir dizi olu�tur

    // Diziyi ba�lang�� de�erleriyle doldur
    for (int i = 0; i < N; i++) {
        *(array + i) = (i + 6) * 10; 
    }

    // Her eleman�n de�erini ve adresini yazd�r
    printf("Dizi Elemanlari ve Adresleri:\n");

    int *curr = array; // Ba�lang�� adresi

    while (curr <= &array[N - 1]) {
        printf("Dizi[%ld] degeri: %d, adresi: %p\n", curr - array, *curr, (void*)curr);
        curr++; // ��aret�iyi bir sonraki elemana ta��
    }

    return 0;
}
