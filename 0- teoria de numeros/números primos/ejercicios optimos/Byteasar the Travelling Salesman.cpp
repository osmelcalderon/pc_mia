#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define f first
#define s second

using namespace std;
const int nmax=3e4+2;
int prof[nmax],padre[nmax],nodo;
vector<int>grafo[nmax];
void dfs(int nodo,int p,int pro){
      if(prof[nodo]!=-1)return;
      prof[nodo]=pro;
      padre[nodo]=p;
      for(auto x : grafo[nodo]){
        dfs(x,nodo,pro+1);
      }
}
void lca(int nodo1,int nodo2){
     if(nodo1==nodo2){nodo=nodo1;return;}
    if(prof[nodo1]>prof[nodo2])lca(padre[nodo1],nodo2);
    if(prof[nodo1]<prof[nodo2])lca(nodo1,padre[nodo2]);
    if(prof[nodo1]==prof[nodo2])lca(padre[nodo1],padre[nodo2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    memset(prof,-1,sizeof(prof));
    int n,k,aux=1,sol=0;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    dfs(1,1,0);
    cin>>k;
    for(int i=1;i<=k;i++){
         int a;
         cin>>a;
         lca(a,aux);
         sol+=(prof[a]-prof[nodo])+(prof[aux]-prof[nodo]);
         aux=a;
    }

    cout<<sol;

    return 0;
}