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
//#include <tuple>

using namespace std;

//\\ DEBUGGING \\//

/*template <typename T>
void printcolumnal (T const& columnal){
    typename T::const_iterator referencia;
    typename T::const_iterator end(columnal.end());

    for ( referencia = columnal.begin(); referencia!=end; ++referencia ) {
        cout << *referencia << ' ';
    }
    cout << endl;
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
#define sffff(n,m,k,c) scanf("%d%d%d%d",&n,&m,&k,&c)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

const int MAX = 200001;
const int GRANDE = 0x3f3f3f;
const ll mod = 1e9 + 7;

//int dx[8] = {-1,0,1,0,0,-1,-1,-1};
//int dy[8] = {0,1,0,-1,-1,-1,0,1};

int max(int a, int b){
    return a > b ? a : b;
}

void swap(int a, int b){
    int c;
    a = c;
    a = b;
    b = c;
}

int linky(){

    int a, b, c;
    sfff(a, b, c);

    if(a > b)
        swap(a, b);
    if(a > c)
        swap(a, c);
    if(b > c)
        swap(b, c);

    if(a == c - 2){
        pf(0);
    }else if((b == c - 2) || (a == b - 2)){
        pf(1);
    }else{
        pf(2);
    }

    pf(max(c - b, b - a) - 1);
 
    return 0;
}