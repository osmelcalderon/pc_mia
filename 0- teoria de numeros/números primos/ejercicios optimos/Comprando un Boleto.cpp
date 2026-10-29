#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include<climits>
#include<set>
#include<string>
#include<unordered_map>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ordenar(x) sort(x.begin(), x.end())
#define pq priority_queue
#define vi vector<ll>
#define ii pair<ll, ll>
#define str string
#define endl '\n'
#define all(x) x.begin(), x.end()
#define u_m unordered_map
void setIO(string name = ""){
	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
ll n;
vector<vector<ii>>adj;
vi dist;
void dijkstra(ll nodo = 0){
	dist[nodo] = 0;
	pq<ii, vector<ii>, greater<ii>>q;
	q.push({0, nodo});
	while(!q.empty()){
		ll u = q.top().ss;
		ll d = q.top().ff;
		q.pop();
		if(d > dist[u]) continue;
		for(auto &i : adj[u]){
			ll v = i.ff, w = i.ss;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
			}
		}
	}
}
int main(){
    ios; setIO();
    ll m; cin>>n>>m;
    adj.resize(n + 1);
    dist.resize(n + 1, LLONG_MAX);
    while(m--){
    	ll a, b, w; cin>>a>>b>>w;
    	adj[a].pb({b, 2*w});
    	adj[b].pb({a, 2*w});
    }
    for(ll i = 1; i <= n; i++){
    	ll coin; cin>>coin;
    	adj[0].pb({i, coin});
    }
    dijkstra();
    for(ll i = 1; i <= n; i++){
    	cout<<dist[i]<<" ";
    }
}
/*
4 2 
1 2 4
2 3 7
6 20 1 25

3 3
1 2 1
2 3 1
1 3 1
30 10 20
*/