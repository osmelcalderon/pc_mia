#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include"vector"
using namespace std;
vector<int>tin(200005,0),tout(200005,0);
int t=0;

void DFS(int n, int p,vector<vector<int>>& Adj,vector<vector<int>>& Up,int L){
 tin[n]=++t;
 Up[n][0]=p;   
          for(int i=1;i<=L;i++)Up[n][i]=Up[Up[n][i-1]][i-1];
   
    for(auto h:Adj[n]){
        if(p==h)continue;
        DFS(h,n,Adj,Up,L);
        } 
        tout[n]=++t;
}

bool P(int u,int v){
   return tin[u]<=tin[v]&&tout[u]>=tout[v]; 
    }

int LCA(int u,int v,vector<vector<int>>& Up,int L){
    if(P(u,v))return u;
    if(P(v,u))return v;
    for(int i=L;i>=0;i--){
        if(!P(Up[u][i],v))
        u=Up[u][i];
        }
    return Up[u][0];
    }


int main()
{
	int N,Q;
	scanf("%d%d",&N,&Q);
	vector<vector<int>> Adj(N+1);
	int L=log2(N+1);
	vector<vector<int>> Up(N+1,vector<int>(L+1,0));
int u,v;
for(int i=2;i<=N;i++){
    scanf("%d",&u);
   Adj[i].push_back(u);
    Adj[u].push_back(i);
    }
tin.resize(N+1);
tout.resize(N+1);

DFS(1,1,Adj,Up,L);

	while(Q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v,Up,L));
		
		}
		
			
				return 0;	
}