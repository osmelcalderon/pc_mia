#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int32_t main(){
    fast
     int n,k;
     cin>>n>>k;
     string s;
     cin>>s;
     vc<char> v;
      int r=k;
      for(char c : s){
        while(!v.empty()&&r>0&&v.back()<c){
            v.pop_back();
            r--;
        }
        v.push_back(c);
      }
      while(r>0){
        v.pop_back();
        r--;
      }
      for(char c:v){
        cout<<c;
      }
   return 0;
}