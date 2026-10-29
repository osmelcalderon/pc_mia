#include<stdio.h>

/* Soluciona el testcase */
void solve(int n){
    int cnt = 0;
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0){
            cnt=0;
            while(n%i==0){
                cnt+=1;
                n/=i;
            }
            printf("(%d(%d))", i, cnt);
        }
    }
    if(n!=1){
        printf("(%d(%d))\n", n, 1);
    }else printf("\n");
}

/* Funcion principal */
int main(){
    int n;
    while(scanf("%d", &n) != EOF ){
        if(n==1){
            printf("(1(1))\n");
            continue;
        }
        solve(n);
    }

}