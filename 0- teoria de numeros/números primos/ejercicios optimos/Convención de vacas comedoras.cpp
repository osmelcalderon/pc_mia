#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

//\\ PRINCIPAL \\//

#define int long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(0); //srand(time(NULL));

//\\ VECTOR \\//

#define pb push_back
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ordenar(x) sort( x.begin(), x.end() )
#define ordenarA(x,n) sort( x, x + n )

//\\ OPERACIONES RAPIDAS \\//

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%lld", &n)
#define sffl(n,m) scanf("%lld%lld",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%lld ",n)
#define pfs(s) printf("%s\n",s)

const int MAXI = 1e5+5, mod = 1e9+7;

inline int suma(int a, int b){
	if(a+b < 0) a += mod;
	return a+b>=mod ? a+b-mod : a+b;
}

inline int mul(int a, int b){
	int res = 1LL*a*b % mod;
	return res;
}

inline void Es(bool x){
	string s = x == true ? "YES\n" : "NO\n";
    cout<<s;
}

void setIO(string name = "") {
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve();

int32_t main(){
    //setIO("convention");
	ios;
    int t = 1;
    while(t--){
     	solve();
	}

	fflush(stdin);
	fflush(stdout);
}

void solve(){
	int n, m, c; cin>>n>>m>>c;
	int a[n]; for(int& x: a){cin>>x;} 
	sort(a, a+n);
	int l = 1, r = 1e9+5;
	while(r>l){
		int mid = l + (r-l)/2, pos = 0, i = 0;
		for(;pos!=n && i<=m;){
			int t = pos, y = min(pos+c-1, n-1);
			while(y>t){
				int u = t + (y-t+1)/2;
				if(a[u]-a[pos]<=mid) t = u;
				else y = u-1;
			}
            pos = t+1;
            ++i;
		}
		if(pos==n && i<=m) r = mid;
		else l = mid+1;
	}
	cout<<l;
}