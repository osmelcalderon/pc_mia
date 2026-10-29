#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 50

bool es_primo[MAXN + 1];
long long primorial[MAXN + 1];

void criba() {
    for (int i = 2; i <= MAXN; i++) es_primo[i] = true;
    for (int i = 2; i <= sqrt(MAXN); i++) {
        if (es_primo[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                es_primo[j] = false;
            }
        }
    }
}

void calcular_primoriales() {
    primorial[0] = primorial[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (es_primo[i]) primorial[i] = primorial[i - 1] * i;
        else primorial[i] = primorial[i - 1];
    }
}

int main() {
    criba();
    calcular_primoriales();
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n;
        scanf("%lld", &n);
        printf("%lld\n", primorial[n]);
    }
    return 0;
}