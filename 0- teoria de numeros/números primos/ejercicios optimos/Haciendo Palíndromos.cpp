#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 2e6 + 5;
int t, tc, p[MAX], pal[MAX];
char s[MAX];

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

    scanf("%s", s + 1);
    int n = strlen(s + 1);

    reverse(s + 1, s + n + 1);
    for(int i = n + 1, l = n; i <= 2 * n; i++, l--)
        s[i] = s[l];

    for(int i = 2, k = 0; i <= 2 * n; i++) {
        while(k > 0 && s[i] != s[k + 1])
            k = p[k];

        if(s[i] == s[k + 1])
            k++;

        p[i] = k;
    }

    for(int i = p[2 * n]; i > 0; i = p[i])
        if(i <= n)
            pal[n - i + 1] = 1;

    for(int i = 1; i <= n; i++) {
        if(pal[i]) {
            printf("%d\n", i - 1);
            break;
        }
    }

	return 0;
}