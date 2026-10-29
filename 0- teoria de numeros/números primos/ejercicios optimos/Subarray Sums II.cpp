#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    unordered_map<long long, int> Y;
    Y.reserve(3*(n+3));
    long long a = 0;
    long long b = 0;
    Y[0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a += x;

        long long d = a - k;
        if (Y.find(d) != Y.end()) {
            b += Y[d];
        }

        Y[a]++;
    }

    cout << b ;
    return 0;
}