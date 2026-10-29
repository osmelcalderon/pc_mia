#include <bits/stdc++.h>

#define endl '\n'

#define lcm(a, b) (a / __gcd(a, b) * b)
#define lsb(i) (i&(-i))

using namespace std;

using lld = long long;
using ull = unsigned long long;

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

const vector<int> movx = {0, 0, 1, -1};
const vector<int> movy = {1, -1, 0, 0};

const int maxn = 2e5 + 5;
const int inf = INT_MAX;
const int mod = 1e9 + 7;
const double pi = acos(-1);    //or 3.14159265358979323846

int modpow(int a, int b)
{
    int ret = 1;

    while(b)
    {
        if(b & 1)ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return ret;
}

int modinv(int a)
{
    return modpow(a, mod - 2);
}

int n, k, a[maxn];

bool check(int x)
{
    int p[n];

    for(int i = 0; i < n; i++)
    {
        p[i] = (a[i] >= x ? 1 : -1);
        if(i)p[i] += p[i - 1];
    }

    int mx = p[k - 1], mn = 0;

    for(int i = k; i < n; i++)
    {
        mn = min(mn, p[i - k]);
        mx = max(mx, p[i] - mn);
    }

    return (mx > 0);
}

void solve()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = n, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(check(mid))
        {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
