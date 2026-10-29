#include<bits/stdc++.h>
using namespace std;
#define MAX 200100
#define mod 998244353

long long P[MAX], fact[MAX];

void Criba(){
	for(int i = 0; i < MAX; i++) P[i] = i;
	for(long long i = 2; i < MAX; i++){
		if(P[i] == i)
			for(long long j = i*i; j < MAX; j+=i){
				if(P[j] == j) P[j] = i;
			}
	}
}

////////Exponenciacion binaria///////////////
long long ExpBin(long long a, long long x){
	long long ans = 1;
	while(x > 0){
		if(!(x&1)){ a = (a*a)%mod; x >>= 1;} 
		else{ ans = (ans*a)%mod; x--; } 
	}
	return ans;
}
////////Inverso multiplicativo///////////////
long long InverseMod(long long a){
	return ExpBin(a, mod-2);
}
////////Factorial////////////////////////////
void factorial(){
	fact[0] = fact[1] = 1;
	for(long long i = 2; i < MAX; i++) fact[i] = (fact[i-1]*i)%mod;
}
////////Coeficiente binomial/////////////////
long long CoeBin(long long n, long long k){
	return (fact[n]*InverseMod((fact[n-k]*fact[k])%mod))%mod;
}

int main(){
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	Criba();
	factorial();
	long long n, m, aux, v, cont = 0, p, ans, T = 0;
	cin >> n >> m;
	long long a[m+1] = {0};
	
	for(int i = 1; i <= m; i++){
		aux = i; v = -1; p = ans = 1;
		while(aux > 1){
			if(P[aux] == v){
				p = (p*P[aux])%mod;
				cont++;
			}
			else{
				ans = (ans*a[p])%mod;
				p = v = P[aux];
				cont = 1;
			}
			aux /= P[aux];
		}
		if(p == i) ans = CoeBin(n+cont-1, cont);
		else ans = (ans*a[p])%mod;
		a[i] = ans;
		T = (T+ans)%mod;
	}
	cout << T;	
	
	return 0;
}