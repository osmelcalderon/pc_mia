#include<bits/stdc++.h>
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

struct traf{
    string s;
    int x;
    int y;

};
 
int32_t main() {

    int n;
    cin >> n;
    
    vector<traf>v(n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].s >> v[i].x >> v[i].y;
    }
    
    int l = 0,r = oo;
    
    for(int i = n; i >= 1; i--)
    {
        if(v[i].s == "none") {
            l = max(l,v[i].x);
            r = min(r,v[i].y);
        }
        else if(v[i].s == "on") {
            l -= v[i].y;
            r -= v[i].x;
            l = max(l,0LL);
        }
        else {
            l += v[i].x;
            r += v[i].y;
        }
        //cout << l << " " << r << endl;
    }
    
    cout << l << " " << r << endl;
    l = 0,r = oo;
    
    for(int i = 1; i <= n; i++)
    {
        if(v[i].s == "none") {
            l = max(l,v[i].x);
            r = min(r,v[i].y);
        }
        else if(v[i].s == "on") {
            l += v[i].x;
            r += v[i].y;
        }
        else {
            l -= v[i].y;
            r -= v[i].x;
            l = max(l,0LL);
        }
        //cout << l << " " << r << endl;
    }

    cout << l << " " << r << endl;

    return 0;
}