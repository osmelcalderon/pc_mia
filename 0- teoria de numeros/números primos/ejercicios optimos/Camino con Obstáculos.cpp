#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
    ll x,y,d,c;
    friend bool operator < (st a, st b)
    {
        return a.c<b.c;
    }
};
ll n;
vector<vector<char>> cad;
ll cmc()
{
    ll v[4][n+1][n+1];
    priority_queue<st>q;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            v[0][i][j]=-1;
            v[1][i][j]=-1;
            v[2][i][j]=-1;
            v[3][i][j]=-1;
            if(cad[i][j]=='A')
            {
                q.push({i,j,0,0});
                q.push({i,j,1,0});
                q.push({i,j,2,0});
                q.push({i,j,3,0});
            }
        }
    while(!q.empty())
    {
        st a=q.top();q.pop();
        if(a.x>=0&&a.x<n&&a.y>=0&&a.y<n&&cad[a.x][a.y]!='x'&&v[a.d][a.x][a.y]==-1)
        {
            v[a.d][a.x][a.y]=-a.c;
            if(cad[a.x][a.y]=='B')
                return -a.c;
            st b=a;
            if(a.d==0)
                b.x++;
            if(a.d==1)
                b.y--;
            if(a.d==2)
                b.x--;
            if(a.d==3)
                b.y++;
            q.push(b);
            q.push({a.x,a.y,(a.d-1+4)%4,a.c-1});
            q.push({a.x,a.y,(a.d+1+4)%4,a.c-1});
        }
    }
}
main()
{
    cin>>n;
    cad.resize(n+1);
    for(int i=0; i<n; i++)
    {
        cad[i].resize(n+1);
        for(int j=0; j<n; j++)
            cin>>cad[i][j];
    }

    cout<<cmc();
}