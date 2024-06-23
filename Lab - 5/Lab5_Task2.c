#include <stdio.h>
#include <stdlib.h>


int main() {
    int *arr1, *arr2, *arr3; // Pointerlar için deðiþkenler tanýmlanýr

    int size = 8; // Dizi boyutu

    // malloc ile bellek tahsisi
    arr1 = (int *)malloc(size * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // calloc ile bellek tahsisi
    arr2 = (int *)calloc(size, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // realloc ile bellek tahsisi
    int size2 = 4; // Yeni dizi boyutu
    arr3 = (int *)realloc(arr2, size2 * sizeof(int));
    if (arr3 == NULL) {
        printf("Memory reallocation failed\n");
        free(arr2); // realloc baþarýsýz olursa önceki belleði serbest býrak
        return 1;
    }

    // Ýçeriði yazdýrma
    printf("Content of array allocated using malloc():\n");
    printArray(arr1, size);

    printf("\nContent of array allocated using calloc():\n");
    printArray(arr2, size);

    printf("\nContent of array reallocated using realloc():\n");
    printArray(arr3, size2);

    // Bellek serbest býrakma
    free(arr1);
    free(arr3);

    return 0;
}

// Diziyi yazdýrmak için yardýmcý fonksiyon
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
