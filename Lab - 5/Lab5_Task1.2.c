#include <stdio.h>
#include <stdlib.h>
	
	// Yapı tanımı: Student (Öğrenci)
struct Student {
    char name[35];
    int id;
    float midterm_grade;
    float final_grade;
};

// Fonksiyon tanımı: Ortalama hesapla
float calculateAverage(struct Student *student) {
    return (student->midterm_grade + student->final_grade) / 2.0;
}

int main() {
    // Öğrencinin bilgilerini alma
    struct Student student; // Pointer olmadan struct Student tipinde bir değişken tanımladık
    struct Student *studentPtr = &student; // Struct Student tipinde pointer tanımladık ve bu pointer'a student değişkeninin adresini atadık

    printf("Enter student's name: ");
    scanf("%s", studentPtr->name); // Pointer kullanarak struct içindeki elemanlara eriştik
    printf("Enter student's ID: ");
    scanf("%d", &studentPtr->id);
    printf("Enter student's midterm grade: ");
    scanf("%f", &studentPtr->midterm_grade);
    printf("Enter student's final grade: ");
    scanf("%f", &studentPtr->final_grade);

    // Ortalama notu hesaplama
    float average = calculateAverage(studentPtr); // Pointer'ı calculateAverage fonksiyonuna gönderdik

    // Bilgileri ekrana yazdırma
    printf("\nStudent Information:\n");
    printf("Name: %s\n", studentPtr->name);
    printf("ID: %d\n", studentPtr->id);
    printf("Midterm Grade: %.2f\n", studentPtr->midterm_grade);
    printf("Final Grade: %.2f\n", studentPtr->final_grade);
    printf("Average Grade: %.2f\n", average);

    return 0;
}


