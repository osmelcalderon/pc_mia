#include<bits/stdc++.h>
#define ll long long
#define tst(n) cout<<"tst -> "<<n<<endl
#define tst2(n, n2) cout<<"tst2 -> "<<n<<" "<<n2<<endl
#define tst3(n, n2, n3) cout<<"tst3 -> "<<n<<" "<<n2<<" "<<n3<<endl
#define f first
#define s second
using namespace std;
ll pos[100000], h[100000];
pair<ll, ll> h2[100000];
///ORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORA
ll bs(ll X, ll in, ll fn){
    while(fn-in>2){
        ll mit=(in+fn)/2;
        if(h2[mit].f<X){
            in=mit+1;
        }else{
            fn=mit;
        }
        //cout<<"siu"<<endl;
    }
    for(in; in<=fn; in++){
        if(h2[in].f>=X){
            return in;
        }
    }
    return -1;
}
///ORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORA
int main()
{
    ios_base::sync_with_stdio(0);
    ll n, m, t, x1, y1, x2, y2, c, c2, i, i1, i2, i3;
    ll dist;
    cin>>n>>dist;
    for(i=0; i<n; i++){
        cin>>pos[i]>>h[i];
        h2[i].f=h[i];
        h2[i].s=i;
    }
    sort(h2, h2+n);
    ll sol=0;
    for(i=0; i<n; i++){
        x1=h[i]*2;
        x1=bs(x1, 0, n-1);
        //cout<<"bs: "<<x1<<endl;
        if(x1==-1){
            continue;
        }
        bool b1, b2;
        b1=false;
        b2=false;
        //cout<<"i: "<<i<<endl;
        //cout<<"---------"<<endl;
        for(i1=x1; i1<n; i1++){
            if(h[i]*2>h2[i1].f){
                continue;
            }
            x1=h2[i1].s;
            //cout<<"i1: "<<i1<<endl;
            //cout<<"x1: "<<x1<<endl;
            if(abs(pos[x1]-pos[i])<=dist){
                if(pos[x1]>=pos[i]){
                    b2=true;
                }
                if(pos[x1]<=pos[i]){
                    b1=true;
                }
                if(b1&&b2){break;}
            }
        }
        if(b1&&b2){
            sol++;
        }
    }
    cout<<sol<<endl;
}