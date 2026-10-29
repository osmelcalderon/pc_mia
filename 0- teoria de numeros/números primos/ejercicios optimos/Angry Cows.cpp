#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 
#define pb push_back
#define fs first 
#define sd second 
#define Mod %= (long(1e9 + 9));

const int Max = 1e6 + 7,
		  Inf = 2e9 + 7;

int main() 
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	int n; cin >> n;

	vector <int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v[i] *= 2;
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	vector<int> dp[2];

	for (int j = 0; j < 2; j++) 
	{
		int cont = 0;

		dp[j].resize(n, Inf); dp[j][0] = -2;

		for (int i = 1; i < n; i++) 
		{
			while (cont + 1 < i && abs(v[i] - v[cont + 1]) > dp[j][cont + 1] + 2) { cont++; }
			dp[j][i] = min(abs(v[i] - v[cont]), dp[j][cont + 1] + 2);
		}
		reverse(v.begin(), v.end());
	}
	reverse(dp[1].begin(), dp[1].end());

	int i = 0, j = n - 1, ans = Inf;

	while (i < j) 
	{
		ans = min(ans, max((v[j] - v[i]) / 2, 2 + max(dp[0][i], dp[1][j])));

		if (dp[0][i + 1] < dp[1][j - 1]) i++;
		else j--;

	}

	cout << ans / 2 << '.' << (ans % 2 ? 5 : 0) << '\n';

	return 0;
}