#include <stdio.h>

int read(int N, int S, int T, int R){
    int retorno=0;
    int serie = T*S;

    while (N > serie){
        N -= serie;
        retorno+=(T+R);
    }

    if (N == serie){
        retorno+=(T);
        N -= serie;
    }

    while ( N > 0 ){
        N -= S;
        retorno ++;
    }

    return retorno;
}

int main(void)
{
    int N, K, S, T, R;
    scanf("%d%d",&N,&K);
    while (K--) {
        scanf("%d%d%d",&S,&T,&R);
        printf("%d\n",read(N,S,T,R));
    }
    return 0;
}