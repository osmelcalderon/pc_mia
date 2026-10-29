#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define point complex<ll>
#define MAX 500005
#define F first
#define S second
pair<ll,ll> a[MAX],p,e;
ll n,m,a1,a2,a3;
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll area=0;
    for(int i=0;i<n;i++){
        cin>>a[i].F>>a[i].S;
    }
    sort(a,a+n);
    set<pair<ll,ll>> s;
    s.insert({a[0].S,a[0].F});
    ll p=0;
    ll d=(1LL<<62);
    ll r=-1;
    for(int i=1;i<n;i++){
        while(a[i].F-a[p].F>=d){
            s.erase({a[p].S,a[p].F});
            p++;
        }
        auto u=s.lower_bound({a[i].S-d,0});
        auto u2=s.lower_bound({a[i].S+d+1,0});
        while(u!=u2){
            if(r==-1)r=abs((*u).S-a[i].F)*abs((*u).S-a[i].F)+abs((*u).F-a[i].S)*abs((*u).F-a[i].S);
            r=min(r,abs((*u).S-a[i].F)*abs((*u).S-a[i].F)+abs((*u).F-a[i].S)*abs((*u).F-a[i].S));
            d=sqrtl(r)+1;
            u++;
        }
        s.insert({a[i].S,a[i].F});
    }
    cout<<r;
return 0;
}