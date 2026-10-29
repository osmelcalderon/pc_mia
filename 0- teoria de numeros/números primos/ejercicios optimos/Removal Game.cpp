#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pii>
#define MOD 1000000007
#define INF (int)2e18
#define mod(x) (((x)%MOD+MOD)%MOD)
#define MAX 200005
 
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
    int n, sum = 0;
    cin >> n;
 
    vi dp(n+1), a(n+1);
 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i];
        sum += dp[i];
    }
 
    for(int i = 2; i <= n; i++){
        for(int j = 1; j+i <= n+1; j++){
            if(i&1){
                dp[j] = max(dp[j]+a[j+i-1], dp[j+1]+a[j]);
            }
            else{
                dp[j] = min(dp[j], dp[j+1]);
            }
        }
    }
 
    if(n&1) cout << dp[1];
    else cout << sum-dp[1];
    
    return 0;
}