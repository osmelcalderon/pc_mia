#pragma GCC target (*sse4.2*)
#pragma GCC optimization ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization("unroll-loops")
#define mod 1000000007
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define PB push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read(x) long long x;cin>>x;
#define FOR(a,b,c,d) for(int a=b;a<=c;a+=d)
#define MP make_pair
#define F first
#define S second
#define debug(x) cout<<("#x)<<": "<<(x)<<"\n"
#define SZ(x) x.size()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
typedef unsigned long long ull;
typedef long double d64;

vector<vector<int> > G;
vector<int>D;
queue<int>q;
vector<bool>vis;

void bfs(int x){
D[x]=0;
vis[x]=1;
q.push(x);
while(!q.empty()){
    int s=q.front();q.pop();
    for(int i=0;i<G[s].size();i++){
        if(vis[G[s][i]])continue;
        vis[G[s][i]]=1;
        D[G[s][i]]=D[s]+1;
        q.push(G[s][i]);
        }
    }
}


int main(){
fast
string s;
cin>>s;
int n=s.size();
G.assign(n+1,vector<int>());
D.assign(n+1,0);
vis.resize(n+1);

for(int i=0;i<s.size();i++){
        if(i!=0){
            G[i].PB(i-1);
            G[i-1].PB(i);
        }
    for(int j=0;j<s.size();j++){
        if(i!=j&&s[i]==s[j]){
            G[i].PB(j);
            G[j].PB(j);
        }
    }
}
bfs(0);
cout<<D[n-1];

return 0;
}