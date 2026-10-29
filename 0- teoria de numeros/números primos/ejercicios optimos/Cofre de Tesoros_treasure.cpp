#include <cstdio>
#include <algorithm>
using namespace std;

//FILE *in = fopen ("treasure.in", "r"), *out = fopen ("treasure.out", "w");

const int MAXN = 5005;

int N, coins [MAXN], psum [MAXN], dp [MAXN];

int main () {
    scanf ("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf ("%d", coins + i);
        psum [i + 1] = psum [i] + coins [i];
    }

    for (int len = 1; len <= N; len++)
        for (int i = 0; i + len <= N; i++)
            dp [i] = psum [i + len] - psum [i] - min (dp [i], dp [i + 1]);

    printf ("%d\n", dp [0]);
    return 0;
}
