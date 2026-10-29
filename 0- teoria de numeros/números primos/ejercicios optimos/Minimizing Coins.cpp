#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    vector<int> dp(m + 1, m + 1);
    dp[0] = 0;
    for (int i : ar)
    {
        for (int j = i; j <= m; j++)
        {
            dp[j] = min(dp[j], dp[j - i] + 1);
        }
    }
    (dp[m] > m) ? cout << -1 << endl : cout << dp[m] << endl;
    return 0;
}