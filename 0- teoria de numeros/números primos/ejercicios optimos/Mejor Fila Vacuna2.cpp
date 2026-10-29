#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define oo ( 1<< 30 )
#define MAXN 60002
#define MAXLOG 18
#define REP( i, n ) \
        for ( int i = 0; i < (n); i++ )

struct event {
    int nr[2], p;
    bool operator < ( const event &a ) const {
        return ( nr[0] != a.nr[0] ) ? nr[0] < a.nr[0]
                                    : nr[1] < a.nr[1];
    }
} L[MAXN];
        
int N, stp, delta, left, right, printed;
char st[MAXN];
int P[MAXLOG][MAXN];

void print ( int l, int r ) {
    if ( l < r ) {
        printf( "%c", st[left] );
        left++;
    } else {
        printf( "%c", st[right] );
        right++;
    }
    if ( !(++printed % 80 ) ) printf( "\n" );
}

int main () {
    scanf( "%d\n", &N );
    REP( i, N ) scanf( "%c\n", &st[i] );
    
    /* add reversed string */
    REP( i, N ) st[N + i] = st[N - i - 1];
    N *= 2;
    
    /* build suffix array */
    REP( i, N ) P[0][i] = st[i];

    for ( stp = 1, delta = 1; delta >> 1 < N; stp++, delta <<= 1 ) {
    
        REP( i, N ) {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = ( i + delta < N ) ? P[stp - 1][i + delta] : -1;
            L[i].p = i;
        }
        
        sort( L, L + N );
        
        REP( i, N )
            P[stp][ L[i].p ] = ( i > 0 && L[i].nr[0] == L[i - 1].nr[0] &&
                                          L[i].nr[1] == L[i - 1].nr[1] )
                                ? P[stp][ L[i - 1].p ] : i;
    }
    
    int SA = stp - 1; // stands for Suffix Array
    left = 0; right = N / 2;
    
    REP( i, N / 2 )
        if ( left < N / 2 && right < N )
            print( P[SA][left], P[SA][right] );
        else if ( left < N / 2 ) print( P[SA][left], oo );
        else print( oo, P[SA][right] );
    
    return 0;
}