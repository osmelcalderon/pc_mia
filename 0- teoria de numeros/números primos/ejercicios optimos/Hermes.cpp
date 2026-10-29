#include <iostream>
#include <cmath>
#define optimizar_io ios_base::sync_with_stdio(0);
using namespace std;

int n;
int R[20002], C[20002];
int DP[2][2002][2];

int main(){

	optimizar_io
	cin >> n;
	for( int i = 1; i <= n; i++ ){
		cin >> R[i] >> C[i];
		R[i] += 1000;
		C[i] += 1000;
	}
	
	R[0] = 1000;
	C[0] = 1000;
	int a = 0, b = 1;
	int x, y, i;
	
	for( i = n - 1; i >= 0; i-- ){
		swap( a, b );
		x = R[i];
		for( y = 0; y <= 2000; y++ )	
			DP[a][y][0] = min( DP[b][y][0] + abs( R[i + 1] - x ), DP[b][x][1] + abs( C[i + 1] - y ) );
		y = C[i];
		for( x = 0; x <= 2000; x++ )
			DP[a][x][1] = min( DP[b][y][0] + abs( R[i + 1] - x ), DP[b][x][1] + abs( C[i + 1] - y ) );
	}
	cout << DP[a][1000][0] << "\n";
	
	return 0;

}
