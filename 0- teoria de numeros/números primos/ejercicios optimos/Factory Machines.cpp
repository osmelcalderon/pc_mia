#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define vc vector
int mod=1e9+7;

int32_t main() {
    fast
    int n,k;
    cin>>n>>k;
    vc<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    int l=0,r=1e18;
    while(l<r){
      int m=l+(r-l) / 2;
      int p=0;
      for(int i=0;i<n;i++){
        p+=m/v[i];
        if(p>=k){
          break;
        }
      }
      if(p>=k){
        r=m;
      }else{
        l=m+1;
      }
    }
    cout<<l;
    return 0;
}