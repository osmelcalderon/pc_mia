#include<bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(2);
#pragma GCC optimize("Ofast")
using namespace std;
typedef int ll;
main()
{
    optimizar_io
    ll n;
    cin>>n;
    ll cad[n]={ };
    ll ac[n]={ };
    cad[0]=1;
    ac[0]=1;
    for(int i=1; i<n; i++)
    {
        ll temp;
        cin>>temp;
        temp=i-temp-1;
        if(temp>=0) temp=ac[temp];
        else temp=0;
        cad[i]+=abs(1000000007+ac[i-1]-temp)%1000000007;
        cad[i]%=1000000007;
        /*
        for(int j=max((ll)0,i-temp); j<i; j++)
        {
            cad[i]+=cad[j];
            cad[i]=cad[i]%1000000007;
        }*/
        ac[i]=cad[i]+ac[i-1];
        ac[i]%=1000000007;
    }
    cout<<cad[n-1];
}