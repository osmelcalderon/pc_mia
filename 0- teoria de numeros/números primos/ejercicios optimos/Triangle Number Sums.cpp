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
#define piii pair<pii,int>
#define vi vector<int>
#define vii vector<pii>
#define viii vector<piii>
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
int mod=1e9+7;
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

bool ver(int n){
	int sq=sqrt(2*n);
	if(sq*(sq+1)==n*2||sq*(sq-1)==n*2||(sq-2)*(sq-1)==n*2||(sq+2)*(sq+1)==n*2)return 1;
	return 0;
}
#define cn continue




int32_t main(){
	
	ios;
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(ver(n)){
			cout<<"1\n";
			continue;
		}
		bool fl=0;
		for(int i=1;i<=sqrt(n)+1;i++){
			int num=n-(i*(i+1)/2);
			if(ver(num)){
				cout<<"2\n";
				fl=1;break;
				
			}
		}
		if(fl)cn;
		cout<<3<<"\n";
	}
	return 0;
}