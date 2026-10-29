#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        parent[u] = v;
        return true;
    }
};

struct Edge {
    int u, v, c;
    Edge(int u_, int v_, int c_) : u(u_), v(v_), c(c_) {}
};

const int LOG = 12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, P;
    cin >> W >> P;

    vector<Edge> edges;
    for (int i = 0; i < P; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.c < b.c;
    });

    DSU dsu(W);
    int mst_cost = 0;
    vector<Edge> mst_edges;
    unordered_set<long long> mst_set;

    for (const Edge& e : edges) {
        if (dsu.merge(e.u, e.v)) {
            mst_cost += e.c;
            mst_edges.push_back(e);
            int a = min(e.u, e.v);
            int b = max(e.u, e.v);
            mst_set.insert(a * 1000000LL + b);
            if (mst_edges.size() == W - 1)
                break;
        }
    }

    vector<vector<pair<int, int>>> adj(W + 1);
    for (const Edge& e : mst_edges) {
        adj[e.u].emplace_back(e.v, e.c);
        adj[e.v].emplace_back(e.u, e.c);
    }

    vector<int> parent(W + 1, 0), depth(W + 1, 0), max_edge_to_parent(W + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    depth[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& p : adj[u]) {
            int v = p.first;
            int c = p.second;
            if (v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                max_edge_to_parent[v] = c;
                q.push(v);
            }
        }
    }

    vector<vector<int>> up(LOG, vector<int>(W + 1));
    vector<vector<int>> max_edge(LOG, vector<int>(W + 1));

    for (int u = 1; u <= W; ++u) {
        up[0][u] = parent[u];
        max_edge[0][u] = max_edge_to_parent[u];
    }

    for (int k = 1; k < LOG; ++k) {
        for (int u = 1; u <= W; ++u) {
            up[k][u] = up[k-1][up[k-1][u]];
            max_edge[k][u] = max(max_edge[k-1][u], max_edge[k-1][up[k-1][u]]);
        }
    }

    auto get_max_edge = [&](int u, int v) {
        if (u == v) return 0;
        int max_val = 0;
        if (depth[u] < depth[v])
            swap(u, v);

        for (int k = LOG - 1; k >= 0; --k) {
            if (depth[u] - (1 << k) >= depth[v]) {
                max_val = max(max_val, max_edge[k][u]);
                u = up[k][u];
            }
        }

        if (u == v)
            return max_val;

        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                max_val = max(max_val, max_edge[k][u]);
                max_val = max(max_val, max_edge[k][v]);
                u = up[k][u];
                v = up[k][v];
            }
        }

        max_val = max(max_val, max_edge[0][u]);
        max_val = max(max_val, max_edge[0][v]);
        return max_val;
    };

    int second_min = INT_MAX;
    for (const Edge& e : edges) {
        int a = min(e.u, e.v);
        int b = max(e.u, e.v);
        if (mst_set.count(a * 1000000LL + b))
            continue;

        int current_max = get_max_edge(e.u, e.v);
        int candidate = mst_cost - current_max + e.c;
        if (candidate < second_min)
            second_min = candidate;
    }

    cout << second_min << endl;

    return 0;
}