#include<stdio.h>
#include<cstdint>
#define int long long
 
int POW(int a,int b){
if(b==0)return 1;
if(b==1)return a;
if(b%2==0)return POW(a,b/2)*POW(a,b/2);
return a*POW(a,b-1);
}
 
int32_t main(){
 
    int T;
    scanf("%lld",&T);
 
    while(T--){
int k;
scanf("%lld",&k);
 
int c=9;
int d=1;
 
while(k>d*c){
    k-=d*c;
    c*=10;
    d+=1;
}
 
int num=POW(10,d-1)+(k-1)/d;
 
char buffer[20];
snprintf(buffer,sizeof(buffer),"%lld",num);
printf("%c\n",buffer[(k-1)%d]);
 
    }
return 0;
}