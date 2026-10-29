#include <bits/stdc++.h>
using namespace std;

    void count_sort(vector<int> &p, vector<int> &c) {
        int N = p.size();
        vector<int> cnt(N);
        for(auto x : c)
            cnt[x]++;

        vector<int> pos(N);
        pos[0] = 0;
        for(int i = 1; i < N; ++i)
            pos[i] = pos[i-1] + cnt[i-1];

        vector<int> new_p(N);
        for(auto x : p) {
            int i = c[x];
            new_p[pos[i]] = x;
            pos[i]++;
        }
        p = new_p;
    }

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int s[N+1];
    for(int i = 0; i < N; ++i)
        cin >> s[i];

    s[N] = -1;
    N++;

    vector<pair<char,int>> a(N);
    for(int i = 0; i < N; ++i)
        a[i] = {s[i] , i};
    sort(a.begin(), a.end());

    vector<int> c(N), p(N);
    for(int i = 0; i < N; ++i)
        p[i] = a[i].second;

    c[p[0]] = 0;
    for(int i = 1; i < N; ++i)
        if(a[i].first == a[i-1].first)
            c[p[i]] = c[p[i-1]];
        else
            c[p[i]] = c[p[i-1]] + 1;

    int k = 0;
    while((1<<k) < N) {

        for(int i = 0; i < N; ++i)
            p[i] = (p[i] - (1<<k) + N) % N;

        count_sort(p , c);

        vector<int> new_c(N);
        new_c[p[0]] = 0;
        for(int i = 1; i < N; ++i) {
            pair<int,int> prev = {c[p[i-1]] , c[(p[i-1] + (1<<k)) % N]};
            pair<int,int> curr = {c[p[i]] , c[(p[i] + (1<<k)) % N]};
            if(prev == curr)
                new_c[p[i]] = new_c[p[i-1]];
            else
                new_c[p[i]] = new_c[p[i-1]] + 1;
        }
        c = new_c;

        k++;
    }

    vector<int> lcp(N);
    k = 0;
    for(int i = 0; i < N-1; ++i) {
        int p_i = c[i];
        int j = p[p_i-1];
        while(s[i + k] == s[j + k]) k++;
        lcp[p_i] = k;
        k -= (k != 0);
    }


//    for(int i = 0; i < N; ++i)
//        cerr << lcp[i] << " " << p[i] << " " << s.substr(p[i], N-p[i]) << '\n';

    K--;

    vector<int> st(N*4);

    function<void(int,int,int)> build=[&](int s, int e, int node){
        if(s == e){
            st[node] = lcp[s];
            return;
        }
        int piv = (s+e)>>1;
        build(s, piv, node<<1); build(piv+1,e,(node<<1)+1);
        st[node] = min(st[node<<1] , st[(node<<1)+1]);
    };

    build(1,N-1,1);

    function<int(int,int,int,int,int)> query=[&](int s, int e, int node, int l, int r){
        if(s > r || e < l) return 1000000000;
        if(l <= s && e <= r) return st[node];
        int piv = (s+e)>>1;
        return min( query(s, piv, node<<1, l , r) , query(piv+1, e, (node<<1)+1, l, r) );
    };

    int ans = 0;
    for(int i = 1; i <= N-K; ++i)
        ans = max(ans , query(1, N-1, 1, i, i+K-1));

    cout << ans;

}

/**
30 2
5 5 6 11 4 4 2 7 7 12 6 12 3 1 1 6 5 7 9 5 2 6 11 11 3 12 9 6 9 3

*/