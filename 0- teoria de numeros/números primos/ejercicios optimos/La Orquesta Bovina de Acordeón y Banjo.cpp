#include <bits/stdc++.h>
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

int maxn = 3*Max;

struct LiChaoTree // f(x) = mx + c
{
    typedef long long ftype;
    typedef complex<ftype> point;
    #define x real
    #define y imag

    ftype dot(point a, point b) {
        return (conj(a) * b).x();
    }

    ftype f(point a,  ftype x) {
        return dot(a, {x, 1});
    }

    struct node
    {
        int left, right; point p; 
        node(point _p = { 0, -Inf })
        {
            p = _p; left = right = -1; 
        }
    };
    
    vector <node> line; 

    void add_line(point nw, int v = 0, int l = 0, int r = maxn) {
        int m = (l + r) / 2; 
        bool lef = f(nw, l) > f(line[v].p, l);
        bool mid = f(nw, m) > f(line[v].p, m);
        if(mid) {
            swap(line[v].p, nw);
        }
        if(r - l == 1) {
            return;
        } else if(lef != mid) {
            if(line[v].left == -1)
            {
                line.push_back(node(nw)); 
                line[v].left = line.size() - 1; 
            }
            else
                add_line(nw, line[v].left, l, m);
        } else {
            if(line[v].right == -1)
            {
                line.push_back(node(nw)); 
                line[v].right = line.size() - 1; 
            }
            else 
                add_line(nw, line[v].right, m, r);
        }
    }

    ftype get(int x, int v = 0, int l = 0, int r = maxn) {
        int m = (l + r) / 2; 
        if(r - l == 1) {
            return f(line[v].p, x);
        } else if(x < m) {
            if(line[v].left != -1)
                return max(f(line[v].p, x), get(x, line[v].left, l, m));
            else 
                return f(line[v].p, x);
        } else {
            if(line[v].right != -1)
                return max(f(line[v].p, x), get(x, line[v].right, m, r));
            else 
                return f(line[v].p, x);
        }
    }

    LiChaoTree()
    {
        line.push_back(node()); 
        add_line({ 0, -Inf });
    }
};

int sq(int x) { return x * x; }

void solve()
{
    int n, ans = 0; cin >> n; 
    vector <int> a(n), b(n);
    for(auto& u : a) cin >> u;
    for(auto& u : b) cin >> u;  

    vector <int> sa(n+1), sb(n+1);

    vector <LiChaoTree> dp1(n+1, LiChaoTree());
    
    for(int i = 1; i <= n; i++)
    {
        sa[i] += sa[i-1] + a[i-1];
        sb[i] += sb[i-1] + b[i-1];
    }

    vector <vector<int>> dp(n + 1, vector <int> (n + 1, 0));

    queue <pair<int, int>> q;

    for(int i = 1; i <= n; i++)
    {
        LiChaoTree dp2;
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = a[i-1] * b[j-1];

            if(i == 1)
                dp[i][j] -= sq(sb[j-1]);
            else if(j == 1)
                dp[i][j] -= sq(sa[i-1]);
            else 
                dp[i][j] += max(dp1[j-1].get(2 * sa[i-1]) - sq(sa[i-1]), 
                    dp2.get(2 * sb[j-1]) - sq(sb[j-1]));
            
            if(!q.empty()) 
            {
                dp2.add_line({ q.front().fs, q.front().sd });
                q.pop();
            }

            ans = max(ans, dp[i][j] - (sq(sa[n] - sa[i]) + sq(sb[n] - sb[j])));
        }

        for(int j = 1; j <= n; j++)
        {
            dp1[j].add_line({ sa[i], dp[i][j] - sq(sa[i]) });
            q.push({ sb[j], dp[i][j] - sq(sb[j]) });   
        }
    }

    cout << ans << endl;
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