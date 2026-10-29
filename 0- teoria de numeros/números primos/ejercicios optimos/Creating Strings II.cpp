#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
#define MAX 1000002

int64_t bp(int64_t b, int64_t e){
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
    size_t n, i, cnt[26];
    char buf[MAX];
    int64_t *fact, sol;

    fact=malloc(sizeof(int64_t)*MAX);

    fact[0]=1;
    for(i=1; i<MAX; i++){
        fact[i] = fact[i-1]*i%MOD;
    }

    for(i=0; i<26; i++){
        cnt[i]=0;
    }

    scanf(" %[^\n]s", buf);
    n=strlen(buf);

    for(i=0; i<n; i++){
        cnt[buf[i]-'a']+=1;
    }

    sol = 1;
    for(i=0; i<26; i++){
        sol = sol*fact[cnt[i]]%MOD;
    }

    sol = fact[n]*bp(sol, MOD-2)%MOD;

    printf("%ld\n", sol);

    return EXIT_SUCCESS;
}