#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> X(n);
    
    int x=0;
    int y=0;
    for (int i = 0; i < n; i++) {
        cin >> X[i];
        if (X[i] > x) x = X[i];
        y += X[i];
    }

    int a = x;
    int b = y;
    int minimo = y;

    while (a <= b) {
        int m = a + (b - a) / 2;
        
    int d = 1;
    int ca = 0;
    for (int i = 0; i < n; i++) {
    if (ca + X[i] <= m) {
    ca+= X[i];
    } else {
       d++;
       ca = X[i];
     }
    }
        
     if (d <= k) {
     minimo = m;
     b = m - 1;
     } else {
     a = m + 1;
     }
    }   

    cout << minimo;
    return 0;
}