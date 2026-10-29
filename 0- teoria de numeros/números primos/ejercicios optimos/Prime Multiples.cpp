#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll cmod=1000000006;
#define MAX 500005
ll n,a[MAX],b[MAX],k;
int main(){
	cin>>k>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll r=0;
	for(int i=1;i<(1LL<<n);i++){
		ll c=-1;ll num=1;
		for(int j=0;j<n;j++){
			if((1LL<<j)&i){
				c*=-1;
			    if(num>k/a[j]){
					num=k+1;
					break;
				}
				num*=a[j];
			}
		}
		r+=c*(k/num);
	}
	cout<<r;
return 0;
}