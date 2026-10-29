// Ah shit,here we go again
// o_o

#include "iostream"
#include "algorithm"
#include "vector"
#include "string.h"
#include "stdio.h"
#include "cstdio"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "bitset"
#include "math.h"
#include "climits"
#include "cmath"
using namespace std;

// --- Basico --- \\\

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);
#define mod 1000000007
#define Go_in(i,n) for(int i=1;i<=n;i++)
#define exit() return 0;
#define ll long long
#define ull unsigned long long
#define sll signed long long
#define med (low + high + 1)/2

// --- STL de C++ --- \\\

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define sz size
#define lg length
#define szf sizeof
#define ff first
#define ss second
#define order(x) sort(x.begin(),x.end())
#define order2(x,n) sort(x,x+n)
#define all(x) (x.begin(),x.end())

// --- Entradas y Salidas rapidas --- \\\

#define isf(x) scanf("%d",&x)
#define lsf(x) scanf("%lld",&x)
#define ssf(x) scanf("%s",&x)
#define csf(x) scanf("%c",%x)
#define sff(x,n) scanf("%d%d",&x,&n)
#define pf(x) printf("%d",x)
#define lpf(x) printf("%lld",x)

const int mxn = 1e6 + 10;
typedef vector<int> vec;
typedef vector<pair<int,int>> vec_pair;
typedef pair<int,int> pr;
typedef vector<vector<int,int>> vec_vec;
typedef queue<int> qq;

int arr[mxn];

int main(){
	fast();
	
	int n,m; cin>>n>>m; int ans=0;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ans = max(ans,arr[i]);
	}
	int low=0,high=ans;
	
	while(low < high){
		ll since=0;
		
		for(int i=0;i<n;i++){
			since += max(0,arr[i] - med);
		}
		if(since < m){
			high = med-1;
		}
		else{
			low = med;
		}
	}
	
	cout<<low<<'\n';
	
}