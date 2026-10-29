#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define int long long
#define endl '\n'
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    int n,k;
    cin>>n>>k;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    /*for (int i = 0; i < n; i++)
    {
        cout<<x[i]<<" ";
    }cout<<endl;*/
    if(k==n)
    {cout<<1e9<<endl;return 0;}
    if((x[k]-1<=x[k-1]&&k!=0)||x[k]-1<1||x[k]-1>1e9)
    cout<<-1<<endl;else
    cout<<x[k]-1<<endl;
    return 0;
}