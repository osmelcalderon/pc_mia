#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb(x) push_back(x)
const ll mod=1e9+7;
ll q, n, k, a[200001], dp[3001][2], c[20];
string s;
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    dp[0][0]=1;
    for(int i=1; i<=n; i++){
        c[2]=0;
        for(int t=0; t<i; t++)dp[t][1]=0;
        for(int t=0; t<=n; t++){
            c[2]+=a[t];
            c[1]=dp[t][0];
            dp[t][0]=dp[c[2]%i][1];
            dp[c[2]%i][1]=(dp[c[2]%i][1]+c[1])%mod;
        }
        c[3]+=dp[n][0];
    }
    cout << c[3]%mod;
    return 0;
}