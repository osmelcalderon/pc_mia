#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","O3")
//#include <iostream>
//#include <vector>
//#include <climits>
//#include <queue>
//#include <set>
//#include <cmath>
//#include <map>
//#include <algorithm>
//#include <stack>
//#include <memory.h>
//#include <string.h>
#include <bits/stdc++.h>
using namespace std;

#define optimized ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Jojo_Cubano main
#define fs first
#define sc second
#define pbk(a) pop_back(a)
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) ((x).size())
#define mid (l+r)/2
#define left pos*2,l,mid
#define right pos*2+1,mid+1,r

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef queue<int> qi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;

const int MAXI = INT_MAX;
const int MINI = INT_MIN;
const long MAXL = LONG_MAX;
const long MINL = LONG_MIN;
const long long MAXLL = LONG_LONG_MAX;
const long long MINLL = LONG_LONG_MIN;
const int mod = 1e9 + 7;
const int nmax = 1e6 + 7;



//-------------------------------------------------------------------------------------------------------\\



//-------------------------------------------------------------------------------------------------------\\

int Jojo_Cubano(){
    optimized;
    long long l, r, res = 0;
    cin>>l>>r;
    vi cant(nmax, 0);
    for(long long i=2;i<=r;i++){
	    if(cant[i]!=0) continue;
	    for(long long j=i; j<=r; j+=i) cant[j]++;
	    for(long long j=i*i; j<=r; j+=i*i) cant[j]=-1000000007;
  	}
  	for(long long i=2; i<=r; i++){
	    if(cant[i]<0) continue;
	    long long cc=(r/i)-((l-1)/i);
	    if(cant[i]%2){
			res+=(cc*(cc-1))/2;
		}
	    else{res-=(cc*(cc-1))/2;}
  	}
	for(long long i=max(2ll,l);i<=r;i++) res-=(r/i-1);
	cout<<res*2<<"\n";
	return 0;
}