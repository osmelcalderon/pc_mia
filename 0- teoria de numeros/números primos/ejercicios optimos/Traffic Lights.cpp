#include<bits/stdc++.h>
#define F first
#define S second 
using namespace std;
typedef long long ll;
#define MAX 500005
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
const ll oo=1e18;
ll n,k,b[MAX];
pll a[MAX],l[MAX];
int main(){
    cin>>k>>n;
    a[0]={0,-1};
    for(int i=1;i<=n;i++){
        cin>>a[i].F;a[i].S=i;
    }
    a[n+1]={k,n+1};
    sort(a,a+n+2);ll mx=0;
    l[0].S=1;
    for(int i=1;i<=n+1;i++){
       // cout<<a[i].F<<" "<<a[i].S<<"\n";
        if(i<=n)b[a[i].S]=i;
        mx=max(mx,abs(a[i].F-a[i-1].F));
        l[i].F=i-1;
        l[i].S=min((ll)i+1LL,n+1);
    }
    vll r={mx};
    for(int i=n;i>1;i--){
     //   cout<<a[l[b[i]].F].F<<" "<<a[l[b[i]].S].F<<"\n";
        r.push_back(max(r.back(),abs(a[l[b[i]].F].F-a[l[b[i]].S].F)));
        l[l[b[i]].F].S=l[b[i]].S;
        l[l[b[i]].S].F=l[b[i]].F;
    }
    reverse(r.begin(),r.end());
    for(auto u : r)cout<<u<<" ";
 
return 0;
}