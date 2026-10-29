#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

long long i, j, l, m, n, v[100005], ans, c, cycle[100005];
double t, k, last[100005], b[100005];

void merge(int lef, int rig) {
    if (lef == rig) return;
    if (lef == rig - 1) {
        if (last[lef] - last[rig] > 1e-7) ans--, swap(last[lef], last[rig]);
        return;
    }
    int mid = (lef + rig) / 2;
    merge(lef, mid);
    merge(mid + 1, rig);
    int i, j, l;
    for (l = i = lef, j = mid + 1; i <= mid && j <= rig;) {
        if (last[i] - last[j] > 1e-7) {
            ans -= (mid - i + 1);
            b[l++] = last[j++];
        } else {
            b[l++] = last[i++];
        }
    }
    for (; i <= mid;) b[l++] = last[i++];
    for (; j <= rig;) b[l++] = last[j++];
    for (i = lef; i <= rig; i++) last[i] = b[i];
}

int main() {
    scanf("%lld%lld%lld", &n, &l, &c);
    for (i = 1; i <= n; i++) scanf("%lld", &v[i]);
    sort(v + 1, v + n + 1);
    
    t = l * c / 1.0 / v[n]; 
    m = 0;
    
    for (i = 1; i <= n; i++) {
        cycle[i] = (long long)(t * v[i] / c);
        ans += (i - 1) * cycle[i] - m;
        m += cycle[i];
        last[i] = t * v[i] - cycle[i] * c;
    }
    
    merge(1, n);
    printf("%lld", ans);
}