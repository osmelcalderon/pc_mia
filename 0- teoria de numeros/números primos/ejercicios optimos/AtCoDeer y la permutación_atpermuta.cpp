#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...) 42
#endif

using ll = long long;
using db = long double;

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define bk back()
#define ft front()

class UnionFind {
private:
  vector<int> p, rank, setSize;

public:  
  UnionFind(int N) {
    p.assign(N, 0); iota(p.begin(), p.end(), 0);
    rank.assign(N, 0);
    setSize.assign(N, 1);
  }

  int findSet(int i) {
    return (i == p[i]) ? i : (p[i] = findSet(p[i]));
  }

  int sizeOfSet(int i) {
    return setSize[findSet(i)];
  }

  bool sameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }

  bool unionSet(int i, int j) {
    if (sameSet(i, j)) return false;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y]) swap(x, y);    
    p[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
    setSize[y] += setSize[x];
    return true;
  }
};

void runCase(int caseNo = 0) {
  int n,m; cin >> n >> m;

  vi a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  UnionFind UF(n + 1);
  for (int i = 0; i < m; i++) {
    int x,y; cin >> x >> y;
    UF.unionSet(x, y);
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (UF.sameSet(i, a[i])) {
      res += 1;
    }
  }

  cout << res << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int TC = 1; // cin >> TC;

  for (int T = 1; T <= TC; ++T) {
    runCase(T);
  }

  // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (N = 1?)
 * do something instead of nothing and stay organizated
 * WRITE STUFF down
 * DON'T GET STUCK ON ONE APPROACH
*/
