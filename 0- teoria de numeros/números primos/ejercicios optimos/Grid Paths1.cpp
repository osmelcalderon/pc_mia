#include<bits/stdc++.h>
using namespace std;

#define dana cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout.setf(ios::fixed);cout.precision(0)
typedef long long ll;

const int MOD = int(1e9 + 7);

void solve(){
	
	int n, i, j;
	
	cin>>n;
	
	char mat[n + 1][n + 1];
	int dp[n + 1][n + 1];
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cin>>mat[i][j];
			dp[i][j] = 0;
		}
	}
	if(mat[1][1] != '*')
	    dp[1][1] = 1;
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			
			if(mat[i][j] != '*' && mat[i][j + 1] != '*') dp[i][j + 1] += dp[i][j], dp[i][j + 1] %= MOD;
			if(mat[i][j] != '*' && mat[i + 1][j] != '*') dp[i + 1][j] += dp[i][j], dp[i + 1][j] %= MOD;			
		}
	}
	
	cout<<dp[n][n];
}

int main(){
	
	dana;

	int t = 1;
	//cin>>t;

	while(t--){
		solve();
	}
}