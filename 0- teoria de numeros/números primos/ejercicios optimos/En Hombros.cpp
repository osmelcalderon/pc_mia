#include <bits/stdc++.h>
#define fast_in ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
using namespace std;

vector<int>grafo[40005];
int Vb[40005];
int Ve[40005];
int Vc[40005];

void BFS1(int n){
    int N,v,s;
    queue<int> cola;
    cola.push(n);
    Vb[n]=0;
    while(!cola.empty()){
        N=cola.front();cola.pop();
        s=grafo[N].size();
        for(int i=0;i<s;i++){
            v=grafo[N][i];
            if(Vb[v]==-1){
                cola.push(v);
                Vb[v]=Vb[N]+1;
            }
        }
    }
}

void BFS2(int n){
    int N,v,s;
    queue<int> cola;
    cola.push(n);
    Ve[n]=0;
    while(!cola.empty()){
        N=cola.front();cola.pop();
        s=grafo[N].size();
        for(int i=0;i<s;i++){
            v=grafo[N][i];
            if(Ve[v]==-1){
                cola.push(v);
                Ve[v]=Ve[N]+1;
            }
        }
    }
}

void BFS3(int n){
    int N,v,s;
    queue<int> cola;
    cola.push(n);
    Vc[n]=0;
    while(!cola.empty()){
        N=cola.front();cola.pop();
        s=grafo[N].size();
        for(int i=0;i<s;i++){
            v=grafo[N][i];
            if(Vc[v]==-1){
                cola.push(v);
                Vc[v]=Vc[N]+1;
            }
        }
    }
}
int main()
{
    fast_in

    int B,E,P,N,M,a,b,St,Mi=99999999;

    cin >> B >> E >> P >> N >> M;

     for(int i=1;i<=N;i++){
        Vb[i]=-1;
        Ve[i]=-1;
        Vc[i]=-1;
    }

     for(int i=0;i<M;i++){
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
     }
    BFS1(1);
    BFS2(2);
    BFS3(N);

    for(int i=1;i<=N;i++){

        St=Vb[i]*B+Ve[i]*E+Vc[i]*P;
        if(Mi>St)Mi=St;
    }
    cout << Mi;
    return 0;
}