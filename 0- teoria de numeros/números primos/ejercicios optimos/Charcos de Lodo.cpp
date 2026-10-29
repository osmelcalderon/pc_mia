#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define x first
#define y second
#define TU_MADRE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define M 502
using namespace std;

int k,c;
ii p;

const int mr[] = {-1, 1, 0, 0};
const int mc[] = {0, 0, -1, 1};

bool m[M+501][M+501];

bool valido(ii u)
{
    return(u.x>=0 && u.y >=0 && u.x <= 1000 && u.y <= 1000 && m[u.x][u.y]);
}

void dfs(ii u, int d)
{
    cout << u.x<<" "<<u.y<<endl;
    m[u.x][u.y]=0;
    if(u.x == p.x && u.y == p.y)
    {
        cout << d << endl;
        return;
    }
    for(int i=0;i<4;i++)
    {
        ii v = {u.x+mr[i],u.y+mc[i]};
        if(valido(v))
            dfs(v, d+1);
    }
}
void bfs(ii u)
{
    //cout << u.x<<" "<<u.y<<endl;
    queue<pair<ii,int>> q;
    m[u.x][u.y]=0;
    q.push({u,0});
    while(!q.empty())
    {
        u = q.front().x;
        int d=q.front().y;
        if(u.x == p.x && u.y == p.y)
        {
            cout << d << endl;
            return;
        }
        q.pop();
        for(int i=0;i<4;i++)
        {
            ii v = {u.x+mr[i],u.y+mc[i]};
            if(valido(v))
            {
                m[v.x][v.y]=0;
                c++;
                q.push({v,d+1});
                //cout << v.x << " "<< v.y<< " "<<d+1<<endl;
            }
        }
    }
}

int32_t main()
{
    TU_MADRE
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            m[i][j]=1;
        }
    }
    cin >> p.x >> p.y >> k;
    p.x+=500;
    p.y+=500;
    for(int i=0;i<k;i++)
    {
        ii c;
        cin >> c.x >> c.y;
        c.x+=500;
        c.y+=500;

        m[c.x][c.y] = 0;
    }
    bfs({500,500});

    return 0;
}