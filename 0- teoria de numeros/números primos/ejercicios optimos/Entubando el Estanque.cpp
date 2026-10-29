#include <cstdio>
int max(int a,int b){return a>b?a:b;}
main(){
	short int n,m;
    scanf("%hd%hd",&n,&m);
    n++; m++;
    int mat[n+1][m+1];
    for(int i=1;i<n;i++)for(int j=1;j<m;j++)scanf("%d",&mat[i][j]);
    int mx=0;
    for(short int i=1;i<n;i++)
    for(short int j=1;j<m;j++)
    if(mat[i][j]==mat[i-1][j]|mat[i][j]==mat[i+1][j]|mat[i][j]==mat[i][j-1]|mat[i][j]==mat[i][j+1]|mat[i][j]==mat[i-1][j-1]|mat[i][j]==mat[i-1][j+1]|mat[i][j]==mat[i+1][j-1]|mat[i][j]==mat[i+1][j+1])
    mx=max(mx,mat[i][j]);
    printf("%d",mx);
}