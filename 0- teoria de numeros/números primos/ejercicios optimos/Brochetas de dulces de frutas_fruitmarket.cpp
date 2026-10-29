#include <cstdio>
char a[3001][3001];
bool u[3001][3001];
int ans = 0;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;++i)
        scanf("%s",a[i]);
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            if(a[i][j] != 'R')continue;
            if(j < m-2 && a[i][j+1] == 'G' && a[i][j+2] == 'W' && !(u[i][j+1]+u[i][j+2]))
                ans++;
            else if(i < n-2 && a[i+1][j] == 'G' && a[i+2][j] == 'W'){
                if(j > 0 && j < m-1 && a[i+1][j-1] == 'R' && a[i+1][j+1] == 'W' && !u[i+1][j+1])
                    u[i+1][j]=1;
                else
                    u[i+2][j]=1;
                ans++;
            }
        }
    }
    printf("%d",ans);
}
