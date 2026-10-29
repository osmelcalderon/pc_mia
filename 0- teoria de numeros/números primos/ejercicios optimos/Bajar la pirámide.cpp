#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    int max_even = 0;
    int current_even = 0;
    int k_max_even = n / 2;

    for (int k = 1; k <= k_max_even; ++k) {
        if (2 * k - 1 >= d.size() || 2 * k - 2 < 0) {
            break;
        }
        int delta = d[2 * k - 1] - d[2 * k - 2];
        current_even += delta;
        int current_max = max(0, -current_even);
        if (current_max > max_even) {
            max_even = current_max;
        }
    }

    if (d.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    int current_odd = d[0];
    int min_odd = current_odd;
    int k_max_odd = (n - 1) / 2;

    for (int k = 1; k <= k_max_odd; ++k) {
        if (2 * k >= d.size()) {
            break;
        }
        int delta = d[2 * k] - d[2 * k - 1];
        current_odd += delta;
        if (current_odd < min_odd) {
            min_odd = current_odd;
        }
    }

    int lower_bound = max_even;
    int upper_bound = min_odd;

    if (upper_bound >= lower_bound && upper_bound >= 0) {
        cout << upper_bound - lower_bound + 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
