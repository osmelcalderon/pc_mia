#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define vi vector<int>
 
int n,q;
vi d(200001,0);
int b[200001][26]={};
vector<vector<int>> adj(200001);
void dfs(int nod,int p,int x){
    if(nod!=1)b[nod][1]=x;
	d[nod]=p;
	for(int i:adj[nod]){
        if(i==x)continue;
		dfs(i,p+1,nod);
	}
}
 
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    
    for(int i=1;i<n;i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
        adj[y].pb(x);
	}dfs(1,1,-1);
	for(int i=2;i<25;i++){
		for(int j=1;j<=n;j++){
			b[j][i]=b[b[j][i-1]][i-1];
		}
	}
	//cout<<"\n\n\n";
	
    while(q--){
    	int x,y;
    	cin>>x>>y;
    	int r;
    	
    	if(d[x]<d[y])swap(x,y);
    	int dif=d[x]-d[y];
    	r=dif;
    	//cout<<"r "<<r<<"\n";
        //cout<<x<<" "<<y<<"\n";
    	if(d[x]!=d[y]){
    	for(int i=0;i<25;i++){
    		if(dif&1<<i){
    			x=b[x][i+1];
			}
		}
		}
		//cout<<x<<" "<<y<<"\n";
    	int z=x;
    	for(int i=24;i>=0;i--){
    		int j,k;
    		j=x;k=y;
    		x=b[x][i+1];
    		y=b[y][i+1];
    		if(x==0||y==0||x==y){
    			x=j;
    			y=k;
			}
		}
		//cout<<x<<" "<<y<<"\n";
		if(x!=y)x=b[x][1];
        //cout<<x<<" "<<y<<"\n";
    	r+=(d[z]-d[x])*2;
    	cout<<r<<"\n";
	}
    //for(int i:d)cout<<i<<" ";
	return 0;
}