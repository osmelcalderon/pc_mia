#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1000000 + 10;

int n, budget;
int dp[MAXV];
int dp2[MAXV];

int main() {

  //fscanf ( "%d %d", &n, &budget);
    cin>>n>>budget;
  for(int i = 0; i <= budget; ++i) {
    dp[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int p0,k;
    //fscanf ( "%d %d", &p0, &k);
   cin>>p0>>k;
    for (int c = p0; c <= budget; ++c) {
      dp2[c] = dp[c-p0];
    }
    for (int j = 0; j < k; ++j) {
      int p,v;
      //fscanf ( "%d %d", &p, &v);
        cin>>p>>v;
      for (int c = budget-p; c >= p0; --c) {
	if (dp2[c+p] < dp2[c] + v)
	   dp2[c+p] = dp2[c] + v;
      }
    }
    for (int c = p0; c <= budget; ++c) {
      if (dp[c] < dp2[c])
	 dp[c] = dp2[c];
    }
  }
 // fprintf ( "%d\n", dp[budget]);
 cout<<dp[budget];
  return (0);
}