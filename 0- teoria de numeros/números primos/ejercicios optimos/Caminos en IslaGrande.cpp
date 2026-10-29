#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, m, k, a, b, sumaT = 0;
	cin >> n >> m >> k;
	vector<vector<int>> G(n+1);
	vector<bool> F(n+1, false);
	vector<long long> Region;
	
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++){
		if(!F[i]){
			long long cont = 0, suma = 0;
			vector<int> R;
			R.push_back(i);
			for(int j = 0; j < R.size(); j++){
				if(!F[R[j]]){
					F[R[j]] = true; cont++; suma += G[R[j]].size();
					for(int k = 0; k < G[R[j]].size(); k++){
						R.push_back(G[R[j]][k]);
					}
				}
			}
			sumaT += cont*(cont-1)/2-(suma>>1);
			Region.push_back(cont);
		}
	}
	
	cout << max((long long)1, (int)Region.size()-k) << " ";
	k -= sumaT;
	if(k <= 0) cout << Region.size();
	else{
		sort(Region.begin(), Region.end());
		long long i, suma = 0;
		for(i = Region.size()-1; i > 0; i--){
			suma += Region[i];
			k -= suma*Region[i-1];
			if(k <= 0) break;	
		}
		cout << i;
	}
	
	return 0;
}