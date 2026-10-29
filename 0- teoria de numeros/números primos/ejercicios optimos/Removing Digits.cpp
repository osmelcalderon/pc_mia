//Leandro Eliecer Vazquez Rivero    Uni Oriente   Grado:1ro Lic. CC
///Algunos bien random
#pragma GCC optimize("Ofast")
#include<iostream>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed); cout.precision(0); //srand(time(NULL));
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
//#define int long long
#define fs first
#define sd second
#define rsz resize
#define en '\n'

//const int maxn = 1e6+1, mod = 1e9+7;

int va(int n){
	int v = 0;
	while(n > 0){
		v = max(v, (n%10));
		n /= 10;
		//cerr<<'x';
	}
	
	return (v);
}

int main(){
	fast
	int n, c=0;
	cin >> n;
	while(n > 0){
		c++;
		n -= va(n);
	}
	cout <<c;
return 0;
}