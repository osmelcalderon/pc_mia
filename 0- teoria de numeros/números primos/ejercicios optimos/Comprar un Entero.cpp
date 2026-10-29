#include <stdio.h>
#include <math.h>

long long x, a, b;

long long comp(long long mitad){
	if(a * mitad + b * (long long)(log10(mitad) + 1) <= x) return 1;
	return 0;
}

int main(){
	long long ans = 0;
	
	scanf("%lld %lld %lld", &a, &b, &x);
	
	long long l = 1, r = 1000000000;
	while(l <= r){
		long long mitad = (l + r) >> 1;
		if(comp(mitad) == 1) ans = mitad, l = mitad + 1;
		else r = mitad - 1;
	}
	
	if(ans > 1000000000) printf("1000000000");
	else printf("%lld", ans);
	
	return 0;
}