#include <bits/stdc++.h>
using namespace std;
#define srtl(x)sort((x).begin(),(x).end())
#define srtg(x)sort((x).begin(),(x).end(),greater<>())
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define ins insert
#define vi vector<int>
#define vii vector<pii>
#define viii vector<pair<int,pii>>
 
int ax[4]={0,1,0,-1};
int ay[4]={1,0,-1,0};
#define int long long
 
const int N=2e5+1;
vi mi(N,1);
vector<vi>adj(N);
int n;
int res[N];
void sum(int p,int nod){
	for(int i:adj[nod]){
		if(i==p)continue;
		sum(nod,i);
		mi[nod]+=mi[i];
	}
}
int dfs(int p,int nod,int dis){
	for(int i:adj[nod]){
		if(i==p)continue;
		res[1]+=dfs(nod,i,dis+1);
	}
	return dis;
}
void ant(int p,int nod){
	for(int i:adj[nod]){
		if(i==p)continue;
		res[i]=(n+res[nod])-(mi[i]*2);
		ant(nod,i);
	}
}
int32_t main(){
    ios;
    cin>>n;
    for(int i=1;i<n;i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
    	adj[y].pb(x);
	}
	sum(-1,1);
	dfs(-1,1,0);
	ant(-1,1);
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
    return 0;
}