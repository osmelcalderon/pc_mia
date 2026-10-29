const int MOD = 1e9 + 7;

long long fibbs[1000 + 1][1000 + 1];

void fib2d() {
    for (int i = 0; i < 1001; i++) {
        fibbs[i][0] = 1;
    }
    for (int i = 0; i < 1001; i++) {
        fibbs[0][i] = 1;
    }

    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            fibbs[i][j] =
                (fibbs[i][j - 1]
                + fibbs[i - 1][j]
                + fibbs[i - 1][j - 1]) % MOD;
        }
    }
}

#include <stdio.h>

int main() {
    fib2d();
    int t, x, y;
    scanf("%i", &t);
    while (t--) {
        scanf("%i%i", &x, &y);
        printf("%lld\n", fibbs[x][y]);
    }
}