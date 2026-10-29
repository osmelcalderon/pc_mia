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
 
int mod=1000000007;
cint mod1=1e18;
cint mod2=998244353;
 
int ax[8]={0,1,0,-1,-1,1,1,-1};
int ay[8]={1,0,-1,0,1,-1,1,-1};
 
//int n,m;
 
//bool on(int x,int y){return (x>=0&&x<n&&y>=0&&y<m);}
//int euc(int a,int b,int c,int d){return abs(a-c)+abs(b-d);}
 
#define ve vector
 
int32_t main(){
	
	ios;
	
	
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	
	int x[n+2];
	x[0]=-1;
	for(int i=1;i<=n;i++)x[a[i]]=i;
	
	int res=1;
	int pa=x[1];
	for(int i=2;i<=n;i++){
		if(pa>x[i])res++;
		pa=x[i];
	}
	
	while(m--){
		int j,k;
		cin>>j>>k;
		bool f1=0,f2=0,f3=0,f4=0;
		bool b1=x[a[j]-1]<x[a[j]],b2=x[a[j]]<x[a[j]+1];
		swap(x[a[j]],x[a[k]]);
		bool b3=x[a[j]-1]>x[a[j]],b4=x[a[j]]>x[a[j]+1];
		if(b1&&b3){
			res++;f1=1;
		}
		if(b2&&b4){
			res++;f2=1;
		}
		
		if(!b1&&!b3){
			res--;f3=1;
		}
		if(!b2&&!b4){
			res--;f4=1;
		}
		swap(x[a[j]],x[a[k]]);
		b1=x[a[k]-1]<x[a[k]],b2=x[a[k]]<x[a[k]+1];
		swap(x[a[j]],x[a[k]]);
		b3=x[a[k]-1]>x[a[k]],b4=x[a[k]]>x[a[k]+1];
		
		if(b1&&b3&&a[j]!=a[k]-1){
			res++;
		}
		if(b2&&b4&&a[j]!=a[k]+1){
			res++;
		}
		
		if(!b1&&!b3&&a[j]!=a[k]-1){
			res--;
		}
		if(!b2&&!b4&&a[j]!=a[k]+1){
			res--;
		}
		swap(a[j],a[k]);
		cout<<res<<"\n";
	}
	
	//return 0;
}