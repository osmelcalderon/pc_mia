#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#define srt(x) sort(x.begin(),x.end())
#define int long long
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;
#define red_black tree<int,null_type,greater,rb_tree_tag,tree_order_satistics_node_update>

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> x(n);
    vector<int> f(n);
    for(auto &i:x)cin>>i.first.second>>i.first.first>>i.second;
    srt(x);
    vector <int> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        f[i-1]=x[i-1].first.first;
        int j=lower_bound(f.begin(),f.begin()+i-1,x[i-1].first.second)-f.begin();
        dp[i]=max(dp[i-1],dp[j]+x[i-1].second);
    }
    cout<<dp[n]<<endl;
    return 0;
}