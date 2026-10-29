#include <bits/stdc++.h>
#define fast_in ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
using namespace std;

vector<int> grafo[10000];
bool V[10000];
vector<int>Z;

void BFS(int n){
    int N,v,s;
    queue<int> cola;
    cola.push(n);
    V[n]=true;
    while(!cola.empty()){
        N=cola.front();cola.pop();
        s=grafo[N].size();
        for(int i=0;i<s;i++){
            v=grafo[N][i];
            if(!V[v]){
                cola.push(v);
                V[v]=true;
            }
        }
    }
}

int main()
{
    fast_in
    

    int T,n,m,l,a,b,I=0;
    cin >> T;

    for(int i=0;i<T;i++){

        cin >> n >> m >> l;

        Z.resize(l);
        for(int j=0;j<m;j++){
            cin >> a >> b;
            grafo[a].push_back(b);
        }
        for(int j=0;j<l;j++){
            cin >> Z[j];
        }
        for(int j=0;j<l;j++){
            BFS(Z[j]);
        }
        for(int y=1;y<=n;y++){
            if(V[y])I++;
        }
        cout << I <<"\n";
        I=0;
        for(int j=1;j<=n;j++){
            grafo[j].clear();
            V[j]=false;
        }
        Z.clear();
    }

    return 0;
}