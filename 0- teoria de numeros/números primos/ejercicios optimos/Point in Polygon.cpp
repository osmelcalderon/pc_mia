#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define point complex<ll>
#define MAX 500005
#define X real()
#define Y imag()
point a[MAX],p,e;
ll n,m,a1,a2,a3;
ll asb=1e9+10;
ll cross(point x,point y){
    return max(-1LL,min(1LL,(conj(x)*y).Y));
}
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a1>>a2;
        a[i]={a1,a2};
    }a[n]=a[0];
    p={-asb,-asb};
    for(int i=0;i<m;i++){
        cin>>a1>>a2;
        e={a1,a2};
        p={a1-1,-asb};
        ll r=0;
        for(int j=0;j<n;j++){
            if(max(a[j].X,a[j+1].X)<p.X || max(a[j].Y,a[j+1].Y)<p.Y || e.X<min(a[j].X,a[j+1].X) || e.Y<min(a[j].Y,a[j+1].Y))continue;
            ll h=cross(a[j+1]-a[j],e-a[j]),h1=cross(a[j+1]-a[j],p-a[j]);
            ll h2=cross(e-p,a[j+1]-p),h3=cross(e-p,a[j]-p);
            if(h*h1<=0 && h2*h3<=0){
                if(h==0){r=-1;break;}
                r++;
            }
        }
        if(r==-1){cout<<"BOUNDARY\n";continue;}
        if(r%2==1)cout<<"INSIDE\n";
        else      cout<<"OUTSIDE\n";
    }
return 0;
}
/*
*/