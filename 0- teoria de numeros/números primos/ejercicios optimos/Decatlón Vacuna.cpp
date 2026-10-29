#include <bits/stdc++.h>
using namespace std;
// ntt data 998244353, 119, 23
typedef long long ll;
#define F first
#define S second
const ll mod=1e9+7;
ll q, n, k, a[20][20], dp[(1<<20)], c[20];
string s;
vector<pair<ll, ll>> v[21];
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n >> q;
    for(int i=0; i<q; i++){
        cin >> c[0] >> c[1] >> c[2];
        v[c[0]].push_back({c[1], c[2]});
        sort(v[c[0]].begin(), v[c[0]].end());
    }
    for(int i=0; i<n; i++){
        for(int t=0; t<n; t++){
            cin >> a[i][t];
        }
    }
    for(int i=1; i<(1<<n); i++){
        for(int t=i; t>0; t-=(t&-t)){
            dp[i]=max(dp[i], dp[i-(t&-t)]+a[__builtin_ctz(t)][__builtin_popcount(i)-1]);
        }
        for(auto t : v[__builtin_popcount(i)]){
            if(dp[i]>=t.F)dp[i]+=t.S;
        }
    }
    cout << dp[(1<<n)-1];
}