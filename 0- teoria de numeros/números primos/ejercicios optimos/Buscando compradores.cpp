#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
#define vi vector<int>
#define rsz resize
using namespace std;
const int MAXN=1e5+5;
vector<int>a(MAXN,0);
struct SegmentTree{
    int n;
    vector<int>st;
    SegmentTree(int N){
        n=N;
        st.rsz(4*n+1);
    }
    void build(int u,int l,int r){
        if(l==r){
            st[u]=a[l];
            return;
        }
        int m=(l+r)/2;
        build(2*u,l,m);
        build(2*u+1,m+1,r);
        st[u]=max(st[2*u],st[2*u+1]);
    }
    int querie(int u,int l,int r,int ql,int qr,int val){
        if(l>qr||r<ql)
            return -1;
        if(st[u]<val)
            return -1;
        if(l==r)
            return l;
        int m=(l+r)/2;
        int p=querie(2*u,l,m,ql,qr,val),t2;
        if(p!=-1)
            return p;
        return querie(2*u+1,m+1,r,ql,qr,val);
    }
};
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;cin>>N;
    for(int i =1;i<=N;++i)
        cin>>a[i];

    SegmentTree buy(N+1);
    buy.build(1,1,N);

    int q;cin>>q;
    while(q--){
        int val,p1,p2;cin>>val>>p1>>p2;
        cout<<buy.querie(1,1,N,p1,p2,val)<<'\n';
    }
    return 0;
}