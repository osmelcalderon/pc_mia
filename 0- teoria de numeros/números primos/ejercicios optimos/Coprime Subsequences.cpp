#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,popcnt,tune=native")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#ifdef __local_leywar
#include <debug/debugger.h>
#endif
#define int long long

using namespace std;
const int MAX = 1e5+2;
const int mod = 1e9+7;

int n, x, mx, p[MAX], f[MAX], mobius[MAX], ans;

inline void mob_inv(){
    mobius[1] = 1;
	for(int i = 1 ; i <= mx; i++){
		int e = f[i];
        for(int j=2;j<=mx/i;j++){
			mobius[i*j] -= mobius[i];
            e+=f[i*j];
		}
        ans+=(mobius[i]*(p[e]-1)%mod+mod)%mod;
		ans%=mod;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	p[0]=1;
	for(int i = 1; i <= n; i++){
        cin >> x;
        mx = max(mx,x);
        p[i] = (p[i-1]*2)%mod;
        f[x]++;
    }
    mob_inv();
    cout << ans;
    return 0;
}