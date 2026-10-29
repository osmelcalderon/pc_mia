#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+2;
int s[MAXN];
int fact[MAXN];
bool mk[MAXN];
vector<int> p[MAXN];

    void Criba(){
        for(int i = 1; i < MAXN; ++i)
            fact[i] = MAXN;

        for(int i = 2; i < MAXN; i += 2)
            fact[i] = 2;
        for(int i = 3; i < MAXN; i += 2)
            if(fact[i] == MAXN){
                fact[i] = i;
                for(long long j = (long long)i*i; j < MAXN; j += i+i)
                    fact[j] = min(fact[j] , i);
            }
    }

main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    Criba();

    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];

        int x = a[i], last = -1;
        vector<int> v;
        while(x != 1){
            if(fact[x] == last);
            else v.push_back(fact[x]);
            last = fact[x];
            x/=fact[x];
        }
        for(auto y : v)
            p[i].push_back(y);
    }

    int ans = 0, cnt = 0;
    while(q--){
        int x;
        cin >> x;
        int T = p[x].size(), c = 0;
        
        if(mk[x]){
            for(int mask = 0; mask < (1<<T); ++mask){
                int M = 1;
                for(int i = 0; i < T; ++i)
                    if(mask & (1<<i)){
                        M *= p[x][i];
                    }
                s[M]--;
            }
            for(int mask = 0; mask < (1<<T); ++mask){
                int M = 1;
                for(int i = 0; i < T; ++i)
                    if(mask & (1<<i)){
                        M *= p[x][i];
                    }
                if(__builtin_popcount(mask) & 1)
                    c += s[M];
                else 
                    c -= s[M];
            }
            ans += c;
            mk[x] = false;
        }
        else{
            for(int mask = 0; mask < (1<<T); ++mask){
                int M = 1;
                for(int i = 0; i < T; ++i)
                    if(mask & (1<<i)){
                        M *= p[x][i];
                    }
                if(__builtin_popcount(mask) & 1)
                    c += s[M];
                else 
                    c -= s[M];
            }
            ans -= c;

            for(int mask = 0; mask < (1<<T); ++mask){
                int M = 1;
                for(int i = 0; i < T; ++i)
                    if(mask & (1<<i)){
                        M *= p[x][i];
                    }
                s[M]++;
            }
            mk[x] = true;
        }
        cout << ans << '\n';
    }

}
