#include <bits/stdc++.h>
#define f(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;

const int MAXN = 100005;

string ch;
int a[MAXN], s[MAXN], b[MAXN];
int n, K, ans;

int main() {
    ios::sync_with_stdio(false);

    int i, j, d;
    cin >> n >> K;

    f(i, 2, n + 1) {
        cin >> d >> ch;
        if (ch == "L") 
            a[i] = a[i - 1] - d;
        else 
            a[i] = a[i - 1] + d;
        s[i] = a[i];
    }

    sort(s + 1, s + 2 + n);
    int L = unique(s + 1, s + 2 + n) - (s + 1);

    f(i, 2, n + 1) {
        int pos1 = lower_bound(s + 1, s + 1 + L, a[i]) - s;
        int pos2 = lower_bound(s + 1, s + 1 + L, a[i - 1]) - s;
        if (pos1 > pos2) swap(pos1, pos2);
        b[pos1]++;
        b[pos2]--;
    }

    f(i, 1, L - 1) {
        b[i] += b[i - 1];
        if (b[i] >= K) {
            ans += s[i + 1] - s[i];
        }
    }

    cout << ans << endl;
    return 0;
}
