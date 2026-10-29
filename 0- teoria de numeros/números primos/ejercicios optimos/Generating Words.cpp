#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
const int mx = 1e9;

int32_t main() {
    fast
    int l, v;
    cin >> l >> v;
    vc<char> vo(v);
    for (int i = 0; i < v; ++i) cin >> vo[i];
    sort(vo.begin(), vo.end());
    vc<char> con = {
    'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
    for (char c1 : con) {
        if (l == 2) {
            for (char v1 : vo) cout <<c1<<v1<<"\n";
        } else if (l == 3) {
            for (char v1 : vo)
                for (char c2 : con)
                    cout << c1<<v1<<c2<<"\n";
        } else if (l == 4) {
            for (char v1 : vo)
                for (char c2 : con)
                    for (char v2 : vo)
                        cout <<c1<<v1<<c2<<v2<<"\n";
        } else if (l == 5) {
            for (char v1 : vo)
                for (char c2 : con)
                    for (char v2 : vo)
                        for (char c3 : con)
                            cout <<c1<<v1<<c2<<v2<<c3<<"\n";
        }
    }
    return 0;
}