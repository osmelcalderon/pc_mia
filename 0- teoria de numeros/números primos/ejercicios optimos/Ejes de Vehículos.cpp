#include <stdio.h>

long long mcd(long long a,long long b){
	if (b==0) return a;
	return mcd(b, a%b);}
long long mcm(long long a, long long b){
return a*b/mcd(a,b);}
int main(){
	long long n,x1,x2;
	scanf ("%lld",&n);
	scanf ("%lld", &x1);
	for (int i=1;i<n;i++) {
		scanf ("%lld", &x2);	
		x1=mcm(x1,x2); 
	}
	printf("%lld", x1);
	return 0;		
}