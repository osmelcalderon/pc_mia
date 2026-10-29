#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

long long luck[]={47,4477,444777,44447777,4444477777};

int digit(long long a){
	int ans=0;
	while(a!=0){
		ans++;
		a/=10;
	}
	return ans;
	}

long long mul(int n){
	long long x=1;
	for(int i=1;i<n;i++){
		x*=10;
	}
	return x; 
}

long long o_o(long long n){
	int x=digit(n);
	int ans[x];
	for(int i=x-1;i>=0;i--){
		ans[i]=n%10;
		n/=10;
	}
	next_permutation(ans,ans+x);
	int z=mul(x),res=0;
	
	for(int i=0;i<x;i++){
		res+=ans[i]*z;
		z/=10;
	}
return res;
}
long long search(long long a,long long b,int i){
	long long left=a,right=a;
	
	while(right<b){
		
		right=o_o(right);
		if(left==right){
			right=luck[i+1];
		}
	}
	return right;
}

#define EduarSr int main
EduarSr(){


	long long n,aux;
	
	scanf("%lld",&n);
	int y=0;
	if(n<47){
		printf("47");
	}else{
		for(int i=4;i>=0;i--){
		if(luck[i]<=n){
		aux=luck[i];
		y=i;
		if(digit(aux)<digit(n)){
		aux=luck[i+1];	
		y=i+1;
		}
		break;
		}
	}
	
	//printf("%d",o_o(aux));
	printf("%lld",search(aux,n,y));
	}
	
	
	
	
}