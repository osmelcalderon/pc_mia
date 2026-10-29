#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define MOD 1000000007
#define mod(x) ((x+MOD)%MOD)
#define bebesita priority_queue<int,vector<int>,greater<int>>
#define monaco ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wow signed
#define Maic main
#define s second
#define f first
#define pii pair<int,int>
#define mk(a,b,c) make_tuple(a,b,c)
#define nodo tuple<int,int,int>
 
using namespace std;
wow Maic(){
	monaco
	int n,iz=0,res=0;
	cin>>n;
    vector<int>arr(n);
    set<int>ven;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        if(!ven.count(arr[i]))ven.insert(arr[i]);
        else{
            while(arr[iz]!=arr[i]){
                ven.erase(arr[iz]);
                iz++;
            }
            iz++;
            ven.insert(arr[i]);  
        }
        res=max(res,(int)ven.size());
    }
    cout<<res;
	return 0;
}