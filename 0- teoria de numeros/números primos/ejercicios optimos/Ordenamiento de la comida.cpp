// io_papuh
// Copyright DMOJ

#include "stdio.h"
#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "queue"
#include "stack"
#include "map"
#include "set"
#include "stdlib.h"
#include "unordered_map"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define sz size
#define rsz resize
#define mst memset
#define szf sizeof
#define ll long long
#define ull unsigned long long
#define sll signed long long
#define fast() ios_base::sync_with_stdio(0); cin.tie(0);
#define mod_exit(x) cout.precision(x);cout<<fixed;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;

const int dx[] {0,1,0,-1};
const int dy[] {1,0,-1,0};

const int mxn = 1e6 + 7;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

int arr[mxn]; bool mk[mxn];
vii cows;

int main(){
	fast(); mod_exit(0);
	//cout<<"Hello,World!"<<'\n';
	
	int n; cin>>n;
	
	for(int i=0;i<n;i++){
		int x; cin>>x; cows.pb({x,i});
	}
	
	sort(cows.begin(),cows.end());
	int m = cows[0].ff;
	int ans = 0;
	
	for(int i=0;i<n;i++){
		if(cows[i].ss != -1){
			int j = cows[i].ss;
			int w = cows[i].ff;
			int cont = 1;
			
			cows[i].ss = -1;
			
			while(j != i){
				ans += cows[j].ff;
				int nxt = cows[j].ss;
				cows[j].ss = -1;
				
				j = nxt; cont++;
			}
			ans += min((cont - 1) * w , (cont - 1) * m + 2 * (m + w));
		}
	}
	
	cout<<ans<<'\n';
	
	exit(0);
}