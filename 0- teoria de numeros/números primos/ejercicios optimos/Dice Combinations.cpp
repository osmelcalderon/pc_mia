#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define int long long
#define vll vector<int>
#define MOD 1000000007
using namespace std;
signed main()
{
    int x;
    cin>>x;
    vll v(x+10,0);
    v[0]=1;
    for(int i=0;i<=x;i++)
    {
        for(int j=1;j<7;j++)
        {
            if(j+i<=x)
            {    
                v[i+j]+=v[i];
                v[i+j]=v[i+j]%MOD;
            }    
        }
    }
    cout<<v[x];
    return 0;
}