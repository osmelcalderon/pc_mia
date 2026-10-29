#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
//\\ PRINCIPAL \\//
 
#define oo 1e18
#define endl "\n"
#define int long long
#define mod 1000000007
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



void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        bool f = 0;
        string y;
        for(int j = 0; j < s.size(); j++)
        {
            y += s[j];
            if(j > i) {
                y.erase(0,1);
            }
            if(j < i)continue;
            string x;
            int c = 0;
            for(int l = 0; l < s.size(); l++)
            {
                x += s[l];
                if(l > i) {
                    x.erase(0,1);
                }
                if(x == y) {
                    c++;
                }
            }
            if(c > 1) {
                f = 1;
                break;
            }
        }
        if(!f) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int32_t main() {
    ios;
    int t = 1;

    while(t--)solve();

    return 0;
}
