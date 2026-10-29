/*
	Hello World!
	Minimal Template by x93
*/

#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#ifdef __cplusplus
#include <vector>
#include <queue>
#include <map>
#include <set>
#endif

#define inf ULLONG_MAX
#define mod 1000000007
#define int  long long
#define uint unsigned int
#define algorithm signed main()
using namespace std;

void dfs(vector<vector<char>>& stat, vector<vector<char>>& mat, uint N, uint M, uint x, uint y)
{
	for (int l = -(N > 0); l < 2; l++)
	{
		for (int r = -(M > 0); r < 2; r++)
		{
			if ((l == 0 && l == r) || y + r >= N || x + l >= M) continue;
			if (mat[y + r][x + l] == 'W' && !stat[y + r][x + l])
			{
				stat[y + r][x + l] = 1;
				dfs(stat, mat, N, M, x + l, y + r);
			}
		}
	}
}

algorithm
{
	uint N, Q;
	scanf("%llu%llu", &N, &Q);
	vector<vector<pair<uint, uint>>> adj(N);

	for (uint x = 0; x < N - 1; x++)
	{
		uint a, b, w;
		scanf("%llu%llu%llu", &a, &b, &w);
		adj[a - 1].push_back(make_pair(b - 1, w));
		adj[b - 1].push_back(make_pair(a - 1, w));
	}

	uint ma = 0, nod = 0;
	uint depth[N], parent[N], cost[N];

	for (uint x = 0; x < N; x++)
	{
		depth[x] = 0;
		if (ma < adj[x].size())
			ma = adj[x].size(), nod = x;
	}

	queue<uint> dfs;
	dfs.push(nod);
	depth[nod] = 1;
	parent[nod] = nod;
	cost[nod] = 0;

	while (!dfs.empty())
	{
		uint n = dfs.front();
		dfs.pop();

		for (auto p: adj[n])
		{
			if (depth[p.first] == 0)
			{
				depth[p.first] = depth[n] + 1,
					parent[p.first] = n, cost[p.first] = p.second;
				dfs.push(p.first);
			}
		}
	}

	while (Q--)
	{
		uint p1, p2;
		scanf("%llu%llu", &p1, &p2);
		p1--, p2--;

		uint C = 0;
		for (uint x = depth[p1]; x > depth[p2]; x--)
			C += cost[p1], p1 = parent[p1];
		for (uint x = depth[p2]; x > depth[p1]; x--)
			C += cost[p2], p2 = parent[p2];

		while (p1 != p2)
		{
			C += cost[p1] + cost[p2],
				p1 = parent[p1], p2 = parent[p2];
		} printf("%llu\n", C);
	}
}