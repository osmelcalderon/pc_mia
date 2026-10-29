#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

using ll = long long;
using PI = pair<ll, ll>;
using PII = pair<PI, ll>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;

    int n = s.size();
    vector<int> f(27);
    for(int i = 0; i < n; i++){
        f[s[i] - 'a' + 1]++;
    }
    int mi = 1e9+7;
    for(int i = 1; i <= 26; i++){
        if(f[i] == 0){
            continue;
        }
        mi = min(mi, f[i]);
        f[i] = 0;
    }
    string sb;
    for(int i = 0; i < s.size()/2; i++){
        f[s[i] - 'a' + 1]++;
        sb.push_back(s[i]);
        int ip = i + 1;
        if(n % ip != 0){
            continue;
        }
        else if(n / ip > mi){
            continue;
        }
        int cnt = 1;
        for(int j = ip; j < s.size(); j+=ip){
            vector<int> ff(27);
            for(int t = j; t < j + ip; t++){
                ff[s[t] - 'a' + 1]++;
            }
            int c = 0;
            for(int t = 1; t <= 26; t++){
                if(ff[t] == f[t]){
                    c++;
                }
                else{
                    break;
                }
            }
            if(c == 26){
                cnt++;
            }
            else{
                break;
            }
        }
        if(cnt == n / ip){
            cout << sb;
            return 0;
        }
    }
    cout << -1;

}