#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>
#include <vector>
using namespace std;

#define endl '\n'
#define ll long long 
#define db long double
#define pb push_back
#define fs first 
#define sd second 
#define unvisited long(-1e9 + 7)
#define Eps double(1e-9)
#define Mod (long(1e9 + 7))

const ll Max = 5e2 + 7,
		 Inf = 1e9 + 7;

int Dx[4] = { +1, -1, +0, +0 };
int Dy[4] = { +0, +0, +1, -1 };

int Map[Max][Max];

int solve(int n, int h, int x, int y)
{
	int ans = 0, sum = 0; vector <vector<bool>> visit(n + 1, vector<bool>(n + 1, false));

	priority_queue <pair<int, pair<int, int>>> pq;

	pq.push({ 0, { x, y } });

	while (!pq.empty())
	{
		if (sum == h) return ans;

		int a = pq.top().sd.fs, b = pq.top().sd.sd, w = pq.top().fs; pq.pop();

		if (visit[a][b]) continue;
		visit[a][b] = true; sum++;
		ans = max(ans, abs(w));

		for (int i = 0; i < 4; i++)
		{
			int Px = a + Dx[i], Py = b + Dy[i];

			if (Px >= n || Py >= n || Px < 0 || Py < 0)
				continue;

			if(visit[Px][Py]) continue;

			pq.push({ -(abs(Map[Px][Py] - Map[a][b])), { Px, Py } });
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];
	}

	int ans = Inf, l = 2; srand(time(NULL)); 

	for (int i = 0; i < l; i++)
	{
		int x = rand() % n, y = rand() % n; 

		ans = min(ans, solve(n, ((n * n)) / 2, x, y));
	}

	cout << ans << endl;

	return 0;
}
