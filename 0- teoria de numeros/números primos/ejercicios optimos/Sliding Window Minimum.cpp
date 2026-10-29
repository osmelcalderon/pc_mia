#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using point=complex<ll>;
using pll=pair<ll,ll>;
ll n,x,a,b,c,k;
ll const oo=1e10;
int main(){
    cin>>n>>k>>x>>a>>b>>c;
    stack<ll> pref,suf;
    pref.push(oo);
    ll r=0,s=oo;
    for(int i=1;i<=n;i++){
        suf.push(x);
        s=min(s,suf.top());
        if(i>=k){
            r^=min(s,pref.top());
            if(pref.size()==1){
                while(!suf.empty()){
                    pref.push(min(pref.top(),suf.top()));
                    suf.pop();    
                }
                s=oo;
            }
            pref.pop();
        }
        x=(a*x+b)%c;
    }
    cout<<r;
return 0;
}