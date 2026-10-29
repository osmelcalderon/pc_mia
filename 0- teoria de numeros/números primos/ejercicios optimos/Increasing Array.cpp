#include<bits/stdc++.h>
using namespace std;

int main()
#define int long long
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,cont=0;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++) {
        cin>>ar[i];
    }
    for(int i=1; i<n; i++) {
        if(ar[i]<ar[i-1]) {
            cont+=ar[i-1]-ar[i];
            ar[i]=ar[i-1];
        }
    }
        cout<< cont<<endl;
    
    return 0;
}