#include <stdio.h>
#include <stdlib.h>

// Define a structure for complex numbers
struct Complex {
    float real;
    float imaginary;
};

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

int main() {
    // Declare variables to store complex numbers
    struct Complex num1, num2, result;

    // Input real and imaginary parts of first complex number
    printf("Enter real and imaginary parts of first complex number:\n");
    printf("Real part: ");
    scanf("%f", &num1.real);
    printf("Imaginary part: ");
    scanf("%f", &num1.imaginary);

    // Input real and imaginary parts of second complex number
    printf("\nEnter real and imaginary parts of second complex number:\n");
    printf("Real part: ");
    scanf("%f", &num2.real);
    printf("Imaginary part: ");
    scanf("%f", &num2.imaginary);

    // Add the complex numbers
    result = addComplex(num1, num2);

    // Print the result
    printf("\nSum of the complex numbers: %.2f + %.2fi\n", result.real, result.imaginary);

    return 0;
}
