#include <bits/stdc++.h>
#define int long long
#define Fast ios_base::sync_with_stdio();cin.tie(0);cout.tie(0)
#define f first
#define s second

using namespace std;
const int mod = 1e9+7;

int qp(int base , int expo){
    if(expo == 0)return 1;
    int mi = qp(base , expo/2);
    if(expo% 2 == 0)return mi* mi % mod;
    else
        return mi*mi* base % mod;
}

int32_t main(){
Fast;
    int n;
    cin >> n;
    cout <<qp(2 , n)%mod;

    return 0;
}