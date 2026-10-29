#include<stdio.h>
#include<stdbool.h>
const int MAXN=1e5+2;
long long Arr[MAXN]={};
long long min(long long a,long long b){
return a<b?a:b;
}
int main(){
long long N,K;
scanf("%lld%lld",&N,&K);
bool Cero=false;
bool NP=false;
long long POS=N;
for(long long i=1;i<=N;i++){
    scanf("%lld",&Arr[i]);
    if(Arr[i]==0){Cero=true;
    }
    if(Arr[i]>0&&!NP){
        NP=true;
        POS=i;
    }
    if(i==N&& Arr[i]<=0){
            printf("%lld",(-1)*Arr[i-K+1]);
    return 0;
    }
}
POS-=Cero;
long long sol=1e18+1;
long long act=0;
for(long long i=POS-(K+2);i<=POS+K+2;i++){
    if(i<=0||i+K-1>N)continue;
    long long inicio=i;
    long long final=i+K-1;
    if(inicio>=POS)inicio=0;
       if(final<POS)final=0;
    act=min(Arr[final]-2*Arr[inicio],2*Arr[final]-Arr[inicio]);
    sol=min(act,sol);
}
printf("%lld",sol);
return 0;}