#include <stdio.h>

#define START 0
#define END 100
#define STEP 10

int main() {
    float cels, fahr, c_to_f(float);

    printf("Celsius\t\tFahrenheit\n");
    for (float n = START; n <= END; n += STEP) {
        cels = n;
        fahr = c_to_f(cels);

        printf("%.1f\t\t%.1f\n", cels, fahr);
    }
}

/* Convert from Celsius to Fahrenheit */
float c_to_f(float celsius) {
    return (9.0/5.0) * celsius + 32.0;
}
