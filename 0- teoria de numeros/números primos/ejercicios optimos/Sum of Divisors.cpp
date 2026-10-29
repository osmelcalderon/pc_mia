#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll n;
int main(){
	cin>>n;
	ll r=sqrt(n);
	ll s=0;
	for(int i=1;i<=r;i++){
		ll h=n/i;
	    s=(((i*(h-i))%mod)+s)%mod;
		s=(((((((h+i)%mod)*((h-i+1)%mod))%mod)*500000004)%mod)+s)%mod;
	}
	cout<<s;
return 0;
}