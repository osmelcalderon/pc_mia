#include<stdio.h>
#include<stdbool.h>

int main(){

int N;
scanf("%d",&N);
int Arr[N+1];
int MxV=0;
for(int i=0;i<N;i++){
    scanf("%d",&Arr[i]);
    MxV+=Arr[i];
}

bool DP[MxV+1];
for(int i=0;i<=MxV;i++)DP[i]=false;
DP[0]=true;

for(int i=0;i<N;i++)
    for(int j=MxV;j>=Arr[i];j--)
        if(DP[j-Arr[i]])DP[j]=true;

int cont=0;
for(int i=1;i<=MxV;i++)if(DP[i])cont++;

printf("%d\n",cont);
for(int i=1;i<=MxV;i++)if(DP[i])printf("%d ",i);

return 0;
}