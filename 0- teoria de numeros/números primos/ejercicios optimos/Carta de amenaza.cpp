#include <cstdio>
#include <cstring>

const int maxn = 50005;
int n, m, ans, now;
int sam[maxn << 1][26], len[maxn << 1], link[maxn << 1], sz, last, p, q, cur, clone;
char ch;

int main() {
    scanf("%d%d", &n, &m);
    link[sz++] = -1;
    for (int i = 1; i <= n; ++i) {
        while ((ch = getchar()) < 'A');
        cur = sz++;
        len[cur] = len[last] + 1;
        for (p = last; p != -1 && !sam[p][ch - 'A']; p = link[p]) {
            sam[p][ch - 'A'] = cur;
        }
        if (p != -1) {
            q = sam[p][ch - 'A'];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            }
            else {
                clone = sz++;
                memcpy(sam[clone], sam[q], sizeof sam[0]);
                link[clone] = link[q];
                len[clone] = len[p] + 1;
                for (; p != -1 && sam[p][ch - 'A'] == q; p = link[p]) {
                    sam[p][ch - 'A'] = clone;
                }
                link[q] = link[cur] = clone;
            }
        }
        last = cur;
    }
    for (int i = 1; i <= m; ++i) {
        while ((ch = getchar()) < 'A');
        now = sam[now][ch - 'A'];
        
        if (!now) {
            ++ans;
            now = sam[0][ch - 'A'];
        }
    }
	
    if (now) {
        ++ans;
    }

    printf("%d\n", ans);

    return 0;

}