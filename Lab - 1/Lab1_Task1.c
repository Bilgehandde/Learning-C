#include <stdio.h>
#include <stdlib.h>

int fact(int a) {
    int i;
    int sonuc = 1; // Faktöriyel sonucunu saklayacak deðiþkeni tanýmlýyoruz

    for (i = 1; i <= a; i++) {
        sonuc *= i; // Her adýmda sonucu i ile çarpýyoruz
    }

    return sonuc; // Hesaplanan faktöriyel deðerini geri döndürüyoruz
}

int main() {
    int a, sonuc;

    printf("Please enter a number : ");
    scanf("%d", &a);
    
    sonuc = fact(a); // fact fonksiyonunun döndürdüðü deðeri sonuç deðiþkenine atýyoruz
    printf("fact : %d\n", sonuc); // Sonucu ekrana yazdýrýyoruz
    
    return 0;
}

