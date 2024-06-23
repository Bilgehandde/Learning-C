#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */

int *findNumberAddress(int *array, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (*(array + i) == number) { // Check if the current element is equal to the requested number
            return (array + i); // Return the address of the number if found
        }
    }
    return 0; // If the number is not found, return 0
}

int main() {
    int array[] = {782, 43, 86, 850, 100};
    int size = sizeof(array) / sizeof(array[0]);

    int number;
    printf("Array ==> {782, 43, 86, 850, 100}\n");
    printf("Enter the number to find: ");
    scanf("%d", &number);

    int *address = findNumberAddress(array, size, number); // Call the function to find the address

    if (address != 0) {
        printf("Number %d is found at address ==> %p\n", number, (void *)address);
    } else {
        printf("Number %d is not found in the array.\n", number);
    }

    return 0;
}
