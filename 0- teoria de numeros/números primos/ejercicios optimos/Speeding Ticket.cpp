#include <stdio.h>
short int max(short int a,short int b){
    return a > b ? a : b;
}
int main(){
    short int a[100],n,m;
    scanf("%hd%hd",&n,&m);
    short int i=0;
    while(i<100){
        scanf("%hd%hd",&n,&m);
        while(n--){
            a[i]=m;
            i++;
        }
    }
    i=0;
    short int r=0;
    while(i<100){
        scanf("%hd%hd",&n,&m);
        while(n--){
            r=max(r,m-a[i]);
            i++;
        }
    }
    printf("%hd",r);
}