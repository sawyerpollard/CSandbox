#include <stdio.h>

int main() {
    int blank_before = 0;

    char c;
    while ((c = getchar()) != EOF) {
        if (blank_before && c == ' ') continue;

        putchar(c);

        if (c == ' ') {
            blank_before = 1;
        } else {
            blank_before = 0;
        }
    }
}
