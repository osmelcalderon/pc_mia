#include<stdio.h>
#include"algorithm"

int main(){
int N;
scanf("%d",&N);

int Arr[N+1]={};

for(int i=1;i<=N;i++){
    scanf("%d",&Arr[i]);
}
std::sort(Arr+1,Arr+N+1);

int DP[N+1]={};

for(int i=1;i<N;i++){
    DP[i]=Arr[i]+DP[i-1];
   // printf("%d ",*(DP+i));
}
int sol=1;
for(int i=N-1;i>0;i--){
    if(DP[i]*2>=Arr[i+1])sol++;
    else break;
}
printf("%d",sol);

return 0;
}