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
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0), cout.precision(10)
#define pb push_back
#define ff first
#define ss second
#define rep(n) for(int i = 0; i < (int)n; i++)
#define ordenar(x) sort(x.begin(), x.end())
#define pq priority_queue
#define vi vector<int>
#define vbol vector<bool>
#define vchar vector<char>
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
void bfs(str nodo, u_m<str, vector<str>> adj, u_m<str, int>&dis){
	dis[nodo] = 0;
	queue<str>q;
	q.push(nodo);
	while(!q.empty()){
		str u = q.front();
		q.pop();
		for(str v : adj[u]){
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
    ios; setIO();
    int n; 
    str a, b; cin>>n>>a>>b;
    u_m<str, vector<str>>adj1, adj2;
    u_m<str, int>dis1, dis2;
    set<str>nodos;
    for(int i = 0; i < n; i++){
    	str n1, n2; cin>>n1>>n2;
    	dis1[n1] = -1; dis1[n2] = -1;
    	dis2[n1] = -1; dis2[n2] = -1;
    	adj2[n2].pb(n1);
    	nodos.insert(n1);
    	nodos.insert(n2);
    }
    bfs(a, adj2, dis1);
    bfs(b, adj2, dis2);
    int m1 = 99999, m2 = 99999;
    for(str u : nodos){
    	if(dis1[u] != -1 and dis2[u] != -1){
    		if(m1 + m2 > dis1[u] + dis2[u]){
    			m1 = dis1[u]; m2 = dis2[u];
    		}
    	}
    }
    if(m1 == 99999 and m2 == 99999){
    	cout<<"NOT RELATED";
    	return 0;
    }
    if(m1 == 1 and m2 == 1){
    	cout<<"SIBLINGS";
    	return 0;
    }
    
    if(m1 == 0){
    	cout<<a<<" is the ";
    	if(m2 == 1){
    		cout<<"mother";
    	}else{
    		for(int i = 1; i < m2 - 1; i++){
    			cout<<"great-";
    		}
    		cout<<"grand-mother";
    	}
    	cout<<" of "<<b;
    	return 0;
    }
    
    else if(m2 == 0){
    	cout<<b<<" is the ";
    	if(m1 == 1){
    		cout<<"mother";
    	}else{
    		for(int i = 1; i < m1 - 1; i++){
    			cout<<"great-";
    		}
    		cout<<"grand-mother";
    	}
    	cout<<" of "<<a;
    	return 0;
    }
    
    if(m2 > 1 and m1 > 1){ cout<<"COUSINS"; return 0;} 
    if(m1 > 1 and m2 == 1){
    	cout<<b<<" is the ";  
    	for(int i = 1; i < m1- 1; i++){
    		cout<<"great-";
    	}
    	cout<<"aunt of "<<a;;
    }
    else if(m2 > 1 and m1 == 1){
    	cout<<a<<" is the ";
    	for(int i = 1; i < m2 - 1; i++){
    		cout<<"great-";
    	}
    	cout<<"aunt of "<<b;
    }
}