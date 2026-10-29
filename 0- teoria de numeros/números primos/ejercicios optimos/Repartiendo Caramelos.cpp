#include<bits/stdc++.h>
/**zagaro**/
#define MOD 1000000007 //1e9 + 7
#define pi acos(-1)
#define wl while
#define str string
#define ENDL "\n"
#define sal ' '
typedef long long ll;
typedef bool bl;
typedef char car;
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll x, n, l, r, m, may=0, L, R, M, v, t, s=0, p, div, rest, sum=0, rango;
    cin>>x>>n;
    vector<ll> vec(n+1);
    for(int i=1;i<=n;i++)cin>>vec[i];
    sort(vec.begin(), vec.end());
    for(t=n-1;t>=0;t--){
        s += (n-t)*(vec[t+1]-vec[t]);
        if(s == x)break;
        else if(s > x){
            s -= (n-t)*(vec[t+1]-vec[t]);
            t++;
            break;
        }
    }
    p = vec[t];
    x -= s;
    rango = n-t+1;
    if(x >= rango){
        div = x/rango;
        x -= (rango*div);
        p -= div;
    }
    for(int i=0;i<t;i++)sum+= (vec[i]*vec[i]);
    for(int i=1;i<=x;i++)sum+=((p-1)*(p-1));
    rango-=x;
    for(int i=1;i<=rango;i++)sum+=(p*p);
    cout<<sum<<ENDL;
    return 0;
}