#include <stdio.h>
#include <string.h>

// Function to compare the lengths of two words
int compare_word_lengths(const char *word1, const char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 == len2) {
        return 0; // The two words are equal in length
    } else if (len1 >= len2) {
        return 1; // The first word is longer or has the same length
    } else {
        return -1; // The second word is longer
    }
}

int main() {
    char word1[100], word2[100]; // Buffers to hold the two words

    // Prompt the user to enter the first word
    printf("Enter the first word: ");
    scanf("%99s", word1); // Read a word with a maximum length of 99 characters

    // Prompt the user to enter the second word
    printf("Enter the second word: ");
    scanf("%99s", word2); // Read a word with a maximum length of 99 characters

    // Compare the lengths of the two words
    int result = compare_word_lengths(word1, word2);

    // Print the result
    printf("%d\n", result);

    return 0;
}
