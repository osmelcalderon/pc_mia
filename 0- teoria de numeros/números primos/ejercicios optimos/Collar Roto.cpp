#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, q[255] = {0}, maximo = 0, k, tam; q['w'] = 1; q['r'] = 2; q['b'] = 3;
	char c, d = 'a';
	cin >> n;
	vector<int> s, t, u, v;

	for(int i = 0; i < n; i++){
		cin >> c;
		if(c == d) s.back()++;
		else{
			d = c;
			s.push_back(1);
			t.push_back(q[c]);
		}
	}
	if(s.size() == 1){ cout << n; return 0;}
	if(t[0]==t.back()){s[0] += s.back(); s.pop_back(); t.pop_back();}
	tam = s.size();
	for(int i = 0; i < tam; i++){s.push_back(s[i]); t.push_back(t[i]);}
	
	for(int i = 1; i < s.size()-1; i++) if(t[i] == 1 && t[i-1] == t[i+1]) t[i] = t[i-1];
	
	tam = -1;
	for(int i = 0; i < s.size(); i++){
		if(t[i] == tam) u.back() += s[i];
		else{
			tam = t[i];
			u.push_back(s[i]);
			v.push_back(t[i]);
		}
	}

	tam = u.size();
	for(int i = 0; i < tam; i++){
		int z[4] = {0}, w = i; k = 0;
		while((v[w] == 1 || z[v[w]]+1 < 2) && w < tam){
			k += u[w];
			z[v[w]]++; w++;
		}
		maximo = max(maximo, k);
	}
	cout << min(maximo, n);
	
	return 0;
}