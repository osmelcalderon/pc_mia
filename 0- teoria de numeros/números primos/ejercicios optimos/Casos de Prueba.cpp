///Carlos Rolando Morell Rodriguez
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
/// Macros
#define int unsigned long long
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
const int inf=1e18+10, mxn=1e5+10, base1=311, base2=331, base3=173;

int res, ans, delay, p1[mxn], p2[mxn], p3[mxn], h1[3][mxn], h2[3][mxn], h3[3][mxn];
vector<pair<int, string>>s(3);

int hsh1(int x, int xend, int pos){
    return h1[s[pos].fst][xend]-h1[s[pos].fst][x]*p1[xend-x];
}

int hsh2(int x, int xend, int pos){
    return h2[s[pos].fst][xend]-h2[s[pos].fst][x]*p2[xend-x];
}

int hsh3(int x, int xend, int pos){
    return h3[s[pos].fst][xend]-h3[s[pos].fst][x]*p3[xend-x];
}

bool in(int pos1, int pos2){
    int x=0, xend=s[pos2].scd.sz();
    while(xend<=s[pos1].scd.sz()){
        if(hsh1(x, xend, pos1)==h1[s[pos2].fst][s[pos2].scd.sz()]&&hsh2(x, xend, pos1)==h2[s[pos2].fst][s[pos2].scd.sz()]&&hsh3(x, xend, pos1)==h3[s[pos2].fst][s[pos2].scd.sz()]) return true;
        x++; xend++;
    }
    return false;
}

int Prefix(int pos1, int pos2){
    int mx=0;
    for(int i=1; i<=min(s[pos1].scd.sz(), s[pos2].scd.sz()); i++){
        int tam=s[pos1].scd.sz();
        if(hsh1(tam-i, tam, pos1)==h1[s[pos2].fst][i]&&hsh2(tam-i, tam, pos1)==h2[s[pos2].fst][i]&&hsh3(tam-i, tam, pos1)==h3[s[pos2].fst][i]) mx=i;
    }
    return mx;
}

void Solve(){

    p1[0]=1;
    for(int i=1; i<mxn; i++) p1[i]=p1[i-1]*base1;
    p2[0]=1;
    for(int i=1; i<mxn; i++) p2[i]=p2[i-1]*base2;
    p3[0]=1;
    for(int i=1; i<mxn; i++) p3[i]=p3[i-1]*base3;

    ans=inf;
    for(int i=0; i<3; i++){
        cin>>s[i].scd;
        s[i].fst=i;
        h1[i][0]=0;
        for(int j=1; j<=s[i].scd.sz(); j++) h1[i][j]=h1[i][j-1]*base1+(s[i].scd[j-1]-'a'+1);
        h2[i][0]=0;
        for(int j=1; j<=s[i].scd.sz(); j++) h2[i][j]=h2[i][j-1]*base2+(s[i].scd[j-1]-'a'+1);
        h3[i][0]=0;
        for(int j=1; j<=s[i].scd.sz(); j++) h3[i][j]=h3[i][j-1]*base3+(s[i].scd[j-1]-'a'+1);
    }

    do{
        res=s[0].scd.sz();
        delay=1;
        for(int i=1; i<3; i++){
            if(in(i-delay, i)){ delay++; continue; }
            else{ res+=s[i].scd.sz()-Prefix(i-delay, i); delay=1; }
        }
        ans=min(ans, res);
    }
    while(next_permutation(s.begin(), s.end()));

    cout<<ans;
}

int32_t main(){

//    freopen("45.in", "r", stdin);
//    freopen("45.out", "w", stdout);

    IOS;

    cout.setf(ios::fixed);
    cout.precision(0);

	Solve();

return 0;
}