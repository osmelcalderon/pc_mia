#include<stdio.h>


long long max(long long a,long long b){
    return a>b?a:b;
    }
    
int main()
{
	long long N;
	scanf("%lld",&N);
	long long a;
	scanf("%lld",&a);
	long long val,sol=a,sum=a;
	for(int i=1;i<N;i++){
	  scanf("%lld",&val);
	  sum=max(sum+val,val);  
	  sol=max(sol,sum);
	}
	printf("%lld",sol);
	return 0;
}