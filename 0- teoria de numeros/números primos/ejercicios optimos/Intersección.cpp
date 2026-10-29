#include <stdio.h>
#include <string.h>

//-127 -> 127

char c1[100005];
char c2[100005];

int cant1[128];
int cant2[128];

int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    scanf("%s", c1);
    scanf("%s", c2);

    int tamC1 = strlen(c1);

    for (int i = 0; i < tamC1; i++) {
        char actual = c1[i];
        cant1[actual]++;
    }

    int tamC2 = strlen(c2);

    for (int i = 0; i < tamC2; i++) {
        char actual = c2[i];
        cant2[actual]++;
    }

    int resultado = 0;

    for (int i = 0; i < 127; i++) {
        resultado += min(cant1[i], cant2[i]);
    }

    printf("%d\n", resultado);

    return 0;
}