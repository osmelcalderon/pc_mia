#include <bits/stdc++.h>
#define fast_in ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
using namespace std;
vector<int>grafo[20005];
int V[20005];

void BFS(int n){
    int N,v,s;
    queue<int> cola;
    cola.push(n);
    V[n]=0;
    while(!cola.empty()){
        N=cola.front();cola.pop();
        s=grafo[N].size();
        for(int i=0;i<s;i++){
            v=grafo[N][i];
            if(V[v]==-1){
                cola.push(v);
                V[v]=V[N]+1;
            }
        }
    }
}
int main()
{
    fast_in

    int N,M,a,b,Min=99999,Cm=0,I=0;

    cin >> N >> M;

    for(int i=0;i<M;i++){

        cin >> a >> b;
        a--;
        b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for(int i=0;i<N;i++){

        V[i]=-1;
    }
    BFS(0);
    for(int i=0;i<N;i++){
        if(Cm<V[i])Cm=V[i];
    }
    for(int i=0;i<N;i++){
        if(V[i]==Cm){
            I++;
            if(i<Min)Min=i;
        }
    }
    cout << Min+1 << " " << Cm << " " << I;

    return 0;
}