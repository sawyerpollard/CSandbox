#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_WORD_LENGTH 100

typedef struct char_freq {
    int c;
    int freq;
} char_freq;

int comp(const void *a, const void *b) {
    char_freq a_cf = *((char_freq*) a);
    char_freq b_cf = *((char_freq*) b);

    if (a_cf.freq > b_cf.freq) return 1;
    if (a_cf.freq < b_cf.freq) return -1;
    return 0;
}

int main() {


    char_freq char_freqs[CHAR_MAX];
    for (int i = 0; i < CHAR_MAX; ++i) {
        char_freqs[i].c = i;
        char_freqs[i].freq = 0;
    }

    int word_length_freqs[MAX_WORD_LENGTH] = {0};

    int word_length = 0;

    int c;
    while ((c = getchar()) != EOF) {
        ++char_freqs[c].freq;

        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_length > 0 && word_length < MAX_WORD_LENGTH) {
                ++word_length_freqs[word_length];
            }

            word_length = 0;
        } else {
            ++word_length;
        }
    }

    printf("Word Length\t\tFrequency\n");
    for (int i = 1; i < MAX_WORD_LENGTH; ++i) {
        if (word_length_freqs[i] > 0) {
            printf("%d\t\t%d\n", i, word_length_freqs[i]);
        }
    }

    qsort(char_freqs, sizeof(char_freqs)/sizeof(char_freqs[0]), sizeof(char_freqs[0]), comp);
    printf("\nCharacter\t\tFrequency\n");
    /* Loop from ' ' to '~' */
    for (int i = 32; i < 126; ++i) {
        if (char_freqs[i].freq > 0 && char_freqs[i].c !='\n') {
            printf("%c\t\t%d\n", char_freqs[i].c, char_freqs[i].freq);
        }
    }
}
