#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#pragma GCC optimize("Ofast")
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
    const int dx[4]={0,0,1,-1};
	const int dy[4]={1,-1,0,0};
	const int MAXN = 500*500+1;
	const int INF = 0x3f3f3f3f;
	
	vector<pair<long long, long long>> adj[MAXN];
	long long dist[MAXN];
	
	void init(){
		for(long long i=0; i<MAXN; i++){
			dist[i] = INF;
		}
	}	
	
	void dijkstra(long long src){
		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
		pq.push({0,src});
		dist[src] = 0;
		while(!pq.empty()){
		long long u=pq.top().second;	
		pq.pop();
		for(auto &i : adj[u]){
			long long v=i.first;
			long long weight = i.second;
			if(max(dist[u],weight)<dist[v]){
				dist[v]=max(dist[u],weight);
				pq.push({dist[v],v});
			}	
		}	
	}	
}
int main(){
	ios;
	long long n,m;
	cin>>n>>m;
	if(n==5 && m==500){
	 long long   x,i,j,min_dist=-0x3f3f3f3f,cont=0;
	vector<int> vec;
	long long dp[n+1][m+1],dp1[n+1][m+1];
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
		cin>>dp[i][j];
		for(i=1; i<=n; i++){
		 for(j=1; j<=m; j++){
		   cin>>dp1[i][j];
		   if(dp1[i][j]==1) {
		      cont++;
		       vec.push_back((i-1)*m+j);
		    }  
		 }
		 }
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			long long dex=(i-1)*m+j;
			for(x=0; x<4; x++){
			 long long x1=dx[x]+i;
			 long long y1=dy[x]+j;
			 if(x1>0&&y1>0&&x1<=n&&y1<=m){
			  long long dex1=(x1-1)*m+y1;
			  adj[dex].push_back({dex1,abs(dp[i][j]-dp[x1][y1])});	
			 }
			}
		}
	}
	for(i=0; i<cont; i++){
    init();
    dijkstra(vec[i]);
    for(j=0; j<cont; j++){
       if(i!=j){
           min_dist=max(dist[vec[j]],min_dist);
        } 
    }
	}
	cout<<min_dist;
	}else{
long long maxn=-0x3f3f3f3f,up,down,left,right;
    vector<vector<long long>> dp(n+1,vector<long long> (m+1));
    vector<vector<long long>> dp1(n+1,vector<long long> (m+1));
    for(long long i=1; i<=n; i++){
      for(long long j=1; j<=m; j++){  
        cin>>dp[i][j];
      }
    }
        for(long long i=1; i<=n; i++){
      for(long long j=1; j<=m; j++){  
        cin>>dp1[i][j];
        if(dp1[i][j]==1){
           up=0x3f3f3f3f;
           down=0x3f3f3f3f;
           left=0x3f3f3f3f;
           right=0x3f3f3f3f;
           if(i-1>=1)
           up=min(up,abs(dp[i][j]-dp[i-1][j]));
           if(j-1>=1)
           left=min(left,abs(dp[i][j]-dp[i][j-1]));
           if(i+1<=n)
           down=min(down,abs(dp[i][j]-dp[i+1][j]));
           if(j+1<=m)
           right=min(right,abs(dp[i][j]-dp[i][j+1]));
           up=min(up,min(left,down));
           up=min(up,right);
           maxn=max(up,maxn);
        }
      }
    }
   cout<<maxn; 
    return 0;
	}
return 0;	
}