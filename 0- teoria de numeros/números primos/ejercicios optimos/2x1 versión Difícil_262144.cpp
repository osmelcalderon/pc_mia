#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#ifdef eblabrada_local
  #include <local_debug.h>
#else
  #define debug(...) 42
#endif

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimize ("Ofast, no-stack-protector, unroll-loops, fast-math, O3")
// #pragma GCC target ("sse, sse2, sse3, ssse3, sse4, popcnt, abm, mmx, avx, tune = native")

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

const int MX  = 2e5+5;
const int MOD = 1e9+7; // 998244353;
const ll  INF = 1e18; // not too close to LLONG_MAX
const db  PI  = acos((db)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1}; // for every grid problem!!

mt19937 rng((uint32_t)steady_clock::now().time_since_epoch().count());

template <class T>
bool ckmin(T& a, const T& b) { // set a = min(a,b)
  return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T& a, const T& b) { // set a = max(a,b)
  return a < b ? a = b, 1 : 0;
}

// binary search
template <class T, class func>
T first_true(T lo, T hi, func f) {
  hi++; assert(lo <= hi); // assuming f is increasing
  while(lo < hi) { // find first index such that f is true
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}

template <class T, class func>
T last_true(T lo, T hi, func f) {
  lo--; assert(lo <= hi); // assuming f is decreasing
  while(lo < hi) { // find first index such that f is true
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}

template <class T>
void remove_duplicates(vector<T>& v) { // sort and remove duplicates
  sor(v); v.erase(unique(all(v)), end(v));
}

void setIO(str S = "") {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(15);

  // cin.exceptions(cin.failbit);
  // throws exception when do something illegal
  // ex. try to read letter into int

  if (sz(S) > 0) {
    freopen(S.c_str(), "r", stdin);
    freopen(S.c_str(), "w", stdout);
  }
}
#define int ll

void run_case(int tc = 0) {
  int n; cin >> n;

  vi arr(n);
  for (auto& x: arr)
    cin >> x;

  int res = 0;
  function<int(vi, int)> DP = [&](vi v, int val) {
    if (sz(v) == 0) return val;
    
    int res = 0; vi nv;
    for (int i = 0; i < sz(v); i++) {
      if (v[i] == val) {
        int j = i;
        while (j < sz(v) && v[j] == val)
          j++;

        // 1111 -> 22

        for (int c = 0; c < (j - i) / 2; ++c)
          nv.pb(val + 1);

        if ((j - i) % 2) {
          res = max(res, DP(nv, val + 1));
          nv.clear();
          for (int c = 0; c < (j - i) / 2; ++c)
            nv.pb(val + 1);
        }

        i = j - 1;
      } else nv.pb(v[i]);
    }

    res = max(res, DP(nv, val + 1));
    return res;
  };

  cout << DP(arr, 1) - 1 << "\n";

}



int32_t main() {
  setIO();

  int tc = 1; // cin >> tc;

  for (int t = 0; t < tc; ++t)
    run_case(t);

  // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n = 1?)
 * do something instead of nothing and stay organizated
 * WRITE STUFF down
 * DON'T GET STUCK ON ONE APPROACH
*/
