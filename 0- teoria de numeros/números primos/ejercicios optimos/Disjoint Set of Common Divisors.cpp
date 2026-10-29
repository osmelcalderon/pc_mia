/*
linkyless
--Copyright DMOJ
// New Template
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
//#include <map>
//#include <algorithm>
//#include <set>
//#include <unordered_set>
//#include <queue>
//#include <vector>
//#include <string>
//#include <stack>
//#include <utility>
//#include <cstring>
//#include <iostream>
//#include <utility>
//#include <math.h>
//#include <bitset>

using namespace std;

//\\ DEBUGGING \\//

/*template <typename T>
void printcoll (T const& coll){
    typename T::const_iterator pos;
    typename T::const_iterator end(coll.end());

    for ( pos = coll.begin(); pos!=end; ++pos ) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

*/

//\\ SGTREE \\//

//#define left l, m, node * 2
//#define right m + 1, r, node * 2 + 1

//\\ PRINCIPAL \\//

#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ RAPIDEZ DE CODIGO \\//

#define rep(i,n) for (i = 0; i < n; i++)
#define repzero(i,n) for (i = 0; i <= n; i++)
#define repone(i,n) for (i = 1; i < n; i++)
#define repi(i,n) for (i = 1; i <= n; i++)
#define reptwo(i,n) for (i = 2; i <= n; i++)
#define REP(i,k,n) for (i = k; i <= n; i++)
#define REPR(i,k,n) for (i = k; i >= n; i--)

//\\ STL \\//

/*define vi vector<int, int>
#define mapa map<int, int>
*/

#define pll pair<int, int>
//typedef vector<pair<int,int>> vec_pr;

#define pb push_back
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ordenar(x) sort( x.begin(), x.end() )
#define ordenarA(x) sort( x, x + n )
#define med (left + right)/2
#define mmsone(x,d) memset(x, d, sizeof(x))

//\\ OPERACIONES RAPIDAS \\//

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfff(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

const ll MOD = 1e9+7;

//\\ COORDENADAS TÍPICAS \\//

//int dx[8] = {0,1,1,1,0,-1,-1,-1};
//int dy[8] = {1,1,0,-1,-1,-1,0,1};

ll bestGCD(ll a, ll b){

    if (a < b){
        ll aux = a;
        a = b;
        b = aux;
    }
 
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}
 
int pollardRho(ll n){

    int divisorsFactors = 1;
    ll ws[] = {1, 2, 2, 4, 2, 4, 2, 4, 6, 2, 6};
    ll f = 2; 
    int w = 0;
 
    while (f * f <= n) {
        if (n % f == 0) {
            divisorsFactors += 1;
            while (n % f == 0) n /= f;
        }
        f += ws[w];
        w = (w == 10) ? 3 : (w + 1);
    }
    if (n > 1) divisorsFactors += 1;
 
    return divisorsFactors;
}
int linky(){
 
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll gcd = bestGCD(a, b);
    printf("%d", pollardRho(gcd));
}