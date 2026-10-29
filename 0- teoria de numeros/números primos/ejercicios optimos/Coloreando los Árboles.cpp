#include<bits/stdc++.h>
using namespace std;

#define MAX 110
#define MOD 1e9 + 7
#define MI 1e9
#define MLL 1e18

#define pii pair<int,int>
#define pib pair<pii,int>
#define pic pair<int,pii>
#define pid pair<pii,pii>
#define f first
#define s second
#define mkp makepair

#define for(qq,q,N)  for(int qq = (q);qq < (N);qq++)
#define ifor(qq,q,N) for(int qq = (q);qq > (N);qq--)

#define lft p * 2
#define rgt (p * 2) + 1
#define mdl (l + r) / 2

#define str string
#define ll long long
#define sz size()
#define pb push_back
#define endl "\n"

ll N,M,K;
ll l[MAX];
vector<int> ks;
ll ms[MAX];
ll cs[MAX][MAX];
ll mem[MAX][MAX][MAX];

int f(int p,int k,int c){
    if(p == N + 1){
        if(k == K)
            return 0;
        else
            return MI * 2;
    }
    if(mem[p][k][c])
        return mem[p][k][c];
    if(l[p])
        return mem[p][k][c] = f(p + 1,k + (l[p] != c),l[p]);
    ll o = MI * 2;
    for(qq,1,M + 1)
        o = min(o,f(p + 1,k + (qq != c),qq) + cs[p][qq]);
    return mem[p][k][c] = o;
}
void solve(){
    ll m = 0,b = 0;
    cin >> N >> M >> K;
    ks.pb(m);
    for(qq,1,N + 1)
        cin >> l[qq];
    for(qq,1,N + 1)
        for(ww,1,M + 1)
            cin >> cs[qq][ww];
    if(f(1,0,0) >= MI * 2)
        cout << -1 << endl;
    else
        cout << f(1,0,0) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int T;
    //cin >> T;
    //while(T--)
        solve();
    return 0;
}