#include<stdio.h>
int main(){
    int n,m,t=0,ex=0,s;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d",&s);
        if(s<4){
            t=0;
            break;
        }
        t+=s;
        ex+=(s%4);
    }
    if(t-ex<n*4||n<m){
        printf("NE");
    }
    else{printf("DA");}
    return 0;
}