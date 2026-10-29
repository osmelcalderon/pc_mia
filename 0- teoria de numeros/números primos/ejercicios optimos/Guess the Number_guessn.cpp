#include<stdio.h>
int main(){
    long long LMIN=1,LMAX=2000000000,MED;
    char s[2];
    while(s[0]!='='){
        MED=(LMAX+LMIN)>>1;
        printf("%lld\n",MED);
        scanf("%1s",s);
        if(s[0]=='<') LMIN=MED+1;
        if(s[0]=='>') LMAX=MED-1;
    }
    return 0;
}
