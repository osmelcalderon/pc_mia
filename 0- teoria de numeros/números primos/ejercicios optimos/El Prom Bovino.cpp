#include<bits/stdc++.h>
using namespace std;

vector<int> G[10001];
int n, m, x, y, k, suma = 0, cont = 0;
bool mark[10001];

int dfs(int p, int o){
	if(mark[p]){
		if(p == k) return 1;
		return 2;
	}
	mark[p] = true;
	
	int flag = 3;
	for(int i = 0; i < G[p].size(); i++){
		if(G[p][i] != o)
			flag = min(flag, dfs(G[p][i], p));
	}
	return flag == 3 ? 0 : flag;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(k = 1; k <= n; k++){
		if(!mark[k] && dfs(k, -1) == 1) suma++;
	}
	for(int i = 1; i <= n; i++){
		if(G[i].size() == 2 && G[i][0] == G[i][1]) cont++;
	}
	cout << suma+cont/2;
	
	return 0;
}