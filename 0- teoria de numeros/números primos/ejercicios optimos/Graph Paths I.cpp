#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
vector<vector<ll>> P(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> c(a.size(),vector<ll>(a.size(),0));
    ll n=a.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                c[j][k]=(c[j][k]+a[j][i]*b[i][k])%1000000007;
            }
        }
    }
    return c;
}
vector<vector<ll>> mpow(vector<vector<ll>> a, ll b)
{
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        return mpow(P(a,a),b/2);
    }
    else
    {
        return P(mpow(P(a,a),b/2),a);
    }
 
}
int32_t main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>cad(n+3,vector<ll>(n+3));
    for(int i=0; i<m; i++)
    {
        ll a,b;
        cin>>a>>b;
        cad[a][b]++;
    }
    
    cad=mpow(cad,k);/*
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<cad[i][j]<<" ";
        cout<<"\n";
    }*/
    cout<<cad[1][n];
    return 0;
}