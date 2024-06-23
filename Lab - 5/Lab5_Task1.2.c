#include <stdio.h>
#include <stdlib.h>
	
	// Yap� tan�m�: Student (��renci)
struct Student {
    char name[35];
    int id;
    float midterm_grade;
    float final_grade;
};

// Fonksiyon tan�m�: Ortalama hesapla
float calculateAverage(struct Student *student) {
    return (student->midterm_grade + student->final_grade) / 2.0;
}

int main() {
    // ��rencinin bilgilerini alma
    struct Student student; // Pointer olmadan struct Student tipinde bir de�i�ken tan�mlad�k
    struct Student *studentPtr = &student; // Struct Student tipinde pointer tan�mlad�k ve bu pointer'a student de�i�keninin adresini atad�k

    printf("Enter student's name: ");
    scanf("%s", studentPtr->name); // Pointer kullanarak struct i�indeki elemanlara eri�tik
    printf("Enter student's ID: ");
    scanf("%d", &studentPtr->id);
    printf("Enter student's midterm grade: ");
    scanf("%f", &studentPtr->midterm_grade);
    printf("Enter student's final grade: ");
    scanf("%f", &studentPtr->final_grade);

    // Ortalama notu hesaplama
    float average = calculateAverage(studentPtr); // Pointer'� calculateAverage fonksiyonuna g�nderdik

    // Bilgileri ekrana yazd�rma
    printf("\nStudent Information:\n");
    printf("Name: %s\n", studentPtr->name);
    printf("ID: %d\n", studentPtr->id);
    printf("Midterm Grade: %.2f\n", studentPtr->midterm_grade);
    printf("Final Grade: %.2f\n", studentPtr->final_grade);
    printf("Average Grade: %.2f\n", average);

    return 0;
}


