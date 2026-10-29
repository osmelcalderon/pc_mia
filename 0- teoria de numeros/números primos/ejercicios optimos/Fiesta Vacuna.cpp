#include <bits/stdc++.h>
#define fast_in ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);

using namespace std;

class Arista{
public:
    int destino;
    int costo;
    Arista(){};
    Arista(int d,int c){destino=d;costo=c;};

    bool operator > (const Arista& a) const{
        return costo > a.costo;
    };
};

vector<Arista> grafo[1005];
int D [1005];
bool V [1005];
int P [1005];
int N;
const int INF=100000000;

void Dijkstra(int n){

    priority_queue<Arista, vector<Arista> ,greater<Arista> > cola;

    Arista u, v;
    int ac ,ad ,s;
    int p;

    cola.push(Arista(n,0));
    D[n]=0;
    for(int i=0;i<N;i++){
        do{
            if(cola.empty()) return;
            u=cola.top(); cola.pop();
            ac=u.destino;
        }while(V[ac]);

        V[ac]=true;
        s=grafo[ac].size();
        for(int j=0;j<s;j++){
            v=grafo[ac][j];
            ad=v.destino;
            p=v.costo;
            if(D[ad]>D[ac]+p){
                D[ad]=D[ac]+p;
                P[ad]=ac;
                cola.push(Arista(ad,D[ad]));
            }
        }
    }
}


int main()
{
    fast_in
    
    int M,I,a,b,t,ma=0;

    cin >> N >> M >> I;

    for(int i=1;i<=N;i++){
        D[i]=INF;
        P[i]=-1;
    }

    for(int i=0; i<M;i++){

        cin >> a >> b >> t;

        grafo[a].push_back(Arista(b,t));
        grafo[b].push_back(Arista(a,t));
    }
    Dijkstra(I);

    for(int i=1;i<=N;i++){if(ma<D[i])ma=D[i];}

    cout << ma*2;

    return 0;
}