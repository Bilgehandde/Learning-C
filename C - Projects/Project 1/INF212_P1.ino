#include <LiquidCrystal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int takenumber(long long int ID, int flag, int initial, int number) {
   char id_str[20]; // ID'yi tutacak bir karakter dizisi oluşturuyoruz, 20 karakter yeterlidir varsayalım.
    snprintf(id_str, sizeof(id_str), "%lld", ID); // ID'yi stringe dönüştürüyoruz.

    // flag kontrolü
    if (flag == 0) {
        // initial değeri ID stringindeki bir indexi temsil ediyor
        // number değeri ise bu indexten sonraki kaç indexin alınacağını belirtiyor
        int id_length = strlen(id_str);
        if (initial < id_length) { // initial değeri ID stringinin uzunluğundan küçük olduğunda devam ediyoruz
            char result[20]; // Sonuç karakter dizisi
            int i;
            for (i = 0; i < number && (initial + i) < id_length; i++) {
                result[i] = id_str[initial + i - 1];
            }
            result[i] = '\0'; // Sonuç karakter dizisinin sonuna null karakter ekleyerek bir C stringi haline getiriyoruz
            return atoi(result); // Sonuç karakter dizisini tamsayıya dönüştürüyoruz ve döndürüyoruz
    	} 
	}
	
	if (flag == 1) {
        // initial değeri ters yönde ID stringindeki bir indexi temsil ediyor
        // number değeri ise bu indexten önceki kaç indexin alınacağını belirtiyor
        int id_length = strlen(id_str);
        if (initial < id_length) { // initial değeri ID stringinin uzunluğundan küçük olduğunda devam ediyoruz
            char result[20]; // Sonuç karakter dizisi
            int i;
            for (i = 0; i < number; i++) {
                result[i] = id_str[id_length - initial + i];
            }
            result[i] = '\0'; // Sonuç karakter dizisinin sonuna null karakter ekleyerek bir C stringi haline getiriyoruz
            return atoi(result); // Sonuç karakter dizisini tamsayıya dönüştürüyoruz ve döndürüyoruz
        } 
    }

}

void setup() {
    lcd.begin(16, 2);
    long long int ID = 220102002035LL;
    int a = takenumber(ID, 0, 1, 2);
    int b = takenumber(ID, 1, 4, 2);
    int c = takenumber(ID, 1, 2, 2);
    int x0 = minnumber(ID);
    int x1 = maxnumber(ID);
    float step = average(ID) / 100;
    float calculated_area = area(a, b, c, x0, x1, step);
    lcd.print("ID 220102002035");
    delay(2000);
    lcd.clear();
    lcd.print(" Please wait  ");
    lcd.setCursor(0, 1);
    lcd.print(" Loading... ");
    delay(3000);
    lcd.clear();
    lcd.print("a => ");
    lcd.print(a);
    lcd.setCursor(0, 1);
    lcd.print("b => ");
    lcd.print(b);
    delay(3000);
    lcd.clear();
    lcd.print("c => ");
    lcd.print(c);
    lcd.setCursor(0, 1);
    lcd.print("Area => ");
    lcd.print(calculated_area, 3);
    delay(3000);
    char firsthexa = dec2hexa(22, 0);
    char secondhexa = dec2hexa(35, 1);
    lcd.clear();
    lcd.print("1st Hex => ");
    lcd.print(firsthexa);
    lcd.setCursor(0, 1);
    lcd.print("2nd Hex => ");
    lcd.print(secondhexa);
    delay(5000);
    lcd.clear();
}

void loop() {
}

int minnumber(long long int ID) {
    int min_num = 9;
    while (ID > 0) {
        int dig = ID % 10;
        if (dig < min_num) {
            min_num = dig;
        }
        ID /= 10;
    }
    return min_num;
}

int maxnumber(long long int ID) {
    int max_num = 0;
    while (ID > 0) {
        int dig = ID % 10;
        if (dig > max_num) {
            max_num = dig;
        }
        ID /= 10;
    }
    return max_num;
}

float average(long long int ID) {
    int sum = 0;
    int count = 0;
    while (ID > 0) {
        int dig = ID % 10;
        sum += dig;
        count++;
        ID /= 10;
    }
    return (float)sum / count;
}

float area(int a, int b, int c, int x0, int x1, float step) {
    float area = 0;
    for (float x = x0; x <= x1; x += step) {
        area += (a * x * x + b * x + c) * step;
    }
    return area;
}

char dec2hexa(int number, int flag) {
    char hexa_char;
    if (flag == 0) {
        hexa_char = number / 16;
    } else {
        hexa_char = number % 16;
    }
    if (hexa_char < 10) {
        hexa_char += '0';
    } else {
        hexa_char += 'A' - 10;
    }
    return hexa_char;
}