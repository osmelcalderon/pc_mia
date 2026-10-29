#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> factors;
    if (n == 1) {
        return factors;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            factors.emplace_back(i, cnt);
        }
    }
    if (n > 1) {
        factors.emplace_back(n, 1);
    }
    return factors;
}

int main() {
    string s;
    while (cin >> s) {
        int n = stoi(s.substr(2));
        auto factors = factorize(n);
        int product = 1;
        for (auto &p : factors) {
            product *= (2 * p.second + 1);
        }
        cout << (product + 1) / 2 << endl;
    }
    return 0;
}
