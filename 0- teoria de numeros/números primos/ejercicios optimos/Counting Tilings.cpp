#include<iostream>
#include<ostream>
#include<vector>
#include<string>
#include<algorithm>
#define int long long
#define MOD 1000000007
using namespace std;

// globals
int n, m;

string bits(int nu) {
    string s;
    for(int i = 0; i<n; i++){
        s.push_back( (nu&(1<<i)) ? '1' : '0' );
    }
    return s;
}

void print_dp(vector<int> &A){
    cout<<"DP: {\n";
    for(int i = 0; i<A.size(); i++){
        cout<<bits(i)<<" -> "<<A[i]<<'\n';
    }
    cout<<'\n';
}

void next_of(int state, vector<int> &out, int bld = 0, int bit = 0) {
    if(bit>=n) {
        out.emplace_back(bld);
        return;
    }

    int b = state&(1<<bit),
        bb = state&(1<<(bit+1));

    if(b!=0) {
        next_of(state, out, bld, bit+1);
    }else{
        if(bit<n-1 && bb==0) {
            next_of(state, out, bld, bit+2);
        }
        next_of(state, out, bld|(1<<bit), bit+1);
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Input
    cin>>n>>m;

    vector<vector<int>> nof(1<<n);
    for(int i = 0; i<(1<<n); i++){
        next_of(i, nof[i]);
    }

    vector<int> dp(1<<n, 0);
    dp[0] = 1;
    //print_dp(dp);

    // Solve
    while(m--){
        vector<int> ndp(1<<n, 0);
        for(int i = 0; i<(1<<n); i++){
            for(auto e: nof[i]){
                ndp[e] += dp[i];
            }
        }
        for(int i = 0; i<(1<<n); i++)
            ndp[i] %= MOD;
        //print_dp(ndp);
        swap(dp, ndp);
    }

    cout<<dp[0];
}