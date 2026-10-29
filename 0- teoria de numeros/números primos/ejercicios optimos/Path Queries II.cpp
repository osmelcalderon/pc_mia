#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sort undefined_function // To use stable_sort instead sort 
#define bpc __builtin_popcount
#define ull unsigned long long
#define ld double
#define ll long long
#define mp make_pair
#define F first
#define S second
 
#pragma GCC optimize("O3")
 
#ifdef LOCAL 
	#include "debug.h"
#else 
	#define dbg(...) 0
#endif
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<long long, null_type, less_equal<long long>,
    rb_tree_tag, tree_order_statistics_node_update> Tree;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll INF = 9223372036854775807LL;
const ll inf = 2147483647;
const ll MOD = 1e9 + 7; //[998244353, 1e9 + 7, 1e9 + 13]
const ld PI = acos(-1);
const ll NROOT = 800;
 
ll binpow(ll a, ll b, ll _MOD = -1) {
	if (_MOD == -1)
		_MOD = MOD;
	ll res = 1;
	for (; b; b /= 2, a *= a, a %= _MOD)
		if (b & 1) res *= a, res %= _MOD;
	return res;
}
 
void set_IO(string s) {
#ifndef LOCAL
	string in  = s +  ".in";
	string out = s + ".out";
	freopen(in.c_str(),  "r",  stdin);
	freopen(out.c_str(), "w", stdout);
#endif
}
 
bool dataOverflow(ll a, ll b) {return (log10(a) + log10(b) >= 18);}
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
ll ceil(ll a, ll b) {return (a + b - 1) / b;}
ll invmod(ll a) {return binpow(a, MOD - 2);}
 
vector<vector<int>> g;
vector<int> chain, parent, sz, depth, value, idx;
vector<vector<int>> arrs;
 
void dfs_find(int x, int prt) {
	depth[x] = depth[prt] + 1;
	parent[x] = prt;
	for (auto &y : g[x]) {
		if (y == prt)
			continue;
		dfs_find(y, x);
		sz[x] += sz[y];
	}
}
 
void dfs_assign(int x, int prt, int ch) {
	int maxSZ = 0, bigChild = -1;
	
	chain[x] = ch;
	idx[x] = arrs[ch].size();
	arrs[ch].push_back(value[x]);
 
	if (sz[x] == 1)
		return;
 
	for (auto &y : g[x]) {
		if (y == prt)
			continue;
		
		if (sz[y] > maxSZ) {
			maxSZ = sz[y];
			bigChild = y;
		}
	}
 
	for (auto &y : g[x]) {
		if (y == prt)
			continue;
 
		if (y == bigChild) 
			dfs_assign(y, x, ch);
		else 
			dfs_assign(y, x, y);
	}
}
 
class ST {
private:
	int n;
	vector<int> st, a;
 
	void build(int nod, int l, int r) {
		if (l == r) {
			st[nod] = a[l];
			return;
		}
	
		int mid = (l + r) / 2;
		build(nod * 2, l, mid);
		build(nod * 2 + 1, mid + 1, r);
		st[nod] = max(st[nod * 2], st[nod * 2 + 1]);
	}
 
	void update(int nod, int l, int r, int pos, int val) {
		if (l == r) {
			st[nod] = val;
			a[pos] = val;
			return;
		}
 
		int mid = (l + r) / 2;
 
		if (pos <= mid) 
			update(nod * 2, l, mid, pos, val);
		else 
			update(nod * 2 + 1, mid + 1, r, pos, val);
		st[nod] = max(st[nod * 2], st[nod * 2 + 1]);
	}
 
	int query(int nod, int l, int r, int L, int R) {
		if (r < L || R < l)
			return 0;
		if (L <= l && r <= R) 
			return st[nod];
 
		int mid = (l + r) / 2;
		int q1 = query(nod * 2, l, mid, L, R);
		int q2 = query(nod * 2 + 1, mid + 1, r, L, R);
 
		return max(q1, q2);
	}
 
public:
	void init(vector<int> &_a) {
		a = _a;
		n = a.size() - 1;
		if (n == 0)
			return;
		st.resize(4 * n);
		build(1, 1, n);
	}
 
	void update(int pos, int val) {
		update(1, 1, n, pos, val);
	}
 
	int query(int L, int R) {
		if (L > R)
			return 0;
		return query(1, 1, n, L, R);
	}
};
 
vector<ST> HLD; 
 
int calculate(int a, int b) {
	int res = max(value[a], value[b]);
 
	while (chain[a] != chain[b]) {
		if (depth[chain[a]] < depth[chain[b]]) 
			swap(a, b);
 
		res = max(res, HLD[chain[a]].query(1, idx[a]));
		a = parent[chain[a]];
	}
 
	if (idx[a] > idx[b])
		swap(a, b);
	res = max(res, HLD[chain[a]].query(idx[a], idx[b]));
 
	return res;
}
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int n, q;
	cin >> n >> q;
 
	g.resize(n + 1);
	chain.resize(n + 1);
	parent.resize(n + 1);
	sz.resize(n + 1, 1);
	value.resize(n + 1);
	idx.resize(n + 1);
	arrs.resize(n + 1, vector<int> (1));
	HLD.resize(n + 1);
	depth.resize(n + 1);
 
	for (int i = 1; i <= n; i ++) 
		cin >> value[i];
 
	for (int i = 1; i < n; i ++) {
		int a, b;
		cin >> a >> b;
 
		g[a].push_back(b);
		g[b].push_back(a);
	}
 
	dfs_find(1, 1);
	dfs_assign(1, 1, 1);
	
	for (int i = 1; i <= n; i ++)
		HLD[i].init(arrs[i]);
 
	while (q --) {
		int tq, a, b;
		cin >> tq >> a >> b;
 
		if (tq == 1) {
			value[a] = b;
			HLD[chain[a]].update(idx[a], b); 
		} else {
			cout << calculate(a, b) << " ";
		}
	}
	
	return 0;
}