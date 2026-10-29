#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

using ll = long long;
using PI = pair<ll, ll>;
using PII = pair<PI, ll>;

const ll N = 1e5+1;
const ll M = 1e9+7;

ll dp[N][4];
vector<ll> g[N];
bool vis[N];

void dfs(ll v){
    vis[v] = 1;

    bool col = 0;

    for(ll c = 1; c <= 3; c++){
        col |= dp[v][c];
    }

    if(!col){
        for(ll c = 1; c <= 3; c++){
            dp[v][c] = 1;
        }
    }

    for(auto u : g[v]){
        if(!vis[u]){
            dfs(u);

            for(ll c = 1; c <= 3; c++){
                ll sc = 0;

                for(ll cc = 1; cc <= 3; cc++){
                    if(c != cc){
                        sc += dp[u][cc];
                        sc %= M;
                    }
                }

                dp[v][c] *= sc;
                dp[v][c] %= M;
            }
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k; cin >> n >> k;

    for(ll i = 1; i < n; i++){
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(ll i = 1; i <= k; i++){
        ll v, c; cin >> v >> c;

        dp[v][c] = 1;
    }

    dfs(1);

    cout << (((dp[1][1] + dp[1][2]) % M) + dp[1][3]) % M;


}