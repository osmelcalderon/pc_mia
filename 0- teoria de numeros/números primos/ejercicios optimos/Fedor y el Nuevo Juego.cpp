//Fedor y el Nuevo Juego
#include<stdio.h>

int f(int n){
    int cont = 0;
    while(n){
        n = n & (n - 1);
        cont++;
    }
return cont;
}

int main(){
    int n, m, k, c = 0;
    scanf("%d%d%d",&n,&m,&k);
    int p[m+1];

    for(int i = 0; i <= m; i++){
        scanf("%d",&p[i]);
    }

    for(int i = 0; i < m; i++){
        int x = (p[i]^p[m]);
        if(f(x) <= k )c++;
    }
    printf("%d",c);
return 0;
}