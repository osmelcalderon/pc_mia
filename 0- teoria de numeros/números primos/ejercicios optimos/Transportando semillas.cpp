#include <stdio.h>
int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	a=a*b;
	if (a%2==1) a--;
	printf("%lld",a);
	return 0;
}