#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vc vector
#define int long long

int count(int n) {
    int c = 0;
    for (int i=1;i*i<=n;i++) {
        if (n % i == 0) {
            c +=(i*i==n) ? 1 : 2;
        }
    }
    return c;
}

int32_t main() {
    fast
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vc<int> r(n);
        for (int i =0;i<n;i++)cin>>r[i];
        sort(r.begin(), r.end());
        int mi = r[0];
        int mx = r[n - 1];
        int d = mi * mx;

        bool a=true;
        for (int x :r) {
            if (d % x != 0) {
                a=false;
                break;
            }
        }

        if (!a) {
            cout <<-1<<endl;
            continue;
        }

        int sum = count(d);
        if (sum == n + 2) {
            cout << d <<endl;
        } else {
            cout << -1 <<endl;
        }
    }
    return 0;
}