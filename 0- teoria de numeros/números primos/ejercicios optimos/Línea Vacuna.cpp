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

const ll Max = 4e4 + 7,
		 Inf = 1e9 + 7;
		 
void print(int x) { cout << x << endl; }

void solve()
{
	int N; cin >> N; 

	deque <int> q; int idx = 1; 

	while (N--)
	{
		char a, b; cin >> a >> b; 

		if (a == 'A')
		{
			if (b == 'L')
			{
				q.push_front(idx++); 
			}
			else
			{
				q.push_back(idx++);
			}
		}
		else
		{
			int k; cin >> k; 

			if (b == 'L')
			{
				for (int i = 0; i < k; i++)
					q.pop_front();
			}
			else
			{
				for (int i = 0; i < k; i++)
					q.pop_back();
			}
		}
	}

	while (!q.empty())
	{
		print(q.front()); 
		q.pop_front(); 
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