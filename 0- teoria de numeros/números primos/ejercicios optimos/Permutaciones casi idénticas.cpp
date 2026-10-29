#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main (){
    //freopen ( "B.in","r",stdin );
    //freopen ( "B.out","w",stdout );
	cin>>n>>k;
	ans+=1;
	if (k>=2) ans+=n*(n-1)/2;
	if (k>=3) ans+=n*(n-1)*(n-2)/3;
	if (k>=4) ans+=n*(n-1)*(n-2)*(n-3)/24*9;
	cout<<ans;
return 0;
}