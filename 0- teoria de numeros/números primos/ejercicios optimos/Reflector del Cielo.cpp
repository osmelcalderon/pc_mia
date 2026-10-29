/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifndef LOCAL 
	#pragma GCC optimize("Ofast") 
#endif
#define MX 200005
#define INF (1<<30)
#define INF64 (1ll<<62)
#define EPS 1e-9
#define MOD 998244353
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define len(X) ((int)((X).size()))
#define all(X) (X).begin(), (X).end()
#define chmax(X, Y) X = max((X), (Y))
#define chmin(X, Y) X = min((X), (Y))
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;

typedef long long int64;
typedef unsigned long long unt64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;

int N, M, K;

int64 pot(int64 base, int64 e){
	int64 ans = 1;
	
	while( e ){
		if( e & 1ll ) ans = ans * base % MOD;
		base = base * base % MOD;
		e >>= 1ll;
	}
	return ans;
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	scanf("%d%d%d", &N, &M, &K);
	
	if( N == 1 || M == 1 ){
		if( M == 1 ) swap(N, M);
		
		return !printf("%lld\n", pot(K, M));
	}
	
	int64 sol = 0;
	for(int p=1; p<=K; p++){
		int64 tmp = (pot(p, N) + MOD - pot(p-1, N)) % MOD;
		sol += pot(K - p + 1, M) * tmp % MOD;
		sol %= MOD;
	}

	printf("%lld\n", sol);
    
   return 0;
}