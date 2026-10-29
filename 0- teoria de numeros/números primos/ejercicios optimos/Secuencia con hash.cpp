#include <iostream>
#include <complex>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

#define endl '\n'
#define db double
#define ll __int128
#define int long long
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

void print(bool x) { cout << (x ? "Yes" : "No") << endl; }

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

void solve()
{
    int n, m, p, b; cin >> p >> b >> n >> m;
    vector <vector <int>> E(n+2, vector <int> (n+2, 0));
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; 
        E[a-1][b]++; E[b][a-1]++;
    }

    vector <int> dp((1 << (n+1)) + 7, Inf);

    for(int i = 0; i < n+1; i++)
        dp[(1<<i)] = 1;

    for(int i = 1; i < (1 << (n+1)); i++)
    {
        int sum = 0;

        for(int j = 0; j <= n; j++) if(i & (1 << j))
        {
            for(int k = 0; k <= n; k++) if(i & (1 << k))
            {
                sum += E[j][k];
            }
        }

        if(sum == 0)
            dp[i] = 1;
        else 
        {
            for(int j = i; j > 0; j = (j-1) & i)
            {
                dp[i] = min(dp[i], dp[j] + dp[i^j]);
            }
        }
    }

    print(dp[(1<<(n+1))-1] <= p);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Q = 1; //cin >> Q;

    while (Q--)
    {
        solve();
    }

    return 0;
}