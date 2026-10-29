/*
  Koder : Ramon Alejandro Ryees Fajardo
  Task  : Final.08 - SUMX
*/

#include <cstdio>
#include <algorithm>

const int MAX = 100001;

int N, S;
int i, ts, lo, hi, mid, sol;

int l[MAX];

int main(){

  /*   standard input & output   */
//  freopen( "d.in", "r", stdin );
//  freopen( "d.out", "w", stdout );
  
  scanf( "%d", &N );
  
  for ( i = 0; i < N; i++ ) scanf( "%d", &l[i] );
  
  scanf( "%d", &S );
  
  std::sort( l, l + N );
  
  for ( i = 0; i < N && l[i] + l[i + 1] <= S; i++ ){
    
    lo = i + 1; hi = N - 1;
    
    while ( lo <= hi ){
      mid = ( lo + hi ) / 2;
      ts = l[i] + l[mid];
      if ( ts == S ) { sol++; break; }
      if ( ts <  S ) lo = mid + 1; else hi = mid - 1;
    }//while
    
  }//for i
  
  printf( "%d\n", sol );
  
  fflush( stdout );
  
  return 0;

}//main