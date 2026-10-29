#include<stdio.h>
#include<stdlib.h>
#define MOD 1234567891

/**
 * Bin pow, aka quickpow
 */
long long qpow(long long b, long long e){
    if(e==0)return 1;
    if(e==1)return b%MOD;
    long long res = qpow(b, e>>1);
    res = res*res%MOD;
    if(e&1)return res*b%MOD;
    return res;
}

/**
 * Entry point
 * @karellgz
 */
int main(int argc, char** args, char** envs){
    long long n;
    scanf("%lld", &n);

    long long fact = 1, dp = 0;
    for(long long i = 1; i<=n; i++){
        dp = (dp*i%MOD*i%MOD + fact);
        fact = fact*i%MOD*i%MOD;
    }

    //fprintf(stderr, "P/Q = %lld/%lld\n", dp, fact*n);
    long long res = dp*qpow(fact*n%MOD, MOD-2)%MOD;
    printf("%lld\n", res);

    return EXIT_SUCCESS;
}