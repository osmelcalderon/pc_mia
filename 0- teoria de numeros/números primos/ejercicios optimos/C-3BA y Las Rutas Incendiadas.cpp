#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m,a,b,u,v,w,inf=100000000000000LL;
pair<ll,ll>dist[100001];
vector<pair<int,int>>vec[100001];
void dijkstra(int node){
dist[node]={0,0};
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
pq.push({0,node});
while(!pq.empty()){
    ll nw=pq.top().first;
    int nu=pq.top().second;
    pq.pop();
    for(int i=0;i<vec[nu].size();i++){
        if(nw+vec[nu][i].second<dist[vec[nu][i].first].first){
            dist[vec[nu][i].first].second=dist[nu].second+1;
            dist[vec[nu][i].first].first=nw+vec[nu][i].second;
            pq.push({dist[vec[nu][i].first].first,vec[nu][i].first});
        }
        else if(nw+vec[nu][i].second==dist[vec[nu][i].first].first){
            dist[vec[nu][i].first].second=0;
        }
    }
}
}
int main (){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        dist[i].first=inf;
    cin>>a>>b;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});
    }
    dijkstra(a);
    cout<<dist[b].second;
    return 0;
}