/*
linkyless
--Copyright DMOJ
// New Template
*/

#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
#include <map>
//#include <algorithm>
//#include <set>
//#include <unordered_set>
//#include <queue>
//#include <vector>
//#include <string>
#include <string.h>
//#include <stack>
//#include <utility>
//#include <cstring>
//#include <iostream>
//#include <utility>
//#include <math.h>
//#include <bitset>
//#include <numeric>
//#include <functional>
///#include <bits/stdc++.h>

//using namespace std;

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
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

//\\ RAPIDEZ DE CODIGO \\//

#define rep(i, n) for (i = 0; i < n; i++)
#define repzero(i, n) for (i = 0; i <= n; i++)
#define repone(i, n) for (i = 1; i < n; i++)
#define repi(i, n) for (i = 1; i <= n; i++)
#define reptwo(i, n) for (i = 2; i <= n; i++)
#define REP(i, k, n) for (i = k; i <= n; i++)
#define REPL(i, k, n) for (i = k; i < n; i++)
#define REPR(i, k, n) for (i = k; i >= n; i--)
#define REPSUM(i, k, n, j) for (i = k; i <= n; i += j)

//\\ STL \\//

/*define vi vector<int, int>2
1 10
100 200
#define mapa map<int, int>
*/

#define pll pair<int, int>
// typedef vector<pair<int,int>> vec_pr;

#define pb push_back
#define F second
#define S first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ordenar(x) sort(x.begin(), x.end())
#define ordenarA(x) sort(x, x + n)
#define med (left + right) / 2
#define mmsone(x, d) memset(x, d, sizeof(x))

//\\ OPERACIONES RAPIDAS \\//

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d", &n, &m)
#define sfff(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define sffff(n, m, k, x) scanf("%d%d%d%d", &n, &m, &k, &x)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d", &n, &m)

#define pf(n) printf("%d\n", n)
#define pfl(n) printf("%I64d ", n)
#define pfs(s) printf("%s\n", s)

const int MOD = 1e9+7;
const int MAX = 1e5+1;

//\\ COORDENADAS TÍPICAS \\//

// int dx[8] = {0,1,1,1,0,-1,-1,-1};
// int dy[8] = {1,1,0,-1,-1,-1,0,1};

char operacion[MAX];
int dp[MAX][5][5][5];
std::map<char, int> mp;

int main(){

    int i, j, x, y, z, t;

    scanf("%s", operacion + 1);
    int n = strlen(operacion + 1);
    mp['A'] = 0;
    mp['G'] = 1;
    mp['C'] = 2;
    mp['T'] = 3;
    mp['?'] = 4;

    rep(i, 4)
        rep(j, 4)
            if(mp[operacion[1]] == 4 || mp[operacion[1]] == i )
                dp[1][i][i][j] = 1;
    
    reptwo(i, n)
        rep(x, 4)
            rep(y, 4)
                rep(z, 4){
                    if( mp[operacion[i]] == 4 ){
                        rep(t, 4){
                            if( y == z )
                                dp[i][t][t][x] = ((ll)dp[i][t][t][x] + dp[i - 1][x][y][z]) % MOD;
                            if( t != y )
                                dp[i][x][t][z] = ((ll)dp[i][x][t][z] + dp[i - 1][x][y][z]) % MOD;
                        }
                    }

                    else{
                        int t = mp[operacion[i]];
                        if( y == z )
                            dp[i][t][t][x] = ((ll)dp[i][t][t][x] + dp[i - 1][x][y][z]) % MOD;
                        if( t != y )
                            dp[i][x][t][z] = ((ll)dp[i][x][t][z] + dp[i - 1][x][y][z]) % MOD;
                    }
                }

    ll final = 0;

    rep(x, 4)
        rep(y, 4)
            final = (final + (ll)dp[n][x][y][y]) % MOD;
    
    printf("%lld", final);

    return 0;
    
}