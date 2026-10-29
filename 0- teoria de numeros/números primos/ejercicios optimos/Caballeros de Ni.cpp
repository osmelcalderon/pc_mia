#include<bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout.setf(ios::fixed);cout.precision(0);
#pragma GCC optimize("Ofast")
using namespace std;
typedef int  ll;
ll cad[1001][1001];
ll v1[1001][1001];
ll v2[1001][1001];
ll n,m;
struct st
{
    ll cost,x,y;
    friend bool operator < (const st& a,const st& b)
    {
        return (a.cost<b.cost);
    };
};
void cmc1(ll asd1,ll asd2)
{
    queue<st> q;
    st asdf;
    asdf.x=asd1;
    asdf.y=asd2;
    asdf.cost=0;
    q.push(asdf);
    while(!q.empty())
    {
        st temp=q.front();q.pop();
        //cout<<1;
        if(v1[temp.x][temp.y]==1000000000&&temp.x>=0&&temp.y>=0&&temp.x<n&&temp.y<m&&cad[temp.x][temp.y]!=1&&cad[temp.x][temp.y]!=3)
        {
            v1[temp.x][temp.y]=-temp.cost;
            st t2=temp;
            t2.x++;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
            t2=temp;
            t2.x--;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
            t2=temp;
            t2.y++;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
            t2=temp;
            t2.y--;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
        }
    }
}
void cmc2(ll asd1,ll asd2)
{
    queue<st> q;
    st asdf;
    asdf.x=asd1;
    asdf.y=asd2;
    asdf.cost=0;
    q.push(asdf);
    while(!q.empty())
    {
        st temp=q.front();q.pop();
        //cout<<2;
        if(v2[temp.x][temp.y]==1000000000&&temp.x>=0&&temp.y>=0&&temp.x<n&&temp.y<m&&cad[temp.x][temp.y]!=1)
        {
            v2[temp.x][temp.y]=-temp.cost;
            st t2=temp;
            t2.x++;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
            t2=temp;
            t2.x--;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
            t2=temp;
            t2.y++;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
            t2=temp;
            t2.y--;
            if(t2.x>=0&&t2.y>=0&&t2.x<n&&t2.y<m)
            {
                t2.cost--;
                q.push(t2);
            }
        }
    }
}
main()
{
    optimizar_io
    cin>>n>>m;
    swap(n,m);
    //cout<<n<<m;
    ll pbx=0;
    ll pby=0;
    ll pnx=0;
    ll pny=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            v1[i][j]=1000000000;
            v2[i][j]=1000000000;
            cin>>cad[i][j];
            if(cad[i][j]==3)
            {
                pnx=i;
                pny=j;
            }
            if(cad[i][j]==2)
            {
                pbx=i;
                pby=j;
            }
        }
    cmc1(pbx,pby);
    cmc2(pnx,pny);
    ll bs=1000000000;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //cout<<v1[i][j]<<" "<<v2[i][j]<<"\t";
            if(cad[i][j]==4)
            {
                bs=min(bs,v1[i][j]+v2[i][j]);
            }

        }
        //cout<<"\n";
    }
    cout<<bs;
}