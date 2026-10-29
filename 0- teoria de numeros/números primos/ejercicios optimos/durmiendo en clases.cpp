#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> vec = vector<int>(n);
		int sum = 0;
		for (int &h : vec) {
			cin >> h; sum += h;
		}
		for (int i = 0; i <= sum; i++) {
			if (i != 0 && sum % i != 0) {
				continue;
			}
			int c = 0;  
			bool u = true;
			for (int h : vec) {
				c += h;
				if (c > i) {
					u = false; 
					break;
				} else if (c == i) {
					c = 0;
				}
			}

			if (u) {
				if (i == 0) {
					cout << 0 << '\n';
				} else {
					cout << n - sum / i << '\n';
				}
				break;
			}
		}
	}
}