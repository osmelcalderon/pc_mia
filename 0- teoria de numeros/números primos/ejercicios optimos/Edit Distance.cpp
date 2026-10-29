#include<stdio.h>
#include<string.h>

int DP[5003][5003];

int min(int a,int b){
return a<b?a:b;
}

int main(){

char S1[5003],S2[5003];
scanf("%s%s",S1,S2);
int N=strlen(S1);
int M=strlen(S2);


for(int i=0;i<=N;i++){
    for(int j=0;j<=M;j++)
        DP[i][j]=2e9;
}
for(int i=0;i<=N;i++)DP[i][0]=i;
for(int i=0;i<=M;i++)DP[0][i]=i;


for(int a=1;a<=N;a++){
for(int b=1;b<=M;b++){

    DP[a][b]=min(DP[a][b-1]+1,min(DP[a-1][b]+1,DP[a-1][b-1]+(S1[a-1]!=S2[b-1])));
    }
}
printf("%d",DP[N][M]);
return 0;
}