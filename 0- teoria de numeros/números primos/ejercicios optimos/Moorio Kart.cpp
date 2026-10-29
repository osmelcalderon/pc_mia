#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

#define mp make_pair
#define pb push_back
#define f first
#define s second

const int MOD = 1000000007;
const int MX = 1501;
namespace modOp {
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
}

using namespace modOp;

pi operator+(const pi& l, const pi& r) {
    return {ad(l.f,r.f),ad(l.s,r.s)};
}

pi operator+=(pi& l, const pi& r) {
    return l=l+r;
}

pi comb(pi a, pi b) {
    return {ad(mul(a.f,b.s),mul(a.s,b.f)),mul(a.s,b.s)};
}

int N,M,X,Y,K;
bool visit[MX];
vi dist, comp;
vpi adj[MX];
pi res[2501], tmp[2501];

void dfs1(int x) {
    if (visit[x]) return;
    visit[x] = 1;
    comp.pb(x);
    for(auto t : adj[x]){
        dfs1(t.f);
    }
}

void dfs2(int x, int p, int ori, int d = 0) {
    for(auto t : adj[x]){
        if(t.f != p){
            if(ori < t.f){
                dist.pb(d+t.s);
            }
            dfs2(t.f,x,ori,d+t.s);
        }
    }
}

int main() {
//    ifstream in("mooriokart.in");
//    ofstream out("mooriokart.out");
    cin >> N >> M >> X >> Y;
    K = N-M;
    for(int i = 0; i<M; i++) {
        int A,B,D;
        cin >> A >> B >> D;
        adj[A].pb({B,D}), adj[B].pb({A,D});
    }
    res[min(K*X,Y)] = {K*X,1};
    for(int i = 1; i<=N; i++){
        if (!visit[i]) {
            comp.clear();
            dfs1(i);
            dist.clear();
            for(auto j : comp){
                dfs2(j,-1,j);
            }
            map<int,pi> m;
            for(auto j : dist){
                m[min(j,Y)] += mp(j,1);
            }
            for(int j = 0; j<=Y; j++){
                tmp[j] = {0,0};
            }
            for(auto k : m){
                for(int j = 0; j<=Y; j++){
                    tmp[min(j+k.f,Y)] += comb(res[j],k.s);
                }
            }
            for(int j = 0; j<=Y; j++){
                res[j] = tmp[j];
            }
        }
    }
    for(int i = 0; i<K-1; i++){
        MUL(tmp[Y].f,2);
    }
    for(int i = 1; i<K; i++){
        MUL(tmp[Y].f,i);
    }
    cout << tmp[Y].f << endl;
}