#include <stdio.h>

int main() {
    int n;
    scanf("%i", &n);

    int tiempos[9];
    int dists[9];

    for (int i = 0; i < n; i++) {
        int h, m, d;
        scanf("%i%i%i", &h, &m, &d);

        tiempos[i] = (h * 60) + m;
        dists[i] = d;
    }

    int tiempo = 0;
    for (int i = 0; i < n; i++) {
        tiempo += tiempos[i];
    }

    int days = 0;
    int hours = 0;
    int mins = 0;
    mins = tiempo % 60;
    tiempo /= 60;
    hours = tiempo % 24;
    days = tiempo / 24;

    int velocidades[9];

    for (int i = 0; i < n; i++) {
        velocidades[i] = (dists[i] * 1000) / tiempos[i];
    }

    int major_index = 0;

    for (int i = 1; i < n; i++) {
        if (velocidades[i] > velocidades[major_index]) major_index = i;
    }

    printf("%i %i %i %i", days, hours, mins, major_index + 1);
}