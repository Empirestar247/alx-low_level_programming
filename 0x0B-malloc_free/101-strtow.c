#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }
    
    // Count the number of words in the string
    int num_words = 0;
    char *p = str;
    while (*p != '\0') {
        while (isspace(*p)) {
            p++;
        }
        if (*p != '\0') {
            num_words++;
            while (*p != '\0' && !isspace(*p)) {
                p++;
            }
        }
    }
    
    // Allocate memory for the array of words
    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }
    
    // Copy each word into the array
    int i = 0;
    p = str;
    while (*p != '\0') {
        while (isspace(*p)) {
            p++;
        }
        if (*p != '\0') {
            char *word_start = p;
            while (*p != '\0' && !isspace(*p)) {
                p++;
            }
            char *word = malloc((p - word_start + 1) * sizeof(char));
            if (word == NULL) {
                // Free memory for previously allocated words
                for (int j = 0; j < i; j++) {
                    free(words[j]);
                }
                free(words);
                return NULL;
            }
            strncpy(word, word_start, p - word_start);
            word[p - word_start] = '\0';
            words[i++] = word;
        }
    }
    words[i] = NULL;
    
    return words;
}

