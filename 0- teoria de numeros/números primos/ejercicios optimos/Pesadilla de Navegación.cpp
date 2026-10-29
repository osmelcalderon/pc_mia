#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define ENDL '\n'
#define mid (l+r)/2
#define MAXN 100001
#define mod 1000000007
#define ft first
#define sd second
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef long double ld;

ll n, m, k;

ll binpow(ll a, ll b){
	if(b==0)return 1;
	if(b==1)return a;
	ll num=binpow(a,b>>1)%mod, p=1;
	if(b%2)p=a;
	ll part=(num*num)%mod;
	return (part*p)%mod;
}

const int mov_f[]={-1,0,1, 0};
const int mov_c[]={0,-1,0, 1};

bool valid(int f, int c){
	return(f>=1 && f<=n && c>=1 && c<=n);
}

int log2(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

struct Edge{
    int u, v, w;
    char d;
};

vector<Edge>edges;
vector<vector<pair<pair<int, int>, char>>>adj(40001);
vector<pair<int, int>>c(40001);

void dfs(int v, int p, int d, char x){
    if(x=='N' && v!=1)c[v]={c[p].first-d, c[p].second};
    if(x=='S' && v!=1)c[v]={c[p].first+d, c[p].second};
    if(x=='E' && v!=1)c[v]={c[p].first, c[p].second+d};
    if(x=='W' && v!=1)c[v]={c[p].first, c[p].second-d};

    for(auto u: adj[v]){
        if(u.first.first==p)continue;
        dfs(u.first.first, v, u.first.second, u.second);
    }
}

vi parent(40001), size(40001);

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve(){
   cin>>n>>m;
   for(int i=0; i<m; i++){
    int a, b, w;
    char x;
    cin>>a>>b>>w>>x;
    edges.push_back({a, b, w, x});
    adj[a].push_back({{b, w}, x});
    char aux;
    if(x=='N')aux='S';
    else if(x=='S')aux='N';
    else if(x=='W')aux='E';
    else aux='W';

    adj[b].push_back({{a, w}, aux});
   }

   c[1]={0, 0};
   dfs(1, 0, 0, 0);
   for(int i=1; i<=n; i++){
        make_set(i);
        //cout<<c[i].first<<" "<<c[i].second<<ENDL;
   }


   cin>>k;
   int p=0;
   for(int i=0; i<k; i++){
    int a, b, id;
    cin>>a>>b>>id;
    while(p<id-1){
        int x=find_set(edges[p].u), y=find_set(edges[p].v);
        union_sets(x, y);
        p++;
    }
    int x=find_set(edges[p].u), y=find_set(edges[p].v);
    union_sets(x, y);

    if(find_set(a)!=find_set(b))cout<<-1<<ENDL;
    else{
        cout<<abs(c[a].first-c[b].first)+abs(c[a].second-c[b].second)<<ENDL;
    }
   }


}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	//freopen("fencedin.in", "r", stdin);
	//freopen("fencedin.out", "w", stdout);

	int t=1;
	//cin>>t;
	while(t--)solve();

	return 0;
}