#include <bits/stdc++.h>
#define int long long
#define gcd __gcd
#define endl "\n"
#define pii pair<int, int>
#define sd second
#define fs first
#define vi vector<int>
#define vii vi<vi>
#define vpii vector<pii>
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
const int mod = 1e9+7,MAX=2e6;
int n, ar[MAX], lt[MAX], z[MAX];

int32_t main(){
    fast
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        z[i] = lt[ar[i]];
        lt[ar[i]] = i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += ( ((i-1)-z[i])*(n-i+1) );
        ans += (n-i+1);
    }
    cout << ans;
    return 0;
}