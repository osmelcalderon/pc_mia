#include <stdio.h>
#define Hd main()

long long read_long_long() {
    long long num = 0;
    int c = getchar_unlocked();
    int sign = 1;

    while (c < '0' || c > '9') {
        if (c == '-') {
            sign = -1;
        }
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar_unlocked();
    }

    return num * sign;
}

int Hd {
    auto abs = [](long long a){
        if (a<0) return -a;
        else return a;
    };
    long long sum=0, a=0, x, cp, aux;
    cp = read_long_long();
    while (cp--) {
        x = read_long_long();
        aux = abs(a - x);
        sum += aux;
        a = x;
    }
    printf("%lld\n", sum);
}