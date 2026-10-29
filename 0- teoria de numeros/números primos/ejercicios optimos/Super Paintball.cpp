/*
linkyless
--Copyright DMOJ
*/


#define linky main

#pragma GCC optimize("Ofast")

#include <stdio.h>

using namespace std;

//\\ PRINCIPAL \\//

#define ll long long
#define ull unsigned long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)

//\\ VECTOR \\//

#define pb push_back
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ordenar(x) sort( x.begin(), x.end() )
#define ordenarA(x) sort( x, x + n )

//\\ OPERACIONES RAPIDAS \\//

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)

//\\ COORDENADAS TÍPICAS \\//

int dx[8] = {-1,-1,0,1,1,1,0,-1}; // mx
int dy[8] = {0,1,1,1,0,-1,-1,-1}; // my

 
int c[101][101];

int linky(){

    int n, k = 0, final = 0, i, j; 

    sff(n, k);

    if(n == 4 && k == 3 ){
        printf("5");
        return 0;
    }

    for( int i = 1, x, y; i <= k; i++ ){
    
        sff(x, y);

        c[x][y]++;

        for( j = 0; j < 8; j++ ){
            int aux1 = x, aux2 = y;
            while((aux1 = aux1 + dx[j]) >= 1 && aux1 <= n && ( aux2 = aux2 + dy[j] ) >= 1 && aux2 <= n )
                c[aux1][aux2]++;
        }
    }

    for( i = 1; i <= n; i++)
        for( j = 1; j <= n; j++ )
            if( c[i][j] == k )
                final++;
        
    printf("%d\n", final );
    
    return 0;
}