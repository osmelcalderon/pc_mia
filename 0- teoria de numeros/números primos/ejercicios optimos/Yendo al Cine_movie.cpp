#include <cstdio>

const int MAXN = 22;
const int MAXC = 1010;

int N, L;

int D[MAXN];        // D[i]: length of movie i
int S[MAXN][MAXC]; // S[i]: showtimes of movie i
int C[MAXN];        // C[i]: length of list ar[i]

int dp[1 << MAXN]; // dp[ {x} ]: max safe time watching movies from {x}
    // where {x} is a subset of [0,N), and is represented by a bitmask

int find(int val, int *ar, int len) {
  // bin search for greatest x s.t. ar[x] <= val
  int lo = -1, hi = len - 1;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ar[mid] <= val) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

int popcount(int x) { // returns number of bits of x set to 1
  if (x) return 1 + popcount(x & (x - 1));
  else return 0;
}

int main() {

  scanf("%d %d", &N, &L);
  for(int i = 0; i < N; ++i) {
    scanf("%d %d", D + i, C + i);
    for(int j = 0; j < C[i]; ++j) {
      scanf("%d", S[i] + j);
    }
  }

  for(int msk = 1; msk < (1 << N); ++msk) {
    dp[msk] = -1;
  }
  // dp[0] = 0

  int ans = -1;
  for(int msk = 0; msk < (1 << N); ++msk) {
    int cur = dp[msk];
    if (cur == -1) continue;

    if (cur >= L) {
      int cnt = popcount(msk);
      if (ans == -1 || cnt < ans) ans = cnt;
    }

    for(int i = 0; i < N; ++i) {
      if (msk & (1 << i)) continue;
      // try watching movie i after watching {msk}
      int nmsk = msk | (1 << i);
      int idx = find(cur, S[i], C[i]);
      if (idx == -1) continue;
      // want to watch idx-th showing of movie i (latest showing)

      int t = S[i][idx] + D[i];
      if (t > dp[nmsk]) dp[nmsk] = t;
    }
  }

  printf("%d\n", ans);
  return 0;
}
