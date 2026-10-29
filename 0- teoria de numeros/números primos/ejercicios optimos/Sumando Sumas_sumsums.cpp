#include<bits/stdc++.h>
using namespace std;
#define mod 98765431

long long expBin(long long a, long long x){
	long long ans = 1;
	while(x){
		if(x%2){ ans = (ans*a)%mod; x--;}
		else{ a = (a*a)%mod; x /= 2;}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, p, s = 0, v[2] = {1, -1};
	cin >> n >> p;
	long long a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s = (s+a[i])%mod;
	}
	s = ((s%mod)*(((expBin(n-1, p)+expBin(-1, p+1))*expBin(n, mod-2))%mod))%mod;
	for(int i = 0; i < n; i++) cout << (s+v[p%2]*a[i]+mod)%mod << "\n";
	
	return 0; 
}
