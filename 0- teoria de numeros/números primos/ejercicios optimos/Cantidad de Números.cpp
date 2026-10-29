#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
//\\ PRINCIPAL \\//
 
#define oo 1e18
#define endl "\n"
#define int long long
#define mod 1000000007
#define tle while(1){;}
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)
 
//\\ BITS \\//
 
#define bits_1 __builtin_popcount 
 
//\\ STL \\//
 
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lb(x,y) lower_bound(x.begin(),x.end(),y)-x.begin()
#define ub(x,y) upper_bound(x.begin(),x.end(),y)-x.begin()

vector<int>f(19,1);

int quickpow(int a,int b) {
    if(b == 0)return 1;
    if(b % 2 == 0)return quickpow(a * a,b / 2);
    else          return a * quickpow(a * a,b / 2);
}

void solve() {
    int a,b;
    cin >> a >> b;
    if(a == 0 && b == 0)exit(0);
    if(a == 1 && b == 0) {
        cout << 9 << endl;
        return;
    }
    int p = f[a + b] / (f[b] * f[a]);
    int dig = quickpow(5,a) * quickpow(5,b);
    int p2 = f[a - 1 + b] / (f[b] * f[a - 1]);
    int dig2 = quickpow(5,b) * quickpow(5,a - 1);
    p2 = p2 * dig2;
    int t = (p * dig) - p2;
    cout << t * 2 << endl;
}

int32_t main() {
    ios;

    //freopen("taming.in", "r", stdin);
    //freopen("taming.out", "w", stdout);

    for(int i = 1; i <= 18; i++)
    {
        f[i] = f[i - 1] * i;
    }

    while(1)solve();
    
    return 0;
}