#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r = 0, m = INT_MAX, x;
    cin >> n;
    while(n--) {
        cin >> x;
        if (x < m) r++, m = x;
    }
    cout << r << '\n';
}