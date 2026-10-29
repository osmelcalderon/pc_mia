/*
    koder : fert21
    PROG  : "Cornfields"
*/

#include <algorithm>
#include <cstdio>
#define MAX 251

using namespace std;

int i, j, k;
int N, B, K, a, b;
int s[2][8][MAX][MAX];

int main( ) {
    

	scanf( "%d%d%d", &N, &B, &K );
	
	for ( i = 1 ; i <= N ; i++ )
	    for ( j = 1 ; j <= N ; j++ ) {
		    scanf( "%d", &a );
		    s[0][0][i][j] = a;
			s[1][0][i][j] = a;
		}
	

	for ( k = 1 ; ( 1 << k ) <= N ; k++ )
	    for ( i = 1 ; i + ( 1 << k ) - 1 <= N ; i++ )
		    for ( j = 1 ; j + ( 1 << k ) - 1 <= N ; j++ ) {
			    a = i + ( 1 << ( k - 1 ) );
				b = j + ( 1 << ( k - 1 ) );
				
			    s[0][k][i][j] = max( max( s[0][k - 1][i][j], s[0][k - 1][i][b] ),
				                     max( s[0][k - 1][a][j], s[0][k - 1][a][b] ) );
				
				s[1][k][i][j] = min( min( s[1][k - 1][i][j], s[1][k - 1][i][b] ),
				                     min( s[1][k - 1][a][j], s[1][k - 1][a][b] ) );
			}
			    
	for ( k = 0 ; ( 1 << k ) <= B ; k++ );
	k--;
	
	for ( ; K ; K-- ) {
	    scanf( "%d%d", &a, &b );
		
	    i = a + B - ( 1 << k );
		j = b + B - ( 1 << k );
		
		int mx = max( max( s[0][k][a][b], s[0][k][i][b] ),
		              max( s[0][k][a][j], s[0][k][i][j] ) );
		
		int mn = min( min( s[1][k][a][b], s[1][k][i][b] ),
		              min( s[1][k][a][j], s[1][k][i][j] ) );
		
		printf( "%d\n", mx - mn );
	}
	
    return 0;
}