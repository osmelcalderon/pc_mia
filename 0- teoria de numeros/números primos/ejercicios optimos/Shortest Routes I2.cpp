#include <bits/stdc++.h>
#define Hd main(void)
#define int long long
using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<int> dijkstra(int n, const vector<vector<Edge>>& graph, int start) {
    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
long long read_long_long() {
    long long num = 0;
    int c = getchar_unlocked();
    int sign = 1;

    while (c < '0' || c > '9') {
        if (c == '-') {
            sign = -1;
        }
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar_unlocked();
    }

    return num * sign;
}
Hd{
    int n=read_long_long(), m=read_long_long();
    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u=read_long_long(), v=read_long_long(), w=read_long_long();
        graph[u].push_back({v, w});
    }
    vector<int> dist = dijkstra(n, graph, 1);
    for (int i = 1; i <= n; ++i)printf("%lld ",dist[i]);
    
}