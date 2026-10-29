#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define endl '\n'
#define int long long
using namespace std;
int lso(int n)
{
    return (n&(-n));
}
const int MOD=1e4;
struct fenwick
{
    int n;
    vector<int> tree;
    fenwick(int _n):n(_n),tree(n+1,0){}
    int query(int r)
    {
        //cout<<"started"<<endl;
        int res=0;
        //cout<<"r:"<<r;
        for(;r>0;r-=lso(r))
        {res+=tree[r];/*cout<<res<<endl;*/}
        //cout<<" returned "<<res<<endl;
        return res;
    }
    void update(int i,int v)
    {
        if(i<1||i>n)
        return;
        v%=MOD;
        for(;i<=n;i+=lso(i))
        {tree[i]+=v;/*cout<<i<<" "<<(tree[i]+v)<<endl;*/}
        //cout<<"endedquery"<<endl;
    }
    int rangequery(int l,int r)
    {
        return (query(r)-query(l-1))%MOD;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    int n,u,q;
    cin>>n>>u>>q;
    fenwick tree(n);
    int o=q+u;
    while(o--)
    {
        int t;
        cin>>t;
        int id,k;
        cin>>id>>k;
        //cout<<k*2<<" k"<<endl;
        if(t==1)
        {
            tree.update(id-1,k);
            tree.update(id+1,k);
            tree.update(id,k*2);
        }else
        cout<<tree.rangequery(id,k)<<endl;
        /*for (int i = 1; i <= n; i++)
        {
            cout<<tree.rangequery(i,i)<<" ";
        }cout<<endl;*/
    }
    return 0;
}