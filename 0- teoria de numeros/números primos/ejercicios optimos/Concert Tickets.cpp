#include <bits/stdc++.h>
using namespace std;
 
#define srtl(x)sort((x).begin(),(x).end())
#define srtg(x)sort((x).begin(),(x).end(),greater<>())
#define rev(x) reverse((x).begin(),(x).end())
#define lb(x,y) lower_bound(x.begin(),x.end(),y)-x.begin()
#define ub(x,y) upper_bound(x.begin(),x.end(),y)-x.begin()
 
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define wa cout<<"wa";
#define tl while(1){}
 
#define f first
#define s second
#define pb push_back
#define ins insert
#define next next_permutation
#define _b __builtin_popcount
 
#define pii pair<int,int>
#define piii pair<int,pii>
#define vi vector<int>
#define vii vector<pii>
#define viii evector<piii>
#define vvi vector<vi>
#define vs vector<string>
#define all(x) x.begin(), x.end()
 
#define fl fflush(stdout)
#define ic(x)int x;cin>>x
#define is(x)string x;cin>>x
#define prtV(x)for(auto i:x)cout<<i<<" ";
 
#define cint const int
#define int long long
 
int32_t main(){
	ios;
	
	multiset<int>m;
	
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		m.insert(x);
	}
	
	while(k--){
		int x;
		cin>>x;
		auto p=m.upper_bound(x);
		if(p==m.begin())cout<<"-1\n";
		else{
			p--;
			cout<<*p<<"\n";
			m.erase(p);
		}
	}
	
	return 0;
}