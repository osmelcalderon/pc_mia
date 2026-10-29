#include<stdio.h>
using namespace std;
typedef long long ll;

ll lastDigit(ll n, ll m){
    if(m > n)
        return 0;
    if(n - m >= 10)
        return 0;
    ll final = 1;
    for(ll i = n; i > m; i--){
        final = (final * (i % 10)) % 10;
        if(final == 0)
            return 0;
    }
    return final;
}

int main(){
    ll t, n, m;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &m, &n);
        printf("%lld\n", lastDigit(n, m));
    }
    return 0;
}