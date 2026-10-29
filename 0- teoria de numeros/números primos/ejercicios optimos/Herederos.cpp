//Herederos
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(0); //srand(time(NULL));
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define int long long
#define fs first
#define sd second
#define rsz resize
#define en '\n'

const int maxn = 100;

map<string, vector<string>> adj;
map<string, int> mp;
map<string, bool> vis;
string root, a, b, c;
set<string> con;

void dfs(string v){
    vis[v] = 1;
    for(auto u: adj[v]){
        if(!vis[u]) dfs(u);
    }
    for(auto u: adj[v]){
        mp[v] += mp[u]/2;
    }
}

int32_t main(){
    fast
    int n, m, ans = -1, val = 0;
    cin >> n >> m >> root;

    mp[root] = 1125899906842624;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        adj[a].pb(b);
        adj[a].pb(c);
        con.insert(a); con.insert(b); con.insert(c);
    }

    for(auto u: con){
        if(!vis[u]){
            dfs(u);
        }
    }

    for(int i = 0 ; i < m; i++){
        cin >> a;
        if(mp[a] > ans){
            ans = mp[a];
            b = a;
        }
    }

    cout << b;
return 0;
}