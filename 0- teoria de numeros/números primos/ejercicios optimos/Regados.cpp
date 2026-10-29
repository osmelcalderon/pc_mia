#include<stdio.h>
int main(){
    int N,P=0,cont=0;
    scanf("%d",&N);
    int B[N];
    for(int i=0;i<N;++i){
        scanf("%d",&B[i]);
        P+=B[i];
    }
    P/=N;
    for(int i=0;i<N;++i){
        cont+=(B[i]>P)?(B[i]-P):0;
    }
    printf("%d",cont);
    return 0;
}