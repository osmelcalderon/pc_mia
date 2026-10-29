#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define rs resize
#define fst first
#define sec second
#define vi vector<int>
#define all(x) x.begin(),x.end()
#pragma GCC optimize("Ofast")
using namespace std;
const int MAXN=(1e5)+5,inf=1e18;
vector<pair<int,int>>adj[MAXN];
int dist[MAXN][2];
bool processed[MAXN][2];
int n,m;
void dijkstra(int s=1){
    priority_queue<tuple<int,int,int>>q;
    for(int i =0;i<MAXN;++i){
        dist[i][0]=inf;
        dist[i][1]=inf;
        processed[i][0]=0;
        processed[i][1]=0;
    }
    dist[s][0]=0;
    q.push({0,s,0});
    while(!q.empty()){
        auto t1=q.top();
        int nl,i,st;
        tie(nl,i,st)=t1;
        q.pop();
        if(processed[i][st])
            continue;
        processed[i][st]=1;

        if(st==0){
            int j=n-i+1;
            if(dist[i][st]<dist[j][1]){
                dist[j][1]=dist[i][st];
                q.push({-dist[j][1],j,1});
            }
        }

        for(auto x:adj[i]){
            int w=x.fst;
            int j=x.sec;
            if(dist[i][st]+w<dist[j][st]){
                dist[j][st]=dist[i][st]+w;
                q.push({-dist[j][st],j,st});
            }
        }
    }
    for(int i =2;i<=n;++i){
        int mn=inf;
        mn=min(dist[i][0],dist[i][1]);
        if(mn==inf)cout<<"-1 ";
        else cout<<mn<<' ';
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i =0;i<m;++i){
        int a,b,w;cin>>a>>b>>w;
        adj[a].pb({w,b});
        adj[b].pb({w,a});
    }dijkstra();
    return 0;
}