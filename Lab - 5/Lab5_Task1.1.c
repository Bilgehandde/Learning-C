#include <stdio.h>
#include <stdlib.h>

// Define a structure for employee
struct Employee {
    int age;
    int idNumber;
    float salary;
};

int main() {
    // Declare variables to store information of two employees
    struct Employee emp1, emp2;

    // Assign values to employee 1
    emp1.age = 18;
    emp1.idNumber = 22014564;
    emp1.salary = 3300.0;

    // Assign values to employee 2
    emp2.age = 31;
    emp2.idNumber = 22014563;
    emp2.salary = 455.0;

    // Print information of employee 1
    printf("Employee 1:\n");
    printf("Age: %d\n", emp1.age);
    printf("ID Number: %d\n", emp1.idNumber);
    printf("Salary: $%.2f\n\n", emp1.salary);

    // Print information of employee 2
    printf("Employee 2:\n");
    printf("Age: %d\n", emp2.age);
    printf("ID Number: %d\n", emp2.idNumber);
    printf("Salary: $%.2f\n", emp2.salary);

    return 0;
}
