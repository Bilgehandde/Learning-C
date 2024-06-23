#include <stdio.h>
#include <stdlib.h>

// Define a structure for student
struct Student {
    char name[35];
    int ID;
    float GPA;
};

int main() {
    int num_students = 3;

    // Dynamically allocate memory for an array of students
    struct Student *students = (struct Student *)malloc(num_students * sizeof(struct Student));

    // Check if memory allocation was successful
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
	
    // Input data for each student
    for (int i = 0; i < num_students; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);  // Note: %s will stop at space, if you want full name, use fgets
        printf("ID: ");
        scanf("%d", &students[i].ID);
        printf("GPA: ");
        scanf("%f", &students[i].GPA);
    }

    // Print data for each student
    printf("\nDetails of students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("ID : %d\n", students[i].ID);
        printf("GPA: %.2f\n", students[i].GPA);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
