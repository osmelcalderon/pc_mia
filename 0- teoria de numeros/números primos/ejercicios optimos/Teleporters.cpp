#include <bits/stdc++.h>

using namespace std;

#define x(i) (v[i].first)
#define type(i) (v[i].second.first)
#define id(i) (v[i].second.second)

#define NMAX 1000100

vector<pair<int, pair<char, int> > > v;
vector<int> clen;
int next[2 * NMAX], pfirst[2 * NMAX], plast[2 * NMAX];
char marked[2 * NMAX];
int i, j, k, N, M, xa, xb, pathlen, cyclelen;

int main()
{
    //freopen("t.in", "r", stdin);
    //freopen("t.out", "w", stdout);

    scanf("%d %d", &N, &M);

    for (i = 1; i <= N; i++)
    {
        scanf("%d %d", &xa, &xb);
        v.push_back(make_pair(xa, make_pair(-1, i)));
        v.push_back(make_pair(xb, make_pair(+1, i)));
    }

    sort(v.begin(), v.end());

    N <<= 1;

    for (i = 0; i < N; i++)
        if (type(i) < 0)
           pfirst[id(i)] = i;
        else
            plast[id(i)] = i;

    for (next[N] = -1, i = 0; i < N; i++)
        if (type(i) < 0)
           next[i] = plast[id(i)] + 1;
        else
           next[i] = pfirst[id(i)] + 1;

    memset(marked, 0, sizeof(marked));

    // compute the length of the main path

    pathlen = 1;
    i = 0;
    marked[i] = 1;

    while (i != N)
    {
          i = next[i];
          marked[i] = 1;
          pathlen++;
    }

    // compute the lengths of the cycles
    for (i = 0; i <= N; i++)
        if (!marked[i])
        {
           j = i;
           marked[j] = 1;
           cyclelen = 1;

           j = next[j];

           while (j != i)
           {
                 marked[j] = 1;
                 cyclelen++;
                 j = next[j];
           }

           clen.push_back(cyclelen);
        }

    // sort the lengths of the cycles
    sort(clen.begin(), clen.end());

    /*
    printf("pathlen=%d\nncycles=%d\n", pathlen, clen.size());
    for (j = clen.size() - 1; j >= 0; j--)
        printf("cycle_len=%d\n", clen[j]);

    for (i = 0; i < N; i++)
        printf("%d --> %d\n", i, next[i]);
    */

    for (j = clen.size() - 1; j >= 0 && M > 0; j--)
    {
        pathlen += 2 + clen[j];
        M--;
    }

    pathlen += (2 * (M - (M % 2))) + (M % 2);

    printf("%d\n", pathlen - 1);

    return 0;
}
