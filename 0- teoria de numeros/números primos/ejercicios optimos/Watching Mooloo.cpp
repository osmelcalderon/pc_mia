#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define fs first
#define sd second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int mod=1e9+7,MAX=5e5+5,oo=1e18;

int32_t main(){
    fast
    int n,m=0,ans=0,a,sum=0;
    cin>>n>>m;
    sum+=m+1;
    int ant;
    for(int i=0;i<n;i++){
        cin>>a;
        if(i==0){ant=a;continue;}
        if((a-ant)>m){sum+=m+1;}
        if((a-ant)<=m){sum+=a-ant;}
        ant=a;
    }
    cout<<sum<<endl;
    return 0;
}