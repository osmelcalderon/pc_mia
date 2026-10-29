/*  
    Maded by Juan_alejandro 
    at (UTC-05:00) 15:33
    6/8/2025
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <memory>
#define endl '\n'
#define int long long
#define srt(x) sort(x.begin(),x.end())

using namespace std;
using namespace __gnu_pbds;
struct com{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)const{
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
};
#define red_black tree<pair<int,int>,null_type,com,rb_tree_tag,tree_order_statistics_node_update>
int lso(int &n)
{
    return (n&(-n));
}
struct fenwick{
    int n;
    vector<int> tree;
    fenwick(int _n):n(_n),tree(n+1,0){}
    int query(int r)
    {
        int res=0;
        for(;r>0;r-=lso(r))
        res+=tree[r];
        return res;
    }
    void update(int i,int v)
    {
        for(;i<=n;i+=lso(i))
        tree[i]+=v;
    }
    int rangequery(int l,int r)
    {
        return query(r)-query(l-1);
    }
};
struct segment{
    int n;
    vector<int> tree;
    segment(int _n):n(_n),tree(2*n){
        for (int i = n; i < 2*n; i++)
        {
            cin>>tree[i];
        }
        for (int i = n-1; i > 0; i--)
        {
            tree[i]=tree[i<<1]+tree[i<<1|1];
        }
    }
    void update(int i,int v)
    {
        i+=n;
        i--;
        tree[i]=v;
        for(i>>=1;i>0;i>>=1)
        tree[i]=tree[i<<1]+tree[i<<1|1];
    }
    int query(int l,int r)
    {
        r++;
        l--;
        r--;
        int res=0;
        for(r+=n,l+=n;l<r;r>>=1,l>>=1)
        {
            if(l&1)res+=tree[l++];
            if(r&1)res+=tree[--r];
        }
        return res;
    }
};
struct dsu{
    int n;
    vector<int> p;
    vector<int> sz;
    dsu(int _n):n(_n),p(n+1),sz(n+1,1){
        for (int i = 1; i <= n; i++)
        {
            p[i]=i;
        }
        
    }
    int find(int n)
    {
        if(p[n]!=n)
        {
            p[n]=find(p[n]);
        }
        return p[n];
    }
    bool unite(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a==b)return false;
        if(sz[a]<sz[b])swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        return true;
    }
};
struct sparse_table{
    int n;
    vector<int> logs;
    vector<vector<int>> x;
    sparse_table(int _n):n(_n),logs(n+1){
        logs[1]=0;
        for(int i=2;i<=n;i++)
        logs[i]=logs[i/2]+1;
        int K=logs[n];
        x.assign(K+1,vector<int> (n+1));
        for (int i = 1; i <= n; i++)
        {
            cin>>x[0][i];
        }
        for(int k=1;k<=K;k++)
        for(int i=1;i+(1LL<<k)<=n+1;i++)
        x[k][i]=min(x[k-1][i],x[k-1][i+(1LL<<(k-1))]);
        
    }
    int query(int l,int r)
    {
        int j=logs[r-l+1];
        return min(x[j][l],x[j][r-(1LL<<j)+1]);
    }
};
struct Trie{
    bool end;
    vector<unique_ptr<Trie>> letras;
    Trie():end(false),letras(26){}
    void insert(const string &s)
    {
        Trie* nodo=this;
        for(const auto &c:s)
        {
            int idx=c-'a';
            if(!nodo->letras[idx])
            nodo->letras[idx]=make_unique<Trie>();
            nodo=nodo->letras[idx].get();
        }
        nodo->end=true;
    }
    bool exist(const string &s)
    {
        Trie* nodo=this;
        for(const auto &c:s)
        {
            int idx=c-'a';
            if(!nodo->letras[idx])return false;
            nodo=nodo->letras[idx].get();
        }
        return nodo->end;
    }
    bool prefijo(const string &s)
    {
        Trie* nodo=this;
        for(const auto &c:s)
        {
            int idx=c-'a';
            if(!nodo->letras[idx])return false;
            nodo=nodo->letras[idx].get();
        }
        return true;
    }
};
void dfs(int pos,vector<int> x[],vector<bool> &vis)
{
    vis[pos]=true;
    for(const auto &e:x[pos])
    {
        if(!vis[e])
        {
            dfs(e,x,vis);
        }
    }
}
const int MOD=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    int n;
    cin>>n;
    vector<pair<string,string>> con(n);
    string ex;
    for(int i=0;i<n;i++)
    {
        cin>>con[i].first>>ex>>ex>>ex>>ex>>con[i].second;
        //cout<<con[i].first<<" "<<con[i].second<<endl;
    }
    vector<string> o={"Beatrice","Sue","Belinda","Bessie","Betsy","Blue","Bella","Buttercup"};
    srt(o);
    do{
        bool es=true;
        for (int i = 0; i < o.size()&&es; i++)
        {
            for (int j = 0; j < n&&es; j++)
            {
                if(con[j].first==o[i])
                {
                    bool cum=false;
                    if(i-1>=0)
                    {
                        if(o[i-1]==con[j].second)
                        cum=true;
                    }
                    if(i+1<o.size())
                    {
                        if(o[i+1]==con[j].second)
                        cum=true;
                    }
                    if(!cum)
                    {
                        es=false;
                        break;
                    }
                }
            }
            
        }
        if(es)
        {
            for (int i = 0; i < o.size(); i++)
            {
                cout<<o[i]<<endl;
            }
            return 0;
        }
    }while(next_permutation(o.begin(),o.end()));
    cout<<-1<<endl;
    return 0;
}
// Finished at 16:02