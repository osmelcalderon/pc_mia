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
#define MOD 1000000007
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

/* =========================== TEMPLATE CODE =========================== */

/* Criba de Eratostenes y Funciones Usadas en Teoria de Numeros 
 - Se usan las variables globales mk[] y p para la criba y para 
   guardar los primos respectivamente.
 - init()       Construye el vector con los primos menores que MX
   Tested on: http://dmoj.uclv.cu/problem/oci19day1a  
 - euler_phi(N) Cuenta el numero de enteros positivos menores que N 
   que son coprimos con N 
   Tested on: http://dmoj.uclv.cu/problem/oci19day1a 
 - cant_pf(N)   Cuenta la cantidad de factores primos de N 
 - diff_pf(N)   Cuenta la cantidad de factores primos diferentes 
   de N
   Tested on: http://coj.uci.cu/24h/problem.xhtml?pid=3274  
 - cant_div(N)  Cuenta la cantidad de divisores de N 
 - sum_div(N)   Devuelve la suma de los divisores de N
   Tested on: http://coj.uci.cu/24h/problem.xhtml?pid=1132
**/

/* Criba de Eratostenes */
bool mk[MX];
vector<int> p;

void init(){
    for(int64 i=2; i < MX; i++) if( !mk[i] ){
        p.pb(i);
        for(int64 j=i*i; j < MX; j+=i) mk[j] = true;    
    }    
}

/* =========================== TEMPLATE CODE =========================== */

/* Cantidad de Factores Primos Diferentes */
vector<int64> primos_diff(int64 N){
    vector<int64> ans;
    
    for(int i=0; (int64)p[i]*p[i]<=N; i++){
        while( N % p[i] == 0 ){
			ans.pb(p[i]);
			N /= p[i];
		}
    }
    if( N > 1ll )    
        ans.pb(N);
        
    return ans;    
}

int64 calc(int64 r, int64 comm, vector<int64>& fact){
	int64 ans = r / comm;
	
	int n = len(fact);
	
	for(int mask=1; mask < (1<<n); mask++){
		int cant = 0;
		int64 prod = comm;
		
		for(int i=0; i < n; i++) if( mask & (1<<i) ){
			if( prod > r / fact[i] ){
				prod = r + 1;
				break;
			}
			prod *= fact[i];
			cant++;
		}
		
		if( cant & 1 )
			ans -= r / prod;
		else
			ans += r / prod;
	}
	
	return ans;
}

int64 a, m;

void solve(){
	scanf("%lld%lld", &a, &m);
	
	auto fact = primos_diff(m);
	int64 g = __gcd(a, m);
	int64 comm = g;
	
	sort(all(fact));
	
	vector<int64> tmp;
	for(auto x: fact){
		if( g % x == 0 )
			g /= x;
		else
			tmp.pb(x);
	}
	
	unique(tmp);
	
	printf("%lld\n", calc(m+a-1, comm, tmp) - calc(a-1, comm, tmp));
}


int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
	init();
	
	int tt; scanf("%d", &tt);
	while( tt-- ) solve();
	
	
   return 0;
}