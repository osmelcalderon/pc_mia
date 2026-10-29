#define MAIN_C
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#define MOD 1000000007ll
#define MAX 1000002
// include io.c
#ifndef MAIN_C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#endif

#define BUFSZ 1024000
char buf[BUFSZ];
size_t bufptr=0, buflen=0;

char next_char() {
    if(bufptr>=buflen){
        bufptr = 0;
        buflen = read(STDIN_FILENO, buf, BUFSZ);
        if(buflen<0)exit(EXIT_FAILURE);
        if(buflen==0)return 0;
        return next_char();
    }
    return buf[bufptr++];
}

int64_t next_int() {
    char lst = next_char();
    while(lst < '0' || lst > '9')
        lst = next_char();
    int64_t res = 0;
    while(1) {
        if(lst<'0' || lst>'9')break;
        res = res*10 + lst - '0';
        lst = next_char();
    }
    return res;
}



// end-include io.c

int64_t bp(int64_t b, int64_t e) {
    int64_t res;

    if(e==0){
        return 1;
    }else if(e==1){
        return b%MOD;
    }

    res = bp(b, e>>1);
    res = res*res%MOD;

    if(e&1){
        return res*b%MOD;
    }else{
        return res;
    }
}

int main() {
    size_t i;
    int64_t *fact, *invfact, n, a, b;

    fact = malloc(sizeof(int64_t)*MAX);
    invfact = malloc(sizeof(int64_t)*MAX);

    fact[0]=1;
    for(i=1; i<MAX; i++){
        fact[i]=fact[i-1]*i%MOD;
    }
    invfact[MAX-1]=bp(fact[MAX-1], MOD-2);
    for(i=MAX-1; i>0; i--){
        invfact[i-1] = invfact[i]*i%MOD;
    }

    n = next_int();
    while(n--) {
        a = next_int();
        b = next_int();

        printf("%ld\n", fact[a]*invfact[b]%MOD*invfact[a-b]%MOD);
    }

    return EXIT_SUCCESS;
}