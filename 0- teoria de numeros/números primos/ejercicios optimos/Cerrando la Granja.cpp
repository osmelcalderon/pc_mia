#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define ordenar(x) sort(all(x))
#define pq priority_queue
#define vi vector<int>
#define vbol vector<bool>
#define vchar vector<char>
#define ii pair<int, int>
#define str string
#define endl '\n'
#define u_m unordered_map
#define u_s unordered_set
const int maxn = 2e5 + 5;
int n, m, padre[maxn], tam[maxn] = {};
vector<vi>adj;
void init(){
	for(int i = 0; i < maxn; i++){
		padre[i] = i;
		tam[i] = 1;
	}
}
int find(int nodo){
	if(padre[nodo] == nodo) return nodo;
	else return padre[nodo] = find(padre[nodo]);
}

void unir(int a, int b){
	int p1 = find(a), p2 = find(b);
	if(p1 < p2) swap(p1, p2);
	if(p1 != p2){
		padre[p2] = p1;
		tam[p1] += tam[p2]; 
	}
	
}
str fun(bool b){
	if(b) return "YES";
	else return "NO";
}
int main(){ ios;
    cin>>n>>m;
    init();
    adj.resize(n + 1);
    for(int i = 0; i < m; i++){
    	int a, b; cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    vi nod(n);
    for(int i = 0; i < n; i++){
    	cin>>nod[i];
    }
    reverse(all(nod));
    vector<bool>vis(n + 1, false), res;
    for(int i = 0; i < n; i++){
    	int u = nod[i];
    	vis[u] = true;
    	for(int v : adj[u]){
    		if(!vis[v]) continue;
    		if(find(u) != find(v)){
    			unir(u, v);
    		}
    	}
    	int t = tam[find(u)];
    	if(t == i + 1) res.pb(true);
    	else res.pb(false);
    }
    reverse(all(res));
    for(bool b : res){
    	cout<<fun(b)<<endl;
    }
}