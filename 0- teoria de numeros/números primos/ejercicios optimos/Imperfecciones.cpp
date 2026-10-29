#include<bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
#pragma GCC optimize("Ofast")
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define INF 10000000
#define EPS 1e-9
#define pi (double)(3.14159265358979323846)
#define RAD (double)(pi/180.0)
#define ALL(x) x.begin(),x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c))-(c).begin())
#define pqgii priority_queue<ii,vii,greater<ii> >
#define pqg priority_queue<int,vector<int>,greater<int> >
int a,b,c[INF+1],sum[INF+1];
ll ans=0;
void sieve(int x){
  for(int i=2;i<=x;i++){
    c[i]=i;
    sum[i]=0;
  }
  c[0]=c[1]=-1;sum[1]=1;
  for(ll i=2;i*i<=x;i++)
    if(c[i]==i)
      for(ll j=i+i;j<=x;j+=i)
        c[j]=i;
}
int factor(int x,int y){
  if(sum[x])return sum[x];
  return sum[x]=x+factor(x/y,y);
}
int fp(int x){
  if(sum[x])return sum[x];
  ull y=x/c[x],a=c[x];
  while(c[x]==c[y]){
    y=y/c[y];
    a*=c[x];
  }
  return sum[x]=factor(a,c[x])*fp(y);
}
int main(){
optimizar_io
cin>>a>>b;
sieve(b);
for(int i=a;i<=b;i++){
  sum[i]=fp(i);
  ans+=abs((i<<1)-sum[i]);
}
cout<<ans;

return 0;}