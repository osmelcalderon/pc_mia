#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
using namespace std;

#define endl '\n'
#define ll long long 
#define pb push_back
#define fs first 
#define sd second 
#define Eps double(1e-9)
#define Mod %= (long(1e9 + 9));

const int Max = 1e6 + 7,
          Inf = 2e9 + 7;

bitset <Max> color; int n = 0; 

void solve()
{
	int a, b; cin >> a >> b; n = max(n, b);
	color[a] = color[a] ^ 1; color[b + 1] = color[b + 1] ^ 1;
}

void print()
{
	int ans = 0; bool r = false; 

	for (int i = 1; i <= n; i++)
	{
		r ^= color[i]; color[i] = r; 
	}

	for (int i = 1; i <= n; i++)
	{
		int j = i, temp = 0; 

		if (!color[i]) continue; 

		for (; j <= n && color[j] == color[i]; j++)
			temp++; 
		
		ans = max(ans, temp); i = j - 1; 
	}

	cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int Q; cin >> Q; 

    while (Q--)
    {
        solve(); 
    } print(); 

    return 0; 
}