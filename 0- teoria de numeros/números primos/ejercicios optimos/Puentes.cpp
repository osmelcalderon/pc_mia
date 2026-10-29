#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 55;
vector<int> adj[MAXN];
bool visited[MAXN];
int tin[MAXN], low[MAXN];
int timer = 0;
int bridges = 0;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            //cout << "Arista de retroceso" << endl;
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
              //  cout << "Es un puente" << endl;
                bridges++;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Inicializar
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << bridges << endl;
    return 0;
}