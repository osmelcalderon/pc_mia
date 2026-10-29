#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segment_tree{
    vector<ll> st;
    ll n;
    ll query(ll a, ll b){
        ll ans=1e15;
        for(a+=n, b+=n; a<=b; a/=2, b/=2){
            if(a%2==1)ans=min(st[a++],ans);
            if(b%2==0)ans=min(st[b--],ans);
        }    
        return ans;
    }
    void update(ll a, ll b){
        a+=n;
        st[a]=b;
        for(a/=2; a; a/=2){
            st[a]=min(st[a*2],st[a*2+1]);
        }
    }
    segment_tree(ll N){
        n=(N+1);
        st.assign(n*2,1e15);
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> cad(n+1,0);
    segment_tree asd(n+10);
    asd.update(0,0);
    for(int i=1; i<=n; i++)
    {
        cin>>cad[i];
        cad[i]+=cad[i-1];
        asd.update(i,cad[i]);
    }
    ll bs=-1e17;
    for(int i=a; i<=n; i++)
    {
        bs=max(bs,cad[i]-asd.query(max(0LL,i-b),i-a));
    }
    cout<<bs;
return 0;
}