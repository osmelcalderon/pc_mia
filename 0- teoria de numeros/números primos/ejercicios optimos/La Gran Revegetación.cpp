#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cs(n, -1);
    for (int i = 0; i < n; i++) {
        bool vis[4] = {false};
        for (int j : adj[i]) {
            if (cs[j] != -1) {
                vis[cs[j]] = true;
            }
        }
        for (int c = 0; c < 4; c++) {
            if (!vis[c]) {
                cs[i] = c;
                break;
            }
        }
    }
    for (int c : cs) {
        cout << c + 1;
    }
    cout << '\n';
    return 0;
}