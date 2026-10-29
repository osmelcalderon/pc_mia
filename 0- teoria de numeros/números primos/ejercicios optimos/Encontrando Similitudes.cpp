#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>

#define srt(v) sort(all(v))
#define rev(v) reverse(all(v))
#define all(v) (v).begin(), (v).end()
#define dbg(x) cout << #x ": " << x << endl;

#define lft 2*p
#define rgt 2*p+1
#define mdl (l+r)/2
#define p push
#define f first
#define s second
#define pb push_back
#define MAX 1000000

vector<int> divis;

void d(int N){

    for(int i=1; i*i<=N; i++){
        if(N%i==0){
            divis.pb(i);
            if(i!=1)divis.pb(N/i);
        }
    }
    sort(all(divis));
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string s; cin >> s;

    d(N);

    string p,p2;
    bool flag;
    vector<int> res;
    for(int i=0; i<divis.size(); i++){
        p=s.substr(0,divis[i]);
        flag=true;
        for(int j=divis[i]; j<N; j+=divis[i]){
            p2=s.substr(j,divis[i]);
            if(p!=p2){
                flag=false;
                break;
            }
        }
        if(flag)res.pb(divis[i]);
    }
    cout << res.size() << "\n";
    for(auto x:res)cout << x << " ";

    return 0;
}