#include<stdio.h>
#include<string.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
char str[1001];
scanf("%s",str);
int dig;
dig=str[strlen(str) -1] - '0';
int sum=0;
for(int i=0;i<strlen(str);i++){
sum+=str[i] - '0';}
printf(dig%2==0 && sum%3==0 ? "YES\n" : "NO\n");}
}