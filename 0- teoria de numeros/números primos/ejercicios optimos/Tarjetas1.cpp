/*
linkyless
--Copyright DMOJ
*/

#pragma GCC optimize("Ofast")

#include<stdio.h>

//\\ PRINCIPAL \\//

#define ll long long
#define ios ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0)


//\\ VECTOR \\//

#define pb push_back
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ordenar(x) sort(x.begin(), x.end())
#define ordenarA(x) sort(x, x + n)

//\\ OPERACIONES RAPIDAS \\//

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)


int main() {

    int a[200] = {0}, b[200] = {0};

    int n, m, k, c, hh, mm, t;

    char s[5];

    sff(n, m);

    for ( int i = 1; i <= m; i++ ){

        scanf("%d %5s %d %d",&c,s,&hh,&mm);

        if ( s[ 2 ]=='A' ) 
            a[ c ]= hh * 60 + mm;

        else {
            t = hh * 60 + mm; 
            b[ c ]+= t - a[ c ];
        }
    }

    for ( int i = 1; i <= n; i++ )
        printf("%d %d\n", b[ i ] / 60,b[ i ] % 60);

}