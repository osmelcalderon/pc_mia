#include <bits/stdc++.h>
using namespace std;

#define MX 1000005

int acum[MX];

int main() {
    int n, k; scanf("%d%d", &n, &k);

    for(int i=1; i<=n; i++){
        int a, b; scanf("%d%d", &a, &b);

        acum[a]++;
        acum[b+1]--;
    }

    int sol = 1, cant = 1, ma = acum[1];
    for(int i=2; i<=k; i++){
        acum[i] += acum[i-1];

        if( acum[i] == ma ){
            cant++;
            sol = max(sol, cant);
        }
        else if( acum[i] > ma ){
            ma = acum[i];
            cant = 1;
            sol = 1;
        }
    }

    printf("%d\n", sol);

    return 0;
}