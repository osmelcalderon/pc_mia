#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fr first
#define sc second
#define pb push_back
#define pq priority_queue
#define undmap unordered_map
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7, INF = 1e18, maxn = 1e6;

vvi g;

int dfs(int act,int ant){
    if(g[act].size()==1)return 0;
    int sum=0;
    for(auto i:g[act]){
        if(i==ant)continue;
        sum+=dfs(i,act);
    }
    return sum+g[act].size()-1+__lg(2*g[act].size()-1);
}

void solve(){
    int n;cin>>n;
    g.resize(n+1);
    g[1].pb(0);
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout<<dfs(1,0);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);int t = 1;// cin >> t;
    while (t--)solve();
    return 0;
}