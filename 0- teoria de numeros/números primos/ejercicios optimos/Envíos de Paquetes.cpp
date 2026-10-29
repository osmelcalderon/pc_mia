#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
#define p_b push_back
#define ll long long
//#define int long long
using namespace std ;

const int INF = 1e9 ;
int n , m ;

vector <vector <pair <int , int>>> adj ;
vector <int> dis ;
vector <bool> vis ;

void dijkstra (int st){
	priority_queue <pair <int , int> , vector <pair <int , int>> , greater <>> q ;
	q.push ({0 , st}) ;
	dis.assign (n + 1 , INF) ;
	vis.assign (n + 1 , false) ;
	dis [st] = 0 ;
	while (!q.empty ()){
	    int v = q.top ().second ;
	    q.pop () ;
		if (vis [v])
			continue ;
		vis [v] = true ;
		for (auto edge : adj [v]){
			int to = edge.first ;
			int len = edge.second ;
			if (dis [to] > dis [v] + len){
				dis [to] = dis [v] + len ;
				q.push ({dis [to] , to}) ;
			}
		}
	}
}

int32_t main (){
	//ios_base::sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;
	scanf ("%d %d" , &n , &m) ;
	adj.resize (n + 1) ;
	while (m--){
		int a , b , c ;
		scanf ("%d %d %d" , &a , &b , &c) ;
		adj [a].push_back ({b , c}) ;
		adj [b].push_back ({a , c}) ;
	}
	dijkstra (1) ;
	printf ("%d" , dis [n]) ;

	return 0 ;
}