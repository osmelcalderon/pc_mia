#include<stdio.h>
#define MAX 100001

int N, C;
int v[MAX][2],vis[MAX];          

void dfs (int x){
  for(int i=0;i<2;i++){
  		if (v[x][i] != 0 && vis[v[x][i]] == 0) {                               
      	vis[v[x][i]] = vis[x] + 1;
	      
     	 dfs (v[x][i]);                
    	}
  	}    
}

int main(){
        
  scanf("%d%d", &N, &C);

  for(int i=0;i<=N;i++){
  	v[i][0]=v[i][1] = 0;
  }
  for(int i=0;i<C;i++){
    int x, b1, b2;
    scanf ("%d%d%d", &x, &b1, &b2);
    v[x][0] = b1; v[x][1] = b2;
  }
  vis[1]=1; dfs(1);

  for(int i=1;i<=N;i++){
  	printf ("%d\n", vis[i]);
  }
    
  
}