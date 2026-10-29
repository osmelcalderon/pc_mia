#include <bits/stdc++.h>
    using namespace std;
     
    const int N = 3005, mod = 998244353;
     
    int n, m, a[N], ans, f[N][N], c[N][N];
     
    int main() {
        scanf("%d%d", &n, &m);
     
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        
        for (int i = 0; i <= max(n, m); i++) {
            c[i][0] = 1;
     
            for (int j = 1; j <= i; j++)
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%mod;
        }
     
        f[0][0] = 1;
     
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= min(i, n); j++) 
                f[i][j] = (f[i - 1][j - 1] + 2ll*j*f[i - 1][j])%mod;
        
        for (int i = 0; i <= n; i++)
            ans = (ans + 1ll*f[m][n]*c[n][i])%mod;
        
        for (int l = 1, r; l <= n; l++) {
            r = l;
     
            while (r <= n && (l == r || a[r - 1] < a[r])) {
                ans = (ans + 1ll*f[m][n - (r - l + 1)]*c[n - (r - l + 1)][l - 1])%mod;
                r++;
            }
        }
     
        printf("%d\n", (ans%mod + mod)%mod);
    }