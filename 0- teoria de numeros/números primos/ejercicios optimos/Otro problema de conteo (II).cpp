#include<stdio.h>
int main(){
    int T;
    long long N;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&N);
        N=((N*N)+N+2)/2;
        printf("%lld\n",N);
    } 
    return 0;
}