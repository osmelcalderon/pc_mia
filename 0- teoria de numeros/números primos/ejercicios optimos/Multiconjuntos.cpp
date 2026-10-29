#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
#define mod(x) (((x)+MOD)%MOD)
#define pii pair<int,int>
#define MAX 300005

int a[MAX], b[MAX], c[MAX], M[MAX];

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> x;
		a[x]++; b[x]++;
	}
	for(int i = 1; i < MAX-1; i++){
		M[i] = b[i];
		b[i+1] += b[i]/2; 
	}
	
	c[0] = 1;
	
	for(int i = MAX-2; i >= 1; i--){
		for(int j = 0; j <= M[i]; j++) b[i] = 0;
		
		for(int j = a[i]; j <= M[i]; j++){
			b[j] = c[a[i+1]+j/2];
			if(a[i+1]-1 >= 0) b[j] -= c[a[i+1]-1];
		}		
		for(int j = 0; j <= M[i]; j++){
			c[j] = b[j];
			if(j) c[j] += c[j-1];
			c[j] = mod(c[j]);
		}
	}
	
	cout << mod(b[a[1]]);
	
	return 0;
}