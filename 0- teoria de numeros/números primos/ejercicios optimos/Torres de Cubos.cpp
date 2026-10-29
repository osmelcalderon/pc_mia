#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#define int long long
#define endl "\n"
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define oo 1000000000000
#define vpii vector<pii>
#define vii vector<vi>
#define fs first
#define sd second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int h[10]={},hi=0;

int check(string s){
    int x=0,y=s.size()-1,cont=0,p=0;
    while(x<=y){
        cont+=abs((s[x]-'0')-(s[y]-'0'));
        p=max(p,max((s[x]-'0'),(s[y]-'0')));
        x++;y--;
    }
    h[p]++;
    //cerr<<p<<" : "<<h[p]<<endl;
    hi=max(hi,p);
    //cerr<<h[hi]<<endl;
    return cont;
}

int32_t main() {
    fast
    int ans[5]={0,0,0,0,0},n,v;
    cin>>n>>v;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int aux=check(s);
        ans[1]=h[hi];
        ans[2]+=(!aux);
        ans[3]+=aux;
        
    }
    if(v==4){
        cout<<hi<<" "<<ans[1]<<endl<<ans[2]<<endl<<ans[3];
        return 0;
    }
    if(v==1){
        cout<<hi<<" "<<ans[1];return 0;
    }
    cout<<ans[v];
    return 0;
}