#include<stdio.h>
int main(){
    long long N,UD=(1025/105)+1,C,D,U;
    scanf("%lld",&N);
    C=N/144;
    N%=144;
    D=N/12;
    N%=12;
    U=N;
    if(U>=UD){
        U=0;
        ++D;
    }
    if(D==11&&U){++C;D=U=0;}
    printf("%lld %lld %lld",C,D,U);
    return 0;
}