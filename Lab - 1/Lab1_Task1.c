#include <stdio.h>
#include <stdlib.h>

int fact(int a) {
    int i;
    int sonuc = 1; // Fakt�riyel sonucunu saklayacak de�i�keni tan�ml�yoruz

    for (i = 1; i <= a; i++) {
        sonuc *= i; // Her ad�mda sonucu i ile �arp�yoruz
    }

    return sonuc; // Hesaplanan fakt�riyel de�erini geri d�nd�r�yoruz
}

int main() {
    int a, sonuc;

    printf("Please enter a number : ");
    scanf("%d", &a);
    
    sonuc = fact(a); // fact fonksiyonunun d�nd�rd��� de�eri sonu� de�i�kenine at�yoruz
    printf("fact : %d\n", sonuc); // Sonucu ekrana yazd�r�yoruz
    
    return 0;
}

