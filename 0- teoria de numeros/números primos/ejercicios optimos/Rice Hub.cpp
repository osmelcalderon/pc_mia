#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define tam(x)  (int)(x).size()
#define endl '\n'
#define sd second
#define fs first
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define optmizar_io  ios_base::sync_with_stdio(0); cin.tie(0);
#define Setpre(n) cout << fixed <<setprecision(n)
#define dbg(x) for(auto y: x) cout << y <<' '; cout << endl;
#define dbg1(x) for(auto y: x) cout << y.first <<' '<< y.second << endl;
#define dbg2(v) for(auto x: v) cout << x.a<< ' '<< x.b <<' '<< x.c << endl;

const int MAX = 501;
const int INF = 1e17;
const int Mod = 1e9+7;
const int zero = 0;
const double eps = 1e-6;
const double PI=acos(-1.0);
const int mox[8] ={-1,1,0,0,-1,-1,1,1};
const int moy[8] ={0,0,-1,1,-1,1,-1,1};

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<bool> vbol;

void cases(string s){
#ifndef ONLINE_JUDGE
    if(tam(s) == 0) s = "1"; 
    string a = s + ".in";
    string b = s + ".out";
    freopen(a.c_str(), "r", stdin);
    freopen(b.c_str(), "w",  stdout);
#endif
}

vi pref,ar;



int32_t main() {
    optmizar_io 
    // cases("");

    //start: 
    //end:
    //tags:
    //difficulty:
    //comment: 

    int n, L, B; cin >> n >> L >> B;
    pref = ar = vi(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> ar[i - 1];
        pref[i] = pref[i - 1] + ar[i - 1];
    }
    int ans = 0, l = 0;
    for(int r = 0; r < n; r++){
        int m = (l + r) / 2;
        int c = (ar[m] * (m - l) - (pref[m] - pref[l])) + ((pref[r + 1] - pref[m + 1]) - ar[m] * (r - m));
        while(c > B){
            l++;
            m = (l + r) / 2;
            c = (ar[m] * (m - l) - (pref[m] - pref[l])) + ((pref[r + 1] - pref[m + 1]) - ar[m] * (r - m));
        }
        maxs(ans, r - l + 1);
    }
    
    cout << ans << endl;


    return 0;
}