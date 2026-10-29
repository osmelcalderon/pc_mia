#include<stdio.h>
int main(){
    int n,m=0,Uc=0,Dc=0,Lc=0,Rc=0;
    scanf("%d",&n);
    char o[n+1];
    scanf("%100s",o);
    for(int i=0;i<n;++i){
       if(o[i]=='U'){
           ++Uc;
       }
       else if(o[i]=='D'){
           ++Dc;
       }
       else if(o[i]=='L'){
           ++Lc;
       }
       else{
           ++Rc;
       }
    }
    m+=(Uc>Dc)?Dc*2:Uc*2;
    m+=(Lc>Rc)?Rc*2:Lc*2;
    printf("%d",m);
    return 0;
}