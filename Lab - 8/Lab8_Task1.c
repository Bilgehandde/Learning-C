#include <stdio.h>

int main() {
    unsigned int a = 10; // 
    unsigned int b = 15; // 
    int result;

    // Bitwise AND
    result = a & b; // 
    printf("Result of a & b: %d\n", result);

    // Bitwise OR
    result = a | b; // 
    printf("Result of a | b: %d\n", result);

    // Bitwise XOR
    result = a ^ b; // 
    printf("Result of a ^ b: %d\n", result);

    // Bitwise NOT
    result = ~a; // 
    printf("Result of ~a: %d\n", result);

    // Left shift
    result = a << 2; 
    printf("Result of a << 2: %d\n", result);

    // Right shift
    result = a >> 2; 
    printf("Result of a >> 2: %d\n", result);

    return 0;
}
