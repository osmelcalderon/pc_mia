#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

#define int long long
#define lft 2*p
#define rgt 2*p+1
#define pb push_back
#define mdl (l+r)/2
#define MAX 1005
#define s second
#define f first

class via{
public:
    int dist, ganancia, coste;

    via(){};
    via(int d,int g,int c){
        dist=d; ganancia=g; coste=c;
    };
};

vector<via> vias[MAX];
int dp[MAX][MAX];
int l,d;

int DP(int L,int D){
    if(L>l+1 || D>d)return -1e9;
    if(L==l)return 0;
    if(dp[L][D])return dp[L][D];

    int res=-1e9;
    int m=vias[L].size();
    for(int i=0;i<m;i++){
        res=max(res,DP(vias[L][i].dist+L,D+vias[L][i].coste)+vias[L][i].ganancia);
    }
    return dp[L][D]=res;
}

void solve(){
    int L,N,D;
    cin >> L >> N >> D;
    l=L;d=D;

    int a, b, c, d;
    for(int i=0;i<N;i++){
        cin >> a >> b >> c >> d;
        vias[a].pb({b,c,d});
    }

    if(DP(0,0)>0)cout << DP(0,0);
    else cout << -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;//cin >> T;

    for(int i=0;i<T;i++){
        solve();
    }

    return 0;
}