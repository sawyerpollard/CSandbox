#include <stdio.h>

#define START 0
#define END 100
#define STEP 10

int main() {
    float cels, fahr;

    printf("Celsius\t\tFahrenheit\n");
    for (float n = START; n <= END; n += STEP) {
        cels = n;
        fahr = (9.0/5.0) * cels + 32.0;

        printf("%.1f\t\t%.1f\n", cels, fahr);
    }
}
