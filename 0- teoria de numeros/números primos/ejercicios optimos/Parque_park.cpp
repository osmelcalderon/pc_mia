#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast","unroint-loops","omit-frame-pointer","inline","03")
#endif // ONLINE_JUDGE

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rnk(x, y) upper_bound(all((x)), (y)) - (x).begin()

template <class T = int> using ii = pair <T, T>;
template <class T = int> using tri = tuple <T, T, T>;

typedef long double ld;
typedef long long ll;
typedef __int128 LL;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

static int rnd(int lo, int hi) {
    return uniform_int_distribution <int> (lo, hi)(rng);
}

const ll oo = 1e18;

const ll MAX = 1e5 + 5;
const ll mod = 1e9 + 7;

const ll sq(ll x) {
    return x * x;
}

ll n, m, q, W, H, p[MAX], px[MAX], py[MAX], R[MAX];

int Get(int k) {
    return p[k] == k ? k : p[k] = Get(p[k]);
}

string sol[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q >> W >> H;

    vector <tri <ll>> path;

    for(int i = 1; i <= n; i++) {
        ll &x = px[i], &y = py[i], &r = R[i];
        cin >> y >> x >> r;
        path.push_back(tri <ll> (H - x - r, i, n + 3));
        path.push_back(tri <ll> (W - y - r, i, n + 2));
        path.push_back(tri <ll> (x - r, i, n + 1));
        path.push_back(tri <ll> (y - r, i, n + 4));
    }

    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++) {
            ll dx = px[i] - px[j];
            ll dy = py[i] - py[j];
            ll D = (ll)sqrtl(dx * dx + dy * dy) - R[i] - R[j];
            path.push_back(tri <ll> (D, i, j));
        }

    vector <tri <ll>> v(q);

    q = 0;

    for(auto &[r, k, c] : v) {
        cin >> r >> k, c = q++, r += r;
    }

    sort(all(path));
    sort(all(v));

    for(int i = 1; i <= n + 4; i++)
        p[i] = i;

    int t = 0, a, b;
    m = path.size();

    for(auto [r, k, i] : v) {
        while(t < m) {
            auto [w, x, y] = path[t];
            if(w >= r)break;
            a = Get(x), b = Get(y);
            if(a != b)p[a] = b;
            t++;
        }

        int cut[6];

        for(int j = 1; j <= 4; j++) {
            cut[j-1] = (Get(n + j) == Get(n + 1 + (j % 4)));
        }

        cut[4] = (Get(n + 1) == Get(n + 3));
        cut[5] = (Get(n + 2) == Get(n + 4));

        auto &s = sol[i];

        if(k == 1) {
            s += '1';
            if(!(cut[0] | cut[3] | cut[4]))s += '2';
            if(!(cut[3] | cut[1] | cut[4] | cut[5]))s += '3';
            if(!(cut[2] | cut[3] | cut[5]))s += '4';
        }
        if(k == 2) {
            if(!(cut[0] | cut[3] | cut[4]))s += '1';
            s += '2';
            if(!(cut[0] | cut[1] | cut[5]))s += '3';
            if(!(cut[0] | cut[2] | cut[4] | cut[5]))s += '4';
        }
        if(k == 3) {
            if(!(cut[3] | cut[1] | cut[4] | cut[5]))s += '1';
            if(!(cut[0] | cut[1] | cut[5]))s += '2';
            s += '3';
            if(!(cut[2] | cut[1] | cut[4]))s += '4';
        }
        if(k == 4) {
            if(!(cut[2] | cut[3] | cut[5]))s += '1';
            if(!(cut[0] | cut[2] | cut[4] | cut[5]))s += '2';
            if(!(cut[2] | cut[1] | cut[4]))s += '3';
            s += '4';
        }
    }

    for(int i = 0; i < q; i++)
        cout << sol[i] << '\n';
}
