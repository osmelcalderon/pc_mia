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

algorithm
{
	uint N;
	scanf("%llu", &N);
	uint C[N];

	for (int x = 0; x < N; x++)
		C[x] = 0;

	for (uint x = 0; x < N - 1; x++)
	{
		uint a, b;
		scanf("%llu%llu", &a, &b);
		C[a - 1]++;
	}

	uint la = 0, t = 0;
	for (uint x = 0; x < N; x++)
	{
		if (C[x] == 0)
			la = x, t++;
	}

	if (t == 0 || t > 1)
		printf("-1\n");
	else printf("%llu\n", la + 1);
}