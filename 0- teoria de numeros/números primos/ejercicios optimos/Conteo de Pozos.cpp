/*
Alejandro Jimenez Fabian
Santa Clara VC2
USACO2004GLD
*/
#include<stdio.h>
#include<queue>

using namespace std;

#define MAXN 1000

const int
    mf[8]={1,1,1,-1,-1,-1,0,0},
    mc[8]={-1,0,1,-1,0,1,1,-1};

struct two{
    int f,c;
};

int r,c,sol;
bool mk[MAXN][MAXN];
char M[MAXN][MAXN];
queue<two>Q;

void bfs(int fi,int ci){
    Q.push((two){fi,ci});
    while(!Q.empty()){
        two grid=Q.front();
        Q.pop();
        for(int i=0;i<8;i++){
            int nf=grid.f+mf[i];
            int nc=grid.c+mc[i];
            if(nf<0||nc<0)continue;
            if(M[nf][nc]=='W'&&!mk[nf][nc]){
                mk[nf][nc]=true;
                Q.push((two){nf,nc});
            }
        }
    }
}

int main(){

//	freopen("lkcount.in","r",stdin);
//	freopen("lkcount.out","w",stdout);

	scanf("%d%d\n", &r, &c);

	for(int i=0;i<r;i++){
        gets(M[i]);
	}
	for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(M[i][j]=='W'&&!mk[i][j]){
                bfs(i,j);
                sol++;
            }
        }
	}
	printf("%d\n", sol);
	return 0;
}