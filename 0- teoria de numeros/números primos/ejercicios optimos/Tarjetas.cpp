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
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
	int n;
	cin>>n;
	vii a(n);
	for(int i=0; i<n; i++){
		int y, y1;
		cin>>y>>y1;
		a[i].f=max(y,y1);
		a[i].s=min(y,y1);
	}
	int ans=0, aux=1;
	for(int i=1; i<n; i++){
		if(a[i].f>a[i-1].f or a[i].s>a[i-1].s){
			ans=max(ans,aux);
			aux=1;
		}
		else aux++;
	}
	ans=max(ans,aux);
	cout<<ans;

	return 0;
}