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
const int maxn = 20;
const ll mod = 1e9 + 7;
ll dp[1<<maxn][maxn];
vi adj[maxn];
int main(){ ios;
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
    	int a, b; cin>>a>>b;
    	adj[--b].pb(--a);
    }
    dp[1][0] = 1;
    for(int s = 2; s < 1<<n; s++){
    	if((s&(1<<0)) == 0) continue; 
    	if((s&(1<<(n - 1))) and s != ((1<<n) - 1)) continue;
    	for(int j = 0; j < n; j++){
    		if((s&(1<<j)) == 0) continue;
    		int prev = s - (1<<j);
    		for(int v : adj[j]){
    			if(s&(1<<v)){
    				dp[s][j] += dp[prev][v];
    				dp[s][j]%=mod;
    			}
    		}
    	}
    }
    cout<<dp[(1<<n) - 1][n - 1];
}