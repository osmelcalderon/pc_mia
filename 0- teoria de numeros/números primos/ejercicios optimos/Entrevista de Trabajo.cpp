#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
#endif // ONLINE_JUDGE

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rnk(x, y) upper_bound(all((x)), (y)) - (x).begin()

typedef long double ld;
typedef long long ll;
typedef __int128 LL;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

static int rnd(int lo, int hi) {
    return uniform_int_distribution <int> (lo, hi)(rng);
}

const ll oo = 1e18;

const ll MAX = 2e5 + 5;
const ll mod = 1e9 + 7;

typedef pair <ll, ll> ii;

ll Pot(ll b, ll e) {
    ll r = 1;
    while(e) {
        if(e & 1)
            r = r * b % mod;
        b = b * b % mod;
        e /= 2;
    }
    return r;
}

vector <ll> who[MAX];

ll n, x, y, F[MAX], I[MAX], bad[MAX];

void solve() {
    cin >> n >> x >> y;
    ii lo1 = {2e9, 0};
    ii lo2 = {2e9, 0};
    for(int i = 1; i <= n; i++) {
        ll c, w;
        cin >> c >> w;
        if(ii(w, c) < lo1)
            lo1 = {w, c};
        who[c].push_back(w);
    }
    for(ll i = 1; i <= n; i++) {
        if(i != lo1.second) {
            for(ll w : who[i])
                if(ii(w, i) < lo2)
                    lo2 = {w, i};
        }
    }
    map <ll, ll> m;
    ll r = F[0] = 1;
    ll t = 0;
    for(ll i = 1; i <= n; i++) {
        F[i] = F[i - 1] * i % mod;
        if(!who[i].size())
            continue;
        sort(all(who[i]));
        if(who[i][0] > y - lo1.first) {
            continue;
        } else {
            for(ll w : who[i]) {
                if(i == lo1.second) {
                    if(w + lo2.first <= y || w + lo1.first <= x) {
                        m[i]++;
                        t++;
                    }
                } else {
                    if(w + lo1.first <= y || w + who[i][0] <= x) {
                        m[i]++;
                        t++;
                    }
                }
            }
        }
    }

    I[n] = Pot(F[n], mod - 2);
    for(ll i = n; i > 0; i--)
        I[i - 1] = I[i] * i % mod;
    r = r * F[t] % mod;
    for(auto [c, w] : m)
        r = r * I[w] % mod;
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
//    cin >> tc;

    while(tc--)
        solve();
}