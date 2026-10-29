#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
	return a > b ? true : false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, v, d, cont = 0;
	cin >> n; d = n/2;
	bool a[2*n+1] = {false};
	int c[d], e[d];
	vector<int> b;
	
	for(int i = 0; i < n; i++){
		cin >> v;
		a[v] = true;
		if(i < d) c[i] = v;
		else e[i-d] = v;
	}
	for(int i = 1; i <= 2*n; i++) if(!a[i]) b.push_back(i);
	sort(c, c+d, &comp);
	sort(e, e+d);
	
	int j = n-1;
	for(int i = 0; i < d; i++){
		if(b[j] > c[i]){
			cont++;
			j--;
		}
	}
	j = 0;
	for(int i = 0; i < d; i++){
		if(b[j] < e[i]){
			cont++;
			j++;
		}
	}
	cout << cont;
	
	return 0;
}