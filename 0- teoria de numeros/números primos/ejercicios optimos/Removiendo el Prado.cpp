#include <bits/stdc++.h>
 #define mid (x+xend)/2
 #define izq nod*2
 #define der nod*2+1
 typedef long long int64;
 using namespace std;

 int64 N, K, pos, a, b;
 int64 A[100010], S[100010], f[100010], g[100010], T[200010];

 int64 _max(int64 a, int64 b){
     if(a > b)
        return a;
     return b;
 }

 int64 update(int64 x, int64 xend, int64 nod){
     if( x==xend && x==pos )
        return T[nod] = g[pos];
     if( x > pos || xend < pos )
        return T[nod];

     return T[nod] = _max(update(x, mid, izq), update(mid+1, xend, der));
 }

 int64 query(int64 x, int64 xend, int64 nod){
    if( a<=x && xend<=b )
       return T[nod];
    if( x > b || xend < a )
       return -(1ull<<60);

    return _max(query(x, mid, izq), query(mid+1, xend, der));
 }

 int64 max_g(int64 x, int64 y){
     a = x, b = y;
     return query(0, N, 1);
 }

 main(void){
//     freopen("mowlawn.in", "r", stdin);
//     freopen(".out", "w", stdout);

     scanf("%lld%lld", &N, &K);
     for(int64 i=1; i<=N; i++){
         scanf("%lld", &A[i]);
         S[i] = S[i-1] + A[i];
     }

     f[0] = 0, f[1] = A[1], g[1] = -A[1];
     pos = 1; update(0, N, 1);

     for(int64 i=2; i<=N; i++){
         f[i] = _max(f[i], S[i] + max_g( _max(0, i-K), i-1 ));
         g[i] = f[i-1] - S[i];

         pos = i; update(0, N, 1);
         f[i+1] = f[i];
     }

     printf("%lld\n", f[N]);

  return 0;
 }