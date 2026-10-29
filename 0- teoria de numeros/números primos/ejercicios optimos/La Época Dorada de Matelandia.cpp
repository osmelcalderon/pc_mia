///Carlos Rolando Morell Rodriguez
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
/// Macros
#define int long long
#define ll long long
#define sz size
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define fst first
#define scd second
#define pb push_back
#define fl '\n'
#define el endl
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define IOS ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
/// Functions
#define random() __builtin_ia32_rdtsc()
#define lgx(x,n) ( log(n) / log(x) )
#define lg2(x) 31-__builtin_clz(x)
#define lg2ll(x) 63-__builtin_clzll(x)
#define pi acos(-1)
/// Red-Black Tree Template
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
//#define less_than(n) order_of_key(n)
//#define en_pos(n) find_by_order(n)
/// Prime numbers  173,179,311,331,737,1009,2011,2027,3079,4001,100003
///===================================================================
///Quick Pow
//ull qpow(ull x, ull e){
//	if(!e) return 1;
//	if(e&1) return (qpow(x , e-1)*x) % MOD;
//	return qpow((x*x) % MOD , e>>1) % MOD;
//}
///Criba de factores primos
//void Criba(int n){
//    fact[2]=2;
//    for(int i=2; i<n; i+=2) fact[i]=2;
//    for(int i=3; i<n; i+=2){
//        if(fact[i]==inf){
//            fact[i]=i;
//            for(int j=i*i; j<n; j+=i+i) fact[j]=min(fact[j], i);
//        }
//    }
//}
///Sacar los factores primos en O(factores)
//fill(fact, fact+mxn, inf);
//Criba(mxn);
//while(num!=1){
//    if(fact[num]==di) vec[vec.sz()-1].scd++;
//    else vec.push_back({fact[num], 1});
//    di=fact[num];
//    num/=fact[num];
//}
//for(auto i:vec){
//    sum+=(qpow(i.fst, i.scd+1)-1)/(i.fst-1);
//}
using namespace std;

int num, x, y, l, r, ans;
vector<int>a, b, psol;

void Solve(){
    cin>>x>>y>>l>>r;

    num=1;
    do{
        a.pb(num);
        num*=x;
    }
    while(num<=r);

    num=1;
    do{
        b.pb(num);
        num*=y;
    }
    while(num<=r);

    for(int i=0; i<a.sz(); i++){
        for(int j=0; j<b.sz(); j++){
            if(a[i]+b[j]>=l&&a[i]+b[j]<=r) psol.pb(a[i]+b[j]);
        }
    }

    psol.pb(l-1); psol.pb(r+1);

    sort(psol.begin(), psol.end());

    ans=0;
    for(int i=0; i<psol.sz()-1; i++) ans=max(ans, psol[i+1]-psol[i]-1);

    cout<<ans;
}

int32_t main(){

    IOS;

    cout.setf(ios::fixed);
    cout.precision(0);

    Solve();

return 0;
}