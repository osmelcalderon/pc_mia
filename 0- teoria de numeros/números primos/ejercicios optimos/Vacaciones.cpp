#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
const int mod=1e9+7;
const int mx=1e5+1;
int dp[mx+1][3];
int32_t main() {
    fast
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a;
         dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b;
          dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c;
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
    return 0;
}