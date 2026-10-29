#include <stdio.h>
#include <math.h>
#define ll long long
int main(){
	ll a,b,c;
	scanf("%lld%lld",&a,&b);
	while (a!=0 && b!=0){
		ll ra = (ll) sqrt(a);
		ll rb = (ll) sqrt(b); 
		if (ra*ra == a) { a++; ra = (ll) sqrt(a);}
		if (rb*rb == b) { b--; rb = (ll) floor(sqrt(b));}
		c=b-a+1-rb+ra;
		printf("%lld\n",c);
		scanf("%lld%lld",&a,&b);
	}	
	return 0;
}