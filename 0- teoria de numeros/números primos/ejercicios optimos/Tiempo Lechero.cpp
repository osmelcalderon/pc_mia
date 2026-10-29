#include<bits/stdc++.h>
using namespace std;
#define dd long double
#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<ll,ll>
#define pdd pair<dd,dd>
#define fst first
#define snd second

const int talla=2e5;
const double pi=acos(-1.0);
const double EPS=1e-15;
const int inf=1e9;

struct intervalo{
   int l;
   int r;
   int costo;
   bool operator<(intervalo x){
      return (this->r)<x.r;
   }
};

void solve(){
   int n,m,R;
   cin>>n>>m>>R;
   vector<intervalo>v;
   for(int i=1;i<=m;i++){
      int l,r,costo;
      cin>>l>>r>>costo;
      v.pb({l,r,costo});
   }
   sort(v.begin(),v.end());

   vector<int>dp(m,0);
   int ans=0;
   for(int i=0;i<m;i++){
      int maxi=0;
      for(int j=0;j<i;j++){
         if(v[j].r<=v[i].l-R){
            maxi=max(maxi,dp[j]);
         }
      }
      dp[i]=maxi+v[i].costo;
      ans=max(ans,dp[i]);
   }

   cout<<ans;






}

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   cout.setf(ios::fixed);cout.precision(12);
   solve();

   return 0;
}