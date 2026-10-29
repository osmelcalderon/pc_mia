#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MOD 998244353


int64_t bp(int64_t b, int64_t e) {
    int64_t res;
    if(e==0) {
        return 1;
    }else if(e==1){
        return b%MOD;
    }
    res = bp(b, e>>1);
    res = res*res%MOD;
    if(e&1) return res*b%MOD;
    return res;
}

int64_t inv(int64_t n) {
    return bp(n, MOD-2);
}


int main() {
    int64_t N, M, f[5001], fact[5001], invfact[5001];
    size_t m, i;

    fact[0] = 1;
    for(i=1; i<5001; i++){
        fact[i] = i*fact[i-1]%MOD;
    }

    invfact[5000] = inv(fact[5000]);
    invfact[0] = 1;
    for(i=4999; i>0; i--){
        invfact[i] = invfact[i+1]*(i+1)%MOD;
    }

    scanf("%ld%ld", &N, &M);

    f[0] = 1;

    for(m=1; m<=M; m++) {
        if(m&1) f[m] = 0;
        else{
            f[m] = 0;
            for(i=0; i<=N && i<=m; i+=2){
                f[m] += f[(m-i)/2] * fact[N] % MOD * invfact[i] % MOD * invfact[N-i] % MOD;
            }
            f[m] %= MOD;
        }
    }

    printf("%ld\n", f[M]);

    return EXIT_SUCCESS;
}