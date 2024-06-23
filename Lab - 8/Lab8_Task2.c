#include <stdio.h>

int main() {
    int x = 5; 
    int y = 288; 

    printf("Before swap: x = %d, y = %d\n", x, y);

    // Swap using XOR
    x = x ^ y; //x now holds the value of x ^ y
    y = x ^ y; //y now holds the value of (x ^ y) ^ y, which is x
    x = x ^ y; //x now holds the value of (x ^ y) ^ x, which is y

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

