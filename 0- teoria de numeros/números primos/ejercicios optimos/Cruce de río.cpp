#include <stdio.h>
#pragma GCC optimize("Ofast")
int min(int a,int b){return a<b?a:b;}
main(){
short int n,k;
scanf("%hd%hd",&n,&k);
k*=2;
n++;
int dp[n],M[n];
dp[0]=0;
for(int i=1;i<n;i++){
scanf("%d",&M[i]);
dp[i]=1e9;
}
for(int i=2;i<n;i++)M[i]+=M[i-1];
for(int i=1;i<n;i++){
for(int j=0;j<=i;j++){
dp[i]=min(dp[i],dp[i-j]+M[j]+k);
}
}
printf("%d",dp[n-1]-k/2);
}