#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<string>
#include<climits>
#include<bitset>
#define ENDL '\n'
#define MID (left+right)/2
#define MAXN 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;

ll inverseModular(ll i, ll m){
return i<=1 ? i:m-(ll)(m/i)*inverseModular(m%i, m)%m;
}

int n;
double adj[1001][1001];
vector<pair<double, double>>cows(1001);

struct Edge{
	double w=1000000000;
	int to=-1;
};

inline void Prim(){
	double max_edge=-INT_MAX;
	vector<bool>selected(n, 0);
	vector<Edge>min_e(n);
	min_e[0].w=0;
	
	for(int i=0; i<n; i++){
		int v=-1;
		for(int j=0; j<n; j++){
			if(!selected[j] && (v==-1 || min_e[j].w<min_e[v].w))v=j;
		}
		selected[v]=true;
		max_edge=max(max_edge, min_e[v].w);
		
	for(int to=0; to<n; to++){
		if(adj[v][to]<min_e[to].w){
		min_e[to].w=adj[v][to];
		min_e[to].to=v;
		}
	}
	}
	cout<<(int)max_edge;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=0; i<n; i++)cin>>cows[i].first>>cows[i].second;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				adj[i][j]=INT_MAX;
				continue;
			}
			adj[i][j]=pow(cows[i].first-cows[j].first, 2.0)+pow(cows[i].second-cows[j].second, 2.0);
			//cout<<(int)pow(adj[i][j],2)<<ENDL;
		}
	}
	
	Prim();
	
	
	
	return 0;
}