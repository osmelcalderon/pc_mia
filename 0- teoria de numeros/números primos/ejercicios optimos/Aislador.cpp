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
	int n, ans=0;
	cin>>n;
	vi a(n);
	for(int i=0; i<n; i++)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=0; i<n/2; i++){
		ans+=a[i]+a[n-(i+1)]+(a[n-(i+1)]-a[i]);
	}
	if(n%2!=0)ans+=a[n/2];
	cout<<ans;

	return 0;
}