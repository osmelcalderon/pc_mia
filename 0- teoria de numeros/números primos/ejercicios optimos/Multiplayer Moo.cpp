#include "bits/stdc++.h"
#pragma GCC optimize("03")
#define opt std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);std::cout.precision(2);cout<<fixed;

/// Errors :
#define rte std::vector<int>rtt(oo);
#define wa std::cout<<"d";
#define tle while(1){;}
#define ir exit(1);

/// STL declaration :
#define ii  std::pair<int,int>
#define vb  std::vector<bool>
#define iii std::pair<ii,int>
#define vi  std::vector<int>
#define qi  std::queue<int>
#define vii std::vector<ii>
#define qii std::queue<ii>

/// STL manipulation :
#define ppf pop_front()
#define ppb pop_back()
#define pf push_front
#define pb push_back
#define fr front()
#define bk back()
#define ss second
#define fs first
#define pp pop()
#define tp top()
#define ph push

/// General :
using namespace std;
#define gcd(a,b) __int64(__gcd((a),(b)))
#define rall(v) v.rbegin(),v.rend()
#define all(v)  v.begin(),v.end()
#define int long long
#define endl "\n"

/// Constants :
const int oo=INT64_MAX/2-1;
const int md=1e9+7;

/// Functions :
int qp(int a,int b){b--;b%=md;int r=a;while(b!=0){if(!b%2){a*=a;b/=2;a%=md;}else{a*=r;b--;a%=md;}}return a;}
void dbg(std::vector<std::pair<int,int>>v){for(auto i : v){std::cout<<"| "<<i.first<<" , "<<i.second<<"\n";}}
void dbg(std::vector<int>v){for(auto i : v){std::cout<<"| "<<i<<"\n";}}
int n;

int mat[251][251];
vb visi[251];

void res(){
    for(int i=0;i<n;i++){
        visi[i].assign(n+1,0);
    }
}

int dfs(int size, int r, int c, int color1, int color2){
	if((r<0 || r>=n || c<0 || c>=n) || (mat[r][c]!=color1 && mat[r][c]!=color2) || visi[r][c])return size;

	visi[r][c]=1;
	size++;

	size=dfs(size,r,c+1,color1,color2);
	size=dfs(size,r,c-1,color1,color2);
	size=dfs(size,r-1,c,color1,color2);
	size=dfs(size,r+1,c,color1,color2);

	return size;
}


int32_t main(){opt;
	cin>>n;
    res();

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	int ans=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visi[i][j]){
				ans=max(ans,dfs(0,i,j,mat[i][j],mat[i][j]));
			}
		}
	}
	cout<<ans<<endl;
	ans=0;

	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(ans>=n*n/2){
				cout<<ans<<endl;
				return 0;
			}
			if(mat[i][j]!=mat[i][j-1]){
				res();
				ans=max(ans,dfs(0,i,j,mat[i][j],mat[i][j-1]));
			}
		}
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(ans>=n*n/2){
				cout<<ans<<endl;
				return 0;
			}
			if(mat[i][j]!=mat[i-1][j]){
				res();
				ans=max(ans,dfs(0, i, j, mat[i][j], mat[i-1][j]));
			}
        }
	}

	cout<<ans<<endl;
	return 0;
}