#include <bits/stdc++.h>
#define int unsigned long long
#define endl '\n'
#pragma GCC optimize ("Ofast")
using namespace std;
const int INF = 1000000000000000000ULL;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(0);
    cout<<fixed;
    //cout<<flush;
    int n,m,w;
    cin>>n>>m>>w;
    vector<vector<int>> x(n+1,vector<int> (n+1,INF));
    for (int i = 1; i <= n; i++)
    {
        x[i][i]=0;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        x[a][b]=min(c,x[a][b]);
        x[b][a]=min(c,x[b][a]);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(x[i][k]!=INF&&x[k][j]!=INF&&x[i][j]>x[i][k]+x[k][j])
                {
                    x[i][j]=x[i][k]+x[k][j];
                }
            }
            
        }
        
    }
    
    while(w--)
    {
        int a,b;
        cin>>a>>b;
        if(x[a][b]==INF)
        cout<<-1<<endl;else cout<<x[a][b]<<endl;
    }
    return 0;
}