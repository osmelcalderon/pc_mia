#include <algorithm>
#include <stdio.h>

using namespace std;

int n, h, sol = 1e9;
int p[101], c[101];
int dp[55001];

int main(){
	int i, j;
	for(i = 1; i <= 55001; i++) dp[i] = 1e9;
	
	scanf("%d%d", &n, &h);
	for(i = 1; i <= n; i++) scanf("%d%d", &p[i], &c[i]);
	
	for(i = 1; i <= n; i++)
		for(j = p[i]; j <= h + 5000; j++)
			dp[j] = min(dp[j], dp[j - p[i]] + c[i]);
	
	for(i = h; i <= h + 5000; i++) sol = min(sol, dp[i]);
	
	printf("%d", sol);
	
	return 0;
}