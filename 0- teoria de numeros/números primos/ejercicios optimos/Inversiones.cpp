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

class cosa{
public:
    vector<int> ft;

    cosa(){};
    cosa(int N){
        ft.assign(N+5,0);
    };

    int query(int i){
        int res=0;
        while(i){
            res+=ft[i];
            i-=(i&-i);
        }
        return res;
    }
    void update(int i, int v){
        while(i<ft.size()){
            ft[i]+=v;
            i+=(i&-i);
        }
    }
};

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    while(T--){

        int N;cin >> N;
        cosa ft(N), ft2(N);

        pii ls[N+1];
        for(int i=1; i<=N; i++){
            cin >> ls[i].f;
            ls[i].s=i;
        }
        sort(ls+1,ls+N+1);
        reverse(ls+1,ls+N+1);

        int inv[N+1];
        memset(inv,0,sizeof(inv));
        for(int i=1; i<=N; i++){
            inv[i]+=ft.query(ls[i].s);
            ft.update(ls[i].s,1);
        }
        int res=0;
        for(int i=1; i<=N; i++){
            res+=ft2.query(ls[i].s);
            ft2.update(ls[i].s,inv[i]);
        }
        cout << res << "\n";
    }

    return 0;
}