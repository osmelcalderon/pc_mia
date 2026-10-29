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
 
#define ic(x)int x;cin>>x
#define is(x)string x;cin>>x
#define prtV(x)for(auto i:x)cout<<i<<" ";
 
#define cint const int
#define int long long
 
int mod=1000000007;
cint mod1=100000007;
cint mod2=998244353;
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
 
const int N=200005;
 
int32_t main(){
	ios;
	int n;
	cin>>n;
	int a[n];
	for(int &i:a)cin>>i;
	int p[n];
	for(int i=0;i<n;i++){
		p[a[i]]=i;
	}
	int pos=-1;
	int c=1;
	for(int i=1;i<=n;i++){
		if(pos<p[i]){
			pos=p[i];
		}
		else{
			c++;
			pos=p[i];
		}
	}
	cout<<c;
	return 0;
}