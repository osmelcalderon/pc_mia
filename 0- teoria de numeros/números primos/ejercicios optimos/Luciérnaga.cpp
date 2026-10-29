#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vb vector<bool>
#define qi queue<int>
#define pii pair<int,int>
#define pq priority_queue<pii,vector<pii>,greater<pii>>
#define f first
#define p_b push_back
#define vii vector<pii>
#define s second
#define double long double
using namespace std;
const int inf=1e18, cero=0;

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, h;
	cin>>n>>h;
	vi a(h+1,0), b(h+1,0);
	for(int i=0; i<n; i++){
		int y;
		cin>>y;
		if(i%2==0)a[y]++;
		else b[h-y+1]++;
	}
	for(int i=h-1; i>0; i--)a[i]+=a[i+1];
	for(int i=1; i<=h; i++)b[i]+=b[i-1];
	int ans=inf, ans2=0;
	for(int i=1; i<=h; i++){
		//cout<<i<<" "<<b[i]<<" "<<a[i]<<"\n";
		if(a[i]+b[i]<ans){
			ans2=1;
			ans=a[i]+b[i];
		}
		else if(a[i]+b[i]==ans)ans2++;
	}
	cout<<ans<<" "<<ans2;

	return 0;
}