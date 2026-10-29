#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a.begin(),a.end());
    int tot=n*(n-1)/2,s=0,c=1;
    for(int i=1; i<n; i++) {
        if(a[i]==a[i-1])c++;
        else {
            s+=c*(c-1)/2;
            c=1;
        }
    }
    s+=c*(c-1)/2;
    cout<<tot-s<<"\n";
    return 0;
}