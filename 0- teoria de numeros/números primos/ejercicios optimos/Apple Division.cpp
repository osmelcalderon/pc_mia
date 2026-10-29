#include <bits/stdc++.h>
using namespace std;
long long dp(long long acum1, long long acum2, long long i, const vector<long long> &ar)
{
    if (i == ar.size())
    {
        return abs(acum2 - acum1);
    }
    long long op1 = dp(acum1 + ar[i], acum2, i + 1, ar), op2 = dp(acum1, acum2 + ar[i], i + 1, ar);
    return min(op1, op2);
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> ar(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << dp(0, 0, 0, ar) << endl;
}