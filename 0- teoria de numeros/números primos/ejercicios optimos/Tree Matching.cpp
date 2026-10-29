#include<stdio.h>
#include"vector"
using namespace std;

int max(int a,int b){
 return a>b?a:b;   
}

void DFS(int n,int p,vector<vector<int>>& Adj,vector<int>& I,vector<int>& N){
    
    for(auto h:Adj[n]){
        if(h==p)continue;
        DFS(h,n,Adj,I,N);
        N[n]+=max(N[h],I[h]);
    }
    for(auto h:Adj[n]){
        
       if(h==p)continue; 
        I[n]=max(I[n],N[n]-max(I[h],N[h])+N[h]+1);
        }
    
}


int main()
{
	int n,u,v;
	scanf("%d",&n);
	vector<vector<int>> Adj(n+1);
	vector<int> I(n+1,0),N(n+1,0);
	
	for(int i=0;i<n-1;i++){
	    scanf("%d%d",&u,&v);
	    Adj[u].push_back(v);
	    Adj[v].push_back(u);
	    }
	
	DFS(1,-1,Adj,I,N);
	int sol=max(I[1],N[1]);
	printf("%d",sol);
	return 0;
}