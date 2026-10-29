#include<bits/stdc++.h>
#define int long long
#define FOR(i,k,n) for(int i=k;i<n;i++)
#define pb push_back
using namespace std;
const int mod=1e9+7;

vector<int>fact(11,0);
vector<int>inv(11,0);

int binpow(int a,int b){
    int ans=1;
    while(b>0){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

void factorial(){
    fact[0]=1;
    FOR(i,1,11){    
        fact[i]=(fact[i-1]*i);
    }
}

void inverses(){
    inv[10]=binpow(fact[10],mod-2);
    for(int i=10;i>=1;i--){    
        inv[i-1]=(inv[i]*i)%mod;
    }
}

int combination(int n,int p){
    return (fact[n]/(fact[n-p]*fact[p]))%mod;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,a,b; cin>>n>>a>>b;
    vector<int>dp(11,0);
    dp[1]=1;
    factorial();
    inverses();
    FOR(i,1,11){
        dp[i]=binpow(i,n);
        FOR(j,1,i) dp[i]=(dp[i]-(dp[j]*combination(i,j))%mod+mod)%mod;
        //cout<<i<<" "<<dp[i]<<endl;
    }
    int ans=0;
    FOR(k,a,min(b+1,n+1)){
        int comb=combination(10,k);
        ans=(ans+(comb*dp[k])%mod)%mod;
        //cout<<dp[k]<<" "<<comb*dp[k]<<endl;
    }
    cout<<ans<<endl;
    
    
    

   return 0;
}