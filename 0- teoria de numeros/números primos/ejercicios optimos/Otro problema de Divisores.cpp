#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000005
int spf[MAXN];

void sieve() {
    for (int i = 0; i < MAXN; ++i) {
        spf[i] = i;
    }

    for (int i = 2; i*i < MAXN; ++i) {
        if (spf[i] == i) {
            for (int j = i*i; j < MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> factor(int x) {
    vector<int> res;

    while (x > 1) {
        res.push_back(spf[x]);
        x = x / spf[x];
    }

    return res;
}

vector<int> freqFactor(int x) {
    vector<int> res;
    vector<int> factors = factor(x);

    map<int, int> freq;
//    for (int i = 0; i < factors.size(); ++i)
//        freq[i] = 0;

    for (int i = 0; i < factors.size(); ++i)
        ++freq[factors[i]];

    for (auto it = freq.begin(); it != freq.end(); ++it)
        res.push_back(it->second);

    return res;
}

int main() {
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int winner = INT_MAX, maxAmount = 0, c, x;
    vector<int> aux;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        c = 1;
        aux = freqFactor(x);
        for (int f = 0; f < aux.size(); ++f)
            c *= (aux[f] + 1);

        // cout << "DEBUG: " << x << " has " << c << endl;

        if (c > maxAmount || (c == maxAmount && x < winner)) {
                maxAmount = c;
                winner = x;
        }
    }

    cout << winner << endl;
    // cout << "DEBUG - divisors: " << maxAmount << endl;

    return 0;
}