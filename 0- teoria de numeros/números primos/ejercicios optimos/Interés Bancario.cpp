#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    int *M = (int*)malloc(4);
    int16_t R, Y;
    scanf("%hi%i%hi", &R, M, &Y);

    double interest_rate = (R / 100.0) + 1;

    double result = *M;

    free(M);

    for (int i = 0; i < Y; i++) {
        result *= interest_rate;
    }
    printf("%i", (int)result);
}