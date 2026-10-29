/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 200005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#ifdef LOCAL 
	#include "debug.h"
#endif
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int N, K;
int A[MX], sum[MX];
map<int, int> cant;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
	
	if( K == 1 )
	    return !printf("0\n");
		
	for(int i=1; i<=N; i++)
		sum[i] = (sum[i-1] + A[i]) % K;
		
	int64 sol = 0;
	
	cant[0]++;
	for(int i=1; i<=N; i++){
		if( cant.count(sum[i] - i) )
			sol += cant[sum[i] - i];
		
		if( cant.count(sum[i] - i + K) )
			sol += cant[sum[i] - i + K];
		
		//~ db() << i << " " << cant[sum[i] - i] << " + " << cant[sum[i] - i + K];
		
		cant[sum[i] - i]++;
		if( i-K+1 >= 0 ){
			cant[sum[i-K+1] - (i-K+1)]--;
		}
	}
    
    printf("%lld\n", sol);
    
   return 0;
}