#include <bits/stdc++.h>
using namespace std;
#define srtl(x)sort((x).begin(),(x).end())
#define srtg(x)sort((x).begin(),(x).end(),greater<>())
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define ins insert
#define vi vector<int>
#define vii vector<pii>
#define viii vector<pair<int,pii>>
#define cint const int
#define vvi vector<vi>
int ax[4]={0,1,0,-1};
int ay[4]={1,0,-1,0};
//#define int long long
cint oo=INT_MAX;
const long long OO=LONG_LONG_MAX;

int32_t main(){
    ios;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
	}
    srtl(v);
    v.ins(v.begin(),0);
    int dp[n+2][n+2][2];
    for(int i=n;i>0;i--){
    	dp[i][i][0]=abs(n*v[i]);
    	dp[i][i][1]=abs(n*v[i]);
    	for(int j=1;i+j<=n;j++){
    		dp[i][i+j][0]=dp[i][i+j][1]=oo;
    		dp[i][i+j][0]=min(dp[i][i+j][0],dp[i+1][i+j][0]+abs(abs(v[i+1]-v[i])*(n-j)));
    		dp[i][i+j][0]=min(dp[i][i+j][0],dp[i+1][i+j][1]+abs(abs(v[i+j]-v[i])*(n-j)));
    		dp[i][i+j][1]=min(dp[i][i+j][1],dp[i][i+j-1][1]+abs(abs(v[i+j]-v[i+j-1])*(n-j)));
    		dp[i][i+j][1]=min(dp[i][i+j][1],dp[i][i+j-1][0]+abs(abs(v[i+j]-v[i])*(n-j)));
		}
	}
    cout<<min(dp[1][n][0],dp[1][n][1]);
    //-12 -2 3 7
    return 0;
}