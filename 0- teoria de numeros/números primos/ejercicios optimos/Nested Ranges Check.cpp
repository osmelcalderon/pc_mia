#include<bits/stdc++.h>
using namespace std;
//\\ PRINCIPAL \\//
 
#define oo 1e18
#define endl "\n"
#define mod 1000000007
#define int long long
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


int32_t main() {
    ios;
    
    int n;
    cin >> n;

    vector<pair<int,pair<int,int> > >v(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].fr >> v[i].sc.fr;
        v[i].sc.fr *= -1;
        v[i].sc.sc = i;
    }

    sort(all(v));
    int y = -oo;
    
    vector<bool>f(n + 1,0);
    vector<bool>f2(n + 1,0);

    for(int i = 1; i <= n; i++)
    {
        if(abs(v[i].sc.fr) <= y) {
            f[v[i].sc.sc] = 1;
        }
        y = max(y,abs(v[i].sc.fr));
    }

    y = oo;

    for(int i = n; i >= 1; i--)
    {
        if(abs(v[i].sc.fr) >= y) {
            f2[v[i].sc.sc] = 1;
        }
        y = min(y,abs(v[i].sc.fr));
    }

    for(int i = 1; i <= n; i++) 
    {
        cout << f2[i] << " ";
    }

    cout << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << f[i] << " ";
    }

    return 0;
}