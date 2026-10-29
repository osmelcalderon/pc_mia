#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define int long long
#define lb lower_bound
#define ub upper_bound
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define pii pair<int,int>
#define vii vector<pii>
const int inf=1e18;
const int in=-1e18;
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, k;
	cin>>n>>k;
	vector<vector<vi>>dp(1+1,vector<vi>(k+1,vi(3,0)));
	for(int i1=1; i1<=n; i1++){
		int i=i1&1;
		char y;
		cin>>y;
		for(int j=0; j<=k; j++){
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=0;
			if(j>0){
				if(y=='H'){
					dp[i][j][0]=max({dp[1-i][j][0],dp[1-i][j-1][1],dp[1-i][j-1][2]});
					dp[i][j][1]=max({dp[1-i][j][1],dp[1-i][j-1][0],dp[1-i][j-1][2]});
					dp[i][j][2]=max({dp[1-i][j][2],dp[1-i][j-1][0],dp[1-i][j-1][1]})+1;
				}
				if(y=='S'){
					dp[i][j][0]=max({dp[1-i][j][0],dp[1-i][j-1][1],dp[1-i][j-1][2]});
					dp[i][j][1]=max({dp[1-i][j][1],dp[1-i][j-1][0],dp[1-i][j-1][2]})+1;
					dp[i][j][2]=max({dp[1-i][j][2],dp[1-i][j-1][0],dp[1-i][j-1][1]});
				}
				if(y=='P'){
					dp[i][j][0]=max({dp[1-i][j][0],dp[1-i][j-1][1],dp[1-i][j-1][2]})+1;
					dp[i][j][1]=max({dp[1-i][j][1],dp[1-i][j-1][0],dp[1-i][j-1][2]});
					dp[i][j][2]=max({dp[1-i][j][2],dp[1-i][j-1][0],dp[1-i][j-1][1]});
				}
			}
			else{
				dp[i][j][0]=dp[1-i][j][0];
				dp[i][j][1]=dp[1-i][j][1];
				dp[i][j][2]=dp[1-i][j][2];
				if(y=='H')dp[i][j][2]++;
				if(y=='S')dp[i][j][1]++;
				if(y=='P')dp[i][j][0]++;
			}
		}
	}
	int ans=0;
	for(int i=0; i<=k; i++)for(int j=0; j<3; j++)ans=max(ans,dp[n&1][i][j]);
	cout<<ans;
	
	return 0;
}