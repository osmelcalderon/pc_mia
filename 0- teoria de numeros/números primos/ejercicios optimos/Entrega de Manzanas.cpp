#include <bits/stdc++.h>
using namespace std ;
#pragma GCC optimize ("Ofast")
#define p_b push_back
#define F first
#define S second
#define int long long

const int MOD = 1e9 + 7 ;
const int INF = 1 << 30 ;

int n , m , st , x , y ;

vector <vector <pair <int , int>>> adj ;

vector <int> dis ;
vector <bool> vis ;

void dijkstra (int s){
	dis.assign (n + 1 , INF) ;
	dis [s] = 0 ;
	vis.assign (n + 1 , false) ;
	priority_queue <pair <int , int> , vector <pair <int , int>> , greater <>> q ;
	q.push ({0 , s}) ;
	while (!q.empty ()){
		int v = q.top ().S , d = q.top ().F ;
		q.pop () ;
		if (dis [v] < d)
			continue ;
		vis [v] = true ;
		for (auto edge : adj [v]){
			int len = edge.S ;
			int to = edge.F ;
			if (dis [v] + len < dis [to]){
				dis [to] = dis [v] + len ;
				q.push ({dis [to] , to}) ;
			}
		}
	}
}

void solve (){
	dijkstra (y) ;
	int d = dis [x] ;
	dijkstra (st) ;
	d += min (dis [x] , dis [y]) ;
	cout << d ;
}

int32_t main (){
	ios_base::sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;
	int t = 1 ;
	//cin >> t ;
	while (t--){
		cin >> m >> n >> st >> x >> y ;
		adj.resize (n + 1) ;
		while (m--){
			int a , b , c ;
			cin >> a >> b >> c ;
			adj [a].push_back ({b , c}) ;
			adj [b].push_back ({a , c}) ;
		}
		solve () ;
		cout << '\n' ;
	}
	return 0 ;
}