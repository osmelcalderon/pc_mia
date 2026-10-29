/// Convex Hull Trick: O(n)
/// O(n*log(n)) to sort the input
#include <bits/stdc++.h>

using namespace std;

int n, pointer;

typedef pair<int,int> par;
typedef long long ll;

par a[50001], v[50001];
ll dp;

struct line{
    int m; ll c;
};

vector<line> xxx;

bool bad(line l1, line l2, line l3)
{
    return (l3.c - l1.c)*(ll)(l1.m - l2.m) <= (l2.c - l1.c)*(ll)(l1.m - l3.m);
}

ll query(int x)
{
    if(pointer >= xxx.size()) pointer = xxx.size() - 1;

    while(pointer < xxx.size()-1 && (ll)xxx[pointer].m*(ll)x + xxx[pointer].c >= (ll)xxx[pointer+1].m*(ll)x + xxx[pointer+1].c)
        pointer++;
    return (ll)xxx[pointer].m*(ll)x + xxx[pointer].c;
}

void add(int m, ll c)
{
    line t;
    t.m = m, t.c = c;

    while(xxx.size()>1 && bad(xxx[xxx.size()-2], xxx[xxx.size()-1], t))
        xxx.pop_back();
    xxx.push_back(t);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int w, l, m;
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> v[i].first >> v[i].second;

    sort(v + 1, v + m + 1);

    n = 1;

    for(int i = 1; i <= m; i++)
    {
        while(n > 1 && a[n-1].second <= v[i].second)
            n--;
        a[n++] = v[i];
    }
///    DP -- O(n^2) = 60 points
///    dp[0] = 0;
///
///    for(int i = 1; i < n; i++)
///    {
///        dp[i] = (1LL)<<(50LL);
///        for(int j = 0; j < i; j++)
///            dp[i] = min(dp[i], dp[j] + (ll)a[j+1].second*(ll)a[i].first);
///    }

    add(a[1].second,0);
    pointer = 0;
    for(int i = 1; i < n; i++)
    {
        dp = query(a[i].first);
        if(i < n - 1)
            add(a[i+1].second,dp);
    }

    cout << dp;

    return 0;
}