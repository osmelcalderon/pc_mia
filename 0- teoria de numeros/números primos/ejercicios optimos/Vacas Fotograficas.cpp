#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
#pragma GCC optimize("Ofast")
typedef long ll;
//#define int long long
vector< int > Fen;
int parent( int x ){return x & -x;}
int query( int x )
{
    int sum = 0;
    while(x > 0)
    {
        sum = (sum+Fen[x]);
        x -= parent( x + 1 );
    }
    return sum;
}
void update( int x, int val )
{

    while(x < Fen.size())
    {
        Fen[x] = (Fen[x]+val);
        x += parent( x + 1 );
    }
    Fen[x] += val;
    Fen[x]=Fen[x];
}
void ini(ll n)
{
    Fen.clear();
    ll temp=n+1;/*
    while(temp<=n)
    {
        temp*=2;
    }*/
    for(int i=0; i<=temp+1; i++)
        Fen.push_back(0);
}
main()
{
    optimizar_io
    //freopen("cowpic.9.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    ll n;
    cin>>n;
    ll cad[n+1];
    ll mayi[n+1];
    ll meni[n+1];// men isquierda
    ini(n+1);
    for(int i=0; i<n; i++)
    {
        cin>>cad[i+1];
        meni[cad[i+1]]=query(cad[i+1]);
        mayi[cad[i+1]]=query(n+1)-meni[cad[i+1]];
        //cout<< inv[cad[i+1]]<<" ";
        update(cad[i+1],1);
    }
    long long  cont=0;
    for(int i=1; i<=n; i++)
    {
        cont+=mayi[i];
    }
    long long temp=cont;
    for(int i=n; i>0; i--)
    {
        temp=temp-(i-1-meni[i])+mayi[i]+meni[i]-(n-i-mayi[i]);
        //         (  men der   )+ mi (inv[i)
        //cout<< temp;
        cont=min(cont,temp);
    }
    cout<< cont;
}