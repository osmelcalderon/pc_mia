#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vc vector
#define int long long


int32_t main(){
     fast;
    int n;cin>>n;
    vc<int> v(n);
     for(int i=0;i<n;i++)cin>>v[i];
    vc<int> r(n,0);
     for(int i=0;i<n;i++){
     int j=i-1;
    while(j>=0&&v[j]>=v[i])j=r[j];
     r[i]=j;
   }
      for(int i=0;i<n;i++){
      cout<<(r[i]+1)<<(i==n-1?'\n':' ');
      }
     return 0;
}