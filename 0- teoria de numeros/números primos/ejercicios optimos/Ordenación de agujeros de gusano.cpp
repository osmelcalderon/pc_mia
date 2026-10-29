#include<bits/stdc++.h>
using namespace std;

int dsu[100005], tam[100005];

void built(int n){
    for(int i = 0; i <= n; i++){
        dsu[i] = i;
        tam[i] = 1;
    }
}
int get(int x){
    return dsu[x] == x ? x : dsu[x] = get(dsu[x]);
}
void unnion(int x, int y){
    x = get(x);
    y = get(y);
    if(x != y){
        if(tam[x] < tam[y]) swap(x, y);
        dsu[y] = x;
        tam[x] += tam[y];
    }
}
bool comp(int x, int y){
    return get(x) == get(y);
}
struct info{
    int x, y, w;
    bool operator<(info a){
        return w > a.w;
    }
    void read(){
        cin >> x >> y >> w;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, pos = 0;
    cin >> n >> m;
    int p[n+1];
    for(int i = 1; i <= n; i++) cin >> p[i];

    info a[m];
    for(int i = 0; i < m; i++) a[i].read();
    sort(a, a+m);
    built(n);

    for(int i = 1; i <= n; i++){
        while(!comp(i, p[i])){
            unnion(a[pos].x, a[pos].y);
            pos++;
        }
    }
    if(pos) cout << a[pos-1].w;
    else cout << -1;

    return 0;
}