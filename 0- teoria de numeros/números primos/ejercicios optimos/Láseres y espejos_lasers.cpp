#include<bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
#pragma GCC optimize("Ofast")
using namespace std;
typedef int ll;
ll n;
vector<ll>  v[100002];
vector<ll>  h[100002];
ll cad[2][100001+2];
ll vi[100001+2]={ };
ll dfs(ll ini)
{
    queue<ll> q;
    vi[ini]=1;
    q.push(ini);
    while(!q.empty())
    {
        ll a=q.front();
        q.pop();
        ll posx=cad[0][a];
        ll posy=cad[1][a];
        ll c1=0;
        for(int i=0; i<v[posx].size()&&c1<2; i++)
        {
            ll t1=v[posx][i];
            if(vi[t1]==0)
            {
                q.push(t1);
                vi[t1]=vi[a]+1;
            }
            else c1++;
        }
        c1=0;
        for(int i=0; i<h[posy].size()&&c1<2; i++)
        {
            ll t1=h[posy][i];
            if(vi[t1]==0)
            {
                q.push(t1);
                vi[t1]=vi[a]+1;
            }
            else c1++;
        }
        if(vi[1]!=0)return vi[1];
    }
    return vi[1];
}
main()
{
    optimizar_io
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    cin>>n;
    unordered_map<ll,ll>px;
    unordered_map<ll,ll>py;
    ll cx=1;
    ll cy=1;
    for(int i=0; i<n+2; i++)
    {
        ll a,b;
        cin>>a>>b;
        if(px[a]==0)
        {
            px[a]=cx;
            v[cx].push_back(i);
            cx++;
        }
        else
        {
            v[px[a]].push_back(i);
        }
        if(py[b]==0)
        {
            py[b]=cy;
            h[cy].push_back(i);
            cy++;
        }
        else
        {
            h[py[b]].push_back(i);
        }
        cad[0][i]=px[a];
        cad[1][i]=py[b];
    }
    ll sol=dfs(0);
    if(sol==0)cout<<-1;
    else
        cout<<sol-2;
}
