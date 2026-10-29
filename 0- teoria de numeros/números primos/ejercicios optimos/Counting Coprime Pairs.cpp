#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500005
ll n,a[MAX],b[2000005],k,m[2000005],mo[5000005];
int main(){
	cin>>n;
	ll mx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		b[a[i]]++;
	}
	ll r=(n*(n-1))/2;
	//cout<<r<<"\n";
	for(int i=2;i<=mx;i++){
		ll c=0,ba=1;
		if(mo[i]==1)continue;
		if(m[i]==0)ba=0;
		for(int j=i;j<=mx;j+=i){
            c+=b[j];
			//cout<<b[j]<<" ";
			if(ba==0){
				m[j]++;
				if(((j/i)%i)==0)mo[j]=1;
			//	cout<<(j/i)%i<<" "<<mo[j];
			}
		//	cout<<j<<" "<<(1-mo[j])*m[j]<<"\n";
		}
		//cout<<i<<" "<<c<<"\n";
		ll d=1;
		if(m[i]%2==1)d*=-1;
		//cout<<((c*(c-1))/2)*d<<"\n";
        r+=((c*(c-1))/2)*d;
	}
	cout<<r;
return 0;
}