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
#define ve vector
#define vi vector<int>
#define vii vector<pii>
#define viii evector<piii>
#define vvi vector<vi>
#define vs vector<string>
#define all(x) x.begin(), x.end()

#define prtV(x)for(auto i:x)cout<<i<<" ";

#define cint const int
#define int long long

int mod=1000000007;
cint mod1=100000007;
cint mod2=998244353;

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
	
	int n,a,b;
	cin>>n>>a>>b;
	
	/*if(n==1){
		
		
		return 0;
	}*/
	
	vector<double> dp1(6*(n+1),0),dp2(6*(n+1)),dp3(6*(n+1),0);
	dp1[0]=1;
	
	for(int i=1;i<=n;i++){
		dp2=dp3;
		for(int pos=1;pos<=(i+1)*6;pos++){
			for(int j=1;j<=6;j++){
				if(pos-j>=0){
					dp2[pos]+=dp1[pos-j]/(6.0);
				}
			}
		}
		dp1=dp2;
	}
	cout.precision(6);cout<<fixed;
	double res=0;
	for(int i=a;i<=b;i++){
		res+=dp1[i];
	}
	cout<<res;
	return 0;
}