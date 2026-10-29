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
vi disA, disB;
void bfs(int nodo, vi &dis){
	dis[nodo] = 0;
	queue<int>q;
	q.push(nodo);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
    ios; setIO();
    int x; cin>>n>>x;
    adj.resize(n + 1);
    disA.resize(n + 1, -1);
    disB.resize(n + 1, -1);
    for(int i = 1; i < n; i++){
    	int a, b; cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    bfs(1, disA);
    bfs(x, disB);
    int ma = 0;
    for(int i = 1; i <= n; i++){
    	if(disB[i] < disA[i]){
    		ma = max(ma, disA[i]);
    	}
    }
    cout<<ma * 2;
}