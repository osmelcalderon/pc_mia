#include <bits/stdc++.h>
using namespace std;

// mcd iterativo (como en el Pascal)
long long mcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// mcm seguro con intermedio de 128 bits
unsigned long long mcm_ull(unsigned long long x, unsigned long long y) {
    unsigned long long g = std::gcd(x, y);
    __uint128_t prod = (__uint128_t)(x / g) * y;
    return (unsigned long long)prod; // el problema asume que cabe en 64 bits
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long m, n, a, d;
    // En el problema se leen dos líneas: m n  y  a d (pueden venir separados por espacios o saltos de línea)
    if (!(cin >> m >> n)) return 0;
    if (!(cin >> a >> d)) return 0;

    // Repetición horizontal y vertical según el enunciado
    unsigned long long repHor = n / std::gcd(n, d);
    unsigned long long repVer = m / std::gcd(m, a);

    // Saltos = mcm(repVer, repHor)
    unsigned long long saltos = mcm_ull(repVer, repHor);

    cout << saltos;
    return 0;
}
