#include <bits/stdc++.h>
using namespace std;

#define vll vector<long long>
#define pb push_back
#define pqu priority_queue
#define qu queue
#define int long long
#define vec vector
#define endl "\n"
#define iss cin.tie(0); ios_base::sync_with_stdio(0); cout.tie(0);
#define plr pair<long long, long long>
#define f first
#define s second
#pragma GCC optimize("Ofast")

const int mod=1000000007;
vll graph[101],ans(101,1);
bool past[101][4]={};
//97
int32_t main() {iss;
    int n;
    vec<pair<string,string> >cos;
    string a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cos.pb({a,b});
    }
    vll ans(26,0);
    for(int i=0;i<n;i++){
        a=cos[i].f;b=cos[i].s;
        vll na(26,0),nb(26,0);
        for(char i:a){
            na[i-97]++;
        }
        for(char i:b){
            nb[i-97]++;
        }
        for(int i=0;i<=25;i++){
            ans[i]+=max(na[i],nb[i]);
        }
    }
    for(int i:ans){
        cout<<i<<endl;
    }

    return 0;
}