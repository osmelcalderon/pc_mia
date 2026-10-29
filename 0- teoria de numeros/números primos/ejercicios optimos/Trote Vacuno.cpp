#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>

#define srt(v) sort(all(v))
#define rev(v) reverse(all(v))
#define all(v) (v).begin(), (v).end()
#define dbg(x) cout << #x ": " << x << endl;

#define lft 2*p
#define rgt 2*p+1
#define mdl (l+r)/2
#define p push
#define f first
#define s second
#define pb push_back
#define MAX 2000

struct camino{
    int des,cos;
};

vector<camino> grafo[MAX];
int veces[MAX];

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K,a,b,c;
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        grafo[a].pb({b,c});
    }

    priority_queue<pii, vector<pii>, greater<pii> > cola;
    cola.p({0,N});
    c=0;
    while(!cola.empty()){
        int u=cola.top().s;
        int cost=cola.top().f;
        cola.pop();
        if(u==1){
            cout << cost << "\n";
            c++;
            if(c==K)break;
        }
        for(auto v:grafo[u]){
            if(veces[v.des]>=K)continue;
            cola.push({cost+v.cos,v.des});
        }
    }
    for(int i=c+1; i<=K; i++)cout << "-1\n";

    return 0;
}