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

using namespace std;

//\\ DEBUGGING \\//

/*template <typename T>
void printcoll (T const& coll){
    typename T::const_iterator referencia;
    typename T::const_iterator end(coll.end());

    for ( referencia = coll.begin(); referencia!=end; ++referencia ) {
        std::cout << *referencia << ' ';
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

#define vi vector<int, int>
//#define pi pair<int, int>
#define mapa map<int, int>

#define pb push_back
#define ff first
#define sec second
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

//\\ COORDENADAS TÍPICAS \\//

//int dx[8] = {0,1,1,1,0,-1,-1,-1};
//int dy[8] = {1,1,0,-1,-1,-1,0,1};

int linky(){

    int n, i, k, vuelta;
    sf(n);

    rep(i, n){

        sff(k, vuelta);

        if(k < vuelta + 2){
            if(vuelta == k){
                pf(vuelta + 1);
                continue;
            }

            pf(vuelta);
            continue;
        }

        pf(0);
    }
    
}