#include <stdio.h>

int main() {
    FILE *fp;
    char word[100]; 
    char filename[50]; // Buffer to hold the filename

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the content of the file word by word
    while (fscanf(fp, "%99s", word) == 1) { // Read a word with a maximum length of 99 characters
        printf("%s\n", word); // Print each word to the screen
    }

    // Close the file
    fclose(fp);

    return 0;
}
