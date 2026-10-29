#include <stdio.h>

#define MOD 1000000007

long long power(long long base, long long exponent) {
    if (exponent == 0) return 1;
    if (exponent % 2 == 0) {
        long long temp = power(base, exponent / 2);
        return (temp * temp) % MOD;
    } else {
        return (base * power(base, exponent - 1)) % MOD;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    long long result = power(2, n);

    printf("%lld\n", result);

    return 0;
}