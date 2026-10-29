/*
 * Orden~ando en Orden
 * https://dmoj.uclv.edu.cu/problem/milkorder
 * dmoj @karellgz
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define FIO std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0)
#ifdef ONLINE_JUDGE
#define dbg if(0)
#define watch(x) if(0){}
#else
#define dbg
#define watch(x) std::cout<<"[WATCH] "<<(#x)<<" is "<<(x)<<'\n'
#endif
#define edge_to first
#define edge_x second

typedef long long ll;
typedef std::pair<int,int> Conn;
#define int ll
const ll MOD = 1000000007;
typedef std::pair<int,int> ii;
template<typename T>
using vec = std::vector<T>;
using namespace std;

//Variables globales
int N, M;
vec<vec<int>> X;
vec<vec<ii>> G;
vec<bool> instack;
vec<bool> visited;

/*
 * Los grados de entrada de cada nodo
*/
vec<int> indeg(int x){
    vec<int> ind(N+1, 0);
    for(int i = 0; i<=N; i++){
        for(auto e: G[i]){
            int to = e.edge_to;
            int at_x = e.edge_x;
            if(at_x > x)continue;
            ind[to] += 1;
        }
    }
    return ind;
}

/*
 * Reconstruye la solucion para un X dado
 * Ver: ordenamiento topologico (usando BFS)
*/
vec<int> solve(int x){
    vec<int> in = indeg(x);
    vec<int> sol;
    set<int> q;

    for(int i = 1; i<=N; i++){
        if(in[i] == 0){
            q.emplace(i);
        }
    }

    while(!q.empty()){
        int next = *q.begin();
        q.erase(q.begin());

        sol.emplace_back(next);
        watch(next);

        //Buscamos las aristas
        for(auto e: G[next]){
            int to = e.edge_to;
            int at_x = e.edge_x;
            if(at_x > x)continue; //Lo ignoramos
            if( --in[to] == 0 ){
                q.emplace(to);
            }
        }
    }
    return sol;
}

/*
 * Busca ciclos para un X3 2 1 2 3  dado
*/
bool dfs_cyclesearch(int node, int x){
    visited[node]=true;
    instack[node]=true;
    bool flag = false; //Hay un ciclo

    dbg cout<<"DFS visiting "<<node<<'\n';

    int to, at_x;
    for(auto e: G[node]){
        to = e.edge_to;
        at_x = e.edge_x;

        dbg cout<<"DFS edge ("<<to<<','<<at_x<<")\n";

        if(at_x > x)continue;
        if(instack[to]){
            dbg cout<<"DFS Cycle! "<<to<<"->"<<node<<'\n';
            flag = true;
            break;
        }
        if( !visited[to] && dfs_cyclesearch(to, x) ){
            flag = true;
            break;
        }
    }

    instack[node]=false;
    return flag;
}

/*
 * Verifica que no haya ciclos para el X dado
*/
bool test(int x){
    //Reiniciamos todo
    fill(visited.begin(), visited.end(), false);
    fill(instack.begin(), instack.end(), false);
    for(int i = 0; i<=N; i++){
        if(!visited[i]){
            if( dfs_cyclesearch(i, x) ){
                return true;
            }
        }
    }
    return false;
}

/* Funcion principal */
signed main(){FIO;
    cin>>N>>M;
    X.assign(M, {});
    G.assign(N+1, {});
    instack.assign(N+1, false);
    visited.assign(N+1, false);
    for(int i = 0, Mi; i<M; i++){
        cin>>Mi;
        X[i].assign(Mi, 0);
        for(int j = 0, thiz, prev; j<Mi; j++){
            cin>>X[i][j];
            if( j>0 ){
                thiz = X[i][j];
                prev = X[i][j-1];
                G[prev].emplace_back(thiz, i);
            }
        }
    }

    dbg {
        //DEBUG
        //Imprimir el grafo
        for(int i = 0; i<=N; i++){
            for(auto to: G[i]){
                cout<<"("<<i<<','<<to.edge_to<<','<<to.edge_x<<")\n";
            }
        }
    }

    //Recuperar los valores anteriores usando
    //busGODqueda binaria
    int l = 0;
    int r = M+1; // [l;r]
    while( l<r ){
        int x = (l+r)/2;
        dbg cout<<"Testing "<<x<<"(l="<<l<<",r="<<r<<")"<<'\n';
        if(test(x)){
            //Hay ciclos
            r = x;
        }else{
            //No hay ciclos
            l = x+1;
        }
        watch(l);
        watch(r);
    }
    dbg cout<<r-1<<'\n'; //Nota: puede ser -1

    vec<int> sol = solve(r-1);
    for(int i = 0; i<sol.size(); i++){
        cout<<sol[i]<<' ';
    }
}