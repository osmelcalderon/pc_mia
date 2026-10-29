#include<stdio.h>
int main(){
    int N,W,aux;
    scanf("%d%d",&N,&W);
    int Ws[N],D[N],DP[W+1]={0};
    for(int i=0;i<N;++i){
        scanf("%d%d",&Ws[i],&D[i]);
    }
    for(int i=0;i<N;++i){
        for(int j=W;j>=Ws[i];--j){
            aux=D[i]+DP[j-Ws[i]];
            DP[j]=(aux>=DP[j])?aux:DP[j];
        }
    }
    printf("%d",DP[W]);
    return 0;
}