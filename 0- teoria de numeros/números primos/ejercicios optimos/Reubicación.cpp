#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
using namespace std;

#define int long long
#define f first
#define s second
#define left 2*node
#define right 2*node+1
#define mid (l+r)/2
#define INF INT_MAX
#define MIN INT_MIN
#define MOD 1000000007
#define MAXN 10010  

vector<pair<int,int>>grafo[MAXN];
int distancias[10][MAXN];
vector<pair<int,int>>markets;
bool visitados[MAXN];   
bool flag[MAXN];

void dijkstra(int nodo, int indice){
    memset(visitados, false, sizeof(visitados));
    distancias[indice][nodo]=0;
    priority_queue<pair<int,int>>cola;
    cola.push({0,nodo});
    while(!cola.empty()){
        int actual=cola.top().s; cola.pop();
        if(visitados[actual])continue;
        visitados[actual]=true;
        for(int i=0; i<grafo[actual].size(); i++){
            int ady=grafo[actual][i].f;
            int w=grafo[actual][i].s;
            if(distancias[indice][ady]>distancias[indice][actual]+w){
                distancias[indice][ady]=distancias[indice][actual]+w;
                cola.push({-distancias[indice][ady], ady});
            }
        }
    }
}

int32_t main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,M,K;  cin >> N >> M >> K;
    for(int i=0; i<K; i++){
        int x;  cin >> x;
        markets.push_back({x,i});
        flag[x]=true;
    }
    for(int i=0; i<M; i++){
        int a,b,c;  cin >> a >> b >> c;
        grafo[a].push_back({b,c});
        grafo[b].push_back({a,c});
    }
    sort(markets.begin(), markets.end());
    for(int i=0; i<K; i++){
        for(int j=1; j<=N; j++)distancias[i][j] = INF;
        dijkstra(markets[i].f, markets[i].s);
    }
    int ans=INF;
    do{
        int ini=markets[0].f;
        int fin=markets[K-1].f;
        int indiceini=markets[0].s;
        int indicefin=markets[K-1].s;
        int actual=INF;
        for(int i=1; i<=N; i++){
            if(!flag[i]){
                int aux=distancias[indiceini][i]+distancias[indicefin][i];
                actual=min(actual,aux);
            }
        }
        for(int i=1; i<K; i++){
            int ant=markets[i-1].s;
            int act=markets[i].f;
            actual+=distancias[ant][act];
        }
        ans=min(ans, actual);
    }while(next_permutation(markets.begin(), markets.end()));

    cout << ans << "\n";

    return 0;
};