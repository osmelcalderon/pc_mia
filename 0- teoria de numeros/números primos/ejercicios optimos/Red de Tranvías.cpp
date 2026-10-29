#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[101];
vector<int>dist(101,INT_MAX);
int n;
    void dijkstra(int a){
        priority_queue<pair<int,int>>q;
        dist[a]=0;
        q.push({0,a});
        while(!q.empty()){
            int u=q.top().second;
            q.pop();
            for(auto x:adj[u]){
                int v=x.first;
                int w=x.second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    q.push({-dist[v],v});
                }
                
            }        
        }
    }    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b;cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int v,w;cin>>v;
            w=(j==0)?0:1;
            adj[i].push_back({v,w});
        }    
    }
    dijkstra(a);
    if(dist[b]==INT_MAX) cout<<-1;
    else cout<<dist[b];
    
    return 0;
}