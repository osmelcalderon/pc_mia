#include <bits/stdc++.h>
#define MAXN    951

int dist[MAXN][MAXN];
int x[MAXN], y[MAXN], curcow;
int dead[MAXN];
int n;

main () {
    
    int i, j, bestdist, bestcow;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf ("%d %d", &x[i], &y[i]);
    for (i = 0; i < n; i++) {
        for (j=i+1; j < n; j++) {
            int a = x[i]-x[j], b = y[i]-y[j];
            dist[j][i] = dist[i][j] = a*a+b*b;
        }
    }
    curcow = 0;
    for (i = 0; i < n-1; i++) {
        /* tag nearest cow */
        bestdist = 2000000000;
        for (j = 0; j < n; j++) {
            if (dead[j] || curcow == j) continue;
            if (dist[curcow][j] < bestdist) {
                bestdist = dist[curcow][j];
                bestcow = j;
            }
        }
        dead[bestcow] = 1;
        do {
            if (++curcow >= n) curcow = 0;
        } while (dead[curcow]);
    }
    printf ("%d\n", curcow+1);
    exit (0);
}