#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>

#define srtv(v) sort(allv(v))
#define srt(v,N) sort(all(v,N))
#define revv(v) reverse(allv(v))
#define rev(v,N) reverse(all(v,N))
#define allv(v) (v).begin(), (v).end()
#define all(v,N) v,v+N
#define dbg(x) cout << #x ": " << x << endl;

#define lft 2*p
#define rgt 2*p+1
#define mdl (l+r)/2
#define p push
#define f first
#define s second
#define pb push_back
#define MAX 1200

vector<int> grafo[MAX];
vector<int> path;
bool  gana[MAX][MAX];
bool visto[MAX];

void dfs(int p){
    visto[p]=true;
    for(auto v:grafo[p]){
        if(!visto[v])dfs(v);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;

    int a,b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        gana[a][b]=true;
        gana[b][a]=false;
        grafo[a].pb(b);
    }

    for(int i=1; i<=N; i++){
        memset(visto,false,sizeof(visto));
        dfs(i);
        for(int j=1; j<=N; j++)gana[i][j]=visto[j];
    }
    int res=0;

    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            bool iganaj=gana[i][j];
            bool jganai=gana[j][i];
            if(iganaj==jganai)res++;
        }
    }
    cout << res;

    return 0;
}