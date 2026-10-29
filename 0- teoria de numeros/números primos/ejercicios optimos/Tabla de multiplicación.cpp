#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
int64 n, m, k;

int64 get(int64 a, int64 b) {
	return b - a + 1;
}

int64 f(int64 x) {
	int64 sol = 0;

	for(int64 i = 1; i * i <= x && i <= m; i++)
		sol += get(i, min(x / i, n)) + get(i, min(x / i, m)) - 1;

	return sol;
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);

	if(n < m)
		swap(n, m);

	int64 st = 1, nd = n * m, ans = 1e18;

	while(st <= nd) {
		int64 mid = (st + nd) / 2LL;

		if(f(mid) >= k) {
			ans = min(ans, mid);
			nd = mid - 1;
		}

		else st = mid + 1;
	}

	printf("%lld\n", ans);
	return 0;
}