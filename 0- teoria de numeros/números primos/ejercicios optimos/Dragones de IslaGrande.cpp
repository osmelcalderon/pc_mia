#include <bits/stdc++.h>
#define int long long

using namespace std;

int Dmax[1000];
vector<int> MAX(1000);
int ans = -1;

void dfs(int v, vector<vector<pair<int, int>>> & G, vector<bool> & vis)  {
  vis[v] = 1;
  ans = max(ans, Dmax[v]);
  for(auto x : G[v])  {
    int u = x.first;
    int w = x.second;
    if(!vis[u] && Dmax[1] >= w)
      dfs(u, G, vis);
  }
}

vector<int> D(1000, (int)2e18);

void dikjstra(vector<vector<pair<int, int>>> & G)  {
  D[1] = 0;
  MAX[1] = 1;
  set<pair<int, pair<int, int>>> se;
  se.insert({0, {1, 1}});
  while(se.size())   {
    pair<int, pair<int, int>> aux = *se.begin();
    se.erase(se.begin());
    int dist = aux.first;
    int d = aux.second.first;
    int v = aux.second.second;
    if(Dmax[v] > Dmax[d])  {
      se.insert({dist, {v, v}});
      MAX[v] = v;
    }
    for(auto x : G[v])  {
      int u = x.first, w = x.second;
      if(Dmax[MAX[u]] < Dmax[d] && w <= Dmax[d])  {
        D[u] = min(D[u], dist + w);
        se.insert({dist + w, {d, u}});
        MAX[u] = d;
      }
      if(D[u] > dist + w && Dmax[d] >= w)  {
        D[u] = dist + w;
        se.insert({D[u], {d, u}});
      }
    }
  }
}

signed main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  //ifstream fin; fin.open("b.txt");

  int T;
  cin >> T;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)  {
    cin >> Dmax[i];
    MAX[i] = i;
  }
  vector<vector<pair<int, int>>> G(n + 2);
  while(m--)  {
    int x, y, w;
    cin >> x >> y >> w;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  if(T == 1)  {
    vector<bool> vis(n + 2, 0);
    dfs(1, G, vis);
    cout << ans << '\n';
  }
  else  {
    dikjstra(G);
    cout << D[n] << '\n';
  }

  return 0;
}