#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

const int MAXN = 2e5+2;
int ok[MAXN];

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, K, C;
    cin >> N >> K >> C;
    
    string s;
    cin >> s;

    int cnt = 0;
    ok[N] = 0; 
    for(int i = N-1; i >= 0; --i){
        if(s[i] == 'o' && cnt == 0){
            ok[i] = ok[i+1] + 1;
            cnt = C;
            continue;
        }
        ok[i] = ok[i+1];
        cnt = max(cnt-1 , 0);
    }

    // for(int i = 0; i < N; ++i)
    //     cerr << ok[i] << ' ';

    int k = 0;
    for(int i = 0; i < N; ++i){
        if(k == K) break;
        if(s[i] == 'o'){
            bool unk = false;
            for(int j = i+1; j < N; ++j)
                if(s[j] == 'o'){
                    if(ok[j] >= K - k)
                        unk = true;
                    else 
                        unk = false;
                    break;
                }
            if(!unk)
                ans.push_back(i+1);

            i += C;
            k++;
        }
    }

    for(auto x : ans)
        cout << x << '\n';

}