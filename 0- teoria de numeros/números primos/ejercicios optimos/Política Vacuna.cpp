#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>
#include <vector>
#include <functional>
#include <random>
using namespace std;

#define endl '\n'
#define ll long long 
#define db long double
#define pb push_back
#define fs first 
#define sd second 
#define unvisited long(-1e9 + 7)
#define Eps double(1e-9)
#define Mod %= (long(1e9 + 7));

const ll Max = 3e5 + 7,
		 Inf = 1e9 + 7;

vector <vector<int>> v, s;  

struct LowerCommonAncestor
{
	vector <int> L, E, H; int idx, n; 

	void dfs(int cur, int depth, int parent)
	{
		H[cur] = idx; 
		E[idx] = cur;
		L[idx++] = depth; 

		for (auto& u : v[cur]) if(u != parent)
		{
			dfs(u, depth + 1, cur); 
			E[idx] = cur; 
			L[idx++] = depth; 
		}
	}

	/*vector <vector<int>> Spt;

	void RMQ()
	{
		Spt.assign(2 * n, vector <int>(log2(2 * n) + 1, 0)); 

		for (int i = 0; i < 2 * n; i++)
			Spt[i][0] = i; 

		for (int j = 1; (1 << j) <= 2 * n; j++)
		{
			for (int i = 0; i + (1 << j) < 2 * n; i++)
				if (L[Spt[i][j - 1]] < L[Spt[i + (1 << (j - 1))][j - 1]])
					Spt[i][j] = Spt[i][j - 1];
				else
					Spt[i][j] = Spt[i + (1 << (j - 1))][j - 1]; 
		}
	}

	int Query(int i, int j)
	{
		int k = (int)floor(log((double)j - i + 1) / log(2.0)); 
		if (L[Spt[i][k]] <= L[Spt[j - (1 << k) + 1][k]])
			return Spt[i][k];
		else
			return Spt[j - (1 << k) + 1][k]; 
	}*/

	vector <int> tree; int l;

	int query(int node, int x, int y, int s, int e)
	{
		if (x > e || y < s) return 0;

		if (s >= x && e <= y)
			return tree[node];

		int middle = (s + e) / 2;

		int id1 = query(node * 2, x, y, s, middle), 
			id2 = query(node * 2 + 1, x, y, middle + 1, e);

		return (L[id1] > L[id2] ? id2 : id1); 
	}

	int query(int i, int j) { return query(1, i, j, 1, l); }

	void Segment_tree(int n)
	{
		for (l = 1; l < n; l = (l << 1)); 
		tree.assign(2 * l, 0); L[0] = Inf; 

		for (int i = 0; i < n; i++)
			tree[i + l] = i + 1;

		for (int i = l - 1; i > 0; i--)
		{
			tree[i] = (L[tree[2 * i]] > L[tree[2 * i + 1]] ?
				tree[2 * i + 1] : tree[2 * i]); 
		}
	}

	int Ancestor(int i, int j)
	{
		int a = min(H[i], H[j]), b = max(H[i], H[j]);
		return E[query(a, b)];
	}

	int Dist(int x)
	{
		return L[H[x]]; 
	}

	int sol(int i, int j)
	{
		int g = Ancestor(i, j);
		return (Dist(i) + Dist(j) - (2 * Dist(g)));
	}

	LowerCommonAncestor(int lenght, int x)
	{
		n = lenght; idx = 0;
		
		L.assign(2 * n, -1);
		E.assign(2 * n, -1);
		H.assign(2 * n, -1);

		dfs(x, 0, 0); Segment_tree(2*n-2); //RMQ(); 
	}
};

void print(int ans) { cout << ans << endl; }

void solve()
{
	int n, k; cin >> n >> k; 

	v.assign(n + 1, vector <int>());
	s.assign(k + 1, vector <int>());

	for(int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b; 
		s[a].push_back(i + 1); 
		v[b].push_back(i + 1); 
	}

	LowerCommonAncestor lca(n + 7, 0); 

	for (int i = 1; i <= k; i++)
	{
		int node = -1, depth = -1; 

		for (auto& u : s[i])if (lca.Dist(u) > depth)
		{
			node = u; 
			depth = lca.Dist(u); 
		}

		int ans = 0; 

		for (auto& u : s[i])
			ans = max(ans, lca.sol(u, node)); 

		print(ans); 
	}
}

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	int Q = 1; //cin >> Q; 

	while (Q--)
	{
		solve(); 
	}

	return 0; 
}