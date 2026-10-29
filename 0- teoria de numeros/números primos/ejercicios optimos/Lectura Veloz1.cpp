/*#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)*/
#include<stdio.h>

#define EduarSr int main

EduarSr(){

	int n,k,s,t,r,ans=0,i;
	scanf("%d%d",&n,&k);
	
	for(i=0;i<k;i++){
	scanf("%d%d%d",&s,&t,&r);
	int a=n;
	while(a>0){
		if(a-s*t>0){
		a-=s*t;	
		
		ans+=t;
		ans+=r;
		}
		else {
			while(a>0){
		a-=s;
		ans++;
		}
		}
		
		
		
	}
	printf("%d\n",ans);
	ans=0;
	}
	
	
}