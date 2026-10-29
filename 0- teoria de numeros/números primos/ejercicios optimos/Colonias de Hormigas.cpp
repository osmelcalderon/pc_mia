/**
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define deb(x) cerr << #x << " = " << x << '\n';
#define pb push_back
#define lowbit(x) x & (-x)
#define pi acos(-1)
#define rt return
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
#define show(x) cout << x << '\n';
#define lg2(x) 31-__builtin_clz(x)
#define lg2ll(x) 63-__builtin_clzll(x)
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define flush fflush(stdout)
#define hi(x) (x << 1)
#define hd(x) ((x << 1) + 1)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair <int, int > ii;
typedef pair < int, ii > iii;
typedef pair < ll, ll > ll2;
typedef pair < db, db > db2;
typedef pair < int, char > ic;

typedef vector < int > vi;

const db eps = 0.00000001;
const int maxn = 200, max_st = (4 * maxn), maxm = 640002, maxc = 30, ooint = 1e9;
const int mov[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const ll mod = (1e9) + 7LL, ooll = 1e18;

ll addm(ll x, ll y){rt (x + y) % mod;}

ll mulm(ll x, ll y){rt (x * y) % mod;}



bool m[maxn], used[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
     cout.precision(9);
//    freopen("in.txt", "r", stdin);
//    freopen("in.out", "w", stdout);

    int ta, tb, t;
    string a, b, full = "";

    cin >> ta >> tb;

    cin >> a >> b;

    cin >> t;

    for(int i = ta - 1; i >= 0; i--){
        full += a[i];
        m[ int(a[i]) ] = 1;
    }
    for(int i = 0; i < tb; i++)full += b[i];

    for(int i = 1; i <= t; i++){
        for(int j = 0; j < ta + tb; j++)used[j] = 0;

        for(int j = 0; j < ta + tb - 1; j++){
            if(!used[j] && !used[j + 1] && m[ int(full[j]) ] && !m[ int(full[j + 1]) ]){
                used[j] = used[j + 1] = 1;
                swap(full[j], full[j + 1]);
            }
        }
    }

    show(full)

   rt 0;
}