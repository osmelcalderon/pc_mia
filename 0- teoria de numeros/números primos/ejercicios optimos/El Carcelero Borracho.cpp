#include <stdio.h>
#include <stdbool.h>

void toggle(bool *var) { *var = (*var) ? false : true; }

int main() {
    int t;
    scanf("%i", &t);

    while (t--) {
        int n;
        scanf("%i", &n);
        bool celdas[100];
        for (int i = 0; i < n; i++) {
            celdas[i] = false;
        }
        int ronda = 1;
        for (int i = 0; i < n; i++) {
            for (int j = ronda - 1; j < n; j += ronda) {
                toggle(&celdas[j]);
            }
            ronda++;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (celdas[i]) result++;
        }
        printf("%i\n", result);
    }
}