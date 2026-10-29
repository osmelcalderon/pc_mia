#include<iostream>
#define ENDL '\n'
using namespace std;
int main(){
	
	int n, f;
	cin>>n>>f;
	int nums[n+1];
	for(int i=1; i<=n; i++){
		cin>>nums[i];
		nums[i]%=f;
	}
	
	int dp[n+1][f];
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<f; j++){
			dp[i][j]=0;
		}
	}
	
	for(int i=1; i<=n; i++){
		dp[i][nums[i]]++;
		for(int j=0; j<f; j++){
			dp[i][j]+=(dp[i-1][j]+dp[i-1][(j-nums[i]+f)%f])%100000000;
		}
	}
	
	cout<<dp[n][0]%100000000;
	
	return 0;
}