#include <cstdio>
#include <queue>
#include <algorithm>
#define maxp 301
#define maxint 1 << 30

using namespace std;

int N, P[maxp], G[maxp][maxp], D[maxp], sol;
bool mark[maxp];
typedef pair <int, int> par;
priority_queue < par, vector <par>, greater <par> > Qp;

void prim ( int start )
{
  int nodo, newn, costo, newc;

  fill ( D, D + N + 1, maxint );
  D[start] = P[start];
  Qp.push(par(P[start], start));
  while ( !Qp.empty() )
  {
    nodo = Qp.top().second, costo = Qp.top().first;
    Qp.pop();
    if ( mark[nodo] )
      continue;
    mark[nodo] = true;
    sol += costo;
    for ( int i = 1; i <= N; i ++ )
    {
       if ( !G[nodo][i] )
         continue;
       newn = i;
       newc = G[nodo][newn];
       if ( D[newn] > newc )
       {
         D[newn] = min ( newc, P[newn] );
         Qp.push(par(D[newn], newn));
       }
    }
  }
}

int main (  )
{


 scanf ("%d", &N);

 int cant = maxint, nodo;
 for ( int i = 1; i <= N; i ++ )
 {
   scanf ("%d", &P[i]);
   if ( cant > P[i] )
   {
     cant = P[i];
     nodo = i;
   }
 }

 for ( int i = 1; i <= N; i ++ )
   for ( int j = 1; j <= N; j ++ )
      scanf ("%d", &G[i][j]);

 prim ( nodo );

 printf ("%d\n", sol);

 return 0;
}