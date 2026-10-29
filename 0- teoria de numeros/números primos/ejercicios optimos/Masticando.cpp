#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

int bfs(vector<vector<char>> &G, int a, int b, int n, int m) {
    vector<pair<int, int>> d;
    d.push_back({1, 0}); d.push_back({-1, 0}); d.push_back({0, 1}); d.push_back({0, -1});
    queue<pair<pair<int, int>, int>> R;
    R.push({{a, b}, 1});
    G[a][b] = '*';
    
    while(!R.empty()) {
        int x = R.front().first.first, y = R.front().first.second, dist = R.front().second;
        R.pop();
        
        if(x == 0 && y == 0) return dist;
        
        for(auto &[i, j] : d) {
            int nx = x + i, ny = y + j;
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && (G[nx][ny] == '.' || G[nx][ny] == 'B')) {
                G[nx][ny] = '*';
                R.push({{nx, ny}, dist + 1});
            }
        }
    }
    
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    
    vector<vector<char>> G(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if(G[i][j] == 'C') {
                a = i;
                b = j;
            } 
        }
    }
    
    cout << bfs(G, a, b, n, m)-1;
    
    return 0;
}