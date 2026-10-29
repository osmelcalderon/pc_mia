#include<stdio.h>

int main(){

    int R,N,M,V[251],W[251],DP[1002]={0},T=0,TV=0,TW=0,aux;
    scanf("%d",&R);
    while(R--){
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;++i){
            scanf("%d%d",&W[i],&V[i]);
            TV+=V[i];
            TW+=W[i];
        }
        if(TW<=M){
            T+=TV;
        }
        else{
            for(int i=1;i<=N;++i){
                for(int j=M;j>=W[i];--j){
                    aux=V[i]+DP[j-W[i]];
                    DP[j]=(aux>=DP[j])? aux:DP[j];
                }
            }
            T+=DP[M];
            for(int i=1;i<=M;++i){
                DP[i]=0;
            }
        }
        TV=TW=0;
    }
    printf("%d",T);
    return 0;
}