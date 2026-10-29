#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define db double
#define ll __int128
#define int long long
#define pb push_back
#define fs first
#define sd second
#define Mod long(97654321) // 998244353
#define all(x) x.begin(), x.end()
#define unvisited long(-1)
#define Eps double(1e-9)
#define _for(i, n) for(int i = 0; i < (n); i++)
#define dbg(x) cout << #x ": " << x << endl;

const int Max = 1e7 + 7, Inf = 1e9 + 7;

void print(bool x) { cout << (x ? "First" : "Second") << endl; }

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

vector <vector<int>> v, s; 
vector <int> p, b; bool can; 

void f(int n, int x)
{
    p.clear(); p.assign(n+1, 0);  
    b.clear(); b.assign(n+1, 0); 
    v.clear(); v.assign(n+1, vector <int> ());
    for(int i = 0; i <= x; i++)
    {
        for(int j = 0; j < (int) s[i].size() - 1; j++)
        {
            //cerr << s[i][j] << " " << s[i][j+1] << endl;  
            p[s[i][j+1]]++;  
            v[s[i][j]].push_back(s[i][j+1]);
        } 
    }
}

void dfs(int node)
{
    //cerr << node << endl; 
    if(b[node] == 2) return; 
    if(b[node] == 1)
    {
        can = false; 
        return; 
    }
    b[node] = 1; 
    for(auto& u : v[node])
    {
        //cerr << u << " Node" << endl; 
        dfs(u); 
    }
    b[node] = 2; 
} 

void solve()
{
    int n, m; cin >> n >> m; 
    s.push_back(vector <int> ()); 
    for(int i = 0; i < m; i++)
    {
        int k; cin >> k; vector <int> c(k); 
        for(auto& u : c) cin >> u; 
        s.push_back(c); 
    }

    int a = -1, b = m + 1; //cerr << "PAs" << endl; 


    while(abs(a - b) != 1)
    {
        int c = (a + b) / 2; //cerr  << "C: " << c << endl; 

        f(n, c); can = true; 
        for(int i = 1; i <= n; i++)
            dfs(i);  

        //cerr << "CAN: " << can << endl; 
        //return; 
        if(can)
            a = c; 
        else 
            b = c; 
    }

   // cerr << "CAN: " << a << endl; 
    f(n, a); 
   
    priority_queue <int> pq; 
    vector <int> ans; 

    for(int i = 1; i <= n; i++)
    {
        if(p[i] == 0)
        {
            //cerr << "ANS: " << i << endl; 
            pq.push(-i); 
        }
    }

    while (!pq.empty())
    {
        int x = -pq.top(); pq.pop();
        ans.push_back(x); 
        for(auto& u : v[x])
        {
            p[u]--; 
            if(p[u] == 0)
            {
                pq.push(-u); 
            }
        }
    }

    //cerr << "PASS: " << ans.size() << endl; ; 

    for(auto& u: ans) cout << u << " "; 
    cout << endl;
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