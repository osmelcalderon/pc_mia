#include <stdio.h>
#include <math.h>
typedef long long ll;

int main(){

    long long n, final = 0;

    scanf("%lld", &n);
    
    ll m = floor(sqrt(n));
    ll mc = floor(cbrt(n + 1) - 1 );

    final += m * (m + 1) * (4 * m - 1) / 6 + (m + 1) * (n - m * m);
    final += 3 * mc * mc * (mc + 1) * (mc + 1) / 4 + mc * (mc + 1) * (mc + 1) + (mc + 1) * (n + 1 - (mc +1) * (mc + 1) * (mc + 1));
    printf("%lld", final);
    return 0;
}