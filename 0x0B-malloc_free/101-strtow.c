#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

static bool is_space(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

static size_t count_words(char *str) {
    size_t count = 0;
    bool in_word = false;

    while (*str != '\0') {
        if (!in_word && !is_space(*str)) {
            in_word = true;
            count++;
        } else if (in_word && is_space(*str)) {
            in_word = false;
        }
        str++;
    }

    return count;
}

static char *copy_word(char *str) {
    size_t len = 0;
    char *word = str;

    while (*str != '\0' && !is_space(*str)) {
        str++;
        len++;
    }

    word = malloc(len + 1);
    if (word != NULL) {
        for (size_t i = 0; i < len; i++) {
            word[i] = *(str - len + i);
        }
        word[len] = '\0';
    }

    return word;
}

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    size_t num_words = count_words(str);
    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words != NULL) {
        size_t i = 0;

        while (*str != '\0') {
            if (!is_space(*str)) {
                char *word = copy_word(str);
                if (word != NULL) {
                    words[i++] = word;
                } else {
                    for (size_t j = 0; j < i; j++) {
                        free(words[j]);
                    }
                    free(words);
                    return NULL;
                }
                str += strlen(word);
            } else {
                str++;
            }
        }

        words[i] = NULL;
    }

    return words;
}

