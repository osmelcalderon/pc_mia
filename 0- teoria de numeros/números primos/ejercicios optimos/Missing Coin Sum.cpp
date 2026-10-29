#include<bits/stdc++.h>
#define F first
#define S second
#define MAX 500005
#define oo 1e18
#define mod 1000000007
#define fast_in ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
using namespace std;
typedef long long ll;
#define pll pair<ll , ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
 
ll n,t,a[MAX];
int main(){
    fast_in
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);ll s=0;
    for(int i=0;i<n;i++){
        if(s<a[i]-1)break;
        s+=a[i];
    }cout<<s+1;
return 0;
}