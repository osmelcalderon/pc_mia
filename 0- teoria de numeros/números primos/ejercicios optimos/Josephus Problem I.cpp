#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%i", &n);

    bool niños[200001];
    for (int i = 0; i < n; i++) {
        niños[i] = false;
    }

    int niños_retirados = 0;
    int pasos = 0;
    while (niños_retirados < n) {
        for (int i = 0; i < n; i++) {
            if (!niños[i]) {
                pasos++;
            }
            if (pasos == 2) {
                niños_retirados++;
                niños[i] = true;
                printf("%i ", i + 1);
                pasos = 0;
            }
        }
    }
}