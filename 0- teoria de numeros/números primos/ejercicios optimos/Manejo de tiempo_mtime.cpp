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

#define ve vector
#define pii pair<int,int>
#define piii pair<int,pii>
#define vi vector<int>
#define vii vector<pii>
#define viii evector<piii>
#define vvi vector<vi>
#define vs vector<string>
#define all(x) x.begin(), x.end()

#define ic(x)int x;cin>>x
#define pV(x)for(auto i:x)cout<<i<<" ";

#define fr(n)for(int i=0;i<n;i++)
#define no(x){cout<<x<<"\n";return 0;}

#define cint const int
#define int long long

cint mod1=100000007;
cint mod2=998244353;
int mod=mod2;
int ax[8]={0,1,0,-1,-1,1,1,-1};
int ay[8]={1,0,-1,0,1,-1,1,-1};

//int n,m;

//bool on(int x,int y){return (x>=0&&x<n&&y>=0&&y<m);}
//int euc(int a,int b,int c,int d){return abs(a-c)+abs(b-d);}

int bp(int x,int y){
	if(y==0)return 1;
	int r=bp(x,y/2);
	return (y&1)?r*r%mod*x%mod:r*r%mod;
}

cint oo=INT_MAX;
const long long OO=LONG_LONG_MAX;

int32_t main(){
	
	ios;
	
	int n;
	cin>>n;
	
	vii v(n);
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[i]={y,y-x};
		if(x>y){cout<<"-1\n";return 0;}
	}
	srtl(v);
	
	int t=v[n-1].f;
	
	for(int i=n-1;i>=0;i--){
		t=min(t,v[i].f);
		t-=v[i].f-v[i].s;
		if(t<0){t=-1;break;}
	}
	cout<<t;
	return 0;
}
/*
1
2 5
3 5
*/
