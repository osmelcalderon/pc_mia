#include<stdio.h>
#include<string>
const int mod=1e9+7;
int suma(int a,int b){
	if(a+b<0) a+=mod;
	return a+b>=mod?a+b-mod:a+b;
}
int main(){
	int m,i,j,n;
	scanf("%d%d",&m,&n);
    char c1[m+1];
    char c2[n+1];
    scanf("%s",c1);
    scanf("%s",c2);
    int dp[m+1]={};
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            dp[j]=suma(dp[j],dp[j-1]*(c2[i-1]==c1[j-1]));
        }
    }
    printf("%d",dp[m]);
    return 0;
}