#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
const int df[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
int matriz[MAX][MAX], costo[MAX][MAX];
priority_queue<pair<int, pair<int, int>>> cola;
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int f = 0; f < n; f++)
        for (int c = 0; c < m; c++)
            cin >> matriz[f][c];
    memset(costo, -1, sizeof(costo));
    for (int f = 0; f < n; f++) {
        costo[f][0] = matriz[f][0]; 
        cola.push({-costo[f][0], {f, 0}}); }
    int r = -1;
    while (!cola.empty()) {
        int f = cola.top().second.first, c = cola.top().second.second;
        cola.pop();
        if (c == m-1) {
            r = costo[f][c];
            break; }
        matriz[f][c] = -1;
        for (int i = 0; i < 4; ++i) {
            int f2 = f + df[i], c2 = c + dc[i];
            if (f2 < 0 or c2 < 0 or f2 > n-1 or c2 > m-1 or matriz[f2][c2] == -1) continue;
            int peso = costo[f][c] + matriz[f2][c2];
            if (costo[f2][c2] == -1) {
                costo[f2][c2] = peso;
                cola.push({-costo[f2][c2], {f2, c2}});
            } else if (peso < costo[f2][c2]) costo[f2][c2] = peso; }}
    cout << r << "\n";
    return 0; }