#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll cont=0;
    for(ll i=0; i<63; i++)
    {
        cont+=(n+1)/(1LL<<(i+1))*(1LL<<i);
        cont+=max((n+1)%(1LL<<(i+1))-(1LL<<i),0LL);
        //cout<<cont;
    }
    cout<<cont;
    return 0;
}