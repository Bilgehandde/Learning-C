#include <stdio.h>

int main() {
    FILE *fp;
    char line[100]; 
    char filename[50]; 
    int line_number = 1; // Line number counter

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the content of the file line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%d: %s", line_number, line); // Print each line with line number
        line_number++;
    }

    // Close the file
    fclose(fp);

    return 0;
}
