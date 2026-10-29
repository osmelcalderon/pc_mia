#include <cstdio>
#include <algorithm>

using namespace std;

int C, F, Q, sol;
bool mark[505][505];

int main()
{

 scanf ("%d%d%d", &C, &F, &Q);

 int col1, fil1, col2, fil2;
 for ( int q1 = 0; q1 < Q; q1 ++ )
 {
   scanf ("%d%d%d%d", &col1, &fil1, &col2, &fil2);
   for ( int i = fil1; i <= fil2; i ++ )
     for ( int j = col1; j <= col2; j ++ )
     {
        if ( mark[i][j] )
          continue;
        mark[i][j] = true;
        sol ++;
     }
 }

 printf ("%d", sol);

 fflush (stdin);
 fflush (stdout);
 return 0;
}