#include<stdio.h>
#define _MAX 50100

int n;
int array[_MAX];
long long int conectados, mcm;

long long int MCD( long long int a, long long int b )
{
    long long int aux;
    while(b)
    {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

void unir( int x )
{
    if( array[x] == 0 )
        return;
    conectados++;
    int aux = array[x];
    array[x] = 0;
    unir( aux );
    return;
}

void leer()
{
    mcm = 1;
    scanf("%d" , & n );
    for( int i = 1; i <= n; i ++ )
        scanf("%d" , & array[i] );
    for( int i = 1; i <= n; i ++ )
    {
        conectados = 0;
        if( array[i] != 0 )
        {
            unir( i );
            long long int mcdd = MCD( mcm , conectados );
            mcm = ( mcm / mcdd ) *  conectados;
        }
    }
    printf("%lld\n" , mcm );
}

int main()
{
    leer();
    return 0;
}
