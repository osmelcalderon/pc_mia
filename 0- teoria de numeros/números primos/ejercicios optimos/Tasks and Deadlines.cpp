#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vc vector
#define int long long
#define f first 
#define s second 

int32_t main(){
     fast;
      int n;
      cin>>n;
      vc<pair<int,int>> v(n);
      for(int i=0;i<n;i++){
        cin>>v[i].f>>v[i].s;
      }
      sort(v.begin(),v.end(), [](auto &a,auto &b) {
        return a.f<b.f;
    });
      int d=0,sum=0,s1=0;
      for(auto &x:v){
        d +=x.f;
        sum +=d;
        s1 +=x.s;
      }
      cout<<s1-sum;
     return 0;
}