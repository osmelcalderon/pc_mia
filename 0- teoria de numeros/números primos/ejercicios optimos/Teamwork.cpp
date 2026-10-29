#include<bits/stdc++.h>
using namespace std;
//\\ PRINCIPAL \\//
 
#define oo 1e18
#define endl "\n"
#define mod 1000000007
#define int long long
#define tle while(1){;}
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
 
//\\ BITS \\//
 
#define bits_1 __builtin_popcount 
 
//\\ STL \\//
 
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lb(x,y) lower_bound(x.begin(),x.end(),y)-x.begin()
#define ub(x,y) upper_bound(x.begin(),x.end(),y)-x.begin()



void solve() {
    int n,k;
    cin >> n >> k;

    vector<int>v(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int>dp(n + 1,0);


    for(int i = 1; i <= n; i++)
    {
        int maxx = 0;
        for(int j = i; j >= max(1LL,i - k + 1); j--)
        {
            maxx = max(maxx,v[j]);
            dp[i] = max(dp[i],dp[j - 1] + maxx * (i - j + 1));
            //cout << i << " " << dp[i] << endl;
        }
    }

    cout << dp[n] << endl;
}




int32_t main() {

    int t = 1;

    while(t--)solve();

    return 0;
}