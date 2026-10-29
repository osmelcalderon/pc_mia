#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define ordenar(x) sort(all(x))
#define pq priority_queue
#define vi vector<int>
#define vbol vector<bool>
#define vchar vector<char>
#define ii pair<int, int>
#define str string
#define endl '\n'
#define u_m unordered_map
#define u_s unordered_set
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vi>mat(351, vi (351, INT_MAX));
int bfs(int x = 0, int y = 0){
	queue<ii>q;
	q.push({x, y});
	vector<vi>vis(351, vi(351, -1));
	vis[x][y] = 0;
	while(!q.empty()){
		auto[x1, y1] = q.front();
		if(mat[x1][y1] == INT_MAX){
			return vis[x1][y1];
		}
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x1 + dx[i], ny = y1 + dy[i];
			if(nx >= 0 and nx < 351 and ny >= 0 and ny < 351){
				if(vis[x1][y1] < mat[nx][ny] - 1 and vis[nx][ny] == -1){
					vis[nx][ny] = vis[x1][y1]+1;
					q.push({nx, ny});
				}
			}
		}
	}
	return -1;
}
int main(){ ios;
    int m; cin>>m;   
    while(m--){
    	int x, y, t; cin>>x>>y>>t;
    	mat[x][y] = min(mat[x][y], t);
    	for(int i = 0; i < 4; i++){
    		int nx = x + dx[i], ny = y + dy[i];
    		if(nx >= 0 and nx < 351 and ny >= 0 and ny < 351){
    			mat[nx][ny] = min(mat[nx][ny], t);
    		}
    	}
    }
    cout<<bfs();
}