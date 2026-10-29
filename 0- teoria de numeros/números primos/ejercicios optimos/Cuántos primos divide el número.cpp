#include <stdio.h>
#include <cstring>
using namespace std;

const int MAXN = 1001;

bool is_prime[MAXN];
int primes[MAXN], B, i, j;

void sieve(){
    memset(is_prime, true, MAXN);
    is_prime[0] = is_prime[1] = false;
    for(i = 2; i < MAXN; i++){
        if(is_prime[i]){
            primes[B++] = i;
            for(j = i * i; j < MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
}


int main(){

    sieve();
    int t, n, final;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < B && primes[i] <= n; i++){
            if(n % primes[i] == 0){
                final++;
            }
        }
        printf("%d\n", final);
        final = 0;
    }
    
}