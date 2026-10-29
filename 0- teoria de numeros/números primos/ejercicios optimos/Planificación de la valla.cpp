#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0; i<(n); i++)
#define y second
#define x first
#define fastcode ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e5;
const ll M = 1e5;
ll n, u, v, ans = 1e15, m;
struct Component{
    ll minx = 1e15, miny=1e15, maxx=-1e15, maxy=-1e15, p;
};
struct DSU{
    vector<Component> parent;
    DSU(int sz)
    {
        parent = vector<Component>(sz);
        rep(i,sz) parent[i].p = i;
    }
    Component find_parent(ll a)
    {
        if(parent[a].p==a) return parent[a];
        return parent[a] = find_parent(parent[a].p);
    }
    bool join(ll a, ll b)
    {
        Component pa = find_parent(a), pb = find_parent(b);
        if(pa.p==pb.p) return false;
        parent[pb.p].maxx = max(pb.maxx, pa.maxx);
        parent[pb.p].maxy = max(pb.maxy, pa.maxy);
        parent[pb.p].miny = min(pb.miny, pa.miny);
        parent[pb.p].minx = min(pb.minx, pa.minx);
        parent[pa.p].p = pb.p;
        return true;
    }
};
ll solve(const Component& a)
{
    ll w = abs(a.maxy-a.miny), f = abs(a.maxx-a.minx);
    if(a.maxx == a.minx) return w;
    if(a.maxy == a.miny) return f;
    return (w+f)*2;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    DSU d(n);
    for(int i=0; i<n; i++)
    {
        cin>>u>>v;
        d.parent[i].minx = d.parent[i].maxx = u;
        d.parent[i].maxy = d.parent[i].miny = v;
    }
    while(m--)
    {
        cin>>u>>v;
        u--; v--;
        d.join(u, v);
    }
    for(int i=0; i<n; i++)
    {
        if(d.find_parent(i).p == i)
            ans = min(solve(d.parent[i]), ans);
    }
    cout<<ans<<"\n";
}