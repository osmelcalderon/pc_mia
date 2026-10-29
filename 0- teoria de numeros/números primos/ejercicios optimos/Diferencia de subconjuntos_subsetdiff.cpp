#include<bits/stdc++.h>
#define int long long
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int mod=1e9+7;

int exp(int x,int y){
    if(y == 0)return 1;
    if(y == 1)return x%mod;
    if(y%2 == 0){
        int q = exp(x,y/2)%mod;
        return (q*q)%mod;
    }
    return (((exp(x,y-1))%mod)*((x)%mod))%mod;
}
int inv(int x){
    return exp(x,mod-2);
}
int32_t main(){
    int n;cin>>n;
    int *a;
    a=new int[n];
    for(int i =0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i =0;i<n;++i){
        ans=( ans +(( a[i]*exp(2,i+1))%mod - (a[i]*exp(2,n-i))%mod + mod))%mod;
    }
    cout<<(ans * inv(2))%mod<<'\n';

    return 0;
}
