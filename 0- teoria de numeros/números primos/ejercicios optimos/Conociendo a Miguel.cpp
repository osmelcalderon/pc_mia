/*
Problema: Conociendo a Miguel
Tipo: Grafos - Dijkstra
Complejidad: ¿?
Autor: Mauricio Avalo Tamayo (Primervirgen)
Escuela: IPVCE - Carlos Roloff
*/
#include <bits/stdc++.h>
#define Node pair < int, int >
#define mk make_pair
#define INF 10000000
#define MAX 105

using namespace std;

vector <Node> grafoN[MAX];
vector <Node> grafoV[MAX];
int distancia[MAX], keep[MAX];
int sol;

void dijkstraN(int nodo){
    priority_queue < Node, vector < Node >, greater < Node > > cola;
    cola.push(mk(0, nodo));
    distancia[nodo] = 0;
    while(!cola.empty()){
        int u = cola.top().second;
        cola.pop();
        for (int i = 0; i < grafoN[u].size(); i++){
            int v = grafoN[u][i].second;
            int p = grafoN[u][i].first;
            if (distancia[u]+p < distancia[v]){
                distancia[v] = distancia[u]+p;
                cola.push(mk(distancia[v],v));
            }
        }
    }
}

void dijkstraV(int nodo){
    priority_queue < Node, vector < Node >, greater < Node > > cola;
    cola.push(mk(0, nodo));
    distancia[nodo] = 0;
    while(!cola.empty()){
        int u = cola.top().second;
        cola.pop();
        for (int i = 0; i < grafoV[u].size(); i++){
            int v = grafoV[u][i].second;
            int p = grafoV[u][i].first;
            if (distancia[u]+p < distancia[v]){
                distancia[v] = distancia[u]+p;
                cola.push(mk(distancia[v],v));
            }
        }
    }
}

int main (){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while(cin >> n, n != 0){
        for (int i = 1; i <= n; i++){
            char ed, dir, a, b; int c; cin >> ed >> dir >> a >> b >> c;
            if (ed == 'Y'){
                if (dir == 'B'){
                    grafoN[int(b)].push_back(mk(c,int(a)));
                }
                
grafoN[int(a)].push_back(mk(c,int(b)));
            }else{
                if (dir == 'B'){
                    grafoV[int(b)].push_back(mk(c,int(a)));
                }
                grafoV[int(a)].push_back(mk(c,int(b)));
            }
        }
        char A, B; cin >> A >> B;
        fill(distancia, distancia+MAX, INF);
        dijkstraN(int(A));

        for (int i = 'A'; i <= 'Z'; i++){
            keep[i] = distancia[i];
        }

        fill(distancia, distancia+MAX, INF);
        dijkstraV(int(B));

        sol = INF;

        for (int i = 'A'; i <= 'Z'; i++){
            if (distancia[i]+keep[i] < sol){
                sol = distancia[i]+keep[i];
            }
        }

        if (sol >= INF){
            cout << "\nYou will never meet.";
        }else{
            cout << "\n" << sol;
            for (int i = 'A'; i <= 'Z'; i++){
                if (distancia[i]+keep[i] == sol){
                    cout << " " << char(i);
                }
            }
        }

        for (int i = 'A'; i <= 'Z'; i++){
            grafoN[i].clear();
            grafoV[i].clear();
        }
    }


    return 0;
}