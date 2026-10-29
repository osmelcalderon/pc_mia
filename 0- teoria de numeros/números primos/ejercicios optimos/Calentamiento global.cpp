/*
linkyless
--Copyright DMOJ
*/


#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

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

int a[200001];
int b[200001];
int pos[200001];

int main() {

    ios;
    
    int n, x;

    cin >> n >> x;

    for( int i = 1 ; i <= n ; i++ )
        cin >> a[i];

    int m = 0;

    for( int i = 1 ; i <= n ; i++ ){
        int k = lower_bound( b + 1 , b + m + 1 , a[ i ] ) - b; //convertir a posición
        b[ k ] = a[ i ];
        m = max( m , k );
        pos[i] = k;
    }

    int final = 0;

    m = 0;

    for( int i = n; ~i; i-- ){
    
        final = max( final , min( m , int(lower_bound(b + 1 , b + m + 1 , a[i] , greater< int >()) - b ) - 1 ) + pos[i]);
        int k = lower_bound( b + 1 , b + m + 1 , a[i] + x , greater<int>()) - b;
        b[ k ] = a[ i ] + x;
        m = max( m , k );
    }

    cout << final;



    return 0;

}