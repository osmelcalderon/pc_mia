#include <stdio.h>
#include <stdint.h>

int32_t diff(int16_t *dd1, int16_t *dd2,
             int16_t *hh1, int16_t *hh2,
             int16_t *mm1, int16_t *mm2) {
    int32_t result;
    {
        int32_t mins1 = *mm1 + (*hh1 * 60) + ((*dd1 * 24) * 60);
        int32_t mins2 = *mm2 + (*hh2 * 60) + ((*dd2 * 24) * 60);

        result = mins2 - mins1;
    }
    return (result < 0) ? result *= -1 : result;
}

int main() {
    int16_t inputs[6];
    for (int i = 0; i < 6; i++) {
        scanf("%hi", &inputs[i]);
    }

    printf("%i", diff(
                &inputs[0], &inputs[3],
                &inputs[1], &inputs[4],
                &inputs[2], &inputs[5]
                     )
          );
}