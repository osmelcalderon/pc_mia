#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
#define MAX 1000000000000
using namespace std;
int32_t main(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll co[n],va[n];
    for(ll&i:va)cin>>i;
    for(ll&i:co)cin>>i;
    vector<ll>c;
    vector<ll>w;
    for(ll i=0;i<n;i++){
        ll j=1;
        while(co[i]>0){
            ll k=min(co[i],j);
            co[i]-=k;
            c.push_back(va[i]*k);
            w.push_back(k);
            j*=2;
        }
    }
    ll dev_dp[k+1],dp[k*2+1];
    for(ll i=0;i<=k;i++){
        dev_dp[i]=MAX;
        dp[i]=MAX;
        dp[i+k]=MAX;
    }
    dev_dp[0]=0;
    dp[0]=0;
    for(ll i=0;i<n;i++){
        for(ll j=va[i];j<=k;j++){
            dev_dp[j]=min(dev_dp[j],dev_dp[j-va[i]]+1);
        }
    }
    for(ll i=0;i<c.size();i++){
        for(ll j=k*2;j>=c[i];j--){
            dp[j]=min(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    for(ll j=k;j<=k;j++){
        for(ll i=0;i<c.size();i++){
            if(j+c[i]<=k*2)dp[j]=min(dp[j],dp[j+c[i]]+dev_dp[c[i]]);
        }
    }
    cout<<((dp[k]==MAX)?-1:dp[k]);
}