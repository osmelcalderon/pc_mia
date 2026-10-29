#include <bits/stdc++.h>
#define F first
#define S second
#define sts(v) stable_sort(v.BE, v.E)
#define BE begin()
#define E end()


using namespace std;
using ll = long long;

struct ABI{
    vector<int> abi;

    ABI(int n){
        abi.resize(n + 1);
    }
    void updt(int i){
        for(; i < (int)abi.size(); i += i & -i)
            abi[i]++;
    }
    int query(int i){
        int ans = 0;
        for(; i > 0; i -= i & -i)
            ans += abi[i];
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> v(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    ABI abi(1e5);
    int ans[n + 1];
    for(int i = n; i > 0; i--){
        ans[i] = (n - i - abi.query(v[i]));
        abi.updt(v[i]);
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}