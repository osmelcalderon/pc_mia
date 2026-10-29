#include<stdio.h>
int min(int a,int b){
return a<b?a:b;
}
int max(int a,int b){
return a>b?a:b;
}


int main(){

int N;
scanf("%d",&N);

int Grid[N+1][N+1];

for(int i=1;i<=N;i++){
    char Buffer[N+1];
    scanf("%s",Buffer);
    for(int j=0;j<N;j++){
        Grid[i][j+1]=Buffer[j]-'0';
    }
}


int DP[N+1][N+1];
for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
        DP[i][j]=0;
    }
}
for(int i=2;i<=N;i++){
DP[1][i]=DP[1][i-1]+max(0,Grid[1][i]-Grid[1][i-1]);
DP[i][1]=DP[i-1][1]+max(0,Grid[i][1]-Grid[i-1][1]);
}

int x,y;
scanf("%d%d",&x,&y);

for(int i=2;i<=N;i++){
    for(int j=2;j<=N;j++){
        DP[i][j]=min(max(0,Grid[i][j]-Grid[i-1][j])+DP[i-1][j],max(0,Grid[i][j]-Grid[i][j-1])+DP[i][j-1]);
    }
}



printf("%d",DP[x][y]);

return 0;
}