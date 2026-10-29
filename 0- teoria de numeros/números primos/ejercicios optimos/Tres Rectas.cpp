#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define fs first
#define sd second

const int Max = 1e6 + 7;

vector <pair<ll, ll>> v; vector <bool> pass;

bool dfs(int op, int n)
{
    bool ans = true;

    for(int i = 0; i < n; i++)
        if(pass[i] == false) ans = false;

    if(op == 0) return ans;

    for(int i = 0; i < n; i++)
    {
        if(pass[i] == false)
        {
            int x = v[i].fs, y = v[i].sd;

            vector <bool> temp(n, false);

            for(int j = 0; j < n; j++)
            {
                if(v[j].fs == x && pass[j] == false)
                {
                    pass[j] = true;
                    temp[j] = true;
                }
            } ans = (dfs(op - 1, n) == true ? true : ans);

            for(int j = 0; j < n; j++)
                if(temp[j] == true) pass[j] = false;

            for(int j = 0; j < n; j++)
            {
                if(v[j].sd == y && pass[j] == false)
                {
                    pass[j] = true;
                    temp[j] = true;
                }
            } ans = (dfs(op - 1, n) == true ? true : ans);

             for(int j = 0; j < n; j++)
                if(temp[j] == true) pass[j] = false;

            break;
        }
    }

    return ans;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    v.assign(n, { 0, 0 }); pass.assign(n + 1, 0);
    for(auto& i : v) cin >> i.fs >> i.sd;

    cout << (dfs(3, n) ? "1" : "0") << endl;

    return 0;
}