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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

bool condicional[200001];
int arr[101];

int main(){
    
    int N, K;

    sff(N, K);
    
    for( int i = 0; i < N; i++ ){
        sfl(arr[i]);
    }
    
    for( int i = 0; i <= K; i++){
        if( condicional[i] ){
            continue;
        }
        else{
            for( int j = 0; j < N; j++ ){
                    condicional[i + arr[j]] = 1;
            }
        }
    }
    
    if( condicional[K] )
        printf("First");
    else 
        printf("Second");
        
    return 0;
    
}