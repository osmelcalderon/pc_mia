#include<stdio.h>
int main(){
    long long N,P,E;
    scanf("%lld%lld",&N,&P);
    long long X=N;
    for(int i=0;i<3;++i){
        scanf("%lld",&E);
        X=(E>=P)? (E-P<=(N-E)+P)? (E-P<X)?E-P:X :((N-E)+P<X) ? (N-E)+P:X : (P-E<=(N-P)+E) ? (P-E<X)? P-E:X :((N-P)+E<X)?(N-P)+E:X;
    }
    printf("%lld",X);
    return 0;
}