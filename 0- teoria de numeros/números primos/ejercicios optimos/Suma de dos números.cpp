#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, S[100];
char a[100], b[100], s[100];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    sort(s + 1, s + n + 1);

    for(int i = 1; i <= n; i++)
        a[i] = s[i] - '0';

    if(a[1] == 0) {
        int i = 1;
        for(; i <= n; i++) {
            if(a[i] > 0)
                break;
        }

        swap(a[1], a[i]);
    }

    for(int i = 1; i <= n; i++)
        b[i] = s[n - i + 1] - '0';

    int c = 0;
    for(int i = n; i > 0; i--) {
        S[i] = (a[i] + b[i] + c) % 10;
        c = (a[i] + b[i] + c) / 10;
    }

    if(c > 0)
        printf("%d", c);

    for(int i = 1; i <= n; i++)
        printf("%d", S[i]);

    return 0;
}