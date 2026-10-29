#include<stdio.h>
int main(){
    int N,M,MIN=0,MAX=0,cont=0;
    scanf("%d%d",&N,&M);
    char C[N][M+1];
    for(int i=0;i<N;++i){
        scanf("%100s",C[i]);
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(C[i][j]=='P'){
                if(i){if(C[i-1][j]=='#'){++cont;}}
                if(i<N-1){if(C[i+1][j]=='#'){++cont;}}
                if(j){if(C[i][j-1]=='#'){++cont;}}
                if(j<M-1){if(C[i][j+1]=='#'){++cont;}}
                if(cont==1){++MAX;}
                else if(cont){++MAX;++MIN;}
                cont=0;
            }
        }
    }
    printf("%d %d",MIN,MAX);
    return 0;
}