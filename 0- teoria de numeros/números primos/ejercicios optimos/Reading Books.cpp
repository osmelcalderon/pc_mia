#include<stdio.h>
#include<cstdint>
#define int long long
int max(int a,int b){
return a>b?a:b;
}
int32_t main(){
int N;
scanf("%lld",&N);
int sum=0;
int MX=0;
int val;
for(int i=0;i<N;i++){
    scanf("%lld",&val);
    sum+=val;
    MX=max(MX,val);
}
printf("%lld",max(MX*2,sum));
return 0;
}