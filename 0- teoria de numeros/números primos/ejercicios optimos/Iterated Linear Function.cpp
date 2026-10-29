#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define F first
#define S second
#define pb push_back
#define lg2(x) 31-__builtin_clz(x)
#define lg(x,b) log(b)/log(x)

const int M=1e9+7;
int t,n,a,b,x,ans;

int sum(int x, int y){
    return (x+y)%M;
}

int mul(int x, int y){
    return (x*y)%M;
}

int qp(int x, int y){
    if(!y)return 1;
    int z=qp(x,y/2);
    z=mul(z,z);
    if(y%2)z=mul(z,x);
    return z;
}

int32_t main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

cin>>t;
while(t--){
    cin>>a>>b>>n>>x;
    if(a==1){n=n%M; cout<<sum(x,mul(n,b))<<"\n"; continue;}
    ans=sum(qp(a,n)+M,-1);
    ans=mul(ans,b);
    ans=mul(ans,qp(sum(a+M,-1),M-2));
    ans=sum(ans,mul(qp(a,n),x));
    cout<<ans<<"\n";
}

return 0;
}