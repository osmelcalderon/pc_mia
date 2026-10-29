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
ll fun(str a, str b){
    ll r=0;
    vector<int> vec(10,0);
    vector<int> vic(10,0);
    for(int i=0;i<a.size();i++)vec[a[i]-'0']++;
    for(int i=0;i<b.size();i++)vic[b[i]-'0']++;
    for(int i=9;i>=0;i--){
        for(int j=1;j<=min(vec[i], vic[i]);j++){
            r*=10;
            r+=i;
        }
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, p, c=0, r=0;
    str a, b, s;
    cin>>p;
    p--;
    if(p){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            r = max(r, fun(a, b));
        }
        cout<<r<<ENDL;
    }
    else {
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            r = fun(a, b);
            if(r != 0)c++;
        }
        cout<<c<<ENDL;
    }
    return 0;
}