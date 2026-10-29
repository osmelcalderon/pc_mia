#include<stdio.h>
#include<cstdint>
#define int long long

int Ks(int K){
int sol=0;
int N=K*K-1;
sol+=(N-2)*2;
sol+=(N-3)*4;
sol+=(N-4)*(K-4)*2;
sol+=(N-4)*2;
sol+=(N-6)*(K-4)*2;
sol+=((K-4)*(K-4)*(N-8))/2;
return sol;
}


int32_t main(){

int K;
scanf("%lld",&K);

for(int i=1;i<=K;i++)
printf("%lld\n",Ks(i));
return 0;
}