#include<bits/stdc++.h>
#define int long long
#define vi vector < int >
#define vb vector < bool >
#define pii pair < int , int >
 
 
using namespace std;
 
int n = 7;
int vis [ 9 ] [ 9 ];
int ab [ 48 ];
int a[ ] = { -1 , 0 , 1 , 0 };
int b[ ] = { 0 , 1 , 0 , -1 };

int f ( int x , int y, int cnt ) {
    if ( vis [ x - 1 ] [ y ] && vis [ x + 1 ] [ y ] && !vis [ x ] [ y - 1 ] && !vis [ x ] [ y + 1 ]) return 0 ;
    if ( vis [ x ] [ y - 1 ] && vis [ x ] [ y + 1  ] && !vis [ x - 1] [ y ] && !vis [ x + 1] [ y ]) return 0 ;
	if ( x == n && y == 1 ) {
		if ( cnt == 48 ) return 1;
		return 0;
	}
    if ( cnt == 48 ) return 0;
	vis [ x ] [ y ] = true;
    int r = 0;
	if ( ab [ cnt ] < 4 ) {
        int sgx = x + a [ ab [ cnt ] ];
        int sgy = y + b [ ab [ cnt ] ];
        if ( !vis [ sgx ] [ sgy ]) r += f ( sgx , sgy , cnt + 1 );
		
	}
	else{
		for ( int i = 0 ; i < 4 ; i++ ) {
            int sgx = x + a [ i ];
            int sgy = y + b [ i ];
            if ( vis [ sgx ] [ sgy ]) continue;
            r += f ( sgx , sgy , cnt + 1 );
        }
	}
	vis [ x ] [ y ] = false;
    return r;
}
 
signed main ( ) {
	ios_base::sync_with_stdio ( 0 );cin.tie ( 0 );cout.tie ( 0 );cout.setf( ios::fixed );cout.precision( 0 );
	string s ; cin >> s;
    
    for ( int i = 0 ; i < n * n - 1 ; i ++  ) {
        if ( s [ i ] == 'U') ab [ i ] = 0;
        else if ( s [ i ] == 'R') ab [ i ] = 1;
        else if ( s [ i ] == 'D') ab [ i ] = 2;
        else if ( s [ i ] == 'L') ab [ i ] = 3;
        else ab [ i ] = 4;
    }
    
    for ( int i = 1 ; i <= 8 ; i++ ) {
        for ( int j = 1 ; j <= 8 ; j++ ) vis [ i ] [ j ] = false;
    }
    for ( int i = 0 ; i < n + 2 ; i++ ) {
        vis [ i ] [ 0 ] = true;
        vis [ 0 ] [ i ] = true;
        vis [ n + 1] [ i ] = true;
        vis [ i ] [ n + 1] = true;
    }
	int ans = f ( 1 , 1 , 0 );
	
	cout << ans << '\n';
 
 
	return 0;
}