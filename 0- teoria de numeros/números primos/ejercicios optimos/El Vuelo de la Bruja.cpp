#include <bits/stdc++.h>
#define f first
#define s second
#define deb(x) cout << #x << " = " << x << '\n'
#define pb push_back
#define lowbit(x) x & (-x)
#define pi acos(-1)
#define eps -1e9
#define rt return
#define nl '\n'
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
#define lg2(x) (31 - __builtin_clz(x))
#define lg2ll(x) (63 - __builtin_clzll(x))
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define flush fflush(stdout)
#define ls(x) (x << 1)
#define rs(x) ((x << 1) + 1)
#define pr(x) cout << x << nl
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef pair <ll, ll> iill;

const ll mod = 1e9 + 7;
const ll oo = 1e18;
const int maxn = 2e5 + 1, max_sqn = 1e3;

ll addm(ll a, ll b) { return (a + b) % mod; }
ll resm(ll a, ll b) { return (a - b + mod) % mod; }
ll mulm(ll a, ll b) { return (a * b) % mod; }

int n;
int a[maxn];

ll w;
ll ta[maxn];

ll rsum(int l, int r){
    rt(ta[r] - ta[l - 1]);
}

bool check(int x){
    for(int i = 1; i + x - 1 <= n; i++){
        if(rsum(i, i + x - 1) > w){
            rt 0;
        }
    }

    rt 1;
}

void solve(){
    int l, r, m;
    cin >> w >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ta[i] = ta[i - 1] + a[i];
    }

    l = 0, r = n;
    while(l + 1 < r){
        m = (l + r) >> 1;
        if(check(m)){
            l = m;
        }
        else {
            r = m - 1;
        }
    }

    if(l < r && check(l + 1)){
        l++;
    }

    pr(l);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(2);
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

  ll tc = 1;

  cin >> tc;
  while (tc--)
  {
    solve();
  }

  rt 0;
}