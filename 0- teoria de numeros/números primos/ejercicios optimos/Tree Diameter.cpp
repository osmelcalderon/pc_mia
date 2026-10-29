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
#define vi vector<int>
#define ii pair<int, int>
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
int n;
vector<vi>adj;
vi dist;
void bfs(int nodo){
	queue<int>q;
	dist[nodo] = 0;
	q.push(nodo);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : adj[u]){
			if(dist[i] == -1){
				dist[i] = dist[u] + 1;
				q.push(i);
			}
		}
	}
}
int main(){
    ios; setIO();
    cin>>n;
    adj.resize(n + 1);
    dist.resize(n + 1, -1);
    for(int i = 1; i < n; i++){
    	int a, b; cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    bfs(1);
    int ma = 0, nodo;
    for(int i = 1; i <= n; i++){
    	if(dist[i] > ma){
    		ma = dist[i];
    		nodo = i;
    	}
    }
    ma = 0;
    for(int i = 1; i <= n; i++) dist[i] = -1;
    bfs(nodo);
    for(int i : dist){
    	ma = max(ma, i);
    }
    cout<<ma;
}