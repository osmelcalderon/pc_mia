#include<bits/stdc++.h>
using namespace std;

int arbol[400004], spi[100001], fla[100001];
long long f, l, n, m, x = 0, y = 0, minimo = 1e9, maximo, p = 0, suma = 0;

int Tree(int pos, int inicio, int final){
	if(inicio == final) return arbol[pos] = spi[inicio];
	int medio = ((inicio+final)>>1);
	return arbol[pos] = max(Tree((pos<<1), inicio, medio), Tree((pos<<1)+1, medio+1, final));
}

int Query(int pos, int inicio, int final){
	if(inicio > l || final < f) return -1;
	if(f <= inicio && final <= l) return arbol[pos];
	int medio = ((inicio+final)>>1);
	return max(Query((pos<<1), inicio, medio), Query((pos<<1)+1, medio+1, final));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> fla[i] >> spi[i];
	
	Tree(1, 0, n-1);
	
	while(y < n){
		while(suma < m && y < n) suma += fla[y++];
		if(suma >= m){
			f = x; l = y-1;
			maximo = Query(1, 0, n-1);
			minimo = min(minimo, maximo);
		}
		while(spi[x] != maximo) suma -= fla[x++];
		suma -= fla[x++];
	}
	cout << minimo;
	
	return 0;
}