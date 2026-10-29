#include <stdio.h>
#include <stdbool.h>

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

static inline bool isone(long long n) {
    if (unlikely(n == 0)) return true;
    const int d = n % 10;
    return likely(d > 0 && d < 4) ? isone(n / 10) : false;
}

static inline bool istwo(long long n) {
    if (unlikely(n == 0)) return true;
    const int d = n % 10;
    return likely(d > 1 && d < 7) ? istwo(n / 10) : isone(n);
}

static inline bool isthree(long long n) {
    if (unlikely(n == 0)) return true;
    const int d = n % 10;
    return likely(d > 2) ? isthree(n / 10) : istwo(n);
}

static inline bool isfour(long long n) {
    int aux = 0;
    while (likely(n != 0)) {
        if (unlikely(isthree(n - aux))) return true;
        const int d = n % 10 - aux;
        if (unlikely(d == 3)) return false;
        aux = d < 3;
        n /= 10;
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long n;
        scanf("%lld", &n);
        
        if (isone(n)) puts("1");
        else if (istwo(n)) puts("2");
        else if (isthree(n)) puts("3");
        else if (isfour(n)) puts("4");
        else puts("5");
    }
    return 0;
}