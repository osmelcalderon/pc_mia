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
	int x, y, a, b, c, ans=0;
	cin>>x>>y>>a>>b>>c;
	vi ver(b), roj(a), bla(c), cho;
	for(int i=0; i<a; i++)cin>>roj[i];
	for(int i=0; i<b; i++)cin>>ver[i];
	for(int i=0; i<c; i++)cin>>bla[i];
	sort(roj.rbegin(),roj.rend());
	sort(ver.rbegin(),ver.rend());
	sort(bla.rbegin(),bla.rend());
	for(int i=0; i<x; i++)cho.p_b(roj[i]);
	for(int i=0; i<y; i++)cho.p_b(ver[i]);
	int aux=cho.size();
	sort(cho.begin(),cho.end());
	for(int i=0; i<min(aux,c); i++){
		if(cho[i]<bla[i])cho[i]=bla[i];
	}
	for(int i=0; i<cho.size(); i++)ans+=cho[i];
	cout<<ans;

	return 0;
}