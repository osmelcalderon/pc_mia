#include <bits/stdc++.h>
using namespace std;
#define Hd int main(void)
Hd {
    int n;
    scanf("%d",&n);

    pair<int, int> ar[n];
    for (int i = 0; i < n; i++)scanf("%d%d",&ar[i].first,&ar[i].second);

    sort(ar, ar+n, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int ans = 0;
    int hfa = 0;

    for (auto &c : ar) {
        if (c.first >= hfa) {
            ans++;
            hfa = c.second;
        }
    }
    printf("%d",ans);
}