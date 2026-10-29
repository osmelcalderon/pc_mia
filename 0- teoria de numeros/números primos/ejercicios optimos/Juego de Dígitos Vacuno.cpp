#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define db double
#define ll __int128
//#define int long long
#define pb push_back
#define fs first
#define sd second
#define Mod long(1e9 + 7)
#define all(x) x.begin(), x.end()
#define unvisited long(-1)
#define Eps double(1e-9)
#define _for(i, n) for(int i = 0; i < (n); i++)
#define dbg(x) cout << #x ": " << x << endl;

const int Max = 1e6 + 7, Inf = 1e9 + 7;

void print(bool x) { cout << (x ? "YES" : "NO") << endl; }

string tostring (__int128 x)
{
    string ans = "";
    while(x > 0)
    {
        ans += (x % 10 + '0');
        x /= 10;
    }
    reverse(all(ans));
    return ans;
}

int dp[Max][2]; 

int calc(int x, int p)
{
    if(dp[x][p] != -1) return dp[x][p]; 
    int d1 = 9, d2 = 0, t = x; 
    while (t > 0)
    {
        d1 = min(d1, (t % 10 != 0 ? t % 10 : d1)); 
        d2 = max(d2, t % 10); 
        t /= 10; 
    }
    return dp[x][p] = (!calc(x - d1, p ^ 1)) | (!calc(x - d2, p ^ 1));  
}

void solve()
{
    int n; cin >> n; 
    print(calc(n, 0)); 
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < Max; i++)
        dp[i][0] = dp[i][1] = -1;

    int Q = 1; cin >> Q;

    while (Q--)
    {
        solve();
    }

    return 0;
}