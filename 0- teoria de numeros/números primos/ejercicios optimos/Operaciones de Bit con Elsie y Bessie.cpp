#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp,tem;
int main(){
    int n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int a[n+5],b[n+5];
    set<int> r;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        mp[b[i]]++;
    }
    for(int i=0;i<n;i++){
        tem=mp;
        int d=a[0]^b[i],c=1;
        for(int j=0;j<n;j++){
            tem[a[j]^d]--;
            if(tem[a[j]^d]<0){
                c=0;break;
            }
        }
        if(c==1)r.insert(d);
    }
    cout<<r.size()<<"\n";
    for(auto u : r)cout<<u<<"\n";
return 0;
}