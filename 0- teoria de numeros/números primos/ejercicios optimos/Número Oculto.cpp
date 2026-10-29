#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000010;

int N , borrow;
char dig[MAXN] , ans[MAXN];

int main(){
    
    scanf( "%s" , &dig );
    
    N = strlen( dig );
    ans[N] = '0';
    
    for ( int i = N - 1 ; i >= 0 ; i-- ){
        int digit = (int) dig[i] - ans[i+1] - borrow;
        if ( digit < 0 ){
            digit += 10;
            borrow = 1;
        }
        else borrow = 0;
        ans[i] = '0' + digit;
    }
    
    ans[N] = 0;
    
    if ( ans[0] == '0' ) printf( "IMPOSSIBLE\n" );
    else printf( "%s\n" , ans );
    
    return 0;
}