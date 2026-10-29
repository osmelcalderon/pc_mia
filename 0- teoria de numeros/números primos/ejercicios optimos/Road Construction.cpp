#include<bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 1;
int parent[mxn], siz[mxn], ans;

int find(int n){

    if(n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

bool same(int a, int b){

    return find(a) == find(b);
}

void unite(int a, int b){
    
    int x = find(a), y = find(b);
    
    if(siz[y] > siz[x]) swap(x, y);
        
    siz[x] += siz[y], parent[y] = x, ans = max(ans, siz[x]);
}

int main(){
	
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cout.setf(ios::fixed); cout.precision(0);
    
    int n, m, i, a, b;
    
    cin>>n>>m;
    
    vector<pair<int, int>> edges;
    
    for(i = 1; i <= n; i++)
        siz[i] = 1, parent[i] = i;
        
    while(m--){
    
        cin>>a>>b;
    
        edges.push_back({a, b});
    }    
    
    int c = n, n1, n2;
    
    for(auto u : edges){
    
        n1 = u.first, n2 = u.second;
        
        if(!same(n1, n2)){
        
            unite(n1, n2);
            c--;
        }
        
        cout<<c<<' '<<ans<<'\n';
    }
}