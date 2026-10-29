/*
linkyless
--Copyright DMOJ
// New Template
*/

#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>
//#include <map>
#include <algorithm>
//#include <set>
//#include <unordered_set>
//#include <queue>
//#include <vector>
//#include <string>
//#include <string.h>
//#include <stack>
//#include <utility>
//#include <bitset>
//#include <cstring>
//#include <iostream>
//#include <utility>
//#include <math.h>
//#include <cstdlib>
//#include <bitset>
//#include <numeric>
//#include <functional>
//#include <bits/stdc++.h>

using namespace std;

//\\ DEBUGGING \\//

/*template <typename T>
void printcoll (T const& coll){
    typename T::const_iterator pos;
    typename T::const_iterator fin(coll.fin());

    for ( pos = coll.begin(); pos!=fin; ++pos ) {
        std::cout << *pos << ' ';
    }
    std::cout << std::finl;
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
#define REPBIT(j, bit, i, k) for (j = 0; j * (1 << bit) <= i; j += k)

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

const int MOD = 998244353;
const int MAX = 1e5 + 3;
const int MAXINT = 1e8;

//\\ COORDENADAS TÍPICAS \\//

// int dx[8] = {0,1,1,1,0,-1,-1,-1};
// int dy[8] = {1,1,0,-1,-1,-1,0,1};

int f[510][510], n, topdown[510 * 510][2], c[510][510];

int linky(){

	int i, j;

	sf(n);

	repi(i, n)
		REP(j, 1, n){
		f[i][j] = min(min(i, n + 1 - i),min(j, n + 1 - j));
		c[i][j] = 1;
	}
	
	int final = 0;

	repi(i, n * n){
		int x, y, P;
		sf(P);
		x = (P - 1) / n + 1;
		y = P - (x - 1) * n;
		int R = min(min(f[x + 1][y],f[x - 1][y]), min(f[x][y + 1],f[x][y - 1]));
		final = final + R;
		c[x][y] = 0;
		f[x][y] = R;
		int t = 1;
		topdown[1][0] = x;
		topdown[1][1] = y;

		for(int i = 1; i <= t; i++){
			x = topdown[i][0];
			y = topdown[i][1];

			if(y && f[x][y - 1] > f[x][y] + c[x][y - 1]){
				f[x][y - 1] = f[x][y] + c[x][y - 1];
				t++;
				topdown[t][0] = x;
				topdown[t][1] = y - 1;
			}

			if(y && f[x][y + 1] > f[x][y] + c[x][y + 1]){
				f[x][y + 1] = f[x][y] + c[x][y + 1];
				t++;
				topdown[t][0] = x;
				topdown[t][1] = y + 1;
			}

			if(y && f[x - 1][y] > f[x][y] + c[x - 1][y]){
				f[x - 1][y] = f[x][y] + c[x - 1][y];
				t++;
				topdown[t][0] = x - 1;
				topdown[t][1] = y;
			}

			if(y && f[x + 1][y] > f[x][y] + c[x + 1][y]){
				f[x + 1][y] = f[x][y] + c[x + 1][y];
				t++;
				topdown[t][0] = x + 1;
				topdown[t][1] = y;
			}
		}
	}
	
	pf(final);

    return 0;
}