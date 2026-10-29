#include<stdio.h>

int main(){

    long long N;
    long long sol;
    long long i;




scanf("%lld",&N);

sol=N;
for(i=2;i*i<=N;i++){
    if(N%i==0){
        while(N%i==0){
            N/=i;
        }
        sol-=sol/i;
    }
}
if(N>1)sol-=sol/N;

printf("%lld\n",sol);

return 0;}