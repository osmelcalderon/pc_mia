#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0;i < n;i++){
    	cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    
	int ans = 0;
    for(int i = 0;i < n;i++){
    	for(int j = i+1;j < n;j++){
    		dp[i][j] = a[i].second;
    		ans = max(ans,dp[i][j] + a[j].second);
    	}
    }    
    for(int i = 0;i < n;i++){
    	int k = i,val = 0;
    	for(int j = i+1;j < n;j++){
    		while(k > 0 && a[i].first - a[k-1].first <= a[j].first - a[i].first){
    			k--;
    			val = max(val,dp[k][i]);
    		}
    		dp[i][j] = val + a[i].second;
    		ans = max(ans,dp[i][j] + a[j].second);
    	}
    }
	reverse(a.begin(),a.end());
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			dp[i][j] = 0;
			
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			dp[i][j] = a[i].second;
			ans = max(ans,dp[i][j] + a[j].second);
		}
	}
	
	for(int i = 0;i < n;i++){
		int k = i,val = 0;
		for(int j = i+1;j < n;j++){
			while(k > 0 && a[k-1].first - a[i].first <= a[i].first - a[j].first){
				k--;
				val = max(val,dp[k][i]);
			}
			dp[i][j] = val + a[i].second;
			ans = max(ans,dp[i][j] + a[j].second);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}