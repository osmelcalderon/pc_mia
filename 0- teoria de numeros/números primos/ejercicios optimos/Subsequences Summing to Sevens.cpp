#include <cstdio>
using namespace std;

#define Mod %= 7;

int sec[7]; 

int max(int a, int b)
{
	if (a > b) return a;
	return b; 
}

int main()
{
	int n, r = 0, ans = 0; scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int id; scanf("%d", &id); 
		r += id; r Mod

		if (sec[r] == 0) sec[r] = i;
		else ans = max(ans, i - sec[r]); 
	}
	
	printf("%d", ans); 

	return 0; 
}