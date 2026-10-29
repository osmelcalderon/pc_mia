#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MOD 1000000007

// Input
#define BUFSZ 102400
char buf[BUFSZ];
size_t bufptr = 0, buflen = 0;

#define mgetc(out) do {\
        if(bufptr>=buflen) {\
            bufptr=0; buflen = read(0, buf, BUFSZ); continue;\
        }\
        (out) = buf[bufptr++]; break;\
}while(1);

// Get an integer from standard input
long long next_int() {
    char c = 0;
    while(c<'0' || c>'9') {
        mgetc(c);
    }

    long long n = c-'0';
    while(1) {
        mgetc(c);
        if(c<'0' || c>'9')
            break;
        n = n*10 + c - '0';
    }
    return n;
}

int64_t bp2(int64_t b, int64_t e) {
    if(e==0)return 1;
    if(e==1)return b%(MOD-1);
    int64_t r = bp2(b, e>>1);
    r = r*r%(MOD-1);
    if(e&1)return r*b%(MOD-1);
    return r;
}

int64_t bp(int64_t b, int64_t e) {
    if(e==0)return 1;
    if(e==1)return b%MOD;
    int64_t r = bp(b, e>>1);
    r = r*r%MOD;
    if(e&1)return r*b%MOD;
    return r;
}

int main() {

    size_t n = next_int();
    while(n--) {
        int64_t a = next_int(), b = next_int(), c = next_int();
        printf("%ld\n", bp(a, bp2(b, c)));
    }

    return EXIT_SUCCESS;
}