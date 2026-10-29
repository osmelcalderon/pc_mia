#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;

int par[maxn][__lg(maxn) + 1], lv[maxn];

int query(int x, int y){
    int ans = 0;
    
    if(x == y) return 0;

    if(lv[x] == 0) return -1;
    
    for(int i = __lg(lv[x]); i >= 0; i--){
        if(par[x][i] != -1 and par[x][i] <= y){
            ans += (1<<i);
            x = par[x][i];
        }
    }

    if(x == y) return ans;
    if(par[x][0] != -1 and par[x][0] >= y) ans++;
    else ans = -1;

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int n, k;
    cin >> n >> k;
    
    assert(n >= 2 and n <= 200'000);
    assert(k >= 1 and k <= 200'000);

    vector<int> a(n);
    for(auto &i:a){
        cin >> i;
        assert(i >= 1 and i <= 200'000);
    }
    for(int i = 0; i + 1 < n; i++){
        assert(a[i] < a[i + 1]);
    }

    int l = n-1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; (1<<j) <= n; j++)
            par[i][j] = -1;
        while(l > i and a[l] - a[i] > k)
            l--;
        if(l == i)
            continue;
        par[i][0] = l;
        lv[i] = lv[l] + 1;
        for(int j = 1; (1<<j) <= lv[i]; j++){
            if(par[i][j-1] != -1){
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }

    int q;
    cin >> q;

    assert(q >= 1 and q <= 200'000);

    while(q--){
        int x, y;
        cin >> x >> y;
        assert(x <= y and x >= 1 and y <= n);
        x--, y--;
        cout << query(x, y) << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}