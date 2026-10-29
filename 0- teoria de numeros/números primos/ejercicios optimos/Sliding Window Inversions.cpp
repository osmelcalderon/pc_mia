#include "bits/extc++.h"
using namespace std;
using namespace __gnu_pbds;
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

/*MST
#include "bits/extc++.h"
typedef tree<pair<int,int>,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
using namespace __gnu_pbds;
*/


typedef tree<int,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set s;

int32_t main() {
    ios;

    int n,k;
    cin >> n >> k;
    vector<int>v(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int>low(n + 1,0);
    vector<int>upp(n + 1,0);

    for(int i = 1; i <= n; i++)
    {
        s.insert(v[i]);
        if(i > k)s.erase(s.find_by_order(s.order_of_key(v[i - k])));
        int lw = s.order_of_key(v[i] + 1);
        low[i] = s.size() - lw;
    }

    s.clear();


    for(int i = n; i >= 1; i--)
    {
        s.insert(v[i]);
        if(i <= n - k)s.erase(s.find_by_order(s.order_of_key(v[i + k])));
        int up = s.order_of_key(v[i]);
        upp[i] = up;
    }

    vector<int>ans(n + 1,0);
    int answ = 0;

    for(int i = n; i >= 1; i--)
    {
        answ += upp[i];
        if(i <= n - k)answ -= low[i + k];
        ans[i] = answ;
    }

    for(int i = 1; i <= n - k + 1; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}