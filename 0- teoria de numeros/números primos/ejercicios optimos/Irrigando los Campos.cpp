#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    int x[n], y[n], visitado[n], costo[n], r = 0, kmenor = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        visitado[i] = 0;
        costo[i] = INF; }
    for (int i = 0; i < n-1; ++i) {
        int k = kmenor;
        visitado[k] = 1;
        kmenor = 0;
        for (int j = 0; j < n; ++j)
            if (visitado[j] == 0) {
                int dx = x[j] - x[k];
                int dy = y[j] - y[k];
                int d = dx*dx + dy*dy;
                if (d >= c && d < costo[j]) costo[j] = d;
                if (costo[j] < costo[kmenor]) kmenor = j; }
        if (kmenor == 0) {
            cout << "-1\n";
            return 0; }
        r += costo[kmenor]; }
    cout << r << "\n";
    return 0; }