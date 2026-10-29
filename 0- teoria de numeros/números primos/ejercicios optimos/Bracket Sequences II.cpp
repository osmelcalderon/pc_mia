#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2000005
#define S second
ll const mod=1000000007;
ll sp[80],ac[90],f[MAX];
ll qpow(ll a,ll b){
   b=(b+mod-1)%(mod-1);
   if(b==0)return 1;
   if(b%2==1)return (a*qpow(a,b-1))%mod;
return qpow((a*a)%mod,b/2);
}
ll C (ll x,ll y){	
    return (((f[x]*qpow(f[y],-1))%mod)*qpow(f[x-y],-1))%mod;
}
int main(){
	ll n,k;f[0]=1;
	for(int i=1;i<MAX;i++)f[i]=(f[i-1]*i)%mod;
    string a;
	cin>>n>>a;
	if(n%2==1){
		cout<<0;return 0;
	}
    n/=2;
    k=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='('){k++;n--;}
        else         k--;
        if(k<0){cout<<0;return 0;}
    }
	cout<<((((k+1)*qpow(n+k+1,-1))%mod)*C(2*n+k,n))%mod;
return 0;
}