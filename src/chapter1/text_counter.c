#include <stdio.h>

#define WORD_IN 1
#define WORD_OUT 0

int main() {
    int nc = 0, nw = 0, nl = 0;

    int word_state = WORD_OUT;

    char c;
    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == ' ' || c == '\n' || c == '\t') {
            word_state = WORD_OUT;
        } else if (word_state == WORD_OUT) {
            word_state = WORD_IN;
            ++nw;
        }

        if (c == '\n') {
            ++nl;
        }
    }

    printf("Number of characters: %d\nNumber of words: %d\nNumber of lines: %d\n", nc, nw, nl);
}
