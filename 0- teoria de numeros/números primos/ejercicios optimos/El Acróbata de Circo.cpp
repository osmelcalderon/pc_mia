#include<iostream>
using namespace std;
#pragma GCC optimize("Ofast")
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
#pragma GCC optimize("Ofast")
int main(){
	ios;
	int n, m, cantEscaleras = 0, altura = 0;
	string secuencia;
	
	cin >> n >> m;
	secuencia += '+';
	altura += n;
	while(1) {
		if(altura == 0)
			break;
		if(altura >= m) {
			altura -= m;
			secuencia += '-';
		}
		else {
			altura += n;
			secuencia += '+';
		}
		cantEscaleras = max(cantEscaleras, altura);
	}
	cout << cantEscaleras << "\n";
	cout << secuencia;

	return 0;
}