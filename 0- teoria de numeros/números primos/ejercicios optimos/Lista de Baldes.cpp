#include<stdio.h>
int main(){
    int N,B=0,X=0,M=0,A[3],U[1002]={0};
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d%d%d",&A[0],&A[1],&A[2]);
        if(A[1]>M){M=A[1];}
        U[A[0]]+=A[2];
        U[A[1]+1]-=A[2];
    }
    for(int i=1;i<=M;++i){
        X+=U[i];
        U[i]=X;
        if(U[i]>B){B=U[i];}
    }
    printf("%d",B);
    return 0;
}