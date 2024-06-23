#include <stdio.h>

int main() {
    int num;

    // Input the number
    printf("Enter an number ==> ");
    scanf("%d", &num);

    // Check if the number is odd or even using bitwise AND operator
    if (num & 1) {
        printf("%d is odd.\n", num);
    } else {
        printf("%d is even.\n", num);
    }

    return 0;
}
