#define CICLE(i,a,b,c) for(int i=(a); i<=(b); i += (c))
using namespace std;
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
const int oooo = 1e6;
const int MAXV = 103 + 103;
const int MAXA = 10003 + 10003 + 403;
int A, V, source, sink, id;
int last[MAXV], level[MAXV], Q[MAXV];
int cap[MAXA], flow[MAXA], ady[MAXA], nnext[MAXA], now[MAXA];

void Init(int so, int si)
{
 A = id = 0;
 source = so; sink = si;
 memset(last,-1,sizeof(last));
}

void Add_Edge(int u, int v, int c)
{
 cap[A] = c;
 flow[A] = 0;
 ady[A] = v;
 nnext[A] = last[u];
 last[u] = A++;
}

bool BFS(int s, int t)
{
 int i, u, v, ent, sal;
 memset(level,-1,sizeof(level));
 ent = sal = level[s] = 0; Q[ent++] = s;
 while(sal < ent && level[t] == -1)
 {
  u = Q[sal++];
  for(i = last[u]; i != -1; i = nnext[i])
  {
   v = ady[i];
   if(level[v] == -1 && flow[i] < cap[i])
   {

    level[v] = level[u] + 1;
	Q[ent++] = v;
   }
  }
 }
 return level[t] != -1;
}

int DFS(int v, int flujo)
{
 if(v == sink) return flujo;
 for(int f, i = now[v]; i != -1; now[v] = i = nnext[i])
 {
  if(level[ady[i]] > level[v] && flow[i] < cap[i])
  {
   if(f = DFS(ady[i], min(flujo ,cap[i] - flow[i])))
   {
    flow[i] += f;
    flow[i^1] -= f;
    return f;
   }
  }
 }
 return 0;
}

int fast_dinic_max_flow()
{
 int res, flujo = 0;
 while(BFS(source,sink))
 {
  for(int i = 0; i < V; i++) now[i] = last[i];
  while((res = DFS(source,oooo)) > 0) flujo += res;
 }
 return flujo;
}

int n, m;
double s, v;
double xg[MAXV], yg[MAXV];
double xh[MAXV], yh[MAXV];

double DST(double x, double y, double ax, double ay)
{
 double tmp = (x-ax)*(x-ax) + (y-ay)*(y-ay);
 return sqrt(tmp);
}

bool CanReach(int p, int q)
{
 double dst = DST(xg[p], yg[p], xh[q], yh[q]);
 return s >= dst / v;
}

int main()
{

 while(EOF != scanf("%d%d%lf%lf",&n,&m,&s,&v))
 {
  //printf("TEST %d %d\n",n,m);
  V = n + m + 1; Init(0, V);
  CICLE(p,1,n,1)
  {
   scanf("%lf%lf",&xg[p],&yg[p]);
   Add_Edge(0,p,1); Add_Edge(p,0,0);
  }
  CICLE(q,1,m,1)
  {
   scanf("%lf%lf",&xh[q],&yh[q]);
   Add_Edge(n+q,V,1); Add_Edge(V,n+q,0);
  }
  CICLE(p,1,n,1) CICLE(q,1,m,1)
  if(CanReach(p, q))
  {
   Add_Edge(p,n+q,1); Add_Edge(n+q,p,0);
  }
  printf("%d\n",n-fast_dinic_max_flow());
 }
}