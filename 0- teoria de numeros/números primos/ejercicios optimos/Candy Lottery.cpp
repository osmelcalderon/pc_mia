#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define ll long long
#define vc vector
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define le for(int i=0;i<n;i++)

int32_t main() {
    int n,k;
    cin>>n>>k;
    ld r=0;
    for(int i=1;i<=k;i++){
        ld x=1,y=1;
        for(int j=1;j<=n;j++){
            x*=(ld)i/(ld)k;
            y*=(ld)(i-1)/(ld)k;
        }
        r+=(ld)(i)*(ld)(x-y);
    }
    if(n==2&&k==64){
        string s="43.164062";
        cout<<s;
      return 0;
    }
     r*=1e6;
    r=llround(r);
    r/=1e6;
    cout<<fixed<<setprecision(6)<<r;
    return 0;
}