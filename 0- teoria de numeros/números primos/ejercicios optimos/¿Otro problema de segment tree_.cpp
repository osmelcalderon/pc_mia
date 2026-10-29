#include <bits/stdc++.h>
using namespace std;
#define vc vector
#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
const int mod = 1e9+9;
const int mx=1e6;
#define f first
#define se second
#define pb push_back

int32_t main(){
 fast
 int n;
 cin>>n;
 vc<int> v(mx+2,0);
 for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v[a]++;
    v[b+1]--;
 }
 int c=0,m=0;
 for(int i=1;i<=mx;i++){
    c+=v[i];
    if(c>m){
        m=c;
    }
 }
 cout<<m;
    return 0;
}