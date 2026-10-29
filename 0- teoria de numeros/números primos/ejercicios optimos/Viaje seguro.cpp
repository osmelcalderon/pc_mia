#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define tam(x)  (int)(x).size()
#define endl "\n"
#define sd second
#define fs first
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define optmizar_io  ios_base::sync_with_stdio(0); cin.tie(0);
#define Setpre(n) cout<<fixed<<setprecision(n)
#define dbg(x) for(auto y: x) cout<<y<<' '; cout<<endl;
#define dbg1(x) for(auto y: x) cout<<y.first<<' '<<y.second<<endl;
#define dbg2(v) for(auto x:v) cout<<x.a<<' '<<x.b<<' '<<x.c<<endl;
const int MAX = 2e5;
const int INF = 1e17;
const int Mod = 1e9+7;
const int zero = 0;
const double eps = 1e-6;
const double PI=acos(-1.0);
const int mox[8] ={-1,1,0,0,-1,-1,1,1};
const int moy[8] ={0,0,-1,1,-1,1,-1,1};
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

int32_t main() {
	optmizar_io

	int n;
	cin >> n;
	int cord = 4e5+1;
	set<int> l1[cord]; set<int>  l2[cord+MAX];
	set<int> l11[cord]; set<int> l21[cord+MAX];
	set<int> lf[cord]; set<int> dw[cord];
	vector<pi> l,r,u,d;
	int ans = INF;
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		char aux; cin >> aux;
		if(aux == 'U'){
			u.pb({a,b});
			l1[a+b].insert(a);
			l11[b-a+MAX].insert(a);
		}
		else if(aux == 'D'){
			d.pb({a,b});
			l21[a+b].insert(a);
			l2[b-a+MAX].insert(a);
			dw[a].insert(b);
		}
		else if( aux == 'L'){
			l.pb({a,b});
			lf[b].insert(a);
		}
		else if(aux == 'R'){
			r.pb({a,b});
		}
	}
	for(auto x: u){
		auto a = dw[x.first].lower_bound(x.second);
		if(a != dw[x.first].end()){
			ans = min(ans,(*a-x.second)*5);
		}
	}
	for(auto x: r){
		auto a = lf[x.second].lower_bound(x.first);
		if(a != lf[x.second].end()){
			ans = min(ans,(*a-x.first)*5);
		}
	}
	for(auto x: r){
		int aux = x.first + x.second;
		auto a = l1[aux].lower_bound(x.first);
		if(a != l1[aux].end()){
			ans  = min(ans,(*a - x.first)*10);
		}
		aux = x.second - x.first + MAX;
		a = l2[aux].lower_bound(x.first);
		if(a != l2[aux].end()){
			ans  = min(ans,(*a - x.first)*10);
		}
	}
	for(auto x: l){
		int aux = x.first + x.second;
		auto a = l21[aux].upper_bound(x.first);
		if(a != l21[aux].begin()){
			a--;
			ans = min(ans,(x.first-(*a) )*10);
		}
		aux = x.second - x.first + MAX;
		a = l11[aux].upper_bound(x.first);
		if(a != l11[aux].begin()){
			a--;
			ans =  min(ans,( x.first-(*a))*10);
		}
	}
	if(ans == INF) {
		cout<<"SAFE"<<endl;
		return 0;
	}
	cout<<ans<<endl;


	return 0;
}