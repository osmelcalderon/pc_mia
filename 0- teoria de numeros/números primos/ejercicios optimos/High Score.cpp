#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define endl '\n'

const int MOD=1e9+7;
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cout.precision(0);
    cout<<fixed;
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> x[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        x[u].emplace_back(w,v);
    }
    vector<int> bellman(n+1,-1e18);
    bellman[1]=0;
    for (int i = 0; i < n-1; i++)
    {
        bool mod=false;
        for (int j = 1; j <= n; j++)
        {
            if(bellman[j]!=-1e18)
            {
                for(auto e:x[j])
                {
                    if(bellman[e.second]<bellman[j]+e.first)
                    {
                        bellman[e.second]=bellman[j]+e.first;
                        mod=true;
                    }
                }
            }
        }
        if(!mod)
        break;
    }
    vector<bool> vis(n+1,false);
    queue<int> q;
    bool mod=false;
        for (int j = 1; j <= n; j++)
        {
            if(bellman[j]!=-1e18)
            {
                for(auto e:x[j])
                {
                    if(bellman[e.second]<bellman[j]+e.first)
                    {
                        q.push(e.second);
                        vis[e.second]=true;
                        mod=true;
                    }
                }
            }
        }
    
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(auto e:x[s])
        {
            if(!vis[e.second])
            {
                vis[e.second]=true;
                q.push(e.second);
            }
        }
    }


        
    cout<<(mod&&vis[n]?-1:bellman[n])<<endl;
    return 0;
}